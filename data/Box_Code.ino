#define FLAME 2 // connect DO pin of sensor to this pin


void setup() {
  Serial.begin(9600);
  Serial.println("Robojax.com Fire Module Test");
  pinMode(FLAME, INPUT);//define FLAME input pin
  // Flame sensor code for Robojax.com

}

void loop() {
    // Flame sensor code for Robojax.com

  int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    Serial.println("Fire! Fire!");
  }else{
    Serial.println("Peace");
    // Flame sensor code for Robojax.com

  }



  delay(200);
}
