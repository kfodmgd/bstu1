import cv2                              # библиотека opencv (получение и обработка изображения)
import mediapipe as mp                  # библиотека mediapipe (распознавание рук)
import serial                           # библиотека pyserial (отправка и прием информации)


camera = cv2.VideoCapture(0)            # получаем изображение с камеры (0 - порядковый номер камеры в системе)
mpHands = mp.solutions.hands            # подключаем раздел распознавания рук
mpHands1 = mp.solutions.hands
hands = mpHands.Hands()                 # создаем объект класса "руки"
hands1 = mpHands1.Hands()
mpDraw = mp.solutions.drawing_utils     # подключаем инструменты для рисования
mpDraw1 = mp.solutions.drawing_utils

portNo = "COM10"                         # указываем последовательный порт, к которому подключена Arduino
uart = serial.Serial(portNo, 9600)      # инициализируем последовательный порт на скорости 9600 Бод


p = [0 for i in range(21)]              # создаем массив из 21 ячейки для хранения высоты каждой точки
p1 = [0 for i in range(21)]
finger = [0 for i in range(5)]          # создаем массив из 5 ячеек для хранения положения каждого пальца
finger1 = [0 for i in range(5)]

# функция, возвращающая расстояние по модулю (без знака)
def distance(point1, point2):
    return abs(point1 - point2)

#результат
def rez(fin):
    if(fin[1]==0 & fin[2]==0&fin[3]==0 & fin[4]==0):
       return 'rock'
    if(fin[1]==1 & fin[2]==1 & fin[3]==1 & fin[4]==1):
       return 'paper'
    if(fin[1] & fin[2] & fin[3]==0 & fin[4]==0):
       return 'scissors'



while True:
    good, img = camera.read()                                   # получаем один кадр из видеопотока
    roi = img[0 : 300, 0 : 300]
    roi1=img[0:300,400:700]
    imgRGB = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)               # преобразуем кадр в RGB
    imgRGB1 = cv2.cvtColor(roi1, cv2.COLOR_BGR2RGB)


    results = hands.process(imgRGB)                             # получаем результат распознавания
    if results.multi_hand_landmarks:                            # если обнаружили точки руки
        for handLms in results.multi_hand_landmarks:            # получаем координаты каждой точки

            # при помощи инструмента рисования проводим линии между точками
            mpDraw.draw_landmarks(roi, handLms, mpHands.HAND_CONNECTIONS)

            # работаем с каждой точкой по отдельности
            # создаем список от 0 до 21 с координатами точек
            for id, point in enumerate(handLms.landmark):
                # получаем размеры изображения с камеры и масштабируем
                width, height, color = roi.shape
                width, height = int(point.x * height), int(point.y * width)

                p[id] = height           # заполняем массив высотой каждой точки

            # получаем расстояние, с которым будем сравнивать каждый палец
            distanceGood = distance(p[0], p[5]) + (distance(p[0], p[5]) / 2)
            # заполняем массив 1 (палец поднят) или 0 (палец сжат)
            finger[1] = 1 if distance(p[0], p[8]) > distanceGood else 0
            finger[2] = 1 if distance(p[0], p[12]) > distanceGood else 0
            finger[3] = 1 if distance(p[0], p[16]) > distanceGood else 0
            finger[4] = 1 if distance(p[0], p[20]) > distanceGood else 0
            finger[0] = 1 if distance(p[4], p[17]) > distanceGood else 0

            # готовим сообщение для отправки
            #print(finger[0],finger[1],finger[2],finger[3],finger[4])
            msg = ''
            # 0 - большой палец, 1 - указательный, 2 - средний, 3 - безымянный, 4 - мизинец
            # жест "коза" - 01001
