#include <LCSeven.h>

//We always have to include the library

 
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn
 pin 11 is connected to the CLK
 pin 10 is connected to LOAD
 We have only a single MAX72XX.
 */
LCSeven lc = LCSeven(12, 11, 10, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 400;

void setup(void) {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
}


/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0.
 */
void writeArduinoOn7Segment() {
  lc.setChar(0, 0, 'a', false);
  delay(delaytime);
  lc.setRow(0, 0, 0x05);
  delay(delaytime);
  lc.setChar(0, 0, 'd', false);
  delay(delaytime);
  lc.setRow(0, 0, 0x1c);
  delay(delaytime);
  lc.setRow(0, 0, B00010000);
  delay(delaytime);
  lc.setRow(0, 0, 0x15);
  delay(delaytime);
  lc.setRow(0, 0, 0x1D);
  delay(delaytime);
  lc.clearDisplay(0);
  delay(delaytime);
}

/*
  This method will scroll all the hexa-decimal
 numbers and letters on the display. You will need at least
 four 7-Segment digits. otherwise it won't really look that good.
 */

/*
 * LedControl.setDigit(address, digit, column, state)
 *
 * address: number of the max7219 chip that's being used.... i think
 * digit - digit on the display?
 * byte - the value we're actually setting
 * dp - whether the decimal point is lit
 */

void scrollDigits() {


  for (int i = 0; i < 13; i++) {
    lc.setDigit(0, 0, i, false);
    lc.setDigit(0, 1, i + 1, false);
    lc.setDigit(0, 2, i + 2, false);
    lc.setDigit(0, 3, i + 3, false);
    lc.setDigit(0, 4, i + 4, false);
    lc.setDigit(0, 5, i + 5, false);
    lc.setDigit(0, 6, i + 6, false);
    lc.setDigit(0, 7, i + 7, false);
    delay(delaytime);
  }
  lc.clearDisplay(0);
  delay(delaytime);
}



void loop(void) {
  // writeArduinoOn7Segment();
  lc.clearDisplay(0);
  lc.showError(0);
}

