use UNIVER;
/*На основе таблиц AUDITORIUM_ TYPE и AUDITORIUM сформировать 
перечень кодов аудиторий и соответствующих им наименований типов 
аудиторий.*/
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
FROM AUDITORIUM_TYPE Inner Join AUDITORIUM
ON AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE;

/*На основе таблиц AUDITORIUM_TYPE и AUDITORIUM сформировать 
перечень кодов аудиторий и соответствующих им наименований типов 
аудиторий. 
При этом следует выбрать только те ауди-тории, в наименовании 
которых присутству-ет подстрока компьютер. 
*/

SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
FROM AUDITORIUM_TYPE Inner Join AUDITORIUM
ON AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE And
		AUDITORIUM_TYPE.AUDITORIUM_TYPENAME Like '%компьютер%';

/*Написать два SELECT-запроса, формирую-щих результирующие наборы 
аналогичные запросам из заданий 1 и 2, но без применения INNER JOIN. */
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
FROM AUDITORIUM_TYPE, AUDITORIUM
WHERE AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE;

SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM_TYPE.AUDITORIUM_TYPENAME from AUDITORIUM_TYPE,AUDITORIUM
WHERE AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE And AUDITORIUM_TYPE.AUDITORIUM_TYPENAME Like '%компьютер%';

/*На основе таблиц PRORGESS, STUDENT, GROUPS, SUBJECT, PULPIT и 
FACULTY сформировать перечень студентов, получивших экзаменационные
оценки (столбец PROGRESS.NOTE) от 6 до 8. 
Результирующий набор должен содержать столбцы: Факультет, Кафедра, 
Специаль-ность, Дисциплина, Имя Студента, Оцен-ка. В столбце Оценка 
должны быть записаны экзаменационные оценки прописью: шесть, семь, 
восемь. 
Результирующий набор отсортировать в порядке возрастания по 
столбцам FACULTY.FACULTY, PULPIT.PULPIT, PROFESSION.PROFESSION, 
STUDENT. STUDENT_NAME и в порядке убывания по столбцу PROGRESS.NOTE.*/
SELECT FACULTY.FACULTY [Факультет], PULPIT.PULPIT [Кафедра], PROFESSION.PROFESSION_NAME [Специальность],
	   SUBJECT.SUBJECT_NAME [Дисциплина], STUDENT.NAME [Имя студента],
Case
		when (PROGRESS.NOTE = 6) then 'шесть'
		when (PROGRESS.NOTE = 7) then 'семь'
		when (PROGRESS.NOTE = 8) then 'восемь'
		else 'неуд'
		end [Оценки]

FROM	FACULTY
		Inner Join PROFESSION ON FACULTY.FACULTY = PROFESSION.FACULTY
		Inner Join PULPIT ON FACULTY.FACULTY = PULPIT.FACULTY 
		Inner Join SUBJECT ON PULPIT.PULPIT = SUBJECT.PULPIT
		Inner Join PROGRESS ON SUBJECT.SUBJECT = PROGRESS.SUBJECT
		Inner Join STUDENT ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
		
WHERE PROGRESS.NOTE BETWEEN 6 And 8

--ORDER BY PROGRESS.NOTE Desc
ORDER BY PROFESSION.PROFESSION_NAME, FACULTY.FACULTY, PULPIT.PULPIT, PROGRESS.NOTE Desc, STUDENT.NAME
--будет сортировка по специальностям

/*Переписать запрос, реализующий задание 4 таким образом, чтобы в 
результирующем наборе сортировка по экзаменационным оценкам была 
следующей: сначала выводились строки с оценкой 7, затем строки с 
оценкой 8 и далее строки с оценкой 6. */
SELECT FACULTY.FACULTY [Факультет], PULPIT.PULPIT [Кафедра], PROFESSION.PROFESSION_NAME [Специальность],
	   SUBJECT.SUBJECT_NAME [Дисциплина], STUDENT.NAME [Имя студента],
Case
		when (PROGRESS.NOTE = 6) then 'шесть'
		when (PROGRESS.NOTE = 7) then 'семь'
		when (PROGRESS.NOTE = 8) then 'восемь'
		else 'неуд'
		end [Оценки]

FROM	FACULTY
		Inner Join PROFESSION ON FACULTY.FACULTY = PROFESSION.FACULTY
		Inner Join PULPIT ON FACULTY.FACULTY = PULPIT.FACULTY 
		Inner Join SUBJECT ON PULPIT.PULPIT = SUBJECT.PULPIT
		Inner Join PROGRESS ON SUBJECT.SUBJECT = PROGRESS.SUBJECT
		Inner Join STUDENT ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
		
WHERE PROGRESS.NOTE BETWEEN 6 And 8
order by
(case
	when(PROGRESS.NOTE=7)then 3
	when(PROGRESS.NOTE=8)then 2
	when(PROGRESS.NOTE=6)then 1
	end
)

