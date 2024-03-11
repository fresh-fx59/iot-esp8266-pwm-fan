# Description
Manage fan with PWM via ESP8266 and MQTT Yandex cloud

# Setup MQTT Yandex Cloud
Setup is pretty the same and can be found [here](https://github.com/fresh-fx59/iot-mqtt-yandex-cloud-with-esp8266/blob/main/README.md)

# Pins connection explanation
PWM fan has 4 pins

![pwm fan pict](https://github.com/fresh-fx59/iot-mqtt-yc-esp8266-pwm-fan/assets/5788874/f0f2b57a-c73c-4b59-8fc1-4267effa9688)

NodeMCU has these pins available

![nodemcu-pins](https://github.com/fresh-fx59/iot-mqtt-yc-esp8266-pwm-fan/assets/5788874/9bc3d5d0-2901-4cf2-a210-ccffb46660bd)

For this project we need to connect **D6** pin to fan's PWM input and **D5** pin to fan's Tach output. I am using 12V 2A DC power adapter to power up fan and same power supply to power up NodeMCU but with DC-DC converter from 12V to 5V. NodeMCU and fan should have common ground. Keep in mind that NodeMCu works on 5V max and fan needs 12V DC. When connecting my 12V 2A DC power supply directly to NodeMCU to **Vin** and **GND** - _FT232_ adapter smoked and now USB connection not working... Please keep this in mind and give proper voltage to appropriate pins.

![board connection](https://github.com/fresh-fx59/iot-mqtt-yc-esp8266-pwm-fan/assets/5788874/57513105-9efd-48ec-912a-8413a9bf614d)

# How does it work?
When everything is setted up you can send 0 or 1 as payload and see how fan speed decrease to least RPM or max RPM. You can measure RPM via [this](https://play.google.com/store/apps/details?id=com.ToolsCompany.TachometerRPM) app. Also RPM are transmitted every second to serial output.

# Source
I've taken a lot of info from [this](https://mysku.club/blog/diy/97421.html) article.


