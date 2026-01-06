#include "pch.h"

namespace Hooks
{
	namespace IW3
	{
		namespace Nightly
		{
			void __fastcall CL_ConsolePrint_Hook(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags)
			{
				OutputDebugStringA(txt);
				OutputDebugStringA("\n");

				Detours::IW3::Nightly::CL_ConsolePrint_Detour.GetOriginal<decltype(Defs::IW3::Nightly::CL_ConsolePrint)>()(localClientNum, channel, txt, duration, pixelWidth, flags);
			}

			int __fastcall G_ModelIndex_Hook(const char *name)
			{
				OutputDebugStringA(name);
				OutputDebugStringA("\n");

				return Detours::IW3::Nightly::G_ModelIndex_Detour.GetOriginal<decltype(Defs::IW3::Nightly::G_ModelIndex)>()(name);
			}

			void __fastcall SV_ClipMoveToEntity_Hook(const Types::IW3::Nightly::moveclip_t *clip, Types::IW3::Nightly::svEntity_s *check, Types::IW3::Nightly::trace_t *trace)
			{
				if (clip && clip->passEntityNum)
					return;

				Detours::IW3::Nightly::SV_ClipMoveToEntity_Detour.GetOriginal<decltype(Defs::IW3::Nightly::SV_ClipMoveToEntity)>()(clip, check, trace);
			}
		}
	}
}
