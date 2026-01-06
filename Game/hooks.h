#pragma once

namespace Hooks
{
	namespace IW3
	{
		namespace Nightly
		{
			void __fastcall CL_ConsolePrint_Hook(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags);
			int __fastcall G_ModelIndex_Hook(const char *name);
			void __fastcall SV_ClipMoveToEntity_Hook(const Types::IW3::Nightly::moveclip_t *clip, Types::IW3::Nightly::svEntity_s *check, Types::IW3::Nightly::trace_t *trace);
		}
	}
}
