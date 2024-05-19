/* LightsDriver_Win32ParallelNonno - Control lights with Kit Faith:
 *	http://www.google.com/search?hl=en&lr=&ie=UTF-8&oe=UTF-8&q=kit+74+relay */

#ifndef LightsDriver_Win32ParallelNonno_H
#define LightsDriver_Win32ParallelNonno_H

#include "arch/Lights/LightsDriver_Win32ParallelBase.h"
#include "cPin.h"

class LightsDriver_Win32ParallelNonno : public LightsDriver_Win32ParallelBase
{
private:
	unsigned char m_PortCabinet;
	unsigned char m_PortPad;
	unsigned char m_PortClock;

	cPin m_PadP1_Left;
	cPin m_PadP1_Right;
	cPin m_PadP1_Up;
	cPin m_PadP1_Down;
	cPin m_PadP2_Left;
	cPin m_PadP2_Right;
	cPin m_PadP2_Up;
	cPin m_PadP2_Down;

	cPin m_Marquee_UpLeft;
	cPin m_Marquee_UpRight;
	cPin m_Marquee_LwLeft;
	cPin m_Marquee_LwRight;
	cPin m_Buttons_Left;
	cPin m_Buttons_Right;
	cPin m_Bass;
	cPin m_Optional;

	cPin m_PinClockPad;
	cPin m_PinClockCabinet;

public:
	LightsDriver_Win32ParallelNonno();
	~LightsDriver_Win32ParallelNonno() override = default;

	void Set( const LightsState *ls ) override;
};

#endif

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
