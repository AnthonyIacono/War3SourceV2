#include "NavMeshLoader.h"

#include <iostream>
#include <sys/stat.h>
#include "sdk/smsdk_ext.h"
#include "List.h"
#include "INavMeshPlace.h"
#include "NavMeshPlace.h"
#include "NavDirType.h"
#include "NavLadderDirType.h"
#include "NavCornerType.h"
#include "NavMeshLadder.h"

namespace War3Source {
	NavMeshLoader::NavMeshLoader(const char *mapName) {
		strcpy_s(this->mapName, sizeof(this->mapName), mapName);
		this->bytesRead = 0;
	}

	NavMeshLoader::~NavMeshLoader() {
	}

	INavMesh *NavMeshLoader::Load(char *error, int errorMaxlen) {
		strcpy_s(error, errorMaxlen, "");

		char navPath[1024];
		g_pSM->BuildPath(Path_Game, navPath, sizeof(navPath), "maps\\%s.nav", this->mapName);

		FILE *fileHandle = fopen(navPath, "rb");

		if(!fileHandle) {
			sprintf_s(error, errorMaxlen, "Unable to find navigation mesh: %s", navPath);
			return NULL;
		}

		unsigned int magicNumber;
		int elementsRead = this->ReadData(&magicNumber, sizeof(unsigned int), 1, fileHandle);

		if(elementsRead != 1) {
			fclose(fileHandle);
			sprintf_s(error, errorMaxlen, "Error reading magic number value from navigation mesh: %s", navPath);
			return NULL;
		}

		if(magicNumber != 0xFEEDFACE) {
			fclose(fileHandle);
			sprintf_s(error, errorMaxlen, "Invalid magic number value from navigation mesh: %s [%p]", navPath, magicNumber);
			return NULL;
		}

		unsigned int version;
		elementsRead = this->ReadData(&version, sizeof(unsigned int), 1, fileHandle);

		if(elementsRead != 1) {
			fclose(fileHandle);
			sprintf_s(error, errorMaxlen, "Error reading version number from navigation mesh: %s", navPath);
			return NULL;
		}

		if (version < 6 || version > 16) {
			fclose(fileHandle);
			sprintf_s(error, errorMaxlen, "Invalid version number value from navigation mesh: %s [%d]", navPath, version);
			return NULL;
		}

		unsigned int navMeshSubVersion = 0;

		if(version >= 10) {
			this->ReadData(&navMeshSubVersion, sizeof(unsigned int), 1, fileHandle);
		}

		unsigned int saveBspSize;
		this->ReadData(&saveBspSize, sizeof(unsigned int), 1, fileHandle);

		char bspPath[1024];
		g_pSM->BuildPath(Path_Game, bspPath, sizeof(bspPath), "maps\\%s.bsp", this->mapName);

		unsigned int actualBspSize = 0;

#ifdef PLATFORM_WINDOWS
		struct _stat s;
		_stat(bspPath, &s);
		actualBspSize = s.st_size;
#elif defined PLATFORM_POSIX
		struct stat s;
		stat(bspPath, &s);
		actualBspSize = s.st_size;
#endif

		if(actualBspSize != saveBspSize) {
			//META_CONPRINTF("WARNING: Navigation mesh was not built with the same version of the map [%d vs %d].\n", actualBspSize, saveBspSize);
		}

		unsigned char meshAnalyzed = 0;

		if(version >= 14) {
			this->ReadData(&meshAnalyzed, sizeof(unsigned char), 1, fileHandle);
		}

		bool isMeshAnalyzed = meshAnalyzed != 0;

		//META_CONPRINTF("Is mesh analyzed: %s\n", isMeshAnalyzed ? "yes" : "no");

		unsigned short placeCount;
		this->ReadData(&placeCount, sizeof(unsigned short), 1, fileHandle);

		//META_CONPRINTF("Nav version: %d; BSPSize: %d; MagicNumber: %p; SubVersion: %d [v10+only]; Place Count: %d\n", version, saveBspSize, magicNumber, navMeshSubVersion, placeCount);
		
		List<INavMeshPlace*> *places = new List<INavMeshPlace*>();

		for(unsigned int placeIndex = 0; placeIndex < placeCount; placeIndex++) {
			unsigned short placeSize;

			this->ReadData(&placeSize, sizeof(unsigned short), 1, fileHandle);

			char placeName[256];
			this->ReadData(placeName, sizeof(unsigned char), placeSize, fileHandle);

			places->Append(new NavMeshPlace(placeIndex, placeName));
			//META_CONPRINTF("Parsed place: %s [%d]\n", placeName, placeIndex);
		}

		unsigned char unnamedAreas = 0;
		if(version > 11) {
			this->ReadData(&unnamedAreas, sizeof(unsigned char), 1, fileHandle);
		}

		bool hasUnnamedAreas = unnamedAreas != 0;

		//META_CONPRINTF("Has unnamed areas: %s\n", hasUnnamedAreas ? "yes" : "no");

		unsigned int areaCount;
		this->ReadData(&areaCount, sizeof(unsigned int), 1, fileHandle);

		//META_CONPRINTF("Area count: %d\n", areaCount);

		for(unsigned int areaIndex = 0; areaIndex < areaCount; areaIndex++) {
			unsigned int areaID;

			this->ReadData(&areaID, sizeof(unsigned int), 1, fileHandle);

			//META_CONPRINTF("Area ID: %d\n", areaID);

			unsigned int areaFlags = 0;

			if(version <= 8) {
				this->ReadData(&areaFlags, sizeof(unsigned char), 1, fileHandle);
			}
			else if(version < 13) {
				this->ReadData(&areaFlags, sizeof(unsigned short), 1, fileHandle);
			}
			else {
				this->ReadData(&areaFlags, sizeof(unsigned int), 1, fileHandle);
			}

			//META_CONPRINTF("Area Flags: %d\n", areaFlags);

			float x1, y1, z1, x2, y2, z2;
			this->ReadData(&x1, sizeof(float), 1, fileHandle);
			this->ReadData(&y1, sizeof(float), 1, fileHandle);
			this->ReadData(&z1, sizeof(float), 1, fileHandle);
			this->ReadData(&x2, sizeof(float), 1, fileHandle);
			this->ReadData(&y2, sizeof(float), 1, fileHandle);
			this->ReadData(&z2, sizeof(float), 1, fileHandle);

			//META_CONPRINTF("Area extent: (%f, %f, %f), (%f, %f, %f)\n", x1, y1, z1, x2, y2, z2);

			float northEastCornerZ, southWestCornerZ;
			this->ReadData(&northEastCornerZ, sizeof(float), 1, fileHandle);
			this->ReadData(&southWestCornerZ, sizeof(float), 1, fileHandle);

			//META_CONPRINTF("Corners: NW(%f), SW(%f)\n", northEastCornerZ, southWestCornerZ);

			// CheckWaterLevel() are we underwater in this area?
			
			IList<INavMeshConnection*> *connections = new List<INavMeshConnection*>();

			for(int direction = 0; direction < NAV_DIR_COUNT; direction++) {
				unsigned int connectionCount;
				this->ReadData(&connectionCount, sizeof(unsigned int), 1, fileHandle);

				//META_CONPRINTF("Connection count: %d (%p)\n", connectionCount, connectionCount);

				for(int connectionIndex = 0; connectionIndex < connectionCount; connectionIndex++) {
					unsigned int connectingAreaID;
					this->ReadData(&connectingAreaID, sizeof(unsigned int), 1, fileHandle);

					INavMeshConnection *connection = new NavMeshConnection(connectingAreaID, direction);
					connections->Append(connection);
				}
			}

			unsigned char hidingSpotCount;
			this->ReadData(&hidingSpotCount, sizeof(unsigned char), 1, fileHandle);
			//META_CONPRINTF("Hiding Spot Count: %d\n", hidingSpotCount);

			for(unsigned int hidingSpotIndex = 0; hidingSpotIndex < hidingSpotCount; hidingSpotIndex++) {
				unsigned int hidingSpotID;
				this->ReadData(&hidingSpotID, sizeof(unsigned int), 1, fileHandle);

				float hidingSpotX, hidingSpotY, hidingSpotZ;
				this->ReadData(&hidingSpotX, sizeof(float), 1, fileHandle);
				this->ReadData(&hidingSpotY, sizeof(float), 1, fileHandle);
				this->ReadData(&hidingSpotZ, sizeof(float), 1, fileHandle);

				unsigned char hidingSpotFlags;
				this->ReadData(&hidingSpotFlags, sizeof(unsigned char), 1, fileHandle);

				//META_CONPRINTF("Parsed hiding spot (%f, %f, %f) with ID [%p] and flags [%p]\n", hidingSpotX, hidingSpotY, hidingSpotZ, hidingSpotID, hidingSpotFlags);
			}

			// These are old but we just need to read the data.
			if(version < 15) {
				unsigned char approachAreaCount;
				this->ReadData(&approachAreaCount, sizeof(unsigned char), 1, fileHandle);

				for(unsigned int approachAreaIndex = 0; approachAreaIndex < approachAreaCount; approachAreaIndex++) {
					unsigned int approachHereID;
					this->ReadData(&approachHereID, sizeof(unsigned int), 1, fileHandle);
					
					unsigned int approachPrevID;
					this->ReadData(&approachPrevID, sizeof(unsigned int), 1, fileHandle);

					unsigned char approachType;
					this->ReadData(&approachType, sizeof(unsigned char), 1, fileHandle);

					unsigned int approachNextID;
					this->ReadData(&approachNextID, sizeof(unsigned int), 1, fileHandle);

					unsigned char approachHow;
					this->ReadData(&approachHow, sizeof(unsigned char), 1, fileHandle);
				}
			}

			unsigned int encounterPathCount;
			this->ReadData(&encounterPathCount, sizeof(unsigned int), 1, fileHandle);
			//META_CONPRINTF("Encounter Path Count: %d\n", encounterPathCount);

			for(unsigned int encounterPathIndex = 0; encounterPathIndex < encounterPathCount; encounterPathIndex++) {
				unsigned int encounterFromID;
				this->ReadData(&encounterFromID, sizeof(unsigned int), 1, fileHandle);

				unsigned char encounterFromDirection;
				this->ReadData(&encounterFromDirection, sizeof(unsigned char), 1, fileHandle);

				unsigned int encounterToID;
				this->ReadData(&encounterToID, sizeof(unsigned int), 1, fileHandle);

				unsigned char encounterToDirection;
				this->ReadData(&encounterToDirection, sizeof(unsigned char), 1, fileHandle);

				unsigned char encounterSpotCount;
				this->ReadData(&encounterSpotCount, sizeof(unsigned char), 1, fileHandle);
	
				//META_CONPRINTF("Encounter [from ID %d] [from dir %p] [to ID %d] [to dir %p] [spot count %d]\n", encounterFromID, encounterFromDirection, encounterToID, encounterToDirection, encounterSpotCount);

				for(int encounterSpotIndex = 0; encounterSpotIndex < encounterSpotCount; encounterSpotIndex++) {
					unsigned int encounterSpotOrderId;
					this->ReadData(&encounterSpotOrderId, sizeof(unsigned int), 1, fileHandle);

					unsigned char encounterSpotT;
					this->ReadData(&encounterSpotT, sizeof(unsigned char), 1, fileHandle);

					//META_CONPRINTF("Encounter spot [order id %d] and [T %p]\n", encounterSpotOrderId, encounterSpotT);
				}
			}

			unsigned short placeID;
			this->ReadData(&placeID, sizeof(unsigned short), 1, fileHandle);

			placeID--;
			//META_CONPRINTF("Place ID: %d\n", placeID);

			for(unsigned int ladderDirection = 0; ladderDirection < NAV_LADDER_DIR_COUNT; ladderDirection++) {
				unsigned int ladderConnectionCount;
				this->ReadData(&ladderConnectionCount, sizeof(unsigned int), 1, fileHandle);

				//META_CONPRINTF("Ladder Connection Count: %d\n", ladderConnectionCount);

				for(unsigned int ladderConnectionIndex = 0; ladderConnectionIndex < ladderConnectionCount; ladderConnectionIndex++) {
					unsigned int ladderConnectID;
					this->ReadData(&ladderConnectID, sizeof(unsigned int), 1, fileHandle);
					
					//META_CONPRINTF("Parsed ladder connect [ID %d]\n", ladderConnectID);
				}
			}

			for(unsigned int navTeamIndex = 0; navTeamIndex < 2; navTeamIndex++) {
				float earliestOccupyTime;
				this->ReadData(&earliestOccupyTime, sizeof(float), 1, fileHandle);

				//META_CONPRINTF("Earliest occupy time: %f\n", earliestOccupyTime);
			}

			if(version < 11) {
				continue;
			}

			for (int navCornerIndex = 0; navCornerIndex < NAV_CORNER_COUNT; navCornerIndex++) {
    			float navCornerLightIntensity;
				this->ReadData(&navCornerLightIntensity, sizeof(float), 1, fileHandle);
				//META_CONPRINTF("Light intensity: [%f] [idx %d]\n", navCornerLightIntensity, navCornerIndex);
		 	}

			if(version < 16) {
				continue;
			}
			
			unsigned int visibleAreaCount;
			this->ReadData(&visibleAreaCount, sizeof(unsigned int), 1, fileHandle);

			//META_CONPRINTF("Visible area count: %d\n", visibleAreaCount);

			for(unsigned int visibleAreaIndex = 0; visibleAreaIndex < visibleAreaCount; visibleAreaIndex++) {
				unsigned int visibleAreaID;
				this->ReadData(&visibleAreaID, sizeof(unsigned int), 1, fileHandle);

				unsigned char visibleAreaAttributes;
				this->ReadData(&visibleAreaAttributes, sizeof(unsigned char), 1, fileHandle);

				//META_CONPRINTF("Parsed visible area [%d] with attr [%p]\n", visibleAreaID, visibleAreaAttributes);
			}

			unsigned int inheritVisibilityFrom;
			this->ReadData(&inheritVisibilityFrom, sizeof(unsigned int), 1, fileHandle);

			//META_CONPRINTF("Inherit visibilty from: %d\n", inheritVisibilityFrom);

			unsigned char unk01;
			this->ReadData(&unk01, sizeof(unsigned char), 1, fileHandle);

			//META_CONPRINTF("Unk01: %d\n", unk01);
		}

		unsigned int ladderCount;
		this->ReadData(&ladderCount, sizeof(unsigned int), 1, fileHandle);
		
		META_CONPRINTF("Ladder count: %d\n", ladderCount);

		for(unsigned int ladderIndex = 0; ladderIndex < ladderCount; ladderIndex++) {
			unsigned int ladderID;
			this->ReadData(&ladderID, sizeof(unsigned int), 1, fileHandle);

			float ladderWidth;
			this->ReadData(&ladderWidth, sizeof(float), 1, fileHandle);
			
			float ladderTopX, ladderTopY, ladderTopZ, ladderBottomX, ladderBottomY, ladderBottomZ;

			this->ReadData(&ladderTopX, sizeof(float), 1, fileHandle);
			this->ReadData(&ladderTopY, sizeof(float), 1, fileHandle);
			this->ReadData(&ladderTopZ, sizeof(float), 1, fileHandle);
			this->ReadData(&ladderBottomX, sizeof(float), 1, fileHandle);
			this->ReadData(&ladderBottomY, sizeof(float), 1, fileHandle);
			this->ReadData(&ladderBottomZ, sizeof(float), 1, fileHandle);

			float ladderLength;
			this->ReadData(&ladderLength, sizeof(float), 1, fileHandle);
			
			unsigned int ladderDirection;
			this->ReadData(&ladderDirection, sizeof(unsigned int), 1, fileHandle);

			unsigned int ladderTopForwardAreaID;
			this->ReadData(&ladderTopForwardAreaID, sizeof(unsigned int), 1, fileHandle);

			unsigned int ladderTopLeftAreaID;
			this->ReadData(&ladderTopLeftAreaID, sizeof(unsigned int), 1, fileHandle);

			unsigned int ladderTopRightAreaID;
			this->ReadData(&ladderTopRightAreaID, sizeof(unsigned int), 1, fileHandle);
			
			unsigned int ladderTopBehindAreaID;
			this->ReadData(&ladderTopBehindAreaID, sizeof(unsigned int), 1, fileHandle);

			unsigned int ladderBottomAreaID;
			this->ReadData(&ladderBottomAreaID, sizeof(unsigned int), 1, fileHandle);
			
			INavMeshLadder *ladder = new NavMeshLadder(ladderID, ladderWidth, ladderLength, ladderTopX, ladderTopY, ladderTopZ,
				ladderBottomX, ladderBottomY, ladderBottomZ, (NavDirType)ladderDirection,
				ladderTopForwardAreaID, ladderTopLeftAreaID, ladderTopRightAreaID, ladderTopBehindAreaID, ladderBottomAreaID);


		}

		return NULL;
	}

	unsigned int NavMeshLoader::ReadData(void *output, unsigned int elementSize, unsigned int elementCount, FILE *fileHandle) {
		unsigned int count = fread(output, elementSize, elementCount, fileHandle);

		unsigned int byteCount = elementCount * elementSize;

		this->bytesRead += byteCount;

		return count;
	}
}