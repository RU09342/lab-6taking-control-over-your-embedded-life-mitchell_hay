# Lab 6: Open Loop Systems
## Shani Thapa, Mitchell Hay
* Populated README on 11/21

### Board
We choose the G2552 for this lab. The main reason we choose this board was because it was the only board that can have its IC replaced and that was a huge benefit since we were working with voltages and currents far above the board's capacity to handle. Also, it is the cheapest option so it would be the most cost-effective if we could properly use the G2 for this lab. 

### Schematics 

### Control Technique 
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
### Code 
  