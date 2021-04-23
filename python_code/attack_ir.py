import serial
attack = True
if __name__ == '__main__':
    ser = serial.Serial('com5', 9600, timeout=1)
    ser.flush()

while attack:
    send_yn = input("do you wanna attack:")
    if send_yn == "Y":
        attack_now = input("send the serial hex code to attack:")
        ser.write(bytes(attack_now, 'utf-8'))  # under testing and
        # ser.write(b'3')
        print(attack_now)
    else:
        print("thankyou")
        attack = False
