--1
set transaction isolation level read committed
begin tran
update Transactions set Info = '����� 6' where Counter = 4
insert Transactions values ('����� 5')
--t1
rollback tran
--t2

--2
set transaction isolation level read committed
begin tran
update Transactions set Info = '������ 6' where Counter = 4
insert Transactions values ('����� 5')
--t1
commit tran
--t2

--3
set transaction isolation level read committed
begin tran
--update Transactions set Info = '������ 6' where Counter = 4
insert Transactions values ('������ 5')
--t1
commit tran
--t2

--4
/*�������� B � ����� �������-��� � ������� ������������-��� READ COMMITED.*/
set transaction isolation level read committed
begin tran
insert Transactions values ('������ 5')
--t1
rollback tran
--t2

