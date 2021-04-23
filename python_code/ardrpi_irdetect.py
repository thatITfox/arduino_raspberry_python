import serial

if __name__ == '__main__':
    ser = serial.Serial('com5', 9600, timeout=1)
    ser.flush()
List = []
read = True
while read:
    with open('serial_save.txt', 'a') as data:
        if len(List) <= 10:
            if ser.in_waiting > 0:
                line = ser.readline().decode('utf-8').rstrip()
                List.append(line)
                print(line)
        else:
            for i in List:
                data.write(i)
                data.write("\n")
            read = False

