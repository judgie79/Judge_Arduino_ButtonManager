#ifndef __BUTTONMATRIX_H__
#define __BUTTONMATRIX_H__

#include <Arduino.h>
#include "Debouncer.h"
#include "FastDigitalPin.h"

typedef void(*ButtonMatrixChanged) (uint8_t, uint8_t);


struct ButtonIndex {
	ButtonIndex(uint8_t _rowIndex, uint8_t _colIndex) {
		rowIndex = _rowIndex;
		colIndex = _colIndex;
	}
	uint8_t rowIndex;
	uint8_t colIndex;
};

class ButtonMatrix {

protected:
	virtual void onStateChange(uint8_t, uint8_t);
	ButtonMatrixChanged buttonChangedCallback;
	FastDigitalPin _button;
	uint8_t _buttonState;
	uint8_t _lastPressedButton;
	unsigned long _buttonLastStateChanged;
	Debouncer _debouncer;


	uint8_t _rowCount;
	uint8_t _colCount;
	uint8_t * _colPins;
	uint8_t * _rowPins;   
private:
	uint8_t *BitMap;
	uint8_t *LastBitMap;
public:
	ButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row);
	ButtonMatrix(uint8_t cols, uint8_t rows, uint8_t * col, uint8_t * row, ButtonMatrixChanged changedCallback);
	virtual void begin();
	virtual void read();
	uint8_t numberOfButtons();
	bool pressDownStarted(uint8_t button);
	bool isPressed(uint8_t button);
	bool wasReleased(uint8_t button);
	bool pressDownStarted(uint8_t row, uint8_t column);
	bool isPressed(uint8_t row, uint8_t column);
	bool wasReleased(uint8_t row, uint8_t column);
	uint8_t *buttonsPressDownStarted();
	uint8_t *buttonsPressed();
	uint8_t *buttonsReleased();

	ButtonIndex getRowAndColumn(uint8_t button);
};


#endif