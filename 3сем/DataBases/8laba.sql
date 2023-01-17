--1
declare @a char='abc',
		@b varchar='qwe',
		@c datetime,
		@d time,
		@e int,
		@f smallint,
		@g tinyint,
		@h numeric(12,5);
set @c=getdate();
set @d=(select convert(varchar(12),getdate(),114) 'hh:mi:ss:mmm');
select @e=1532,
		@f=21,
		@g=1;
select @a 'строка', @b 'вар строка', @c 'дата',@d 'время';
print 'целое '+cast(@e as varchar(10));
print 'целое малое '+cast(@f as varchar(10));
print 'очень малое целое '+cast(@g as varchar(10));
print 'нумерик '+cast(@h as varchar(10));

--2
/*Разработать скрипт, в котором опреде-ляется общая вместимость а
удиторий. Когда общая вместимость превышает 200, то вывести 
количество аудиторий, среднюю вместимость аудиторий, коли-чество 
аудиторий, вместимость которых меньше средней, и процент таких 
ауди-торий. Когда общая вместимость ауди-торий меньше 200, то 
вывести сообще-ние о размере общей вместимости*/
use UNIVER;
declare @capacity int=(select cast(sum(AUDITORIUM_CAPACITY) as int) from AUDITORIUM),
	@total int,
	@avgCap int,
	@numLessAvg int,
	@prcent numeric(4,2);
if @capacity>200
begin
	select @total=(select cast(count(*) as int)from AUDITORIUM),
			@avgCap=(select avg(AUDITORIUM_CAPACITY)from AUDITORIUM),
			@numLessAvg=(select cast(count(*) as int) from AUDITORIUM where AUDITORIUM_CAPACITY<@avgCap),
			@prcent=@numLessAvg*100/@total;
	select @total 'колво аудиторий', @avgCap 'ср знач', 
		@numLessAvg 'чисто ауд с вместимостью меньшей ср',
		@prcent'процент ауд с вмест меньше ср'
	end
	else select @capacity'вместимость аудитории'

/*вывод глобальных переменных*/
print 'число обработанных строк'+cast(@@ROWCOUNT  as varchar)
print 'версия SQL Server'+cast(@@VERSION   as varchar)
print 'системный id процесса у текущего подключения'+cast(@@SPID   as varchar)
print 'код посл ошибки'+cast(@@ERROR   as varchar)
print 'имя сервака'+cast(@@SERVERNAME   as varchar)
print 'lvl вложенности транзакции'+cast(@@TRANCOUNT   as varchar)
print 'проверка результата считывания строк результирующего набора'+cast(@@FETCH_STATUS   as varchar)
print 'lvl вложенности текущей процедуры'+cast(@@NESTLEVEL   as varchar)

/*скрипт выполняющий:
 вычисление значений переменной zдля различных значений исходных дан-ных;
 преобразование полного ФИО сту-дента в сокращенное (например, Макей-чик Татьяна Леонидовна в Макейчик Т. Л.);
 поиск студентов, у которых день рождения в следующем месяце, и 
опре-деление их возраста;
 поиск дня недели, в который сту-денты некоторой группы сдавали 
экза-мен по СУБД.
*/
declare @tmp float,@t int =14,@x int =3;
if @t>@x
	set @tmp=power(sin(@t),2)
else if @t<@x
	set @tmp=4*(@t+@x)
else
	set @tmp=1-exp(@x-2)
select @tmp

declare @lName nvarchar(20)='Сеницин',
		@fName nvarchar(20)='Глеб',
		@surname nvarchar(20)='Анатольевич',
		@long nvarchar(20),
		@short nvarchar(20);
set @long=@lName+' '+@fName+' '+@surname;
set @fName=SUBSTRING(@fname,1,1);
set @lName=SUBSTRING(@lName,1,1);
set @surname=substring(@surname,1,1);
set @short=@lName+' '+@fName+' '+@surname;
select @long 'полное',@short'сокращённое';

select STUDENT.NAME,STUDENT.BDAY,(datediff(YY,STUDENT.BDAY,sysdatetime())) as 'ДР'
	from STUDENT
	where MONTH(STUDENT.BDAY)=month(sysdatetime())-1;

declare @grNum int=3;
select distinct PROGRESS.PDATE[день сдачи], case
	when DATEPART(dw,PROGRESS.PDATE)=1 then 'пн'
	when DATEPART(dw,PROGRESS.PDATE)=2 then 'вт'
	when DATEPART(dw,PROGRESS.PDATE)=3 then 'ср'
	when DATEPART(dw,PROGRESS.PDATE)=4 then 'чт'
	when DATEPART(dw,PROGRESS.PDATE)=5 then 'пт'
	when DATEPART(dw,PROGRESS.PDATE)=6 then 'сб'
	when DATEPART(dw,PROGRESS.PDATE)=7 then 'вс'
end [хз]
from GROUPS inner join STUDENT on STUDENT.IDGROUP=GROUPS.IDGROUP
	inner join PROGRESS on STUDENT.IDSTUDENT=PROGRESS.IDSTUDENT
	where GROUPS.IDGROUP=@grNum

/*Продемонстрировать конструкцию IF… ELSE на примере анализа данных 
таб-лиц базы данных Х_UNIVER.*/
declare @am int=(select count(*) from AUDITORIUM)
	if @am>=10
	BEGIN
		print 'больше или равно 10'
	end;
	begin
		print 'меньше 10'
	end;

/*Разработать сценарий, в котором с по-мощью CASE анализируются 
оценки, полученные студентами некоторого фа-культета при сдаче 
экзаменов.*/
select(case
	when NOTE between 0 and 3 then '0-3'
	when NOTE between 4 and 5 then '4-5'
	when NOTE between 6 and 7 then '6-7'
	when NOTE between 8 and 10 then '8-10'
end) оценки,count(*)[колво] from PROGRESS
group by(case
	when NOTE between 0 and 3 then '0-3'
	when NOTE between 4 and 5 then '4-5'
	when NOTE between 6 and 7 then '6-7'
	when NOTE between 8 and 10 then '8-10'
end)

/*Создать временную локальную таблицу из трех столбцов и 10 строк, 
заполнить ее и вывести содержимое. Использовать оператор WHILE.*/
create table #TestTbl(целое int, строка nvarchar(50));
set nocount on;
declare @i int=1;
while @i<11
begin
	insert into #TestTbl values (cast(@i as int),replicate('a ',@i))
	set @i+=1;
end
select * from #TestTbl
order by целое desc
go
drop table #TestTbl;

/*Разработать скрипт, демонстрирующий использование оператора RETURN. */
declare @t int=1
	print @t+1
	print @t+2
return
	print @t+8

/*Разработать сценарий с ошибками, в ко-тором используются для обработки 
ошибок блоки TRY и CATCH. Приме-нить функции ERROR_NUMBER (код последней 
ошибки), ERROR_ES-SAGE (сообщение об ошибке), ERROR_LINE (код последней 
ошибки), ER-ROR_PROCEDURE (имя процедуры или NULL), ERROR_SEVERITY (уровень 
серьезности ошибки), ERROR_ STATE (метка ошибки).*/
begin try
	update PROGRESS set NOTE='abc' where NOTE=9
end try
begin catch
	print ERROR_NUMBER()--код ерр
	print ERROR_MESSAGE()--сообщение
	print ERROR_LINE()--стр
	print ERROR_PROCEDURE()--имя процедуры\null
	print ERROR_SEVERITY()--серьёзность
	print ERROR_STATE()--метка
end catch

