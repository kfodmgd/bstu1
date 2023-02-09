int LEDrot=12;
int LEDgelb=11;
int LEDgruen=10;
int cnt=0;
int state=1;
String message;
void setup()
{
  pinMode(LEDrot,OUTPUT);
   pinMode(LEDgelb,OUTPUT);
   pinMode(LEDgruen,OUTPUT);
    Serial.begin(9600);
}

void loop(){
  while(Serial.available()){
    char incomingChar=Serial.read();
    message+=incomingChar;
    message.toLowerCase();
    if(incomingChar=='\n'){
      if(message=="n\n"){
        Serial.println("Включён режим normal");
        Statemaschine();
        message="";
      }
      if(message=="s\n"){
        Serial.println("Включён режим sleep");
        SleepFlash();
        //delay(500);
        //SleepFlash();
        delay(10);
        message="";
      }
      if(message=="r\n"){
        Serial.println("Включён режим red");
        RedFlash();
        message="";
      }
      if(message=="g\n"){
        Serial.println("Включён режим green");
        GreenFlash();
        message="";
      }
    }
  }
}
 void Statemaschine1(void){
  digitalWrite(LEDrot,HIGH);
  delay(1000);
  
 }




  void SleepFlash(void){
    digitalWrite(LEDgelb,HIGH);
      delay(1000);
            digitalWrite(LEDgelb,LOW);
      delay(1000);
            digitalWrite(LEDgelb,HIGH);
      delay(1000);
                  digitalWrite(LEDgelb,LOW);
      delay(1000);
  }

    
      /*switch(state){
        case 1:
        state++;
        digitalWrite(LEDrot,LOW);
        digitalWrite(LEDgelb,HIGH);
        digitalWrite(LEDgruen,LOW);
        //state++;
        //delay(250);
        //break;
        case 2:
        digitalWrite(LEDrot,LOW);
        digitalWrite(LEDgelb,LOW);
        digitalWrite(LEDgruen,LOW);
        state++;
        //delay(250);
        //break;
        case 3:
        digitalWrite(LEDrot,LOW);
        digitalWrite(LEDgelb,HIGH);
        digitalWrite(LEDgruen,LOW);
        state=1;
        //break;
      }
  }*/

  void RedFlash(void){
        digitalWrite(LEDrot,HIGH);
        digitalWrite(LEDgelb,LOW);
        digitalWrite(LEDgruen,LOW);
  }

  void GreenFlash(void){
        digitalWrite(LEDrot,LOW);
        digitalWrite(LEDgelb,LOW);
        digitalWrite(LEDgruen,HIGH);
  }
  
  /*cnt++;
  if(cnt==100)
  {
    cnt=0;
    Statemaschine();
    }

    delay(10);
  }*/
  

  void Statemaschine1(void){
    switch(state)
    {
      case 1:
      digitalWrite(LEDrot,HIGH);
      digitalWrite(LEDgelb,LOW);
      digitalWrite(LEDgruen,LOW);
      state++;
      break;

            case 2:
      digitalWrite(LEDrot,HIGH);
      digitalWrite(LEDgelb,HIGH);
      digitalWrite(LEDgruen,LOW);
      state++;
      break;
            case 3:
      digitalWrite(LEDrot,LOW);
      digitalWrite(LEDgelb,LOW);
      digitalWrite(LEDgruen,HIGH);
      state++;
      break;
            case 4:
      digitalWrite(LEDrot,LOW);
      digitalWrite(LEDgelb,HIGH);
      digitalWrite(LEDgruen,LOW);
      state=1;
      break;
      }
    }
