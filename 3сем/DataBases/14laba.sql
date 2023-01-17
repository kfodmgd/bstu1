/*С помощью сценария, представленного на ри-сунке, создать таблицу TR_AUDIT. Таблица предназначена 
для добавления в нее строк триггерами. 
В столбец STMT триггер должен поместить событие, на которое он среагировал, а в стол-бец TRNAME  
собственное имя. 
*/
drop table TR_AUDIT
create table TR_AUDIT
(
ID int identity, -- номер
STMT varchar(20) check (STMT in ('INS', 'DEL', 'UPD', 'UPD--')), -- DML-оператор
TRNAME varchar(50), -- имя триггера
CC varchar(300) -- коммент
)

/*Разработать AFTER-триггер с именем TR_TEACHER_INS для таблицы TEACHER, реагирующий на событие 
INSERT. Триггер должен записывать строки вводимых данных в таблицу TR_AUDIT. В столбец СС 
помеща-ются значения столбцов вводимой строки. */
--drop trigger TR_TEACHER_INS
drop trigger TR_TEACHER_INS;
go
create trigger TR_TEACHER_INS on TEACHER after insert as
	begin
		declare @code nvarchar(10), @name nvarchar(100), @gender char(1), @pulpit nvarchar(10), @all nvarchar(300) = '', @time datetime
		print 'событие INSERT '
		set @code = rtrim((select TEACHER from inserted))
		set @name = (select TEACHER_NAME from inserted)
		set @gender = (select GENDER from inserted)
		set @pulpit = (select PULPIT from inserted)
		set @time = sysdatetime()
		set  @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20))
		insert into TR_AUDIT (STMT, TRNAME, CC) values
						('INS','TR_TEACHER_INS',@all)
		return
	end
go

insert into TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) values
			('ЖrЛК','Жиляк Надежда Александровна','ж','ИСиТ')

select * from TR_AUDIT

/*Создать AFTER-триггер с именем TR_TEACHER_DEL для таблицы TEA-CHER, реагирующий на событие DELETE. 
Триггер должен записывать строку данных в таблицу TR_AUDIT для каждой удаляемой строки. В столбец 
СС помещаются значения столбца TEACHER удаляемой строки. */
drop trigger TR_TEACHER_DEL
go
create trigger TR_TEACHER_DEL on TEACHER after delete as
begin
	declare @code nvarchar(10), @name nvarchar(100), @gender char(1), @pulpit nvarchar(10), @all nvarchar(300) = '', @time datetime
	print 'удаление '
	set @code = rtrim((select TEACHER from deleted))
	set @name = (select TEACHER_NAME from deleted)
	set @gender = (select GENDER from deleted)
	set @pulpit = (select PULPIT from deleted)
	set @time = sysdatetime()
	set  @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20))
	insert into TR_AUDIT (STMT, TRNAME, CC) values
					('DEL','TR_TEACHER_DEL',@all)
	return
end
go

delete TEACHER where TEACHER_NAME = 'Жиляк Надежда Александровна'
select * from TR_AUDIT

/*Создать AFTER-триггер с именем TR_TEACHER_UPD для таблицы TEA-CHER, реагирующий на событие 
UPDATE. Триггер должен записывать строку данных в таблицу TR_AUDIT для каждой изменяемой строки. В 
столбец СС помещаются значения столбцов изменяемой строки до и после изме-нения.*/
drop trigger TR_TEACHER_UPD
go
create trigger TR_TEACHER_UPD on TEACHER after update as
begin
	declare @code nvarchar(10), @name nvarchar(100), @gender char(1), @pulpit nvarchar(10), @all nvarchar(300) = '', @time datetime
	declare @code1 nvarchar(10), @name1 nvarchar(100), @gender1 char(1), @pulpit1 nvarchar(10), @all1 nvarchar(300) = '', @time1 datetime
	print 'операция UPDATE '
	set @code = rtrim((select TEACHER from inserted))
	set @name = (select TEACHER_NAME from inserted)
	set @gender = (select GENDER from inserted)
	set @pulpit = (select PULPIT from inserted)
	set @time = sysdatetime()
	set @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20)) + '--'

	set @code1 = rtrim((select TEACHER from deleted))
	set @name1 = (select TEACHER_NAME from deleted)
	set @gender1 = (select GENDER from deleted)
	set @pulpit1 = (select PULPIT from deleted)
	set @time1 = sysdatetime()
	set @all1 = @code1 + ' ' + @name1 + ' ' + @gender1 + ' ' + @pulpit1 + ' ' + cast(@time1 as nvarchar(20))

	insert into TR_AUDIT (STMT, TRNAME, CC) values
				('UPD','TR_TEACHER_UPD',@all),
				('UPD--','TR_TEACHER_UPD',@all1)
	return
