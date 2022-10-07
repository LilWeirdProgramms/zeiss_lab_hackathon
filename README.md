# Hackathon @ CARLA Graz - The Photonics Career Hub

-> group hackathon repo of the ZEISS Lab of the Medical University of Vienna (Center for Meidcal Physics and Biomedical Engineering)


## 0. Required Packages:

- Adafruit BusIO by Adafruit
- SHT31 by Adafruit
- TCS34725 by Adafruit
- Adafruit Unified Sensor by Adafruit
- ClosedCube SHT31D by ClosedCube
- WebSockets by Markus Sattler


# Official Description

The Hackathon will take place on three consecutive days. However, it is not mandatory to be present on all three days. The site of the Hackathon can be left at will to for example listen to speeches, attend to 1:1 sessions or simply take a break.

Please bring your own laptop along!

------------------------------------------------------------------------------------------------------------------------------------------------------

### Main goals

Create an innovative concept for coping with Green Tech challenges with a special focus on photonics. A business concept and a prototype supporting your business idea should be developed and presented in the finals.

Focus: substantially reducing the number of deaths and illnesses from hazardous chemicals and air, water, and soil pollution and contamination

The combination of both the concept and the prototype can then be submitted. The team with the best overall idea and execution wins 1500 €.

### Organizational information

    Necessary sensors, components, tools and devices for your prototype will be provided
    Participants will work in groups
        The number of group members can be chosen freely, however groups of 3-4 people are preferred
    On Wednesday, September 21st, the workshop Smartphone controlled RGB lamp will be held – it is advisable (but not mandatory) to participate in this workshop, helpful tips might be mentioned
    On the CARLA Graz website information can be found about the elements available and their specifications
    Mentoring by experts will be available for the duration of the event


# Available Hardware

## Microcontroller "D1 Mini"

The heart piece of all components for the Hackathon is the D1 Mini - ESP8266 developer board. It features 4 MB flash memory and ESP8266 chipset. The board can be programmed with Arduino IDE, it has the CH340 USB chipset and enables easy and fast creation of IoT devices.

### specifications:

    11 digital input pins
    all pins have interrupts
    support PWM/I2C and One-Wire
    1 analogue input (3.3 V max)
    4 MB flash - onboard wifi antenna
    micro-USB port

## DEBO SENS COLOR developer boards - RGB-color sensor, TCS34725

This color sensor with the TCS34725 chip has a RGB and clear-light sensor element. Additionally, this sensor has an incredible dynamic range of 3.800.000:1 with adjustable averaging time and amplification, which allows its functioning even behind darkened glasses.


## GRV PIR MOTION Arduino - Grove PIR motion sensor, TM2291

This is a simple to use PIR motion sensor with Grove compatible interface. Simply connect it to Stem shield and program it, when anyone moves in its detecting range, the sensor outputs HIGH on its SIG pin.

The detecting range and response speed can be adjusted by 2 potentiometers soldered on its circuit board, The response speed is from 0.3s - 25s, and max 6 meters of detecting range.

### Specification
    • Grove compatible interface
    • Voltage range: 3 ... 5 V
    • 2.0cm x 4.0cm twig module
    • Detecting angle: 120 degree
    • Detecting distance: max 6m (3m by default)
    • Adjustable detecting distance and holding time

### Application Ideas
    • Motion sensor
    • Thief-guarding System
    • Switch
    • Industrial automation


## DEBO TEMP HUM developer boards - Temperature and Humidity Sensor, SHT31-D

This sensor uses I2C-adress 0x44 or 0x45. It can measure relative moisture with +- 2 % and has an accuracy of +- 0.3°C


## GRV LIGHT SENSE Arduino - Grove Light Sensor, GL5528

The Grove - Light sensor module uses GL5528 photoresistor(light dependent resistor) to detect the intensity of light in the environment. The resistance of photoresistor decreases when the intensity of light increases. A dual OpAmp chip LM358 on board produces voltage corresponding to intensity of light(i.e based on resistance value). The output signal from this module will be HIGH in bright light and LOW in the dark.

