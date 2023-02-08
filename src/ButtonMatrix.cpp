#include "ButtonMatrix.h"
const uint8_t MAX_ROWS = 8;
const uint8_t MAX_COLS = 8;

void ButtonMatrix::onStateChange(uint8_t button, uint8_t pressed)
{
	if (buttonChangedCallback != NULL)
	{
		buttonChangedCallback(button, pressed);
	}
}

void ButtonMatrix::begin(uint8_t cols, uint8_t rows, uint8_t *col, uint8_t *row, ButtonMatrixChanged changedcallback)
{
	if (cols > MAX_COLS || rows > MAX_ROWS)
	{
		return;
	}

	_debouncer.begin(10);
	_rowCount = rows;
	_colCount = cols;
	_colPins = col;
	_rowPins = row;

	BitMap = new uint8_t[rows];
	LastBitMap = new uint8_t[rows];

	for (size_t x = 0; x < _rowCount; x++)
	{
		pinMode(_rowPins[x], INPUT);
		BitMap[x] = B00000000;
		LastBitMap[x] = B00000000;
	}

	for (size_t x = 0; x < _colCount; x++)
	{
		pinMode(_colPins[x], INPUT_PULLUP);
	}

	buttonChangedCallback = changedcallback;
}

void ButtonMatrix::read()
{
	// iterate the columns
	for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
	{
		// col: set to output to low
		uint8_t curCol = _colPins[colIndex];
		pinMode(curCol, OUTPUT);
		digitalWrite(curCol, LOW);

		// row: uint8_terate through the rows
		for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
		{
			uint8_t rowCol = _rowPins[rowIndex];
			pinMode(rowCol, INPUT_PULLUP);

			uint8_t value = digitalRead(rowCol);
			value = value == 1 ? 0 : 1;
			uint8_t lastValue = (LastBitMap[rowIndex] >> colIndex) & 1;

			if (lastValue != value)
			{
				if (value == 0)
				{
					BitMap[rowIndex] &= ~(1 << colIndex);
				}
				else
				{
					BitMap[rowIndex] |= (1 << colIndex);
				}
				onStateChange((rowIndex * _colCount) + colIndex, value);
			}

			if (value == 0)
			{
				LastBitMap[rowIndex] &= ~(1 << colIndex);
			}
			else
			{
				LastBitMap[rowIndex] |= (1 << colIndex);
			}

			pinMode(rowCol, INPUT);
		}
		// disable the column
		pinMode(curCol, INPUT);
	}

	return;
}

void ButtonMatrix::print()
{
	String output = "";
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		uint8_t row = BitMap[rowIndex];

		String templ = String(rowIndex) + ":";
		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{

			uint8_t isOn = (row >> colIndex) & 1;
			templ += String(isOn);
		}
		templ += ",";

		output += templ;
	}
}

ButtonIndex ButtonMatrix::getRowAndColumn(uint8_t button)
{
	uint8_t rowIndex = (uint8_t)button / _rowCount;
	uint8_t colIndex = button % _rowCount;
	return ButtonIndex(rowIndex, colIndex);
}

bool ButtonMatrix::pressDownStarted(uint8_t button)
{
	ButtonIndex bIndex = getRowAndColumn(button);
	return pressDownStarted(bIndex.rowIndex, bIndex.colIndex);
}

bool ButtonMatrix::pressDownStarted(uint8_t rowIndex, uint8_t colIndex)
{
	uint8_t row = BitMap[rowIndex];
	uint8_t isOn = (row >> colIndex) & 1;

	uint8_t lastRow = LastBitMap[rowIndex];
	uint8_t wasOn = (lastRow >> colIndex) & 1;

	return isOn == 1 && wasOn == 0;
}

bool ButtonMatrix::isPressed(uint8_t button)
{
	ButtonIndex bIndex = getRowAndColumn(button);
	return isPressed(bIndex.rowIndex, bIndex.colIndex);
}

bool ButtonMatrix::isPressed(uint8_t rowIndex, uint8_t colIndex)
{
	uint8_t row = BitMap[rowIndex];
	uint8_t isOn = (row >> colIndex) & 1;

	uint8_t lastRow = LastBitMap[rowIndex];
	uint8_t wasOn = (lastRow >> colIndex) & 1;

	return isOn == 1 && wasOn == 1;
}

bool ButtonMatrix::wasReleased(uint8_t button)
{
	ButtonIndex bIndex = getRowAndColumn(button);
	return wasReleased(bIndex.rowIndex, bIndex.colIndex);
}

bool ButtonMatrix::wasReleased(uint8_t rowIndex, uint8_t colIndex)
{
	uint8_t row = BitMap[rowIndex];
	uint8_t isOn = (row >> colIndex) & 1;

	uint8_t lastRow = LastBitMap[rowIndex];
	uint8_t wasOn = (lastRow >> colIndex) & 1;

	return isOn == 0 && wasOn == 1;
}
uint8_t *ButtonMatrix::buttonsPressDownStarted()
{
	uint8_t pressedLength = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (pressDownStarted(rowIndex, colIndex)) 
			{
				pressedLength++;
			}
		}
	}

	uint8_t* pressedButtons = new uint8_t[pressedLength];
	uint8_t pressedCounter = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (pressDownStarted(rowIndex, colIndex)) 
			{
				pressedButtons[pressedCounter] = rowIndex * colIndex;
				pressedCounter++;
			}
		}
	}

	return pressedButtons;
}
uint8_t *ButtonMatrix::buttonsPressed()
{
	uint8_t pressedLength = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (isPressed(rowIndex, colIndex)) 
			{
				pressedLength++;
			}
		}
	}

	uint8_t* pressedButtons = new uint8_t[pressedLength];
	uint8_t pressedCounter = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (isPressed(rowIndex, colIndex)) 
			{
				pressedButtons[pressedCounter] = rowIndex * colIndex;
				pressedCounter++;
			}
		}
	}

	return pressedButtons;
}
uint8_t *ButtonMatrix::buttonsReleased()
{
	uint8_t pressedLength = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (wasReleased(rowIndex, colIndex)) 
			{
				pressedLength++;
			}
		}
	}

	uint8_t* pressedButtons = new uint8_t[pressedLength];
	uint8_t pressedCounter = 0;
	for (size_t rowIndex = 0; rowIndex < _rowCount; rowIndex++)
	{
		// uint8_t row = BitMap[rowIndex];
		// uint8_t lastRow = LastBitMap[rowIndex];

		for (size_t colIndex = 0; colIndex < _colCount; colIndex++)
		{
			if (wasReleased(rowIndex, colIndex)) 
			{
				pressedButtons[pressedCounter] = rowIndex * colIndex;
				pressedCounter++;
			}
		}
	}

	return pressedButtons;
}