end
go
update TEACHER set TEACHER = 'ЖиЛК' where TEACHER = 'ЖиЛК'
select * from TR_AUDIT

/*Создать AFTER-триггер с именем TR_TEACHER для таблицы TEACHER, 
реа-гирующий на события INSERT, DELETE, UPDATE. 
Триггер должен записывать строку данных в таблицу TR_AUDIT для каждой 
изменяемой строки. В коде триггера определить событие, активизировавшее 
триггер и поместить в стол-бец СС соответствующую событию информа-цию. 
*/
drop trigger TR_TEACHER

go
create trigger TR_TEACHER on TEACHER after insert, update, delete
as
begin
	declare @code nvarchar(10), @name nvarchar(100), @gender char(1), @pulpit nvarchar(10), @all nvarchar(300) = '', @time datetime
	declare @code1 nvarchar(10), @name1 nvarchar(100), @gender1 char(1), @pulpit1 nvarchar(10), @all1 nvarchar(300) = '', @time1 datetime
	declare @ins int = (select count(*) from inserted), @del int = (select count(*) from deleted)
	if @ins >0 and @del = 0
	begin
		print 'операция Insert'
		set @code = rtrim((select TEACHER from inserted))
		set @name = (select TEACHER_NAME from inserted)
		set @gender = (select GENDER from inserted)
		set @pulpit = (select PULPIT from inserted)
		set @time = sysdatetime()
		set  @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20))
		insert into TR_AUDIT (STMT, TRNAME, CC) values
						('INS','TR_TEACHER',@all)
		return
	end
	else if @ins = 0 and @del>0
	begin
		print 'операция Delete'
		set @code = rtrim((select TEACHER from deleted))
		set @name = (select TEACHER_NAME from deleted)
		set @gender = (select GENDER from deleted)
		set @pulpit = (select PULPIT from deleted)
		set @time = sysdatetime()
		set  @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20))
		insert into TR_AUDIT (STMT, TRNAME, CC) values
						('DEL','TR_TEACHER',@all)
	return
	end
	else if @ins>0 and @del>0
	begin
		print 'операция Update '
		set @code = rtrim((select TEACHER from inserted))
		set @name = (select TEACHER_NAME from inserted)
		set @gender = (select GENDER from inserted)
		set @pulpit = (select PULPIT from inserted)
		set @time = sysdatetime()
		set @all = @code + ' ' + @name + ' ' + @gender + ' ' + @pulpit + ' ' + cast(@time as nvarchar(20)) + '--'

		set @code1 = rtrim((select TEACHER from deleted))
		set @name1 = (select TEACHER_NAME from deleted)
		set @gender1 = (select GENDER from deleted)
		set @pulpit1 = (select PULPIT from deleted)
		set @time1 = sysdatetime()
		set @all1 = @code1 + ' ' + @name1 + ' ' + @gender1 + ' ' + @pulpit1 + ' ' + cast(@time1 as nvarchar(20))

		insert into TR_AUDIT (STMT, TRNAME, CC) values
						('UPD','TR_TEACHER',@all),
						('UPD--','TR_TEACHER',@all)
	return
	end
end
go

insert into TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) values
			('ЖqЛК','Жиляк Надежда Александровна','ж','ИСиТ')
update TEACHER set TEACHER = 'ЖrЛК' where TEACHER = 'ЖrЛК'
delete TEACHER where TEACHER = 'ЖиЛК'

select * from TR_AUDIT

delete TR_AUDIT

/*Разработать сценарий, который демонстрирует на примере базы данных 
X_UNIVER, что про-верка ограничения целостности выполняется до срабатывания 
AFTER-триггера.*/
insert into TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) values
			('ЖрЛК','Жиляк Надежда Александровна','ж','ИСиТ')

select * from TR_AUDIT

