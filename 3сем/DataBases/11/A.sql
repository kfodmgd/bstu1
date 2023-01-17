create table Transactions
(
	Counter int identity(1,1),
	Info nvarchar(20)
)
insert Transactions values ('число 1'),('число 2'),('число 3'),('число 4')

--1
/*Разработать два сценария A и B на примере базы данных X_UNIVER. 
Сценарий A представляет со-бой явную транзакцию с уров-нем изолированности READ 
UNCOMMITED, сценарий B – явную транзакцию с уровнем изолированности READ COM-MITED 
(по умолчанию). 
*/
set transaction isolation level read uncommitted
begin tran
select * from Transactions
select count(*) from Transactions
--t1
select count(*) from Transactions
select * from Transactions
commit
--t2

--2
/*Сценарии A и В  представля-ют собой явные транзакции с уровнем изолированности 
READ COMMITED. 
Сценарий A должен демон-стрировать, что уровень READ COMMITED не допускает 
не-подтвержденного чтения, но при этом возможно неповторя-ющееся и фантомное чтение.
*/
set transaction isolation level read committed
begin tran
select * from Transactions
select count(*) from Transactions
--t1
select * from Transactions
select count(*) from Transactions
commit
--t2
update Transactions set Info = 'оценка 4' where Counter = 4
delete from Transactions where Info = 'цифра 5'

--3
/*Сценарий A представляет со-бой явную транзакцию с уров-нем изолированности 
RE-PEATABLE READ. Сценарий B – явную транзакцию с уровнем изолированности READ 
COM-MITED. 
Сценарий A должен демон-стрировать, что уровень REAPETABLE READ не допус-кает 
неподтвержденного чтения и неповторяющегося чтения, но при этом возможно фантомное 
чтение. 
*/
set transaction isolation level repeatable read
begin tran
select * from Transactions
select count(*) from Transactions
--t1
select * from Transactions
select count(*) from Transactions
commit
--
delete from Transactions where Info = 'оценка 5'
--t2

--4
/*Сценарий A представляет со-бой явную транзакцию с уров-нем изолированности 
SERIAL-IZABLE. 
Сценарий A должен демон-стрировать отсутствие фантом-ного, неподтвержденного и 
не-повторяющегося чтения.*/
set transaction isolation level serializable
begin tran
select * from Transactions
select count(*) from Transactions
--t1
select * from Transactions
select count(*) from Transactions
commit
--t2