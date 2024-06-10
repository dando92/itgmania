#ifndef LightsDriver_HidBlueDot_H
#define LightsDriver_HidBlueDot_H

#include "arch/Lights/LightsDriver.h"
#include "cPin.h"
#include "hidapi.h"

class LightsDriver_HidBlueDot : public LightsDriver
{
private:
	uint8_t m_iCabData[3];
	uint8_t m_iPadData[3];
	hid_device* handle;

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
public:
	LightsDriver_HidBlueDot();
virtual ~LightsDriver_HidBlueDot();

virtual void Set( const LightsState *ls );
};

#endif
