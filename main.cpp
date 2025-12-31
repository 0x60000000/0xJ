/*Precompiled Header File*/
#include "pch.h"

// Resolving a function by ordinal
void *ResolveFunction(const std::string &moduleName, uint32_t ordinal)
{
    HMODULE moduleHandle = GetModuleHandle(moduleName.c_str());
    if (moduleHandle == nullptr)
        return nullptr;

    return GetProcAddress(moduleHandle, reinterpret_cast<const char *>(ordinal));
}

// Resolving XNotifyQueueUI from xam.xex
XNOTIFYQUEUEUI XNotifyQueueUI = static_cast<XNOTIFYQUEUEUI>(ResolveFunction("xam.xex", 656));

// Worker Thread
static volatile bool g_Running = true;
static HANDLE g_ThreadHandle = nullptr;

// Monitor Title ID
DWORD WINAPI MonitorTitleThread(void*)
{
    uint32_t lastTitleId = 0;

    while (g_Running)
    {
        uint32_t current = XamGetCurrentTitleId();

        if (current != lastTitleId && XNotifyQueueUI)
        {
            lastTitleId = current;

            switch (current)
			{
            case Title_Dashboard:
				if (XNotifyQueueUI)
					XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"Dashboard", nullptr);
				break;

            case Title_IW3:
				IW3::Initialize();
                break;

			case Title_IW4:
				IW4::Initialize();
				break;
			}
		}

        Sleep(250);
	}

    return 0;
}

// DLLMain
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ExCreateThread(
            &g_ThreadHandle,
            0,
            nullptr,
            nullptr,
            MonitorTitleThread,
            nullptr,
            2
        );
        break;

    case DLL_PROCESS_DETACH:
        g_Running = false;

        if (g_ThreadHandle)
        {
            WaitForSingleObject(g_ThreadHandle, INFINITE);
            CloseHandle(g_ThreadHandle);
        }
        break;
    }

    return TRUE;
}