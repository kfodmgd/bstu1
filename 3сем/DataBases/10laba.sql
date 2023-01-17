--курсор-программной конструкцией, которая дает возможность пользователю 
--обрабатывать строки результирующего набора запись за записью
--локальные, глобальные, статические, динамические

/*Разработать сценарий, формирующий список дисциплин на кафедре ИСиТ. В 
отчет должны быть выведены краткие названия (поле SUBJECT) из таблицы 
SUBJECT в одну строку через запятую. */
declare line cursor for select SUBJECT from SUBJECT;
declare @one nvarchar(10), @all nvarchar(200)=' ';
open line
fetch line into @one;
print 'дисциплины';
while @@FETCH_STATUS=0
	begin
		set @all=rtrim(@one)+', '+@all;--rtrim удаление конечных пробелов из сроки
		fetch line into @one
	end
print rtrim(@all)+'конец'
close line
deallocate line
go

/*Разработать сценарий, демонстрирую-щий отличие глобального курсора от 
локального на примере базы данных X_UNIVER*/
declare LinesLocal cursor global for select SUBJECT from SUBJECT
declare @First nvarchar(10), @All nvarchar(200) = ' ';

open LinesLocal
fetch LinesLocal into @First
print '1. ' + @First
go

declare @First nvarchar(10), @All nvarchar(200) = ' ';
fetch LinesLocal into @First
print '2. ' + @First
go

/*Разработать сценарий, демонстрирую-щий отличие статических курсоров от 
динамических на примере базы данных X_UNIVER.*/

--динамический
set nocount on

declare @One nvarchar(20), @Two nvarchar(20)
declare Local cursor global dynamic for select AUDITORIUM_TYPE, AUDITORIUM_CAPACITY from AUDITORIUM

open Local
update AUDITORIUM set AUDITORIUM_CAPACITY = 299 where AUDITORIUM like '423-1%'
print 'изменение'
fetch Local into @One, @Two
while @@FETCH_STATUS = 0
	begin
		print '' + @One + ' ' + @Two
		fetch Local into @One, @Two
	end
close Local

open Local
print ''
print 'изменение2'
fetch Local into @One, @Two
while @@FETCH_STATUS = 0
	begin
		print '' + @One + ' ' + @Two
		fetch Local into @One, @Two
	end
close local
deallocate Local
go
update AUDITORIUM set AUDITORIUM_CAPACITY = 90 where  AUDITORIUM like '423-1%'

--статический
set nocount on

declare @One nvarchar(20), @Two nvarchar(20)
declare Local cursor local static for select AUDITORIUM_TYPE, AUDITORIUM_CAPACITY from AUDITORIUM

open Local
update AUDITORIUM set AUDITORIUM_CAPACITY = 299 where AUDITORIUM like '423-1%'
print 'изменение'
fetch Local into @One, @Two
while @@FETCH_STATUS = 0
	begin
		print '' + @One + ' ' + @Two
		fetch Local into @One, @Two
	end
close local

open Local
print ''
print 'изменение2'
fetch Local into @One, @Two
while @@FETCH_STATUS = 0
	begin
		print '' + @One + ' ' + @Two
		fetch Local into @One, @Two
	end
close local
go
update AUDITORIUM set AUDITORIUM_CAPACITY = 90 where  AUDITORIUM like '423-1%'

/*Разработать сценарий, демонстрирую-щий свойства навигации в результиру-ющем 
наборе курсора с атрибутом SCROLL на примере базы данных X_UNIVER.*/
deallocate Local

set nocount on

declare @type nvarchar(20), @capacity nvarchar(20)
declare Local cursor global static scroll for select AUDITORIUM_TYPE, AUDITORIUM_CAPACITY from AUDITORIUM

open Local
print 'next: '
fetch Local into @type, @capacity
while @@FETCH_STATUS = 0
	begin
		print '' + @type + ' ' + @capacity
		fetch Local into @type, @capacity
	end
close Local

open Local
print 'первая строка'
fetch first from Local into @type, @capacity
print '' + @type + @capacity

