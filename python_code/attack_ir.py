import serial
import time
attack = True
if __name__ == '__main__':
    try:
        # for raspberry pi
        ser = serial.Serial('/dev/ttyS0')
    except:
        # for a satndard desktop or laptop, usualy for testing
        ser = serial.Serial('com5', 9600, timeout=1)
    ser.flush()

while attack:
    send_yn = input("do you wanna attack:")
    if send_yn == "Y":
        attack_now = input("send the serial hex code to attack:")
        ser.write(bytes(attack_now, 'utf-8'))  # under testing and
        time.sleep(0.5)
        make_sure = ser.read()
        print(make_sure)
        # ser.write(b'3')
        # print(attack_now)
    else:
        print("thankyou")
        attack = False
