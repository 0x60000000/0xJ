#pragma once

#include "types.h"

namespace Defs
{
	namespace IW3
	{
		namespace Nightly
		{
			typedef void	(__fastcall *CL_CONSOLEPRINT)(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags);
			extern CL_CONSOLEPRINT CL_ConsolePrint;

			typedef int		(__fastcall *G_MODELINDEX)(const char *name);
			extern G_MODELINDEX G_ModelIndex;

			typedef void	(__fastcall *SV_CLIPMOVETOENTITY)(const Types::IW3::Nightly::moveclip_t *clip, Types::IW3::Nightly::svEntity_s *check, Types::IW3::Nightly::trace_t *trace);
			extern SV_CLIPMOVETOENTITY SV_ClipMoveToEntity;
		}
	}
}