print 'строка из начала т.к. полож(absolute)'
fetch absolute 2 from Local into @type, @capacity
print ''  + @type + @capacity

print 'строка из конца т.к. отр (absolute)'
fetch absolute -5 from Local into @type, @capacity
print ''  + @type + @capacity

print 'вывод строк за текущей (relative)'
fetch relative 2 from Local into @type, @capacity
print ''  + @type + @capacity

print 'след строка'
fetch next from Local into @type, @capacity
print ''  + @type + @capacity

print 'строка перелд текущей'
fetch prior from Local into @type, @capacity
print ''  + @type + @capacity

print 'последняя строка'
fetch last from Local into @type, @capacity
print ''  + @type + @capacity

close Local
go

/*Создать курсор, демонстрирующий применение конструкции CURRENT OF в секции WHERE с
использованием операторов UPDATE и DELETE.*/
set nocount on;

declare @Sub nvarchar(10), @Sub_Name nvarchar(30);
declare currentOf cursor global dynamic for select SUBJECT, SUBJECT_NAME from SUBJECT for update

open currentOf 
fetch currentOf into @Sub, @Sub_Name
while @@FETCH_STATUS = 0
	begin
		if @Sub like 'ÁÄ%' update SUBJECT set SUBJECT_NAME = 'Ñàìûé êëàññíûé ïðåäìåò â ìîåé æèçíè' where current of currentOf
		print '' + @Sub + ' ' + @Sub_Name
		fetch currentOf into @Sub, @Sub_Name
	end
close currentOf
deallocate currentOf

select SUBJECT[предмет], SUBJECT_NAME[имя] from SUBJECT
go

update SUBJECT set SUBJECT_NAME = 'Áàçû äàííûõ' where SUBJECT_NAME = 'Ñàìûé êëàññíûé ïðåäìåò â ìîåé æèçíè'

/*Разработать SELECT-запрос, с помо-щью которого из таблицы PROGRESS удаляются 
строки, содержащие ин-формацию о студентах, получивших оценки ниже 4 (использовать 
объеди-нение таблиц PROGRESS, STUDENT, GROUPS). */
declare @Note int, @Name nvarchar(50), @Faculty nvarchar(20);
declare Goodbye cursor dynamic global for select PROGRESS.NOTE, STUDENT.NAME, GROUPS.FACULTY
										  from PROGRESS inner join STUDENT on PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
										  inner join  GROUPS on STUDENT.IDGROUP = GROUPS.IDGROUP

open Goodbye
fetch Goodbye into @Note, @Name, @Faculty
while @@FETCH_STATUS = 0
	begin
		print 'Оценка ' + cast(@Note as nvarchar(10)) + ' - ' + @Name + ' - ' + @Faculty
		fetch Goodbye into @Note, @Name, @Faculty

		if @Note <4 
		delete PROGRESS where current of Goodbye

		if
		@Note <4 delete STUDENT where current of Goodbye

		if
		@Note <4 delete GROUPS where current of Goodbye
	end
close Goodbye
deallocate Goodbye
go
/*Разработать SELECT-запрос, с по-мощью которого в таблице PROGRESS для студента с 
конкретным номером IDSTUDENT корректируется оценка (увеличивается на единицу).*/
declare @Subject nvarchar(10), @IDStudent int, @Note int
declare Task6 cursor global dynamic for select SUBJECT, IDSTUDENT, NOTE
										from PROGRESS for update

open Task6
fetch Task6 into @Subject, @IDStudent, @Note
while @@FETCH_STATUS = 0
	begin
		print @Subject + ' ' +cast(@IDStudent as nvarchar(10)) + ' ' + cast(@Note as nvarchar(20)) -- ïðåîáðàçîâàíèå òèïîâ äàííûõ
		if @IDStudent = 1021 update PROGRESS set NOTE = NOTE + 1 where current of Task6
		fetch Task6 into @Subject, @IDStudent, @Note
	end
close Task6
deallocate Task6

select SUBJECT[предмет], IDSTUDENT[Id], NOTE[оценка] from PROGRESS
go

update PROGRESS set NOTE = 9 where IDSTUDENT = 1021