
#import serial
#from time import sleep, strftime, time

#ser = serial.Serial('/dev/ttyACM0', 9600)

#with open ("/home/pi/ard.csv", "a") as log:
#       while 1:
#               log.write(format(strftime("%Y-%m-%d %H:%M:%S"),str(ser.readline())))
#               sleep(1)
import csv

import serial

from time import sleep, strftime, time

while (1):
        ser = serial.Serial('/dev/ttyACM0', 9600)
        file = open("liste.csv", "a") #permet de garder les anciennes valeurs sans avoir a les ecraser a chaque fois
        cw=csv.writer(file)
        cw.writerow([ser.readline(), strftime("%Y-%m-%d %H:%M:%S")])
        file.close()

#file = open("liste.csv", "a")
#ajout=csv.writer(file)
#ajout.writerow(["numero carte", "date et heure"])
#file.close()


#file = open("qq.csv","r")
#cr=csv.reader(file)
#crr = file.read()
#print(crr)

#for row in cr :
#       print row
#file.close()
