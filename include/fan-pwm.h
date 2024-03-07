#include <Arduino.h>

//Settings 
#define Fan_Pin_Tach 14
#define Fan_Pin_PWM 12
#define Fan_PWM_FRQ 25000

//Data
volatile int Fan_InterrupCount;
unsigned long Fan_PrevMills;

void InitFan(){

 Fan_InterrupCount=0;
 Fan_InterrupCount=0;

 //Fan Controls
  analogWriteFreq(Fan_PWM_FRQ);
  pinMode(Fan_Pin_PWM, OUTPUT);
}

void SetFanLevel(int percent) {
  analogWrite(Fan_Pin_PWM,  map(percent, 0, 100, 0, 255));
}