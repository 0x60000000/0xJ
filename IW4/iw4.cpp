/*Precompiled Header File*/
#include "pch.h"

namespace IW4
{
	void Initialize()
	{
		if (XNotifyQueueUI)
			XNotifyQueueUI(0, 0, XNOTIFY_SYSTEM, L"IW4", nullptr);
	}
}
