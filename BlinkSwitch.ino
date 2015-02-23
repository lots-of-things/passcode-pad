/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton1 = 4;
int blinker1 = 11;
int pushButton2 = 2;
int blinker2 = 12;
int pushButton3 = 3;
int blinker3 = 13;
int lastButton = 0;

int newOne = 0;
int MYSIZE = 4;
int pushed[] = {0, 0, 0, 0};
int myCode[] = {1,2,3,4};

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton1, INPUT);
  pinMode(blinker1, OUTPUT);
  pinMode(pushButton2, INPUT);
  pinMode(blinker2, OUTPUT);
  pinMode(pushButton3, INPUT);
  pinMode(blinker3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState1 = digitalRead(pushButton1);
  // print out the state of the button:
  digitalWrite(blinker1,buttonState1);
  
  int buttonState2 = digitalRead(pushButton2);
  // print out the state of the button:
  digitalWrite(blinker2,buttonState2);
  
  int buttonState3 = digitalRead(pushButton3);
  // print out the state of the button:
  digitalWrite(blinker3,buttonState3);
  if(buttonState1==1){
    if(lastButton!=1){
      lastButton=1;
      newOne=1;
    }
  }else if(buttonState2==1){
    if(lastButton!=2){
      lastButton=2;
      newOne=2;
    }
  }else if(buttonState3==1){
    if(lastButton!=3){
      lastButton=3;
      newOne=3;
    }
  }else{
    lastButton=0;
  }
  if(newOne!=0){
    for(int i = 0; i < MYSIZE-1; i++){
      pushed[i]=pushed[i+1];
    }
    pushed[MYSIZE-1]=newOne;
    boolean checkit = true;
    for(int i = 0; i < MYSIZE; i++){
      if(pushed[i]!=myCode[i]){
        checkit=false;
        break;
      }
    }
    if(checkit){
      for(int i = 0; i < 20; i ++){
        digitalWrite(blinker1,HIGH);
        digitalWrite(blinker2,HIGH);
        digitalWrite(blinker3,HIGH);
        delay(100);
        digitalWrite(blinker1,LOW);
        digitalWrite(blinker2,LOW);
        digitalWrite(blinker3,LOW);
        delay(100);
      }
      memset(pushed,0,sizeof(pushed));
    }
  }
  newOne=0;
  for (int i = 0; i < MYSIZE; i++){
    Serial.print(pushed[i]);
    Serial.print(", ");
  }
  Serial.println();
  delay(1);        // delay in between reads for stability
}



