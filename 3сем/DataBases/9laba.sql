--кластер
--не кластер-сост, индекс покрытия, фильтруемый


/*С помощью SSMS определить все индексы, которые имеются в БД UNIVER. 
Определить, какие из них являются кластеризованными, а ка-кие 
некластеризованными. 
Создать временную локальную таблицу. Заполнить ее данными (не менее 1000 
строк). 
Разработать SELECT-запрос. По-лучить план запроса и определить его стоимость. 

Создать ..кластеризованный индекс.., уменьшающий стоимость SELECT-запроса.
*/
use UNIVER
exec sp_helpindex 'AUDITORIUM_TYPE'--execute-запуска хранимых процедур и SQL инструкций в виде текстовых строк
--перечень индексов связанных c табл
create table #Test (f int, s varchar(100))
set nocount on;
declare @i int =0
while @i<1000
begin
	insert #Test(f,s) values (floor(20000*RAND()),replicate('a',10));
	if(@i%100=0)print @i;
	set @i=@i+1
end
select * from #Test where f between 1500 and 2500 order by f; 

checkpoint;  --фиксация БД
DBCC DROPCLEANBUFFERS;  --очистить буферный кэш

CREATE clustered index #Test_cl on #Test(f asc)--создание кластеризованного индекса

drop index #Test_cl on #Test
drop table #Test

/*Создать временную локальную таб-лицу. Заполнить ее данными (10000 строк 
или больше). 
Разработать SELECT-запрос. По-лучить план запроса и определить его
стоимость. 
Создать ..некластеризованный не-уникальный составной индекс. ..
Оценить процедуры поиска ин-формации.
*/
create table #test2(tkey int,iterat int identity(1,1),tf varchar(100));
set nocount on;
declare @i int=0;
while @i<20000
begin
	insert #test2(tkey,tf) values(floor(30000*rand()),replicate('str',10));
	set @i=@i+1;
end;

select * from #test2 where tkey=556 and iterat<4500;

checkpoint;
dbcc dropcleanbuffers;
--созд индекса
create index #test2_nocl on #test2(tkey,iterat)

drop index #test2_nocl on #test2
drop table #test2

/*Создать временную локальную таб-лицу. Заполнить ее данными (не ме-нее 
10000 строк). 
Разработать SELECT-запрос. По-лучить план запроса и определить его стоимость. 
Создать ..некластеризованный ин-декс покрытия.., уменьшающий сто-имость SELECT-запроса

включить в состав индексной строки значения одного или нескольких неиндексируемых столбцов
*/
create table #test3(inf nvarchar(20),iterat int identity(1,1),num int)
declare @i int =0;
while @i<10000
begin
	insert into #test3 values (replicate('str',3),floor(30000*rand()))
	set @i+=1
end

select inf from #test3 where iterat>9000

checkpoint;
DBCC DROPCLEANBUFFERS;  --очистить буферный кэш

create index #test3_noIndexPok on #test3(iterat)include (inf) 

drop index #test3_noIndexPok on #test3;
drop table #test3;

/*Создать и заполнить временную ло-кальную таблицу. 
Разработать SELECT-запрос, по-лучить план запроса и определить его 
стоимость. 
Создать ..некластеризованный фильтруемый индекс.., уменьшаю-щий стоимость 
SELECT-запроса.

Если запросы основаны на WHERE-фильтрации строк
*/
create table #test4Filter(inf nvarchar(20),iterat int identity(1,1),num int)
declare @i int=0
while @i<10000
begin
	insert into #test4Filter values (replicate('str',3),floor(30000*rand()))
	set @i+=1
end
create index #test4Where on #test4Filter(iterat) where (iterat>9000);
checkpoint;
DBCC DROPCLEANBUFFERS;  --очистить буферный кэш
select iterat from #test4Filter where iterat>9000;--yup
select iterat from #test4Filter where iterat>8000;--nope
drop index #test4Where on #test4Filter;
drop table #test4Filter;

/*Заполнить временную локальную таблицу. 
Создать некластеризованный ин-декс. Оценить уровень фрагмента-ции индекса. 
Разработать сценарий на T-SQL, выполнение которого приводит к уровню 
фрагментации индекса выше 90%. Оценить уровень фрагмента-ции индекса. 
Выполнить процедуру реоргани-зации индекса, оценить уровень фрагментации. 
Выполнить процедуру пере-стройки индекса и оценить уровень фрагментации 
индекса.
*/
create table #test5(tkey int, cc int identity(1,1), tf varchar(100))
set nocount on
declare @i int = 0
while @i < 10000
begin
	insert #test5(tkey, tf) values (floor(30000*rand()), replicate('str ', 2))
	set @i = @i + 1
end
checkpoint;
DBCC DROPCLEANBUFFERS;  --очистить буферный кэш
create index #test5Key on #test5(tkey);

--получение фрагментации-Процесс образования неиспользуемых фрагментов памяти. 
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
        FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'), 
        OBJECT_ID(N'#test5'), NULL, NULL, NULL) ss
        JOIN sys.indexes ii on ss.object_id = ii.object_id and ss.index_id = ii.index_id WHERE name is not null;
INSERT top(1000000) #test5(tkey, tf) select tkey, tf from #test5;
drop index #test5Key on #test5;
drop table #test5;

--реорганизация
ALTER index #test5Key on #test5 reorganize;
--перестройка
ALTER index #test5Key on #test5 rebuild with (online = off);

/*Разработать пример, демонстриру-ющий применение параметра FILL-FACTOR при 
создании некластери-зованного индекса.*/
drop index #test5Key on #test5;
--fillfactor-процент заполнения индексных стр нижнего lvl
create index #test5Key on #test5(tkey) with fillfactor=65;
insert top(50) percent into #test5(tkey,tf)
	select tkey,tf from #test5;
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
       FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'),    
       OBJECT_ID(N'#EX'), NULL, NULL, NULL) ss  JOIN sys.indexes ii 
		ON ss.object_id = ii.object_id and ss.index_id = ii.index_id WHERE name is not null;

--PAD_INDEX указывает процент, до которого заполняется не листовые индексные страницы.


