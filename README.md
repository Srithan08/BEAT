# BEAT
Biometric Evaluation and Analysis Tracker

Wearable health monitors have become the norm of modern health monitoring, allowing patients to monitor essential vitals such as heart rate, blood oxygen saturation, and body temperature in real time. Wearable health monitors allow proactive management of health, management of chronic conditions, and fitness monitoring. However, their high cost makes them inaccessible to many of the global populations, particularly in low-resource communities. To fill this chasm, this project presents the concept of a low-cost, Arduino-based wearable medical monitor capable of monitoring three vital physiological parameters: body temperature, heart rate, and SpO₂.  The prototyped medical monitor, called the Biometric Evaluation and Analysis Tracker (BEAT), consists of a pulse sensor, a MAX30102 oximeter, and a thermistor interfaced by an Arduino microcontroller. These modules were chosen based on their low cost, availability, and reliability. Modularity, scalability, and ease of hardware and software combining the device from open-source hardware and software were the device design priorities. BEAT demonstrates measurements relatively close to commercial devices, within clinically acceptable limits. This proves the technical viability of low-cost medical wearables without compromise on primary functionality. The system has widespread deployment potential: it might be employed in remote healthcare regions where traditional infrastructure does not reach, in the health settings where medical technology exists without accessibility, or to educate biomedical engineers and health scientists in classrooms. By enabling democratization of basic healthcare information by putting all files here in this github, the project enables universal health equity as well as more accessible prevention-focused care. In addition, the open-source platform promotes ongoing improvement and community innovation, thus a solution that is easily tweakable to future healthcare requirements. Ongoing development and verification could make this device a cost-effective substitute for pricey commercial monitors, allowing users around the world to take better control of their own health.

## Wiring guide:
MAX30102 Sensor:
- VCC → 3.3V on Arduino
- GND → GND
- SDA → A4
- SCL → A5

Thermistor:
- One leg → A0 on Arduino
- Other leg → 10k resistor to GND and also to 5V (voltage divider)

SSD1306 OLED Display:
- VCC → 3.3V on Arduino
- GND → GND
- SDA → A4
- SCL → A5

## Building the device:
1. Export the stl files of the arduino case to a preferred slicer and 3D print all stl file.
2. Take the arduino case and gently place the arduino within the case and put on the protective cover.
4. Use a wire stripper to remove the ruber at the end of insulated wires and then solder the wires to the pins of the MAX30102 sensor.
5. place shrink tubing on the connections and use a heat gun to shrink it and to protect the connections.
6. gently place the MAX30102 sensor in its case and run the wire through the top of the case and run it back to the arduino connecting it to the speific points listed in the wiring guide.
7. Use the same method to solder insulated whires to the thermistor and run the wires through the bottom of the auduino case making sure the tip of the thermistor is the only thing poking out underneath the case.
8. Connect the thermistor wires to the arduino board as seen in the wiring guide, soldering connections if 2 wires need to be plugged into the same port on the arduino.
9. gently push the 3D printed pins in the arduino hole and weld the side of the pin that is not touching the arduino to the arduino case using a soldering iron to keep the arduino in place.
10. Put the SSD1306 OLED screen on the lid of the arduino case using double sided tape, ensuring a secure and tight fit.
11. Solder insulated wire to the SSD1306 and connect it back to the arduino according to the wiring guide, soldering if nescessary.
12. Place the lid of the arduino casing on the arduino, clipping them together to ensure a tight fit..
13. Attach the battery connecter to the battery holder right next to the opening for the wire.
14. Plug in the battery connector cable into the arduino and weld the battery holder to the arduino casing using a soldering iron and slowly melting the plastic along the edge of the battery case.
15. Remove the lid of the battery connecter and place the battery within the device to turn on.
16. Connect the arduino to computer of choice and upload the arduino ide code provided here into the arduino ide and upload it into the arduino.
17. Test the device by placing the battery inside.
