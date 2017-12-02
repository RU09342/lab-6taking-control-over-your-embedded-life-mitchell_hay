# Lab 6: Precision Control
## Shani Thapa, Mitchell Hay

### PWM
The code for this part was already written in the previous lab. The output PWM is then put through a low-pass-filter to get an analog voltage. We had to put the signal through multiple LPF until we could get an accurate average voltage that didn't vary heavily. Our Vref for the PWM was 3.3V, so the target analog voltage was around 1.6V.  

![Alt text](https://user-images.githubusercontent.com/31711430/33461846-45e519d6-d602-11e7-96c3-216c0310d2b3.png)

### R2R DAC
The R2R ladder is one of the simplest DAC to make. The circuit is very straitforward just requires connecting several resisters of two different values in a ladder-like arrangement. Then just have them connected to the MSP board which gives each of them either a digital 1 or 0, which corresponds to 3.3 V and 0 V.

![Alt text](https://user-images.githubusercontent.com/31711430/33461847-45f138b0-d602-11e7-8363-9ed5e92cdf76.png)

### Loading Effects 
Changing the output resistance had the expected results. The voltage went down by a certain amount in both cases. Pictures below show some of the results from both the LPF and the R2R ladder. 

![Alt text](https://user-images.githubusercontent.com/31711430/33461851-461f5f10-d602-11e7-9b82-beb913a04172.png)

![Alt text](https://user-images.githubusercontent.com/31711430/33461848-45fc53c6-d602-11e7-89e9-944a54fc804d.png)
