#if (USING_CB1 == 1)
void CB1Setup()
{
//ROW 5
if (ROW5_ACTIVE == 1)
{
  for(int i = 0; i<8;i++)
  {
    pinMode(row5Pins[i],INPUT_PULLUP);
  }
}

//ROW 6
if (ROW6_ACTIVE == 1)
{
  for(int i = 0; i<8;i++)
  {
    pinMode(row6Pins[i],INPUT_PULLUP);
  }
}

//ROW 8 COL 1

  pinMode(0, INPUT_PULLUP);

//PE interrupt pins
  pinMode(8, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);

//ADC alert pins
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);

//I2C setup
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire1.setSDA(6);
  Wire1.setSCL(7);
  wire0Init = true;
  wire1Init = true;

//ROW8
  if (DISABLE_ANALOG == 1)
  {
    pinMode(A0, INPUT_PULLUP);
    pinMode(A1, INPUT_PULLUP);
    pinMode(A2, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
  }
  if (DISABLE_LED_PIN == 1)
  {
    pinMode(25, INPUT_PULLUP);
  }
}

void CB1Alert()
{   
  if(DISABLE_ALERT_PINS == 0)
  {
    int addr = 0x48;
    Wire1.beginTransmission(addr);
    Wire1.write(0b00000011); //Write to high threshold register
    Wire1.write(0b10000000);
    Wire1.write(0b00000000);
    Wire1.endTransmission();

    Wire1.beginTransmission(addr);
    Wire1.write(0b00000010); //Write to low threshold register
    Wire1.write(0b00000000);
    Wire1.write(0b00000000);
    Wire1.endTransmission();

    addr = 0x49;
    Wire1.beginTransmission(addr);
    Wire1.write(0b00000011); //Write to high threshold register
    Wire1.write(0b10000000);
    Wire1.write(0b00000000);
    Wire1.endTransmission();

    Wire1.beginTransmission(addr);
    Wire1.write(0b00000010); //Write to low threshold register
    Wire1.write(0b00000000);
    Wire1.write(0b00000000);
    Wire1.endTransmission();
  }
}
#endif
void shiftRegisterSetup()
{
    if (SRCOUNT >= 1)
    {
        pinMode(SR1LATCH, OUTPUT);
        pinMode(SR1CLOCK, OUTPUT);
        pinMode(SR1DATA, INPUT);
    }
    if (SRCOUNT >= 2)
    {
        pinMode(SR2LATCH, OUTPUT);
        pinMode(SR2CLOCK, OUTPUT);
        pinMode(SR2DATA, INPUT);
    }
    if (SRCOUNT >= 3)
    {
        pinMode(SR3LATCH, OUTPUT);
        pinMode(SR3CLOCK, OUTPUT);
        pinMode(SR3DATA, INPUT);
    }
    if (SRCOUNT >= 4)
    {
        pinMode(SR4LATCH, OUTPUT);
        pinMode(SR4CLOCK, OUTPUT);
        pinMode(SR4DATA, INPUT);
    }
}


#if (USING_PCA9555 == 1)
void PCA9555Setup()
{
  for (int i = 0; i < sizeof(PCA9555interruptPins)/sizeof(PCA9555interruptPins[0]); i++)
  {
    pinMode(PCA9555interruptPins[i], INPUT_PULLUP);
  }
  #if (BOARDTYPE == 2)
    #if (PCA9555_I2C_NUMBER == 1 && USING_PCA9555 == 1)
    {
      Wire1.setSDA(SDA1PIN);
      Wire1.setSCL(SCL1PIN);
      wire1Init = true;
    }
    #elif (USING_PCA9555 == 1)
    {
      Wire.setSDA(SDA0PIN);
      Wire.setSCL(SCL0PIN);
      wire0Init = true;
    }
    #endif
  #else
    wire0Init = true;
  #endif
}
#endif

#if (USING_ADS1115 == 1)
  #if (ADS1115_ALERT == 1)
void ADS1115Alert()
{
  for(int i = 0; i < ADS1115_CHIPS; i++)
  {
    pinMode(ADS1115_alertPins[i], INPUT_PULLUP);
    int addr = ADS1115_chipAddress[i];
    Wire.beginTransmission(addr);
    Wire.write(0b00000011); //Write to high threshold register
    Wire.write(0b10000000);
    Wire.write(0b00000000);
    Wire.endTransmission();

    Wire.beginTransmission(addr);
    Wire.write(0b00000010); //Write to low threshold register
    Wire.write(0b00000000);
    Wire.write(0b00000000);
    Wire.endTransmission();
  }
}
  #endif

void ADS1115Setup()
{
  for(int i = 0; i<ADS1115_CHIPS; i++)
  {
    ADS1115sentReq[i] = false;  
    ADS1115channelCounter[i] = 0;
  }

  for(int i = 0 ; i<4*ADS1115_CHIPS; i++)
  {
    ADS1115value[i] = 0;  
  }
  
  
  #if (BOARDTYPE == 2)
    #if (ADS1115_I2C_NUMBER == 1 && USING_ADS1115 == 1)
      Wire1.setSDA(SDA1PIN);
      Wire1.setSCL(SCL1PIN);
      wire1Init = true;
    #elif(USING_ADS1115 == 1)
    {
      Wire.setSDA(SDA0PIN);
      Wire.setSCL(SCL0PIN);
      wire0Init = true;
    }
    #endif
  #else
    wire0Init = true;
  #endif
}
#endif


#if (USING_CB1 == 1 || USING_PCA9555 == 1 || USING_ADS1115 == 1)
void startI2C()
{
  #if(BOARDTYPE == 2)
  if(wire1Init)
  {
    Wire1.begin();
  }
  #endif
  if(wire0Init)
  {
    Wire.begin();
  }
}
#endif
