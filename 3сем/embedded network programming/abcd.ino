const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  Serial.begin(9600);
  // делаем цифровые контакты выходными:
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
}

void loop() {
  // если доступны какие-нибудь данные, считываем их:
  while (Serial.available() > 0) {
    // ищем во входных данных подходящее целое число:
    int red = Serial.parseInt(); 
    // ищем еще раз:
    int green = Serial.parseInt(); 
    // и еще:
    int blue = Serial.parseInt(); 

    // ищем символ новой строки – он должен стоять в конце вашего сообщения:
    if (Serial.read() == '\n') {
      red = 255 - constrain(red, 0, 255);
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);

      // задаем красному, зеленому и синему «суб-светодиодам» необходимую яркость:
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
    }
  }
}
