/*Разработать хранимую процедуру без параметров с именем PSUBJECT. Процедура 
формирует результи-рующий набор на основе таблицы SUBJECT*/
create procedure PSUBJECT
as
begin
	declare @k int=(select count(*) from SUBJECT);
	select SUBJECT [код], SUBJECT_NAME[дисциплина],PULPIT[кафедра] from SUBJECT;
	return @k;
end;
declare @y int=0;
exec @y=PSUBJECT;
print(' колво предметов =')+cast(@y as varchar(3));
drop procedure PSUBJECT;

/*Изменить процедуру PSUBJECT, созданную в за-дании 1, таким образом, чтобы она принимала два 
па-раметра с именами @p и @c. Параметр @p является входным, имеет тип VARCHAR(20) и значение 
по умолчанию NULL. Параметр @с является выходным, имеет тип INT.*/
go
set QUOTED_IDENTIFIER on
go
alter procedure [dbo].[PSUBJECT] @p varchar(20)=NULL, @c int output
as
begin
	declare @k int=(select count(*) from SUBJECT where PULPIT=@p);
	print 'дисциплина @p ='+@p+',@c='+cast(@c as varchar(3));
	select SUBJECT [код], SUBJECT_NAME[дисциплина],PULPIT[кафедра] from SUBJECT where PULPIT=@p;
	set @c=@@rowcount;
	return @k;
end;
declare @y int=0,@z varchar(20)='ИСиТ', @w int=0
exec @y=PSUBJECT @p=@z,@c=@w output  --вызов фукнкции
print 'кол-во ' +cast(@y as nvarchar)
print'кафедра '+@z+' '+cast(@w as nvarchar)

/*Создать временную локальную таблицу с именем #SUBJECT. Наименование и тип столбцов 
таблицы должны соответствовать столбцам результирующего набора процедуры PSUBJECT, 
разработанной в задании 2. */
create table #subject
(
	subj nvarchar(20),
	subj_name nvarchar(300),
	pulp nvarchar(20)
)
go
alter procedure PSUBJECT @p varchar(20)=null as
begin
	select SUBJECT [код], SUBJECT_NAME[дисциплина],PULPIT[кафедра] from SUBJECT where PULPIT=@p;
end
go
insert #subject exec PSUBJECT @p='ИСиТ'
insert #subject exec PSUBJECT @p='ЛУ'
select * from #subject
drop table #subject;

/*Процедура добавляет строку в таблицу AUDITO-RIUM. Значения столбцов AUDITORIUM, 
AUDI-TORIUM_NAME, AUDITORIUM_CAPACITY и AUDITORIUM_TYPE добавляемой строки задаются 
соответственно параметрами @a, @n, @c и @t*/
go 
create procedure PASUDITORIUM_INSERT @a char(20), @n varchar(50), @c int=0,@t char(10)
as
begin
	begin try
		insert into AUDITORIUM(AUDITORIUM,AUDITORIUM_NAME,AUDITORIUM_CAPACITY,AUDITORIUM_TYPE) values (@a,@n,@c,@t)
		return 1;
	end try
	begin catch
		print cast(error_number() as varchar(10));
		print cast(error_severity() as varchar(6));
		print error_message();
		return -1;
	end catch
end
go

declare @res int
begin tran
	exec @res =PASUDITORIUM_INSERT @a='206-1', @t='ЛК',@c=90,@n='206-1'
	print ' ';
	if @res=1
	print('успешно')
	else print('ошибка')
rollback
declare @res1 int
begin tran
	exec @res1=PASUDITORIUM_INSERT @a='222-1',@t='ЛК-К', @c=30, @n='222-1'
	print ' ';
	if @res1=1
	print('успешно')
	else print ('ошибка')
rollback
drop procedure PASUDITORIUM_INSERT;

/*Разработать процедуру с именем SUBJECT_REPORT, формирующую в стандартный выходной 
поток отчет со списком дисциплин на кон-кретной кафедре. В отчет должны быть 
выведены краткие названия (поле SUBJECT) из таблицы SUBJECT в одну строку через 
запятую (использовать встроенную функцию RTRIM). Процедура имеет входной параметр с 
именем @p типа CHAR(10), кото-рый предназначен для указания кода кафедры.
В том случае, если по заданному значению @p не-возможно определить код кафедры, 
процедура должна генерировать ошибку с сообщением ошибка в пара-метрах. 
*/
go
create procedure SUBJECT_REPORT @p nvarchar(10) as 
begin
	declare @counter int = 0;
	begin try
		declare @sub nvarchar(10), @line_sub nvarchar(500) = ''
		declare Subjects cursor local static for
		select SUBJECT from SUBJECT where PULPIT = @p order by PULPIT
		if not exists (select PULPIT from SUBJECT where PULPIT = @p)
		begin
			raiserror('ошибка', 11, 1);
		end
		else
		begin
			open Subjects
			fetch Subjects into @sub--извлечение строки из серверного курсора
			set @line_sub = trim(@sub)--удал пробелов в начале и конце
			set @counter +=1
			fetch Subjects into @sub
			while @@FETCH_STATUS = 0
			begin
				set @line_sub = '' + trim(@sub) + ', ' + @line_sub
				set @counter +=1
				fetch Subjects into @sub
			end
			print 'Специальность ' + @p + ': ' + @line_sub
			return @counter
		end
	end try
	begin catch
		print 'проверка на ошибки' 
        if error_procedure() is not null   
			print 'Ошибка : ' + error_procedure()
        return @counter
	end catch
end
go

declare @c int
exec @c = Subject_Report @p = 'ИСиТ'
print 'колво дисциплин в отчёте: ' + cast(@c as nvarchar)

drop procedure SUBJECT_REPORT;

/*Процедура добавляет две строки. Первая строка добавляется в таблицу AUDITORIUM_TYPE
Значе-ния столбцов AUDITORIUM_TYPE и AUDITORI-UM_ TYPENAME добавляемой строки 
задаются со-ответственно параметрами @t и @tn. Вторая строка добавляется путем 
вызова процедуры PAUDITORI-UM_INSERT.

Добавление строки в таблицу AUDITORI-UM_TYPE и вызов процедуры PAUDITORI-UM_INSERT 
должны выполняться в рамках одной явной транзакции с уровнем изолированности 
SERI-ALIZABLE. 
*/
go
create procedure PAUDITORIUM_INSERT_TYPE @a_ char(20), @n_ varchar(50), @c_ int = 0, @t_ char(10), @tn_ varchar(50)
as
begin
	declare @err nvarchar(50) = 'ошибка: '
	declare @rez int
		set transaction isolation level serializable
			begin tran
				begin try
					insert into AUDITORIUM_TYPE values (@t_, @tn_)
						exec @rez = PASUDITORIUM_INSERT @a = @a_, @n = @n_, @c = @c_, @t = @t_
						if (@rez = -1)
							begin
								return -1
							end
				end try
				begin catch
					set @err = @err + error_message()
					raiserror(@err, 11, 1)
					rollback
					return -1
				end catch
			commit tran
		return 1
end
go

declare @rez int
begin tran
exec @rez = PAUDITORIUM_INSERT_TYPE @a_ = '208-1', @n_ = '208-1', @c_ = 90, @t_ = '208-1', @tn_ = 'Äëÿ 12 ëàáû' 
print @rez
if @rez = 1
	select * from AUDITORIUM
	select * from AUDITORIUM_TYPE
rollback
go

drop procedure PAUDITORIUM_INSERT_TYPE;