/*На основе таблиц PULPIT и TEACHER получить полный перечень кафедр
и преподавателей на этих кафедрах. Результирующий набор должен 
содержать два столбца: Кафедра и Преподаватель. Если на кафедре нет
преподавателей, то в столбце Преподаватель должна быть выведена 
строка ***. */
select ISNULL(TEACHER.TEACHER_NAME,'***')[Препод], PULPIT.PULPIT[кафедра]
	from PULPIT left outer join TEACHER
	on PULPIT.PULPIT=TEACHER.PULPIT

/*В запросе, реализующем пункт 6, поменять порядок таблиц в 
выражении LEFT OUTER JOIN. Объяснить: почему в столбце Кафедра не 
может быть значения NULL.*/
select ISNULL(TEACHER.TEACHER_NAME,'***')[Препод], PULPIT.PULPIT[кафедра]
	from TEACHER left outer join PULPIT
	on PULPIT.PULPIT=TEACHER.PULPIT

/*Переписать запрос таким образом, чтобы получился аналогичный 
результат, но при-менялось соединение таблиц RIGHT OUTER JOIN.
*/
select ISNULL(TEACHER.TEACHER_NAME,'***')[Препод], PULPIT.PULPIT[кафедра]
	from TEACHER right outer join PULPIT
	on PULPIT.PULPIT=TEACHER.PULPIT

/*Показать на примере, что соединение FULL OUTER JOIN двух таблиц:
− является коммутативной операцией;
− является объединением LEFT OUTER JOIN и RIGHT OUTER JOIN 
  соединений этих таблиц;
− включает соединение INNER JOIN этих таблиц.
Примечание: создать две таблицы, заполнить их данными. Разработать 
SELECT-запросы, реализующие задания. */
  create table TOVAR(
	tov_id int primary key,
	tov_name nvarchar(20),
  );
  create table DESK(
	tov int foreign key references TOVAR(tov_id),
	desk nvarchar(75),
	pokup_id int primary key,
  );
  insert into TOVAR(tov_id,tov_name)
	values
		(1,'сыр'),
		(2,'молоко'),
		(3,'масло'),
		(4,null);
  insert into DESK(tov,desk,pokup_id)
	values
		(1,'сыр',55),
		(2,'молоко',13),
		(3,'масло',9),
		(4,null,45);

--коммутативность
select isnull (TOVAR.tov_name,'Нозвание товара')[товар],isnull(DESK.pokup_id,1)[id покупаптеля]
	from TOVAR full outer join DESK on TOVAR.tov_id=DESK.tov;
select isnull(DESK.pokup_id,1)[id покупателя],isnull (TOVAR.tov_name,'масло')[товар]
	from DESK full outer join TOVAR on DESK.tov=TOVAR.tov_id;

--является объединением LEFT OUTER JOIN и RIGHT OUTER JOIN
select TOVAR.tov_name[Товар], isnull (DESK.pokup_id,1)[Покупатель]
from TOVAR left outer join DESK on TOVAR.tov_id=DESK.tov;
select isnull(TOVAR.tov_name,'Имя товара')[Товар], DESK.pokup_id[Покупатель]
from TOVAR right outer join DESK on TOVAR.tov_id=DESK.tov;

--включает соединение INNER JOIN этих таблиц
select TOVAR.tov_name[Товар], DESK.pokup_id[Покупатель]
from TOVAR inner join DESK on TOVAR.tov_id=DESK.tov;

/*Создать три новых запроса:
− запрос, результат которого содержит данные левой 
  (в операции FULL OUTER JOIN) таблицы и не содержит данные правой; 
− запрос, результат которого содержит данные правой таблицы и не 
  содержащие данные левой; 
− запрос, результат которого содержит данные правой таблицы и 
  левой таблиц;*/

  --содержит данные левой таблицы и не содержит данные правой
  select isnull(DESK.pokup_id,0)[id покупателя]
	from DESK full outer join TOVAR on DESK.tov=TOVAR.tov_id
	where DESK.desk is  null;

--содержит данные правой таблицы и не содержащие данные левой; 
select isnull(TOVAR.tov_name,'lol')[товар]
	from DESK full outer join TOVAR on DESK.tov=TOVAR.tov_id
	where TOVAR.tov_name is  null;

--содержит данные правой таблицы и левой таблиц;
	select isnull(TOVAR.tov_name,'lol')[товар],isnull(DESK.pokup_id,0)[id покупателя]
	from DESK full outer join TOVAR on DESK.tov=TOVAR.tov_id
	where TOVAR.tov_name is  null;

/*Разработать SELECT-запрос на основе CROSS JOIN-соединения таблиц 
AUDITORIUM_TYPE и AUDITORIUM, формирующего результат, аналогичный
результату, полученному при выполнении запроса в задании 1.*/
select AUDITORIUM.AUDITORIUM[аудитория],AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
	from AUDITORIUM cross join AUDITORIUM_TYPE
	where AUDITORIUM_TYPE.AUDITORIUM_TYPE = AUDITORIUM.AUDITORIUM_TYPE;

