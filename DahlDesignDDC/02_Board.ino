/*
 * Chose your board. Default is to 32U4-based boards. 
 */

//------------------------------
//-----------BOARD MCU----------
//------------------------------

#define BOARDTYPE 2

// 0 -> Atmel 32U4 based boards. (Leonardo, Pro Micro, Feather, Teensy 2.0, etc) SAM3X based boards. (Due)

// 1 -> SAMD21 or SAMD51 based boards. (Arduino Zero and many more)

// 2 -> RP2040 based boards. (Dahl Design CB1, Raspberry Pi Pico, Pico W, Pro Micro RP2040, and many more)


//------------------------------
//-------DAHL DESIGN CB1--------
//------------------------------

//Enable CB1 board
#define USING_CB1 1

//ADC setup
#define CB1_ADC1 1
#define CB1_ADC1_CHANNELS 4
#define CB1_ADC1_RATE 7
#define CB1_ADC1_GAIN 1

#define CB1_ADC2 1
#define CB1_ADC2_CHANNELS 4
#define CB1_ADC2_RATE 7
#define CB1_ADC2_GAIN 1

//Port expander setup
#define CB1_PE1 1
#define CB1_PE2 1

//ROW5 and ROW6
#define ROW5_ACTIVE 1
#define ROW6_ACTIVE 1

//ROW7

#define GROUND_CALIBRATION 10

//ROW8 setup
#define DISABLE_ALERT_PINS 1  //Gives access to COL2 and COL3. Disables ALERT pins for the ADCs, making them heavier to run.
#define DISABLE_ANALOG 0      //Gives access to COL4 - COL 7 by using (and disabling analog function of) ADC9 - ADC12 pins. 
#define DISABLE_LED_PIN 0     //Gives access to COL8, use the dedicated 8-8 pin. The LED pin will no longer work. 

//------------------------------
//---------I2C DEVICES----------
//------------------------------

#define SDA0PIN 0
#define SCL0PIN 1
#define SDA1PIN 2
#define SCL1PIN 3

//PORT EXPANDER PCA9555
#define USING_PCA9555 0
#define PCA9555_I2C_NUMBER 0
uint8_t PCA9555interruptPins [] = {0};

//16-BIT ADC ADS1115
#define USING_ADS1115 0
#define ADS1115_I2C_NUMBER 0
#define ADS1115_CHIPS 1
uint8_t ADS1115_chipAddress [] = {0x48};

#define ADS1115_ALERT 0

#if (ADS1115_ALERT == 1)
uint8_t ADS1115_alertPins [] = {8};
#endif

//EEPROM CAT24C512
#define USING_CAT24C512 1
#define CAT24C512_I2C_NUMBER 0
#define CAT24C512_ADDRESS 0x50

//VARIABLES
bool wire1Init = false;
bool wire0Init = false;

#if(USING_CB1 == 1)
  #include <ADCInput.h>
  ADCInput oversamples (A0, A1, A2, A3);
  bool ADS1115sentReq[2] = {false, false};
  long ADS1115value[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  uint8_t ADS1115channelCounter[2] = {0,0};  
#elif(ADS1115_CHIPS > 0)
  bool ADS1115sentReq[ADS1115_CHIPS];
  uint16_t ADS1115value[4*ADS1115_CHIPS];
  uint8_t ADS1115channelCounter[ADS1115_CHIPS];
#endif

//------------------------------
//---------LIBRARIES------------
//------------------------------

#if (BOARDTYPE == 0)
  #include <DDC32U4.h>
#elif (BOARDTYPE == 1)
  #include <DDCSAMD.h>
#elif (BOARDTYPE == 2)
  #include <DDCPI.h>
#endif

#if (USING_CB1 == 1 || USING_PCA9555 == 1 || USING_ADS1115 == 1 || USING_CAT24C512 == 1)
  #include <Wire.h>
#endif
