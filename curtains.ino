int relay1=4;
int relay2 = 3;
int s= 3;
int clk = 1;
int aclk = 2;
int clockwise, anticlockwise, st;
char data;
//float temp;
//int temp_pin = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
//  pinMode(s, INPUT);
//  pinMode(clk, INPUT);
//  pinMode(aclk, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 //  stop();
  clockwise = analogRead(clk);
  anticlockwise = analogRead(aclk);
  st = analogRead(s);
  if(st > 200){
    stop();
  }
  else if(clockwise > 200){
    forward();
  }
  else if(anticlockwise > 200){
    backward();
  }
//  else if(clockwise < 200){
//    stop();
//  }
//  else if(anticlockwise < 200){
//    stop();
//  }
//  else{
//    stop();
//  }
  while(Serial.available()>0){
    data = Serial.read();
    if (data == 's'){
      stop();
    }
    else if(data == 'f'){
      forward();
    }
    else if(data == 'b'){
      backward();
    }
//    else{
//      stop();
//    }
  }
//  temp = analogRead(temp_pin);
//   // read analog volt from sensor and save to variable temp
//   temp = temp * 0.48828125;
//   // convert the analog volt to its temperature equivalent
////   Serial.print("TEMPERATURE = ");
////   Serial.print(temp); // display temperature value
////   Serial.print("*C");
////   Serial.println();
////   
//
//  if(temp > 30){
//    backward();
//  }
////  else{
////    stop();
////  }
  Serial.print("st:");
  Serial.println(st);
  Serial.print("clk:");
  Serial.println(clockwise);
  Serial.print("aclk:");
  Serial.println(anticlockwise);
  //delay(2000);
  
}
int stop(){
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  Serial.println("stop");
}
int forward(){
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  Serial.println("front");
}
int backward(){
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, LOW);
  Serial.println("back");
}
