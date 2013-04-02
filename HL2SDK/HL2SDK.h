#ifndef __war3source_hl2sdk_h__
#define __war3source_hl2sdk_h__

#ifdef CLIENT_DLL
#undef CLIENT_DLL
#endif // CLIENT_DLL

#ifndef GAME_DLL
#define GAME_DLL 1
#endif // !GAME_DLL

#include <vstdlib/random.h>
#include <igameevents.h>
#include <engine/IEngineSound.h>
#include <filesystem.h>
#include <icvar.h>
#include <edict.h>
#include <iserver.h>
#include <game/shared/shareddefs.h>

#if SOURCE_ENGINE >= SE_ORANGEBOX
#include <toolframework/itoolentity.h>
#endif

#include <engine\IEngineTrace.h>
#include <ivoiceserver.h>

class CBasePlayer;

#endif