/*Создать для таблицы TEACHER три AFTER-триггера с именами: 
TR_TEACHER_ DEL1, TR_TEACHER_DEL2 и TR_TEA-CHER_ DEL3. Триггеры должны 
реагировать на событие DELETE и формировать соответствующие строки в таблицу 
TR_AUDIT.  Получить список триггеров таблицы TEACHER. 
Упорядочить выполнение триггеров для таблицы TEACHER, реагирующих на 
событие DELETE следующим образом: первым должен выполняться триггер с 
именем TR_TEA-CHER_DEL3, последним – триггер TR_TEACHER_DEL2. 
*/
go
create trigger TR_TEACHER_DEL1 on TEACHER after delete as
begin
	print 'удалить 1' 
	declare @a nvarchar(50) = (select TEACHER from deleted)
	insert into TR_AUDIT values
		('DEL','TR_TEACHER_DEL1',@a)
end
go

go
create trigger TR_TEACHER_DEL2 on TEACHER after delete as
begin
	print 'удалить 2' 
	declare @a nvarchar(50) = (select TEACHER from deleted)
	insert into TR_AUDIT values
	('DEL','TR_TEACHER_DEL2',@a)
end
go

go
create trigger TR_TEACHER_DEL3 on TEACHER after delete as
begin
	print 'удалить 3' 
	declare @a nvarchar(50) = (select TEACHER from deleted)
	insert into TR_AUDIT values
	('DEL','TR_TEACHER_DEL3',@a)
end
go

exec  SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL1', @order = 'None', @stmttype = 'DELETE';
exec  SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL2', @order = 'Last', @stmttype = 'DELETE';
exec  SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL3', @order = 'First', @stmttype = 'DELETE';

insert into TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) values
			('ЖиЛК','Жиляк Надежда Александровна','ж','ИСиТ')
delete TEACHER where TEACHER = 'ЖиЛК'

select * from TR_AUDIT

select t.name, e.type_desc 
from sys.triggers  t join  sys.trigger_events e  
on t.object_id = e.object_id  
where OBJECT_NAME(t.parent_id) = 'TEACHER' and e.type_desc = 'DELETE' ;

/*Разработать сценарий, демонстрирующий на примере базы данных X_UNIVER 
утвержде-ние: AFTER-триггер является частью транзак-ции, в рамках которого 
выполняется оператор, активизировавший триггер.*/
drop trigger TRTASK7

go
create trigger TRTASK7 on TEACHER after insert, delete, update as
begin
	declare @count int = (select count(*) from TEACHER)
	if (@count>10)
		begin
			raiserror('общее колво не может быть больше 10',10,1)
			rollback
		end
	return
end
go

insert into TEACHER (TEACHER, TEACHER_NAME, GENDER, PULPIT) values
			('ЖиЛК','Жиляк Надежда Александровна','ж','ИСиТ')

/*Для таблицы FACULTY создать INSTEAD OF-триггер, запрещающий удаление 
строк в таблице. 
Разработать сценарий, который демонстри-рует на примере базы данных 
X_UNIVER, что проверка ограничения целостности выполнена, если есть 
INSTEAD OF-триггер.
С помощью оператора DROP удалить все DML-триггеры, созданные в этой 
лабораторной работе.
*/
drop trigger InsteadOf

go
create trigger InsteadOf on TEACHER instead of delete as
begin
	raiserror(N'запрещено!',10,1)
	return
end
go

delete TEACHER
select * from TEACHER

delete TEACHER where TEACHER = 'ЖиЛК'

/*Создать DDL-триггер, реагирующий на все DDL-события в БД UNIVER. Триггер 
должен запрещать создавать новые таблицы и удалять существующие. Свое 
выполнение триггер дол-жен сопровождать сообщением, которое со-держит: тип 
события, имя и тип объекта, а так-же пояснительный текст, в случае 
запрещения выполнения оператора. */
drop trigger TR_UNIVERSITY

go
create trigger TR_UNIVERSITY on database for DDL_DATABASE_LEVEL_EVENTS as
	declare @t1 varchar(50), @t2 varchar(50), @t3 varchar(50)
	set @t1 = EVENTDATA().value('(/EVENT_INSTANCE/EventType)[1]','varchar(50)')
	set @t2 = EVENTDATA().value('(/EVENT_INSTANCE/ObjectName)[1]','varchar(50)')
	set @t3 = EVENTDATA().value('(/EVENT_INSTANCE/ObjectType)[1]','varchar(50)')

	print 'тип события: ' + @t1;
	print 'имя объекта: ' + @t2;
	print 'тип объекта: ' + @t3;

	raiserror ('операции запрещены',10,1)
rollback
return
go

drop table NewTable;

create table NewTable
(
id int primary key,
vasilisa varchar(300)
);

select * from NewTable;
drop table NewTable;