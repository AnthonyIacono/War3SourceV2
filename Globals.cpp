#include "Globals.h"

using namespace War3Source;

Extension g_War3SourceExtension;
ClientListener *g_ClientListener = NULL;
SourceMod::IDBDriver *g_DBDriver = NULL;
SourceMod::IDatabase *g_Database = NULL;
List<War3Source::IClient*> g_ClientList;