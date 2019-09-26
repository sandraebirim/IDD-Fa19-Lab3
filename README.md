# Data Logger (and using cool sensors!)

*A lab report by Sandra Ebirim.*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

The range of the analog values is from 0 to 1023 based on the serial monitor output. 
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

It has 10 bits of resolution which can be found by reading the documentation. 

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

[RGB Video](https://www.youtube.com/watch?v=RtFBro4ZOV4&feature=youtu.be)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

There is a range of analog values between 0 and 1023 using the serial monitor. 

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

It seems as if relationship between the voltage and the force applied is logarithmic. A small amount of force changes the amount of voltage significantly. However, as you apply more force, the resulting increase in voltage becomes less significant. 

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

We can use analogRead from A0 to give us the voltage range of 0 to 1024 that is produced by the FSR. This output can be used as the brightness parameter in the analogWrite function so the brightness will vary as the voltage varies. We can then group the different LED colors based on the resistance value that is being read in. 


**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

Softpot - 10k resistor 

Photocell - 5k resistor

CHECK 

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

When force was applied to the softpot resistor in different spots, the resistance changed. For the photocell resistor, there was increase in voltage when there was more light this means that the more light, the less resistance which is an inverse relationship. 

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

[Working Graphic Display](https://www.youtube.com/watch?v=hw0PQMfqLUA&feature=youtu.be)

[Working Graphic Display Code](https://github.com/sandraebirim/IDD-Fa19-Lab3/blob/master/OLED.ino) 

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes, it does matter. If you set the values and clear them before outputting them, you will never get an output value. Essentially, while the action assigned to a particular state doesn't matter, the order of the states does matter. 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

The code is in the setup function because it doesn't need to be called on a continuous loop. The code only needs to be deployed when the sensor changes. 

**c. How many byte-sized data samples can you store on the Atmega328?**

1024 byte sized data samples can be stored on the Atmega328. 

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

The map function has the capability to convert analog data to byte-sized data like how it is utilized in the SwitchState1 code. The analog data from both the Arduino analog pins and the I2C devices can be converted in this manner. 

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

EEPROM.put() can be used to store data that's larger than a byte. 

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

[Analog Value Printer](https://github.com/sandraebirim/IDD-Fa19-Lab3/tree/master)


### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

[Data Logger Code](https://github.com/sandraebirim/IDD-Fa19-Lab3/blob/master/DataLogger.ino)

[Data Logger Video](https://www.youtube.com/watch?v=PzJTUqx8RjA&feature=youtu.be)
