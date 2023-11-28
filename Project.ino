int left_ir_pin = 2;
int right_ir_pin = 4;
int echopin = 8;
int triggerpin=7;
int distance;
int in1=12;
int in2=13;
int ena1 = 5;
int ena2 = 3;
int motor_speed=55;
int duration;
unsigned long endtime;
unsigned long starttime;
;




void setup() {
  // put your setup code here, to run once:
    pinMode(left_ir_pin,INPUT);
    pinMode(right_ir_pin,INPUT);
    pinMode(triggerpin,OUTPUT);
    pinMode(echopin, INPUT);
    Serial.begin(9600);
    digitalWrite(in2,LOW);
    digitalWrite(in1,LOW); 

}
void motor_start(){
  analogWrite(ena1, motor_speed);
  analogWrite(ena2, motor_speed);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);  
}
void motor_stop(){
  analogWrite(ena1, motor_speed);
  analogWrite(ena2, motor_speed);
  digitalWrite(in2,LOW);
  digitalWrite(in1,HIGH);  
}

int ultrasonic(){
  digitalWrite(triggerpin, LOW);
  digitalWrite(triggerpin, HIGH);
  digitalWrite(triggerpin, LOW);
  duration = pulseIn(echopin, HIGH);
  return duration;  
}

void loop() {
  motor_stop();
  // put your main code here, to run repeatedly:
  int right_ir_val=digitalRead(right_ir_pin);
  if (right_ir_val == 0){Serial.println("The object is at place");}
  delay(1500);
  int left_ir_val=digitalRead(left_ir_pin);
  while(left_ir_val != 0){motor_start();}
  if (left_ir_val == 0){
    motor_stop();
    duration= ultrasonic();
    delay(5000);
  if (duration> 350) { delay(150000); }
  
  else {
    starttime = millis();
    endtime = starttime;
    while ((endtime - starttime) <=10000) // do this loop for up to 1000mS
    {
      motor_start();
      endtime = millis();}
}
}