#            if not (finger[0]) and finger[1] and not (finger[2]) and not (finger[3]) and finger[4]:
#                msg = '@'
#            if finger[0] and not (finger[1]) and not (finger[2]) and not (finger[3]) and not (finger[4]):
#                msg = '^'
#            if not(finger[0]) and finger[1] and finger[2] and not(finger[3]) and not(finger[4]):
#                msg = '$' + str(width) + ';'
#            if not(finger[0]) and finger[1] and not(finger[2]) and not(finger[3]) and not(finger[4]):
#                msg = '#' + str(width) + ';'



            cv2.putText(roi, rez(finger), (20,20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
            # отправляем сообщение в Arduino

            #rez(finger)
            msg+=str("f")+str(finger[0])+str(finger[1])+str(finger[2])+str(finger[3])+str(finger[4])+str(";")
            if msg != '':
                msg = bytes(str(msg), 'utf-8')
                uart.write(finger)
                print("ПЕРВЫЙ",end=' ')
                print(msg)


    results1 = hands1.process(imgRGB1)                             # получаем результат распознавания
    if results1.multi_hand_landmarks:                            # если обнаружили точки руки
        for handLms1 in results1.multi_hand_landmarks:            # получаем координаты каждой точки

            # при помощи инструмента рисования проводим линии между точками
            mpDraw1.draw_landmarks(roi1, handLms1, mpHands1.HAND_CONNECTIONS)

            # работаем с каждой точкой по отдельности
            # создаем список от 0 до 21 с координатами точек
            for id1, point1 in enumerate(handLms1.landmark):
                # получаем размеры изображения с камеры и масштабируем
                width1, height1, color1 = roi1.shape
                width1, height1 = int(point1.x * height1), int(point1.y * width1)

                p1[id1] = height1           # заполняем массив высотой каждой точки

            # получаем расстояние, с которым будем сравнивать каждый палец
            distanceGood1 = distance(p1[0], p1[5]) + (distance(p1[0], p1[5]) / 2)
            # заполняем массив 1 (палец поднят) или 0 (палец сжат)
            finger1[1] = 1 if distance(p1[0], p1[8]) > distanceGood1 else 0
            finger1[2] = 1 if distance(p1[0], p1[12]) > distanceGood1 else 0
            finger1[3] = 1 if distance(p1[0], p1[16]) > distanceGood1 else 0
            finger1[4] = 1 if distance(p1[0], p1[20]) > distanceGood1 else 0
            finger1[0] = 1 if distance(p1[4], p1[17]) > distanceGood1 else 0

            # готовим сообщение для отправки
            #print(finger1[0],finger1[1],finger1[2],finger1[3],finger1[4])
            msg1 = ''
            
            # 0 - большой палец, 1 - указательный, 2 - средний, 3 - безымянный, 4 - мизинец
            # жест "коза" - 01001
#            if not (finger[0]) and finger[1] and not (finger[2]) and not (finger[3]) and finger[4]:
#                msg = '@'
#            if finger[0] and not (finger[1]) and not (finger[2]) and not (finger[3]) and not (finger[4]):
#                msg = '^'
#            if not(finger[0]) and finger[1] and finger[2] and not(finger[3]) and not(finger[4]):
#                msg = '$' + str(width) + ';'
#            if not(finger[0]) and finger[1] and not(finger[2]) and not(finger[3]) and not(finger[4]):
#                msg = '#' + str(width) + ';'


            cv2.putText(roi1, rez(finger1), (20,20), cv2.FONT_HERSHEY_SIMPLEX, 1, (0,0,255), 2)
            # отправляем сообщение в Arduino
            msg1+=str("s")+str(finger1[0])+str(finger1[1])+str(finger1[2])+str(finger1[3])+str(finger1[4])+str(";")
            if msg1 != '':
                msg1 = bytes(str(msg1), 'utf-8')
                uart.write(finger1)
                print("ВТОРОЙ",end=' ')
                print(msg1)


    cv2.imshow("Image", img)           # выводим окно с нашим изображением
    cv2.imshow('ROI',roi)
    cv2.imshow('ROI1',roi1)
    if cv2.waitKey(1) == ord('q'):     # ждем нажатия клавиши q в течение 1 мс
        break                          # если нажмут, всё закрываем
