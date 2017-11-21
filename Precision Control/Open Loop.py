import serial
#Use the COM port you are trying to use
#also set the baud at object creation
ser = serial.Serial('COM6', baudrate=9600)
#treat like a file object
#can read and readline from
data = ser.read()
#show what we got
print data
#send some data, I usually send a newline too
#don't have too though, depends on what your 
#interfacing with
ser.write("hello world\n")
#close the file like serial object
ser.close()
