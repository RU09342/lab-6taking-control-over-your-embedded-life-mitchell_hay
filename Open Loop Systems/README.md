# Lab 6: Open Loop Systems
# Shani Thapa, Mitchell Hay

## Board
We choose the MSP430G2552 for this lab. The main reason we choose this board was because it was the only board that can have its IC replaced and that was a huge benefit since we were working with voltages and currents far above the board's capacity to handle. Also, it is the cheapest option so it would be the most cost-effective if we could properly use the G2 for this lab. 

## Schematics 
As seen in the schamtic below, there were five components to the open loop system. The first was the MSP430, which was used to read in temperature values, send out a PWM signal to a fan, and to send data to a computer program. The other component was the fan, which was used to cool off the system. The system to be cooled was a voltage regulator pressed against a temperature sensor. The voltage regulator and fan were powered by a 20 V input, and the voltage regulator was connected to a 100 ohm power resistor. The last component was the computer, which was connected to the MSP430 via a UART connection. It was used to send and receive values to and from the microcontroller.

## Control Technique 
We started off by testing the maximum temperature that the voltage regulator could output. Afterwards, we tested a range of values for the PWM and recorded the minimum temperature the regulator reached. Using this set of data, we plotted into a graph and produced a trendline and equation for represent the data best. Initially, Excel was used, but since it could not produce a satisfactory trendline, we eneded up using MatLab. The plot below shows the graph obatined from MatLab. The equation for this line was Y = Ae^(bx) + Ce^(dx). Where y was the temperature and x was the PWM duty cycle value. Every other variable was a constant provided by MatLab. By solving for x in this equation, we could input a temperature and get a PWM value to reach that temperature. Since this was an open-looped-system, we simply hard coded the equation to get the PWM value for a certain temperature we choose.   

| PWM | Temperature |
| ----|-------------|
|  0  |     63.8    |
| 10  |     52.3    |
| 15  |     47.9    |
| 20  |     42.3    |
| 25  |     39.5    |
| 35  |     37      |
| 50  |     34.5    |
| 100 |     32.02   | 

![Alt text](https://user-images.githubusercontent.com/31711430/33098433-6de47e50-cedb-11e7-8536-5813dd48f80b.jpg) 

## Code 
There was two programs written; one for the MSP430 and one for the computer. The computer ran a Python script to read in and send out values from the microcontroller. The PySerial library was used, and the following code block was written to open communication to the board:
```python
ser = serial.Serial(port = 'COM6', baudrate = 9600)
```
The program consists of a loop that will always run unless the user enters the word, "exit". The input from the user is converted to a byte string before being sent out, so that the MSP430 can understand the input. The program then prints out the values to the console and runs the loop again.

## Tasks
* [x] Implement serial communication using Python and MSP430
* [x] Control fan with PWM signal
* [x] Read in temperatures using LM35 temperature sensor
