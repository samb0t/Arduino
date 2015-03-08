#include <Arduino.h>
#include <ButtonState.h>


ButtonState::ButtonState(int buttonPin, char* writeOut) {
	_buttonPin = buttonPin;
	_writeOut = writeOut;
	pinMode(_buttonPin, INPUT_PULLUP);
	lastButtonState = LOW;
	lastDebounceTime = 0;
	debounceDelay = 50;
}

void ButtonState::PollButton() {
	int reading = digitalRead(_buttonPin);
	if (reading != lastButtonState) {
		lastDebounceTime = millis();
	}

	if((millis() - lastDebounceTime) > debounceDelay) {
		if(reading != buttonState) {
			buttonState = reading;
			if(buttonState == LOW) {
				//Send keyboard input here!!
				Keyboard.print("hiya");
				Serial.write(_writeOut);
			}
		}	
	}
	lastButtonState = reading;
}

