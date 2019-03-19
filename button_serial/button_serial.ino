const int ledPin = 9;
const int buttonPin = 8;

int buttonVal;
int toggleValue = 0;

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

bool serial_to_int(int &toggleValue){
  if(Serial.available()<1){
    return false;
  }
  String num;
  int number;
  while(Serial.available()>0){
    num += char(Serial.read());
  }
  number = num.toInt();
  Serial.print("character received: ");
  Serial.println(number);
  toggleValue = number;
  return true;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  

}
void loop() {
  // put your main code here, to run repeatedly:
  //if(serial_to_int(toggleValue) ){
    
  //}
  
  if(button_press(buttonPin) ){
    if(toggleValue == 0){
      toggleValue = 1;
    }
    else{
      toggleValue = 0;
    }
    Serial.write(toggleValue);
  }
  
  //Serial.print("toggle value: ");
  //Serial.println(toggleValue);

  digitalWrite(ledPin,toggleValue);
}
