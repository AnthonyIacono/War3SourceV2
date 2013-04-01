#ifndef __war3source_globals_h__
#define __war3source_globals_h__

#include "Extension.h"
#include "ClientListener.h"
#include "IClient.h"
#include "List.h"
#include "INavMesh.h"

extern War3Source::Extension g_War3SourceExtension;
extern War3Source::ClientListener *g_ClientListener;
extern War3Source::IList<War3Source::IClient*> *g_ClientList;
extern SourceMod::IDBDriver *g_DBDriver;
extern SourceMod::IDatabase *g_Database;
extern War3Source::INavMesh *g_NavMesh;

#endif