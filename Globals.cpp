#include "Globals.h"

using namespace War3Source;

Extension g_War3SourceExtension;
ClientListener *g_ClientListener = NULL;
SourceMod::IDBDriver *g_DBDriver = NULL;
SourceMod::IDatabase *g_Database = NULL;
IList<War3Source::IClient*> *g_ClientList = NULL;
War3Source::INavMesh *g_NavMesh = NULL;
IServerGameClients *g_ServerGameClients = NULL;
ICvar *g_CVar = NULL;
ICvar *icvar = NULL;
CGlobalVars *g_Globals = NULL;
CGlobalVars *gpGlobals = NULL;
IClientCommandListener *g_ClientCommandListener = NULL;
ISayCommandListener *g_SayCommandListener = NULL;