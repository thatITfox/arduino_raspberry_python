import serial

if __name__ == '__main__':
    ser = serial.Serial('com3', 9600, timeout=1)
    ser.flush()
while True:
    with open('serial_save.txt', 'w') as data:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            data.write(line)
            print(line)
