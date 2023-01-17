--Транзакция   это механизм базы данных, позволяющий таким образом объединять 
--несколько операторов, изменяющих базу данных, чтобы при выполнении этой 
--совокупности операторов они или все выполнились или все не выполнились
--атомарность, согласованность, изолированность, долговечность

/*Разработать сценарий, демон-стрирующий работу в режиме неявной транзакции.*/
set nocount on
if exists (select * from sys.objects where OBJECT_ID = object_id(N'dbo.Tabl')) -- существует ли Tabl?
	begin
		drop table Tabl
		print 'таблица удалена'
	end

declare @Kolich int, @flag int = 100 -- commit или rollback?

set implicit_transactions on--вкл режим неявной транзакции
	create table Tabl(Chislo int); --начало транзакции
	insert Tabl values (1),(2),(3),(4)
	set @Kolich = (select count(*) from Tabl)
	print 'количество строк в таблице: ' + cast(@Kolich as nvarchar(10))
	if @flag = 1000 commit--завершение транзакции:фиксация
	else rollback--завершение транзакции:откат
set implicit_transactions off

if exists (select * from sys.objects where OBJECT_ID = object_id(N'dbo.Tabl'))
print 'таблица есть'
else print 'таблицы нет'

drop table Tabl

/*Разработать сценарий, демон-стрирующий свойство атомар-ности явной транзакции 
на примере базы данных X_UNIVER. 
В блоке CATCH предусмот-реть выдачу соответствующих ошибок*/
begin try 
	begin tran--начало явной транзакции
		insert into AUDITORIUM_TYPE(AUDITORIUM_TYPE,AUDITORIUM_TYPENAME) values
		('лк-к      ','test')
		delete from AUDITORIUM_TYPE where AUDITORIUM_TYPE = 'лк-к      '
	commit tran--фиксация транзакции можно rollback
end try
begin catch 
	print 'Error: ' + cast(error_number()as nvarchar(20))
	print error_message()
	if @@TRANCOUNT>0 rollback tran--возвращает уровень вложенности транзакции
end catch
go

/* Разработать сценарий, демон-стрирующий применение опера-тора SAVE TRAN на примере 
базы данных X_UNIVER. */
declare @controlPoint nvarchar(10)--макс длина 10 символов

begin try
	begin tran
		create table #Local (Numbers int primary key)
		insert into #Local values (1),(2),(3),(4),(5),(6),(7),(8),(9)
		set @controlPoint = 'Point1'--контрольная точка 1
		save tran @controlPoint

		insert into #Local values (1),(11),(12)
		select Numbers[числа] from #Local
		rollback tran @controlPoint--откат
		select Numbers[числа] from #Local

		drop table #Local
		save tran @controlPoint
	commit tran--фиксация изменений
end try

begin catch
	print 'Ошибка ' + error_message()
	print 'контрольная точка ' + @controlPoint
	rollback tran @controlPoint
	select * from #Local
	drop table #Local 
end catch
go

/*Разработать сценарий, демон-стрирующий свойства вложен-ных транзакций, на примере 
ба-зы данных X_UNIVER. */
drop table #Task8

begin tran 
	create table #Task8 (Num int identity, Words nvarchar(20))
	insert #Task8 values ('йцу'), ('фыв'), ('ячс')

	begin tran --внутр
		insert #Task8 values ('1 вуцк')
	commit tran --внутр

 if exists (select Words from #Task8 where Words = '1 вуцк')
 commit tran 
 else rollback tran 
 select Num[Id], Words[слова] from #Task8


drop table #Task8_1
begin tran 
	create table #Task8_1(Num int identity, Words nvarchar(20))
	insert #Task8_1 values ('qwerty'), ('asdfg'), ('zxcvb')
	begin tran 
		insert #Task8_1 values ('zxcvbn')
	rollback tran 
 if exists (select Words from #Task8_1 where Words = 'zxcvbn')
 commit tran 
 else rollback tran 
 select Num[Id], Words[слова] from #Task8_1