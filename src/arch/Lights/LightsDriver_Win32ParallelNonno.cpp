#include "global.h"
#include "LightsDriver_Win32ParallelNonno.h"
#include "windows.h"
#include "RageUtil.h"

REGISTER_LIGHTS_DRIVER_CLASS(Win32ParallelNonno);
//! Define LPT port used.
#define LPT_PORT_USED 0

LightsDriver_Win32ParallelNonno::LightsDriver_Win32ParallelNonno()
	:
	LightsDriver_Win32ParallelBase(),
	m_PortCabinet(0),
	m_PortPad(0),
	m_PortClock(0),
	m_PadP1_Up(&m_PortPad, 0x01),
	m_PadP1_Down(&m_PortPad, 0x02),
	m_PadP1_Left(&m_PortPad, 0x04),
	m_PadP1_Right(&m_PortPad, 0x08),
	m_PadP2_Up(&m_PortPad, 0x10),
	m_PadP2_Down(&m_PortPad, 0x20),
	m_PadP2_Left(&m_PortPad, 0x40),
	m_PadP2_Right(&m_PortPad, 0x80),

	m_Marquee_UpLeft(&m_PortCabinet, 0x10),
	m_Marquee_UpRight(&m_PortCabinet, 0x08),
	m_Marquee_LwLeft(&m_PortCabinet, 0x20),
	m_Marquee_LwRight(&m_PortCabinet, 0x80),
	m_Buttons_Left(&m_PortCabinet, 0x40),
	m_Buttons_Right(&m_PortCabinet, 0x04),
	m_Bass(&m_PortCabinet, 0x02),
	m_Optional(&m_PortCabinet, 0x01),

	m_PinClockCabinet(&m_PortClock, 0x01),
	m_PinClockPad(&m_PortClock, 0x02)
{

}

void LightsDriver_Win32ParallelNonno::Set( const LightsState *ls )
{
	//! Set lights.
	m_Marquee_UpLeft.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_UP_LEFT]);
	m_Marquee_UpRight.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_UP_RIGHT]);
	m_Marquee_LwLeft.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_LR_LEFT]);
	m_Marquee_LwRight.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_LR_RIGHT]);
	m_Buttons_Left.Set(ls->m_bCabinetLights[LIGHTSMODE_MENU_START_AND_DIRECTIONS]);
	m_Buttons_Right.Set(ls->m_bCabinetLights[LIGHTSMODE_MENU_START_AND_DIRECTIONS]);
	m_Bass.Set(ls->m_bCabinetLights[LIGHT_BASS_LEFT] || ls->m_bCabinetLights[LIGHT_BASS_RIGHT]);

	m_PinClockCabinet.Swap();

	//! Put out cabinet lights.
	Write(LPT_PORT_USED, m_PortCabinet);
	Write(LPT_PORT_USED + 2, m_PortClock);


	//! Set lights.
	m_PadP1_Left.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_LEFT]);
	m_PadP1_Right.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_RIGHT]);
	m_PadP1_Up.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_UP]);
	m_PadP1_Down.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_DOWN]);
	m_PadP2_Left.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_LEFT]);
	m_PadP2_Right.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_RIGHT]);
	m_PadP2_Up.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_UP]);
	m_PadP2_Down.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_DOWN]);
	m_PinClockPad.Swap();

	//! Put out pad lights.
	Write(LPT_PORT_USED, m_PortPad);
	Write(LPT_PORT_USED + 2, m_PortClock);
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
