#include <math.h>

int row_excel = 0; // количество строк
int test = 123; // тестовая переменная, которая будет передана excel
int test_2 = 456; // вторая тестовая переменная, которая будет передана excel

#define TERMIST_B 4300
#define VIN 5.0
 
void setup(){
  Serial.begin(9600); // скорость передачи данных
  Serial.println("CLEARDATA"); // очистка листа excel
  Serial.println("LABEL,Time,Test 1, Test 2, Num Rows"); // заголовки столбцов
}
 
void loop(){
  float voltage = analogRead(A0) * VIN / 1024.0;
  float r1 = voltage / (VIN - voltage);
  float temperature = 1./( 1./(TERMIST_B)*log(r1)+1./(25. + 273.) ) - 273;

  
  row_excel++; // номер строки + 1
  Serial.print("DATA,TIME,"); // запись в excel текущей даты и времени
  
  Serial.print(test);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.println(row_excel);
 
  // если строк больше 50, то начинаем заполнять строки по новой
  /*if (row_excel > 50){
    row_excel = 0;
    Serial.println("ROW,SET,2");
  } */
  delay(2000); // задержка
}
