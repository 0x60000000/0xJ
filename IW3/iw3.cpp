/*Precompiled Header File*/
#include "pch.h"

namespace IW3
{
	namespace Nightly
	{
		namespace Types
		{
			//
		}

		namespace Defs
		{
			CHEATSOK CheatsOk = 
				reinterpret_cast<CHEATSOK>(0x8227BF40);

			CLIENTCOMMAND ClientCommand = 
				reinterpret_cast<CLIENTCOMMAND>(0x8227DCF0);

			CL_CONSOLEPRINT CL_ConsolePrint = 
				reinterpret_cast<CL_CONSOLEPRINT>(0x822E4D18);

			I_STRNICMP I_strnicmp = 
				reinterpret_cast<I_STRNICMP>(0x821CDA98);

			SV_CMD_ARGVBUFFER SV_Cmd_ArgvBuffer = 
				reinterpret_cast<SV_CMD_ARGVBUFFER>(0x82239F48);

			SV_GAMESENDSERVERCOMMAND SV_GameSendServerCommand = 
				reinterpret_cast<SV_GAMESENDSERVERCOMMAND>(0x82204BB8);

			SV_SENDSERVERCOMMAND SV_SendServerCommand = 
				reinterpret_cast<SV_SENDSERVERCOMMAND>(0x821FFE30);

			VA va = 
				reinterpret_cast<VA>(0x821CD858);
		}

		namespace Detours
		{
			Detour ClientCommand_Detour;
			Detour CL_ConsolePrint_Detour;
		}

		namespace Hooks
		{
			Types::gentity_s* g_entities = reinterpret_cast<Types::gentity_s *>(0x8287CD08);

			void __fastcall Cmd_UFO_f(Types::gentity_s *ent)
			{
			  Types::gclient_s *client; // r10
			  int ufo; // r11
			  const char *ufoStr; // r5
			  const char *cmd; // r3
			  int entt; // r11
			
			  if ( Defs::CheatsOk(ent) )
			  {
			    client = ent->client;
			    ufo = client->ufo;
			    if ( ufo )
			      ufoStr = "GAME_UFOOFF";
			    else
			      ufoStr = "GAME_UFOON";
			    client->ufo = ufo == 0;
			    cmd = Defs::va("%c \"%s\"", 101, ufoStr);
			    entt = ent - g_entities;
			    if ( entt == -1 )
			      Defs::SV_SendServerCommand(0, Types::SV_CMD_CAN_IGNORE, "%s", cmd);
			    else
			      Defs::SV_GameSendServerCommand(entt, Types::SV_CMD_CAN_IGNORE, cmd);
			  }
			}

			void __fastcall ClientCommand_Hook(int clientNum)
			{
				Types::gentity_s *v2 = &g_entities[clientNum];
				char v23[1032];
				int v12 = 3;

				Detours::ClientCommand_Detour
					.GetOriginal<decltype(Defs::ClientCommand)>()(clientNum);
				
				if ( v2->client )
				{
					Defs::SV_Cmd_ArgvBuffer(0, v23, 1024);
					/*
					if ( !Defs::I_strnicmp(v23, "noclip", 5) )
						Cmd_Noclip_f(v2);
						*/
					if ( !Defs::I_strnicmp(v23, "ufo", v12) )
						Cmd_UFO_f(v2);
				}
			}

			void __fastcall CL_ConsolePrint_Hook(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags)
			{
				Detours::CL_ConsolePrint_Detour
					.GetOriginal<decltype(Defs::CL_ConsolePrint)>()(localClientNum, channel, txt, duration, pixelWidth, flags);

				OutputDebugStringA( txt );
				OutputDebugStringA( "\n" );
			}
		}
	}

	/* First, check build. Then, check MP or SP. */
	void Initialize()
	{
		/* If Retail Build, Tu4, and MP. */
		if (!strcmp(reinterpret_cast<char *>(0x8206C5CC), "nightly Tue Aug 04 2009 01:51:14PM"))
			if (!strcmp(reinterpret_cast<char *>(0x82032AC4), "multiplayer"))
				OutputDebugStringA("[Nightly-MP] Initializing IW3...\n");

		if (XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"[Nightly-MP] Initializing IW3...", nullptr);

		Nightly::Detours::ClientCommand_Detour = Detour(Nightly::Defs::ClientCommand, Nightly::Hooks::ClientCommand_Hook);
		Nightly::Detours::CL_ConsolePrint_Detour = Detour(Nightly::Defs::CL_ConsolePrint, Nightly::Hooks::CL_ConsolePrint_Hook);

		if (Nightly::Detours::ClientCommand_Detour.Install())
		{
			OutputDebugStringA("[Nightly::Detours::ClientCommand_Detour ]	Detour installed!\n");
		}

		if (Nightly::Detours::CL_ConsolePrint_Detour.Install())
		{
			OutputDebugStringA("[Nightly::Detours::CL_ConsolePrint_Detour]	Detour installed!\n");
		}
	}
}