This module can be used to build a light controlled switch i.e switch off lights during day time and switch on lights during night time.

### Key Features
    • Grove compatible interface
    • Plug and play

### Specifications
    • Operating Voltage: 3-5V
    • Supply Current: 0.5-3mA
    • Photoresistor: GL5528
    • Light resistance: 20KO
    • Dark resistance: 1MO
    • Response time: 20-30 secs
    • Peak Wavelength: 540 nm


## GRV ULTRASONIC Arduino - Grove Ultrasonic Rangefinder, HC-SR04

The Grove - Ultrasonic Sensor is a non-contact distance measurement module compatible with the Grove system. It is designed for simple, modular projects with industrial performance. An electronic version of this module is also available.

### Technical features • sensor range: 3 cm to 4 m - best results at 30 degree angle.
    • Grove interface
    • power supply: 3.3/5 V DC
    • ready for Arduino Library


## GRV WATER SENS Arduino - Grove water sensor

Grove - Water Sensor detects the presence of water using exposed PCB traces. The sensor is made up of interlaced traces of Ground and Sensor signals. The sensor traces are weakly pulled up using 1 M O resistor. The resistor will pull the sensor trace value high until a drop of water shorts the sensor trace to the ground trace. This circuit will work with digital I/O pins of Arduino or you can use it with the analog pins to detect the amount of water induced contact between the grounded and sensor traces.

### Applications
    • Rainfall detection
    • Liquid leakage
    • Tank overflow detection

### Features
    • Grove compatible interface
    • Low power consumption
    • High sensitivity


## GRV LOUDNESS Arduino - Grove Volume Sensor, LM2904

The Grove - Loudness Sensor is designed to detect the loudness of environmental sound. Based on amplifier LM2904 and a built-in microphone, it amplifies and filters the high frequency signal that received from the microphone, and outputs a positive envelop. This will make for Arduino's signal acquisition. The output value depends on the level of sound input. In order to avoid unnecessary signal disturbances, input signal will go through two times filtering inside the module. Lastly, there is a screw potentiometer that enables manual adjustments to the output gain.

### Features
    • Grove compatible interface
    • Wide supply voltage range
    • Built-in signal filtering
    • Gain adjustable via screw potentiometer

### Specifications
    Voltage: 3.5 ... 10 VDC
    Working Frequency: 50 ... 20000 Hz
    Sensitivity: -48 ... +66 dB
    Signal-to-noise Ratio: >58 dB
    Output Signal Range: Digital Signal (0 - 1023)


## DEBO MEMS MIC Developer Boards - Microphones, SPH0645

### This component is a microphone with amplifier and digital exit. 

    Digital output
    50 Hz to 15 kHz
    I2S Interface
    1,6 ... 3,6 V Operating voltage
    SPH0645LM4H


## DEBO SOUND AMP1 Developer Boards - Audio Amplifier, Class D, PAM8302A

This super small mono amplifier is surprisingly powerful. It can deliver up to 2.5 watts for speakers with 4-8 ohms impedance.

Filterless design with ferrite bead and capacitors from the output:
    
    supply voltage: 5 V
    fixed 24 dB gain
    onBoard trimming potentiometer for controlling the input volume
    Protection against thermal overload, short-circuit and overcurrent
    Dimensions: 24 x 15 x 2 mm


## DEBO LCD240X240 Developer Boards - Display LCD, 1.3", 240 x 240 Pixel, ST7789

This is an LCD display module with IPS screen, and a diagonal of 1.3 inches. The display has HD resolution and an integrated controller that communicates via an SPI interface.

### Technical data - Controller: ST7789

    Interface: SPI
    Display color: RGB, 65 K Colors
    Resolution: 240 x 240
    Backlight: LED
    Operating voltage: 3.3 V

### Scope of delivery
    1x 1.3-inch LCD module
    1x PH2.0 20 cm, 8-pin


## GRV SERVO Arduino - Grove Servo Motor

The three-core servo was converted into a Grove standard connector here. Now you can use it like a typical Grove module according to the Plug & Play principle, without much effort with jumpers.
