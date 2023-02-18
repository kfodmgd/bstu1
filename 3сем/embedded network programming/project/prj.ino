// Ref Videos:
// https://www.youtube.com/watch?v=utnPvE8hN3o
// https://www.youtube.com/watch?v=OJtpA_qTNL0

// Notes: 
// 1- Strings must always be inside double quotes ("text") or the code won't run.

// initialize a variable
int prevPower = 0;      // хранение предыдущего значения яркости
byte parseStart = 0;    // переменная запуска парсинга
bool powerLED = 0;      // флаг управления яркостью ленты
String count="";
String count1="";
#define PIN_LED 5     //пин
#define LENGTH_LED 50    //колво светодиодов
#include "FastLED.h"  //библиотека
CRGB leds[LENGTH_LED];   //массив со светодиодами

void setup() {
  // The same baud rate (9600) should be set in the python code
  // and in the Arduino code.
  Serial.begin(9600);

  // set LED_BUILTIN (pin 13) as an output
  pinMode(LED_BUILTIN, OUTPUT);
    FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, LENGTH_LED); //тип ленты, пин, порядок цветов, в скобках имя массива и его длина
  FastLED.setBrightness(50);
}

void loop() {
if (Serial.available())                 //  если что-то пришло в Serial-порт
  {
    char in = Serial.read();              //  читаем один байт (символ)
    if (!(in == '\n' || in == '\r'))      //  отсеиваем символы возврата картеки и переноса строки
    {
        switch (in)       // в зависимости от принятого символа, делаем выбор
        {
            case ';': parseStart = 1; break;                    // окончание сообщения
            case 's': parseStart = 2;  powerLED = 1; break;     // начало сообщения (управляем яркостью)
            case 'f': parseStart = 3;  powerLED = 1; break;     // начало сообщения (управляем цветом)
        }

        // если парсинг запущен и это не символы начала или окончания посылки
        if ((parseStart == 2) && (in != '#') && (in != '$') && (in != '^') && (in != '@')) 
        {  
          count += in;    // запоминаем переданное число (складываем по одному байту в общую строку)
        }
                // если парсинг запущен и это не символы начала или окончания посылки
        if ((parseStart == 3) && (in != '#') && (in != '$') && (in != '^') && (in != '@')) 
        {  
          count1 += in;    // запоминаем переданное число (складываем по одному байту в общую строку)
        }
     }
  }
  
  if(parseStart == 1)   //  если прием остановлен
  {
     int prevcolor=0;
          int cntt= count.toInt();
           cntt= map(cntt,200,800,0,255);

          
     for(int i=0;i<LENGTH_LED;i++){
     if(count.equals("f01100;") && count1.equals("s01111;")||    //н б
        count.equals("f01111;") && count1.equals("s00000;")||    //б к
        count.equals("f00000;") && count1.equals("s01100;")||    //к н
        count1.equals("s01100;") && count.equals("f01111;")||    //б н
        count1.equals("s01111;") && count.equals("f00000;")||    //к б
        count1.equals("s00000;") && count.equals("f01100;")     //н к
        )                                 //если был флажок управления цветом
        {
            leds[i] = CHSV(cntt,255,0);
          //leds[i] = CHSV(0, 255, 0); // задаем предыдущее значение яркости и меняем цвет на новый
        } 
      else{
        leds[i] = CHSV(0, 255, 0);
      }
    }   
      FastLED.show();   //  отображаем изменения на ленте
      int powerLED = 0;
      parseStart = 0;
      count = "";
      count1="";
    }
}











    /*// Example: This is how to send a message from the Arduino to 
    // the python code on the laptop.
    // It's just like writing to the Arduino Serial Monitor. But the message goes to
    // the python code instead of to the serial monitor.
    //Serial.println("Hello");

    // Read the count sent by the python code and store it in a variable called "count".
    // This line means: "read until you reach a newline chracter".
    // You will see that in the python code we have added a newline character before sending the string.
    count = Serial.readStringUntil('\n');
    count1= Serial.readStringUntil('\n');

    // Remove any leading and trailing whitespaces that could have been added.
    // Sometimes when devices are communicating they add a whitespace.
    count.trim();
    count1.trim();
    Serial.println("FIRST"+count);
    Serial.println("SECOND"+count1);
     if(count.equals("01100") && count1.equals("01111")||    //н б
        count.equals("01111") && count1.equals("00000")||    //б к
        count.equals("00000") && count1.equals("01100")||    //к н
        count1.equals("01100") && count.equals("01111")||    //б н
        count1.equals("01111") && count.equals("00000")||    //к б
        count1.equals("00000") && count.equals("01100")     //н к
        ) 
        {
            for (int i = 0; i < LED_NUM; i++) {
              leds[i].setRGB(0,255,0);
            }      
                  // Turn the LED on.
             digitalWrite(LED_BUILTIN, HIGH);
             //analogWrite(LED_PIN,255);//test
             FastLED.show();   //  отображаем изменения на ленте
             count="";
             count1="";
        }
       else{
              for (int i = 0; i < LED_NUM; i++) {
              leds[i].setRGB(255,0,0);
              FastLED.show();   //  отображаем изменения на ленте
              FastLED.delay(1);
             count="";
             count1="";
            } 
       }



    // Add a delay before the next communication is read.
    delay(100);

}*/
