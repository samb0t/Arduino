#ifndef ButtonState_h
#define ButtonState_h

#include "Arduino.h"

class ButtonState {
	public: 
		ButtonState(int buttonPin, char* writeOut);
		void PollButton();
	private:
		int _buttonPin;
		char* _writeOut;
		int buttonState;
		int lastButtonState;
		long lastDebounceTime;
		long debounceDelay;
};

#endif
