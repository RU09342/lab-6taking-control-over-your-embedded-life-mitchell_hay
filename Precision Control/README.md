# Lab 6: Precision Control
## Shani Thapa, Mitchell Hay
* Populated README on 11/29

### PWM
The code for this part was already written in the previous lab. The output PWM is then put through a low-pass-filter to get an analog voltage. We had to put the signal through multiple LPF until we could get an accurate average voltage that didn't vary heavily. 
![Alt text](https://user-images.githubusercontent.com/31711430/33461850-46140afc-d602-11e7-94eb-dddea91abab4.png)

### R2R DAC
The R2R ladder is one of the simplest DAC to make. The circuit is very straitforward just requires connecting a bunch of resisters of two different values in a ladder like arrangement. Then just have them connected to the MSP which gives each of them either a digital 1 or 0.  

![Alt text](https://user-images.githubusercontent.com/31711430/33461847-45f138b0-d602-11e7-8363-9ed5e92cdf76.png

###
Changing the output resistance had the expected results. The voltage went down by a certain amount in both cases. Pictures below show some of the results from both the LPF and the R2R ladder. 

![Alt text](https://user-images.githubusercontent.com/31711430/33461842-45b64d54-d602-11e7-8b18-5f59148c2495.png)

![Alt text](https://user-images.githubusercontent.com/31711430/33461848-45fc53c6-d602-11e7-89e9-944a54fc804d.png)