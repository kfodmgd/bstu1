use UNIVER;

/*Разработать представление с именем Препода-ватель. Представление 
должно быть построено на основе SELECT-запроса к таблице TEACH-ER и 
содержать следующие столбцы: код (TEACHER), имя преподавателя 
(TEACHER_NAME), пол (GENDER), код кафедры (PULPIT). */
go
create view [Преподаватель]
	as select TEACHER[Учитель],
			  TEACHER_NAME[Имя],
			  GENDER[Пол],
			  PULPIT[код кафедры] from TEACHER;

go
select * from Преподаватель;
select * from Преподаватель order by [Пол];

go
alter view [Преподаватель]
	as select TEACHER_NAME[Имя],
			  GENDER[Пол],
			  PULPIT[код кафедры] from TEACHER;
go
select * from [Преподаватель]
drop view [Преподаватель];

/*Разработать и создать представление с именем Количество кафедр. 
Представление должно быть построено на основе SELECT-запроса к 
таблицам FACULTY и PULPIT*/
go
create view [Колво кафедр]
	as select FACULTY.FACULTY_NAME[Имя факультета],
			  count(*)[колво кафедр]
			  from FACULTY join PULPIT
				on FACULTY.FACULTY=PULPIT.FACULTY
				group by FACULTY.FACULTY_NAME;
go
select * from [Колво кафедр];

/*Разработать и создать представление с именем Аудитории. 
Представление должно быть по-строено на основе таблицы AUDITORIUM и 
содержать столбцы: код (AUDITORIUM), наименование аудитории 
(AUDITORI-UM_NAME). */
go
alter view [Аудитории](Имя, Тип, Код)
	as select AUDITORIUM[Код],
			  AUDITORIUM_NAME[Имя],
			  AUDITORIUM_TYPE[Тип] from AUDITORIUM
			  where AUDITORIUM.AUDITORIUM_TYPE like 'ЛК%';
go
select * from [Аудитории];
insert Аудитории values('210-3','210-3','ЛК');

/*Разработать и создать представление с именем Лекционные_аудитории. 
Представление должно быть построено на основе SELECT-запроса к 
таблице AUDITO-RIUM и содержать следующие столбцы: код (AUDITORIUM), 
наименование аудитории (AUDITORIUM_NAME). 
Представление должно отображать только лекционные аудитории (в 
столбце AUDITO-RIUM_TYPE строка, начинающаяся с симво-лов ЛК). 
Выполнение INSERT и UPDATE допускает-ся, но с учетом ограничения, 
задаваемого оп-цией WITH CHECK OPTION. */
go
alter view [Лекционные_аудитории](Код, Имя, Тип)
	as select AUDITORIUM[Код],
			  AUDITORIUM_NAME[Имя],
			  AUDITORIUM_TYPE[Тип] from AUDITORIUM
			  where AUDITORIUM.AUDITORIUM_TYPE like 'ЛК%' with check option;
go
select * from Лекционные_аудитории;
insert Лекционные_аудитории values('210-4','210-4','ПЗ');

/*5. Разработать представление с именем Дис-циплины. Представление 
должно быть по-строено на основе SELECT-запроса к таблице SUBJECT, 
отображать все дисциплины в ал-фавитном порядке и содержать 
следующие столбцы: код (SUBJECT), наименование дис-циплины 
(SUBJECT_NAME) и код кафедры (PULPIT). Использовать TOP и ORDER BY.
*/
go
alter view [Дисциплины]
	as select top 10 SUBJECT[Код],
		SUBJECT_NAME[Имя],
		PULPIT[Кафедра] from SUBJECT
		order by SUBJECT_NAME;
go
select * from Дисциплины;

/*Изменить представление Количество_кафедр, созданное в задании 2 
так, чтобы оно было привязано к базовым таблицам. Продемонстрировать 
свойство привязанности представ-ления к базовым таблицам. 
Примечание: ис-пользовать опцию SCHEMABINDING. */
go
alter view [Колво кафедр] with SCHEMABINDING
	as select fc.FACULTY_NAME[Факультет],
			  count(*) [Колво кафедр]
			  from dbo.FACULTY fc join dbo.PULPIT pl
			  on fc.FACULTY=pl.FACULTY
			  group by fc.FACULTY_NAME;
go
select * from [Колво кафедр];

