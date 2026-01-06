#include "pch.h"

namespace Initialize
{
	void CoD2()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD2", nullptr);
	}

	void CoD3()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD3", nullptr);
	}

	void CoD4()
	{
	    const char* addr1 = reinterpret_cast<const char*>(0x8206C5CC);
	    const char* addr2 = reinterpret_cast<const char*>(0x82032AC4);
	
	    if (addr1 && addr2 && !strcmp(addr1, "nightly Tue Aug 04 2009 01:51:14PM") && !strcmp(addr2, "multiplayer"))
	    {
	        if (XNotifyQueueUI)
				XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"[Nightly MP] Initializing CoD4...", nullptr);

			Detours::IW3::Nightly::CL_ConsolePrint_Detour		= Detour(Defs::IW3::Nightly::CL_ConsolePrint,		Hooks::IW3::Nightly::CL_ConsolePrint_Hook);
			Detours::IW3::Nightly::G_ModelIndex_Detour			= Detour(Defs::IW3::Nightly::G_ModelIndex,			Hooks::IW3::Nightly::G_ModelIndex_Hook);
			Detours::IW3::Nightly::SV_ClipMoveToEntity_Detour	= Detour(Defs::IW3::Nightly::SV_ClipMoveToEntity,	Hooks::IW3::Nightly::SV_ClipMoveToEntity_Hook);

			if (Detours::IW3::Nightly::CL_ConsolePrint_Detour.Install())
			{
				OutputDebugStringA("[CL_ConsolePrint_Detour] Detour installed successfully!\n");
			}

			if (Detours::IW3::Nightly::G_ModelIndex_Detour.Install())
			{
				OutputDebugStringA("[G_ModelIndex_Detour] Detour installed successfully!\n");
			}

			if (Detours::IW3::Nightly::SV_ClipMoveToEntity_Detour.Install())
			{
				OutputDebugStringA("[SV_ClipMoveToEntity_Detour] Detour installed successfully!\n");
			}
	    }
	}

	void CoD5()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD5", nullptr);
	}

	void CoD6()
	{
	    const char* addr1 = reinterpret_cast<const char*>(0x82023170);
	    const char* addr2 = reinterpret_cast<const char*>(0x82001270);
	
	    if (addr1 && addr2 && !strcmp(addr1, "1.4") && !strcmp(addr2, "multiplayer"))
	    {
	        if (XNotifyQueueUI)
				XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"[Retail MP] Initializing CoD6...", nullptr);
	    }
	}

	void CoD7()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD7", nullptr);
	}

	void CoD8()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD8", nullptr);
	}

	void CoD9()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD9", nullptr);
	}

	void CoD10()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD10", nullptr);
	}

	void CoD11()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"CoD11", nullptr);
	}

	void GTASA()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"GTA SA", nullptr);
	}

	void GTAIV()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"GTA IV", nullptr);
	}

	void GTAV()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"GTA V", nullptr);
	}

	void SR()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"SR", nullptr);
	}

	void SR2()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"SR2", nullptr);
	}

	void SR3()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"SR3", nullptr);
	}

	void SR4()
	{
		if(XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"SR4", nullptr);
	}
}
