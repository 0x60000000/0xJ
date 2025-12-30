#pragma once

// Xbox 360 SDK
#include <xtl.h>

// C++ standard library
#include <cstdint>
#include <string>

// Defining XNotifyQueueUI
typedef void (*XNOTIFYQUEUEUI)(uint32_t type, uint32_t userIndex, uint64_t areas, const wchar_t *displayText, void *pContextData);
extern XNOTIFYQUEUEUI XNotifyQueueUI;

// Title ID's
enum TitleId : uint32_t
{
    Title_Dashboard = 0xFFFE07D1,
    Title_IW3       = 0x415607E6,
	  Title_IW4		    = 0x41560817,
};

// Imports
extern "C"
{
    uint32_t XamGetCurrentTitleId();

    uint32_t ExCreateThread(
        HANDLE* pHandle,
        uint32_t stackSize,
        uint32_t* pThreadId,
        void* pApiThreadStartup,
        PTHREAD_START_ROUTINE pStartAddress,
        void* pParameter,
        uint32_t creationFlags
    );
}
