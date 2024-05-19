#include "global.h"
#include "LightsDriver_Win32ParallelBase.h"
#include "windows.h"
#include "RageUtil.h"

HINSTANCE hDLL = nullptr;

typedef void (WINAPI PORTOUT)(short int Port, char Data);
PORTOUT* PortOut = nullptr;
typedef short int (WINAPI ISDRIVERINSTALLED)();
ISDRIVERINSTALLED* IsDriverInstalled = nullptr;

short LPT_ADDRESS[MAX_PARALLEL_PORTS] = 
{
	0x378,	// LPT1
	0x278,	// LPT2
	0x3bc,	// LPT3
};

LightsDriver_Win32ParallelBase::LightsDriver_Win32ParallelBase()
{
	// init io.dll
	hDLL = LoadLibrary("parallel_lights_io.dll");
	if(hDLL == nullptr)
	{
		auto err = GetLastError();
		MessageBox(nullptr, "Could not LoadLibrary( parallel_lights_io.dll ).", "ERROR", MB_OK );
		return;
	}

	//Get the function pointers
	PortOut = (PORTOUT*) GetProcAddress(hDLL, "PortOut");
	IsDriverInstalled = (ISDRIVERINSTALLED*) GetProcAddress(hDLL, "IsDriverInstalled");
}

LightsDriver_Win32ParallelBase::~LightsDriver_Win32ParallelBase()
{
	FreeLibrary( hDLL );
}

void LightsDriver_Win32ParallelBase::Write(const int index, const char data)
{
	ASSERT(index < MAX_PARALLEL_PORTS);
	PortOut(LPT_ADDRESS[index], data);
}

/*
 * (c) 2003-2004 Chris Danford
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
