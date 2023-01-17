use master  
go
create database UNIVER 
on primary
( name = N'UNIVER_mdf', filename = N'F:\BD\UNIVER_mdf.mdf', 
   size = 10240Kb, maxsize=UNLIMITED, filegrowth=1024Kb),
( name = N'UNIVER_ndf', filename = N'F:\BD\UNIVER_ndf.ndf', 
   size = 10240KB, maxsize=1Gb, filegrowth=25%),
filegroup FG1
( name = N'UNIVER_fg1_1', filename = N'F:\BD\UNIVER_fgq-1.ndf', 
   size = 10240Kb, maxsize=1Gb, filegrowth=25%),
( name = N'UNIVER_fg1_2', filename = N'F:\BD\UNIVER_fgq-2.ndf', 
   size = 10240Kb, maxsize=1Gb, filegrowth=25%)
log on
( name = N'UNIVER_log', filename=N'F:\BD\UNIVER_log.ldf',       
   size=10240Kb,  maxsize=2048Gb, filegrowth=10%)
go

use UNIVER;
CREATE TABLE AUDITORIUM 
    (AUDITORIUM   char(20)  primary key,              
	 AUDITORIUM_TYPE  char(10), 
     AUDITORIUM_CAPACITY  int default 1 check  (AUDITORIUM_CAPACITY between 1 and 300),  
     AUDITORIUM_NAME  varchar(50)                                     
) on FG1;
go
