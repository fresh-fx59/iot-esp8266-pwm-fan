#include <Arduino.h>

//Settings 
#define Fan_Pin_Tach D5
#define Fan_Pin_PWM D6
#define Fan_PWM_FRQ 25000
#define Fan_RPM_Update_Period 1000

//Data
volatile int Fan_InterrupCount;
unsigned long Fan_PrevMills;
int Fan_RPM;

void ICACHE_RAM_ATTR HandleInterrupt() { //This is the function called by the interrupt
  Fan_InterrupCount++;
}

void InitFan(){

 Fan_InterrupCount=0;
 Fan_RPM=0;
 Fan_InterrupCount=0;

 //Fan Controls
  analogWriteFreq(Fan_PWM_FRQ);
  pinMode(Fan_Pin_PWM, OUTPUT);

  //Fan data
  pinMode(Fan_Pin_Tach, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Fan_Pin_Tach), HandleInterrupt, FALLING);
}

void SetFanLevel(int percent) {
  analogWrite(Fan_Pin_PWM,  map(percent, 0, 100, 0, 255));
}

void DisplayFanRPM() {
  Serial.print(Fan_RPM, DEC);
  Serial.print(" RPM\r\n");
}

void CalcFanRPM(){
  if ((millis() - Fan_PrevMills) > Fan_RPM_Update_Period) {
    Fan_PrevMills = millis();
    Fan_RPM =  Fan_InterrupCount / 2 * 60;
    Fan_InterrupCount=0;
    DisplayFanRPM();
  }
  yield();
}