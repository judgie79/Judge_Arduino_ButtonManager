#include <UseJoystick.h>

#ifdef __USE_JOYSTICK_
#include <JoystickButtonMatrix.h>
#include <Joystick.h>
#include <DebugOut.h>

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
	JOYSTICK_TYPE_JOYSTICK, 128, 0,
	false, false, false, false, false, false,
	false, false, false, false, false);

#define BMATRIX_COLS 3         //{"Name":"BMATRIX_COLS","Title":"Columns","DefaultValue":"3","Type":"int","Condition":"ENABLED_BUTTONMATRIX>0","Min":2,"Max":8}
#define BMATRIX_ROWS 3         //{"Name":"BMATRIX_ROWS","Title":"Rows","DefaultValue":"3","Type":"int","Condition":"ENABLED_BUTTONMATRIX>0","Min":2,"Max":8}

#define BMATRIX_COL1 4         //{"Name":"BMATRIX_COL1","Title":"Column 1 pin","DefaultValue":"2","Type":"pin;Button M. Col 1","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=1"}
#define BMATRIX_COL2 5         //{"Name":"BMATRIX_COL2","Title":"Column 2 pin","DefaultValue":"3","Type":"pin;Button M. Col 2","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=2"}
#define BMATRIX_COL3 6         //{"Name":"BMATRIX_COL3","Title":"Column 3 pin","DefaultValue":"4","Type":"pin;Button M. Col 3","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=3"}
#define BMATRIX_COL4 5         //{"Name":"BMATRIX_COL4","Title":"Column 4 pin","DefaultValue":"5","Type":"pin;Button M. Col 4","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=4"}
#define BMATRIX_COL5 2         //{"Name":"BMATRIX_COL5","Title":"Column 5 pin","DefaultValue":"2","Type":"pin;Button M. Col 5","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=5"}
#define BMATRIX_COL6 2         //{"Name":"BMATRIX_COL6","Title":"Column 6 pin","DefaultValue":"2","Type":"pin;Button M. Col 6","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=6"}
#define BMATRIX_COL7 2         //{"Name":"BMATRIX_COL7","Title":"Column 7 pin","DefaultValue":"2","Type":"pin;Button M. Col 7","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=7"}
#define BMATRIX_COL8 2         //{"Name":"BMATRIX_COL8","Title":"Column 8 pin","DefaultValue":"2","Type":"pin;Button M. Col 8","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_COLS>=8"}

#define BMATRIX_ROW1 7         //{"Name":"BMATRIX_ROW1","Title":"Row 1 pin","DefaultValue":"6","Type":"pin;Button M. Row 1","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=1"}
#define BMATRIX_ROW2 8         //{"Name":"BMATRIX_ROW2","Title":"Row 2 pin","DefaultValue":"7","Type":"pin;Button M. Row 2","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=2"}
#define BMATRIX_ROW3 9         //{"Name":"BMATRIX_ROW3","Title":"Row 3 pin","DefaultValue":"8","Type":"pin;Button M. Row 3","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=3"}
#define BMATRIX_ROW4 9         //{"Name":"BMATRIX_ROW4","Title":"Row 4 pin","DefaultValue":"9","Type":"pin;Button M. Row 4","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=4"}
#define BMATRIX_ROW5 2         //{"Name":"BMATRIX_ROW5","Title":"Row 5 pin","DefaultValue":"2","Type":"pin;Button M. Row 5","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=5"}
#define BMATRIX_ROW6 2         //{"Name":"BMATRIX_ROW6","Title":"Row 6 pin","DefaultValue":"2","Type":"pin;Button M. Row 6","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=6"}
#define BMATRIX_ROW7 2         //{"Name":"BMATRIX_ROW7","Title":"Row 7 pin","DefaultValue":"2","Type":"pin;Button M. Row 7","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=7"}
#define BMATRIX_ROW8 2         //{"Name":"BMATRIX_ROW8","Title":"Row 8 pin","DefaultValue":"2","Type":"pin;Button M. Row 8","Condition":"ENABLED_BUTTONMATRIX>0 && BMATRIX_ROWS>=8"}

byte BMATRIX_COLSDEF[8] = { BMATRIX_COL1, BMATRIX_COL2, BMATRIX_COL3, BMATRIX_COL4, BMATRIX_COL5, BMATRIX_COL6, BMATRIX_COL7, BMATRIX_COL8 };
byte BMATRIX_ROWSDEF[8] = { BMATRIX_ROW1, BMATRIX_ROW2, BMATRIX_ROW3, BMATRIX_ROW4, BMATRIX_ROW5, BMATRIX_ROW6, BMATRIX_ROW7, BMATRIX_ROW8 };

JoystickButtonMatrix jButtonMatrix(&Joystick, 0);

void onSwitchChanged(bool isPressed)
{
    DebugOut.debug("triggered " + String(isPressed));
}

void setup() {
    Serial.begin(9600);
    jButtonMatrix.begin(BMATRIX_COLS, BMATRIX_ROWS, BMATRIX_COLSDEF, BMATRIX_ROWSDEF, buttonMatrixStatusChanged);
    Joystick.begin();
}

void buttonMatrixStatusChanged(int buttonId, byte state) {
  Serial.println("button " + String(buttonId) + " " + String(state));
}

void loop() {
    jButtonMatrix.read();
}
#else 
void setup() {

}

void loop() {
}
#endif