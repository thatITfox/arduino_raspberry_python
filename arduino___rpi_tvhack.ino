// percobaan pertama kode arduino gagal, gak hanya hardware nya, tapi juga software nya
// percobaan percobaan lain nya akan di uji pada kode ini

#include <IRremote.h>
const int RECV_PIN = 4;  // pin penerima inframerah 
char raspberry_pi_info;
char decoded_resultes;
char data_need_tosend;
IRsend irsend;
IRrecv irrecv(RECV_PIN);
decode_results results;

// pembuka serial
void setup() {
  Serial.begin(9600);
  Serial.println("data colection is now on"); // if the arduino got restart, it would send the this line when it turn on again
  // Enable the IR Receiver
  irrecv.enableIRIn();
}
void loop() {
  if (irrecv.decode(&results)){
    // Print Code in HEX
        Serial.println(results.value, HEX); 
        irrecv.resume();
  }
   if (Serial.available() > 0) { //detect the raspberry pi serial code 
    data_need_tosend = Serial.read(); // recive and read the data from raspberry pi
    irsend.sendNEC(data_need_tosend, 32); // proses penyaerangan nya entar di tambahi kode hex nya lewat variabel 
  }
    // Add a small delay before repeating
    delay(200);
}
