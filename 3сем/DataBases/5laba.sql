use UNIVER;

/*На основе таблиц FACULTY, PULPIT и PROFESSION сформировать список
наименований кафедр (столбец PUL-PIT_NAME), которые находятся на 
факультете (таблица FACULTY), обеспечи-вающем подготовку по 
специальности, в наименовании (столбец PROFESSION_ NAME) которого 
содержится слово технология или технологии.*/
select PULPIT.PULPIT_NAME [Кафедра],FACULTY.FACULTY_NAME[Факультет], PROFESSION.PROFESSION_NAME [специальность]
	from PULPIT,PROFESSION,FACULTY
	where FACULTY.FACULTY=PULPIT.FACULTY and FACULTY.FACULTY=PROFESSION.FACULTY and 
	PROFESSION_NAME in (select PROFESSION_NAME from PROFESSION where PROFESSION_NAME like '%технология%')

/*Переписать запрос пункта 1 таким образом, чтобы тот же подзапрос 
был записан в конструкции INNER JOIN секции FROM внешнего запроса. 
При этом результат выполнения запроса должен быть аналогичным 
результату исходного запроса. */
select PULPIT.PULPIT_NAME [Кафедра],FACULTY.FACULTY_NAME[Факультет], PROFESSION.PROFESSION_NAME [специальность]
	from PULPIT inner join FACULTY on FACULTY.FACULTY=PULPIT.FACULTY 
		inner join PROFESSION on FACULTY.FACULTY=PROFESSION.FACULTY
		where PROFESSION_NAME in (select PROFESSION_NAME from PROFESSION where PROFESSION_NAME like '%технология%')

/*Переписать запрос, реализующий 1 пункт без использования 
подзапроса. Примечание: использовать соединение INNER JOIN трех 
таблиц*/
select PULPIT.PULPIT_NAME [Кафедра],FACULTY.FACULTY_NAME[Факультет], PROFESSION.PROFESSION_NAME [специальность]
	from PULPIT inner join FACULTY on FACULTY.FACULTY=PULPIT.FACULTY 
		inner join PROFESSION on FACULTY.FACULTY=PROFESSION.FACULTY
		where PROFESSION_NAME like '%технология%';

/*На основе таблицы AUDITORIUM сформировать список аудиторий самых 
больших вместимостей (столбец AUDITORIUM_CAPACITY) для каждого типа
аудитории (AUDITORIUM_TYPE).При этом результат следует отсортировать 
в порядке убывания вместимости. Примечание: использовать 
коррелируемый подзапрос c секциями TOP и ORDER BY*/
select AUDITORIUM.AUDITORIUM_CAPACITY,AUDITORIUM.AUDITORIUM_TYPE
	from AUDITORIUM
	where AUDITORIUM_CAPACITY=(select top(1) AUDITORIUM_CAPACITY
	where AUDITORIUM.AUDITORIUM_TYPE=AUDITORIUM.AUDITORIUM_TYPE
	order by AUDITORIUM_CAPACITY desc)

/*На основе таблиц FACULTY и PULPIT сформировать список 
наименований факультетов (столбец FACULTY_NAME) на котором нет ни 
одной кафедры (таблица PULPIT). Примечание: использовать предикат 
EXISTS и коррелированный подзапрос. */
select FACULTY.FACULTY_NAME from FACULTY
	where exists (select * from PULPIT
	where FACULTY.FACULTY = PULPIT.FACULTY)

/*На основе таблицы PROGRESS сформировать строку, содержащую 
средние значения оценок (столбец NOTE) по дисциплинам, имеющим 
следующие коды: ОАиП, БД и СУБД. Примечание: исполь-зовать три 
некоррелированных подзапроса в списке SELECT; в подзапросах 
применить агрегатные функции AVG*/
select top 1
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like 'ОАиП')[ОАиП],
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like 'КГ')[КГ],
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like 'СУБД')[СУБД]
	from PROGRESS

/*Разработать SELECT-запрос, демонстрирующий принцип применения 
ALL совместно с подзапросом*/
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM.AUDITORIUM_CAPACITY
FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM_CAPACITY >= all (SELECT AUDITORIUM.AUDITORIUM_CAPACITY 
	FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM like '4%')

/*Разработать SELECT-запрос, демонстри-рующий принцип применения 
ANY совместно с подзапросом.*/
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM.AUDITORIUM_CAPACITY
FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM_CAPACITY >= any (SELECT AUDITORIUM.AUDITORIUM_CAPACITY 
	FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM like '4%')
