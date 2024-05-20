#include "global.h"
#include "LightsDriver_HidBlueDot.h"

#define VID 0x04d8
#define PID 0x0C

REGISTER_LIGHTS_DRIVER_CLASS(HidBlueDot);

LightsDriver_HidBlueDot::LightsDriver_HidBlueDot()
	:
	m_Marquee_UpLeft(&m_iCabData[1], 0x01),
	m_Marquee_UpRight(&m_iCabData[1], 0x02),
	m_Marquee_LwLeft(&m_iCabData[1], 0x04),
	m_Marquee_LwRight(&m_iCabData[1], 0x08),
	m_Buttons_Left(&m_iCabData[1], 0x10),
	m_Buttons_Right(&m_iCabData[1], 0x20),
	m_Bass(&m_iCabData[1], 0x40),
	m_Optional(&m_iCabData[1], 0x80),

	m_PadP2_Up(&m_iPadData[1], 0x01),
	m_PadP2_Down(&m_iPadData[1], 0x02),
	m_PadP2_Left(&m_iPadData[1], 0x04),
	m_PadP2_Right(&m_iPadData[1], 0x08),
	m_PadP1_Up(&m_iPadData[1], 0x10),
	m_PadP1_Down(&m_iPadData[1], 0x20),
	m_PadP1_Left(&m_iPadData[1], 0x40),
	m_PadP1_Right(&m_iPadData[1], 0x80)
{
	m_iCabData[0] = 0x01;
	m_iPadData[0] = 0x02;
	
	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(VID, PID, NULL);
	
	if (!handle) {
		hid_exit();
		return;
	}
}

LightsDriver_HidBlueDot::~LightsDriver_HidBlueDot()
{
	// Close the device
	hid_close(handle);

	// Finalize the hidapi library
	hid_exit();
}

void LightsDriver_HidBlueDot::Set(const LightsState *ls)
{
	if (!handle)
		return;

	//! Set cabinet lights.
	m_Marquee_UpLeft.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_UP_LEFT]);
	m_Marquee_UpRight.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_UP_RIGHT]);
	m_Marquee_LwLeft.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_LR_LEFT]);
	m_Marquee_LwRight.Set(ls->m_bCabinetLights[LIGHT_MARQUEE_LR_RIGHT]);
	m_Buttons_Left.Set(ls->m_bGameButtonLights[PLAYER_1][GAME_BUTTON_START]);
	m_Buttons_Right.Set(ls->m_bGameButtonLights[PLAYER_2][GAME_BUTTON_START]);
	m_Bass.Set(ls->m_bCabinetLights[LIGHT_BASS_LEFT] || ls->m_bCabinetLights[LIGHT_BASS_RIGHT]);
	
	hid_write(handle, (unsigned char *)&m_iCabData, 2);

	//! Set pad lights.
	m_PadP1_Left.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_LEFT]);
	m_PadP1_Right.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_RIGHT]);
	m_PadP1_Up.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_UP]);
	m_PadP1_Down.Set(ls->m_bGameButtonLights[PLAYER_1][DANCE_BUTTON_DOWN]);
	m_PadP2_Left.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_LEFT]);
	m_PadP2_Right.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_RIGHT]);
	m_PadP2_Up.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_UP]);
	m_PadP2_Down.Set(ls->m_bGameButtonLights[PLAYER_2][DANCE_BUTTON_DOWN]);

	hid_write(handle, (unsigned char *)&m_iPadData, 2);
}
