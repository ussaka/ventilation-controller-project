/*
 * LcdUi.h
 *
 *  Created on: 5 Oct 2022
 *      Author: kkivi
 */

#ifndef LCDUI_H_
#define LCDUI_H_

#include "DigitalIoPin.h"
#include "LiquidCrystal.h"
#include "NumericProperty.h"
#include "Menu.h"

#include <functional>

class LcdUi {
public:
	LcdUi(NumericProperty <int>& mode, NumericProperty <int>& speed, NumericProperty <int>& pressure, NumericProperty <int>& setpoint);
	virtual ~LcdUi();
	void read_btns();
	void update(int _temp, int _co2, int _rh);
	void btnStatusUpdate(void);

	std::function <void(Property& property)> onValueChange;

private:
	NumericProperty <int>& mode;
	NumericProperty <int>& speed;
	NumericProperty <int>& pressure;
	NumericProperty <int>& setpoint;

	struct button {
		button(int port, int pin) : btn(port, pin, DigitalIoPin::pullup, true)
		{
		}

		DigitalIoPin btn;
		bool isPressed = false;
	};

	// Buttons
	button buttons[4];

	// Lcd display pins
	DigitalIoPin rs;
	DigitalIoPin en;
	DigitalIoPin d4;
	DigitalIoPin d5;
	DigitalIoPin d6;
	DigitalIoPin d7;

	LiquidCrystal lcd;

	Menu menu;

	NumericProperty<int> temp;
	NumericProperty<int> co2;
	NumericProperty<int> rh;
};

#endif /* LCDUI_H_ */
