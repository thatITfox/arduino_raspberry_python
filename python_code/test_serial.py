import serial

if __name__ == '__main__':
    try:
        # for raspberry pi
        ser = serial.Serial('/dev/ttyS0')
    except:
        # for a satndard desktop or laptop, usualy for testing
        ser = serial.Serial('com5', 9600, timeout=1)
    ser.flush()
read = True
print("test is now on!!")
jumlah_deteksi = int(input("input how many remote detection u want:"))
while read:
    for line in range(jumlah_deteksi):
        if ser.in_waiting < 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
