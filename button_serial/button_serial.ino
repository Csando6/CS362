const int ledPin = 9;
const int buttonPin = 8;

int buttonVal;
int toggleValue = 0;
int toggleRead;
String TR;

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
  if(Serial.available()>0){
    delay(100);
    TR = char(Serial.read() );
    while(Serial.available() > 0){
      TR += char(Serial.read() );
    }
    Serial.print("TR: ");
    Serial.println(TR);
    toggleRead = TR.toInt();
  }
  
  
  if(button_press(buttonPin) ){
    if(toggleValue == 0){
      toggleValue = 1;
    }
    else{
      toggleValue = 0;
    }
    Serial.write(char('0'+toggleValue));
    //Serial.println(char(toggleValue+'0') );
  }
  
  //Serial.print("toggle value: ");
  //Serial.println(toggleValue);
  
  digitalWrite(ledPin,toggleRead);
}
