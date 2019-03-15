const int ledPin = 9;
const int buttonPin = 8;
int buttonVal;
int toggleValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  

}

bool button_press(int pin){
  int val;
  val = digitalRead(pin);
  if(val == LOW){
    return false;
  }
  
  while(val == HIGH){
    delay(10);
    val = digitalRead(pin);
  }
  //Serial.println("Button pressed!");
  return true;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(button_press(buttonPin) ){
    if(toggleValue == 0){
      toggleValue = 1;
    }
    else{
      toggleValue = 0;
    }
    Serial.print("toggle value: ");
    Serial.println(toggleValue);
  }

  digitalWrite(ledPin,toggleValue);
  

}
