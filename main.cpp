#include "pch.h"

/* https://github.com/ClementDreptin/ */

// Get the address of a function from a module by its ordinal
void *ResolveFunction(const std::string &moduleName, uint32_t ordinal)
{
    HMODULE moduleHandle = GetModuleHandle(moduleName.c_str());
    if (moduleHandle == nullptr)
        return nullptr;

    return GetProcAddress(moduleHandle, reinterpret_cast<const char *>(ordinal));
}

// Create a pointer to XNotifyQueueUI in xam.xex
XNOTIFYQUEUEUI XNotifyQueueUI = static_cast<XNOTIFYQUEUEUI>(ResolveFunction("xam.xex", 656));

bool g_Running = true;

// Infinitely check the current game running
uint32_t MonitorTitleId(void *pThreadParameter)
{
    uint32_t currentTitleId = 0;

    while (g_Running)
    {
        uint32_t newTitleId = XamGetCurrentTitleId();

        if (newTitleId == currentTitleId)
            continue;

        currentTitleId = newTitleId;

        switch (newTitleId)
        {
        case Title_Dashboard:
			if(XNotifyQueueUI)
				XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"0xJ v0.3\n<3", nullptr);
            break;
		case Title_CoD2:
			Initialize::CoD2();
            break;
		case Title_CoD3:
			Initialize::CoD3();
            break;
		case Title_CoD4:
			Initialize::CoD4();
            break;
        case Title_CoD5:
			Initialize::CoD5();
            break;
		case Title_CoD6:
			Initialize::CoD6();
            break;
		case Title_CoD7:
			Initialize::CoD7();
            break;
		case Title_CoD8:
			Initialize::CoD8();
            break;
		case Title_CoD9:
			Initialize::CoD9();
            break;
		case Title_CoD10:
			Initialize::CoD10();
            break;
		case Title_CoD11:
			Initialize::CoD11();
            break;
		case Title_GTASA:
			Initialize::GTASA();
            break;
		case Title_GTAIV:
			Initialize::GTAIV();
            break;
		case Title_GTAV:
			Initialize::GTAV();
            break;
		case Title_SR:
			Initialize::SR();
            break;
		case Title_SR2:
			Initialize::SR2();
            break;
		case Title_SR3:
			Initialize::SR3();
            break;
		case Title_SR4:
			Initialize::SR4();
            break;
        }

		Sleep(250);
    }

    return 0;
}

HANDLE g_ThreadHandle = INVALID_HANDLE_VALUE;

// State variables for enabling notifications in system threads
static uint16_t defaultInstruction = 0;
static uintptr_t patchAddress = 0x816A3158;

BOOL DllMain(HINSTANCE hModule, DWORD reason, void *pReserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        // Allow notifications to be displayed from system threads
        if (defaultInstruction == 0)
            defaultInstruction = *reinterpret_cast<uint16_t *>(patchAddress);
        *reinterpret_cast<uint16_t *>(patchAddress) = 0x4800;

        // Run MonitorTitleId in separate thread
        ExCreateThread(&g_ThreadHandle, 0, nullptr, nullptr, reinterpret_cast<PTHREAD_START_ROUTINE>(MonitorTitleId), nullptr, 2);
        break;
    case DLL_PROCESS_DETACH:
        // Remove patch for system thread notifications
        if (defaultInstruction != 0)
            *reinterpret_cast<uint16_t *>(patchAddress) = defaultInstruction;

        g_Running = false;
        // Wait for the run thread to finish
        WaitForSingleObject(g_ThreadHandle, INFINITE);
        CloseHandle(g_ThreadHandle);
        break;
    }

    return TRUE;
}
