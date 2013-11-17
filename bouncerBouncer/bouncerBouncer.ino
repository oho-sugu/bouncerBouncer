#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  #include "Wire.h"
#endif

MPU6050 accelgyro;

int16_t ax,ay,az;
int16_t gx,gy,gz;

int FIN = 5;
int RIN = 6;
int count = 0;
int OFFSET = 40;
int MAX = 256;

void setup() {
  delay(1000);
  pinMode(FIN, OUTPUT);
  pinMode(RIN, OUTPUT);
  
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
  #endif
  
  accelgyro.initialize();
}

void loop() {
  delay(100);
  accelgyro.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);
  if(az > 32000){ count = 0; }
  count += 1;
  count %= MAX - OFFSET;
  analogWrite(FIN, count + OFFSET);
  digitalWrite(RIN, LOW);
}

