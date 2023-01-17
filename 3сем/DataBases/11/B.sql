--1
set transaction isolation level read committed
begin tran
update Transactions set Info = 'число 6' where Counter = 4
insert Transactions values ('цифра 5')
--t1
rollback tran
--t2

--2
set transaction isolation level read committed
begin tran
update Transactions set Info = 'оценка 6' where Counter = 4
insert Transactions values ('цифра 5')
--t1
commit tran
--t2

--3
set transaction isolation level read committed
begin tran
--update Transactions set Info = 'оценка 6' where Counter = 4
insert Transactions values ('оценка 5')
--t1
commit tran
--t2

--4
/*Сценарий B – явную транзак-цию с уровнем изолированно-сти READ COMMITED.*/
set transaction isolation level read committed
begin tran
insert Transactions values ('оценка 5')
--t1
rollback tran
--t2

