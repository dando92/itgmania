#ifndef cPin_H
#define cPin_H

class cPin
{
private:
	unsigned char* mask;
	unsigned char  pinIndex;

public:
	cPin(unsigned char* portValue, unsigned char pin) : mask(portValue), pinIndex(pin) {};

	void Set(bool value)
	{
		if (value != false) *mask = *mask | pinIndex;
		else
			if (value == false) *mask = *mask & ~pinIndex;
	};

	void Swap()
	{
		bool value = (*mask & pinIndex) ? false : true;
		Set(value);
	};
};

#endif
