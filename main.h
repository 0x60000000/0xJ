#pragma once

#include <xtl.h>

#include <cstdint>
#include <string>

void *ResolveFunction(const std::string &moduleName, uint32_t ordinal);

typedef void (*XNOTIFYQUEUEUI)(uint32_t type, uint32_t userIndex, uint64_t areas, const wchar_t *displayText, void *pContextData);
extern XNOTIFYQUEUEUI XNotifyQueueUI;

// Enum for game title IDs
typedef enum _TitleId
{
	/* Dash */
    Title_Dashboard = 0xFFFE07D1,

	/* Call of Duty */
    Title_CoD2		= 0x415607D1, // Call of Duty 2
    Title_CoD3		= 0x415607E1, // Call of Duty 3
    Title_CoD4		= 0x415607E6, // Call of Duty 4:	Modern Warfare
    Title_CoD5		= 0x4156081C, // Call of Duty:		World at War
    Title_CoD6		= 0x41560817, // Call of Duty:		Modern Warfare 2
    Title_CoD7		= 0x41560855, // Call of Duty:		Black Ops
    Title_CoD8		= 0x415608CB, // Call of Duty:		Modern Warfare 3
    Title_CoD9		= 0x415608C3, // Call of Duty:		Black Ops II
    Title_CoD10		= 0x415608FC, // Call of Duty:		Ghosts
    Title_CoD11		= 0x41560914, // Call of Duty:		Advanced Warfare

	/* Grand Theft Auto */
    Title_GTASA		= 0x545408B8, // Grand Theft Auto:	San Andreas
    Title_GTAIV		= 0x545407F2, // Grand Theft Auto	IV
    Title_GTAV		= 0x545408A7, // Grand Theft Auto	V

	/* Saints Row */
    Title_SR		= 0x545107D1, // Saints Row
    Title_SR2		= 0x545107FC, // Saints Row		2
    Title_SR3		= 0x5451086D, // Saints Row:	The Third
	Title_SR4		= 0x4B4D07F6, // Saints Row		IV
} TitleId;

// Imports from the Xbox libraries
extern "C"
{
    uint32_t XamGetCurrentTitleId();

    uint32_t ExCreateThread(
        HANDLE *pHandle,
        uint32_t stackSize,
        uint32_t *pThreadId,
        void *pApiThreadStartup,
        PTHREAD_START_ROUTINE pStartAddress,
        void *pParameter,
        uint32_t creationFlags
    );
}

extern bool g_Running;

extern HANDLE g_ThreadHandle;

extern uint16_t defaultInstruction;
extern uintptr_t patchAddress;
