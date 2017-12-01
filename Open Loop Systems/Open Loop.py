import time
import serial

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='COM6',
    baudrate=9600)

ser.isOpen()

def wr(s, pwm):
    i = 0
    pwm = chr(pwm)
    while i<3:
        s.write(bytes(pwm))
        s.flush()
        i += 1
        pwm/(10**i)

print 'Enter PWM below.\r\nInsert "exit" to leave the application.'
i=1
while 1 :
    # Get PWM input
    i = raw_input()
    if i == 'exit':
        ser.close()
        exit()
    else:
        # send the character to the device
        #wr(ser, i)
        out = ''
        # Wait one second before reading output (let's give device time to answer)
        time.sleep(1)
        # Read all values
        # ADC Values delimited by newline
        while ser.inWaiting() > 0:
            out = ser.readline()
        if out != '':
            print "Output of MSP: " + out
