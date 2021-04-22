// percobaan pertama kode arduino gagal, gak hanya hardware nya, tapi juga software nya
// percobaan percobaan lain nya akan di uji pada kode ini

#include <IRremote.h>
#define led 13
const int RECV_PIN = 2;  // pin penerima inframerah
char raspberry_pi_info;
String decoded_resultes;
String data_need_tosend;
IRsend irsend;
IRrecv irrecv(RECV_PIN);
decode_results results;

// pembuka serial
void setup() {
  Serial.begin(9600);
  // Serial.println(0x01); // if the arduino got restart, it would send the this line when it turn on again
  // Enable the IR Receiver
  irrecv.enableIRIn();
  pinMode(led, OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
   if (Serial.available()) { //detect the raspberry pi serial code
      data_need_tosend = Serial.readStringUntil('\n'); // recive and read the data from raspberry pi
      // if (data_need_tosend[0] == "r"){
      // data_need_tosend[0] = '\0';
      // irsend.sendNEC(data_need_tosend, 32); // proses penyaerangan nya entar di tambahi kode hex nya lewat variabe
      Serial.println(data_need_tosend);
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
   }

    // Add a small delay before repeating
    delay(200);
}
