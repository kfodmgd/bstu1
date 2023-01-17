/*����������� ��������� ������� � ������ COUNT_STUDENTS, ������� ��������� ���������� 
���-������ �� ����������, ��� �������� �������� ���������� ���� VARCHAR(20) � ������ 
@faculty. ������������ ���������� ���������� ������ FACULTY, GROUPS, STU-DENT. 
���������� ������ �������.*/
create function Count_Students (@faculty nvarchar(20)) returns int
as
begin
	declare @kolich int;
	set @kolich = (select count(*) from FACULTY
						  join GROUPS on FACULTY.FACULTY = GROUPS.FACULTY 
						  join STUDENT on GROUPS.IDGROUP = STUDENT.IDGROUP
						  where  FACULTY.FACULTY = @faculty)
	return @kolich
end
go

print '����� ��������� �� �������� ��: ' + cast(dbo.Count_Students('��') as nvarchar(20))
select FACULTY, dbo.Count_Students(FACULTY) from FACULTY

/*������ ��������� � ����� ������� � ������� ��������� ALTER � ���, ����� ������� 
��������� ������ �������� @prof ���� VARCHAR(20), ������������ ������������� 
���������. ��� ���������� ���������� �������� �� ������-��� NULL. ���������� ������ 
������� � ������� SE-LECT-��������.*/
go
alter function COUNT_STUDENTS (@faculty nvarchar(20)= null, @prof nvarchar(200) = null) returns int
as
begin
	declare @counter int = 0
	set @counter =
	(select count(STUDENT.IDSTUDENT) from FACULTY
			join GROUPS on FACULTY.FACULTY = GROUPS.FACULTY
			join STUDENT on GROUPS.IDGROUP = STUDENT.IDGROUP
			join PROFESSION on FACULTY.FACULTY = PROFESSION.FACULTY
	where FACULTY.FACULTY = @faculty and PROFESSION.PROFESSION_NAME = @prof)
	return @counter
end
go

select FACULTY.FACULTY, PROFESSION.PROFESSION_NAME,
	   dbo.COUNT_STUDENTS(FACULTY.FACULTY, PROFESSION.PROFESSION_NAME)
	   from FACULTY
	   join PROFESSION on FACULTY.FACULTY = PROFESSION.FACULTY

print '����� ��������� � ��: ' + 
cast(dbo.Count_students('��', '�������������� ������� � �����-�����') as nvarchar(20))

/*����������� ��������� ������� � ������ FSUBJECTS, ����������� �������� @p ���� 
VARCHAR(20), �������� �������� ������ ��� ������� (������� SUBJECT.PULPIT). 
������� ������ ���������� ������ ���� VARCHAR(300) � �������� ��������� � ������. 
*/
go
create function fsubjects (@p nvarchar(20)) returns nvarchar(300) as
begin
	declare @word nvarchar(10), @string nvarchar(200) = ' ';

	declare fsubj cursor local static
	for select SUBJECT from SUBJECT where PULPIT = @p

	open fsubj
	fetch fsubj into @word
	set @string  = @string + rtrim(@word)
	fetch fsubj into @word
	while @@FETCH_STATUS = 0
		begin
			fetch fsubj into @word
			set @string  =@string  + ', ' + rtrim(@word)
		end
	close fsubj
	return @string
end
go

select PULPIT, dbo.fsubjects(PULPIT) [����������] from SUBJECT group by PULPIT

/*����������� ��������� ������� FFACPUL, ���������� ������ ������� ������������������ 
�� ������� ����. 
������� ��������� ��� ���������, �������� ��� ��-�������� (������� FACULTY.FACULTY) � 
��� ������� (������� PULPIT.PULPIT). ���������� SELECT-������ c ����� ������� 
����������� ����� ��������� FACULTY � PULPIT. 
*/
create function ffacpul (@ff nvarchar(20), @pp nvarchar(20)) returns table 
as return
select FACULTY.FACULTY, PULPIT.PULPIT from FACULTY
	   left join PULPIT on FACULTY.FACULTY = PULPIT.FACULTY
where FACULTY.FACULTY = isnull(@ff,FACULTY.FACULTY)
	  and PULPIT.PULPIT = isnull(@pp,PULPIT.PULPIT)
go

select * from dbo.ffacpul (null,null)
select * from dbo.ffacpul ('���',null)
select * from dbo.ffacpul (null,'��')
select * from dbo.ffacpul ('���','��') 

/*������� ��������� ���� ��������, �������� ��� �������. ������� ���������� 
���������� �������������� �� �����-��� ���������� �������. ���� �������� ����� NULL, 
�� ������������ ����� ���������� ��������������. */
drop function fcteacher

go
create function fcteacher (@p nvarchar(20)) returns int as 
begin 
	declare @counter int = (select count(*) from TEACHER
							where PULPIT = isnull(@p,PULPIT))
	return @counter
end
go

select PULPIT, dbo.fcteacher(PULPIT)[����� ��������] from TEACHER group by PULPIT
select dbo.fcteacher(null) [����� ��������]









/*������ �������*/
create function FACULTY_REPORT(@c int) returns @fr table
	                        ( [���������] varchar(50), [���������� ������] int, [���������� �����]  int, 
	                                                                 [���������� ���������] int, [���������� ��������������] int )
	as begin 
                 declare cc CURSOR static for 
	       select FACULTY from FACULTY 
                                                    where dbo.COUNT_STUDENTS(FACULTY, default) > @c; 
	       declare @f varchar(30);
	       open cc;  
                 fetch cc into @f;
	       while @@fetch_status = 0
	       begin
	            insert @fr values( @f,  (select count(PULPIT) from PULPIT where FACULTY = @f),
	            (select count(IDGROUP) from GROUPS where FACULTY = @f),   dbo.COUNT_STUDENTS(@f, default),
	            (select count(PROFESSION) from PROFESSION where FACULTY = @f)   ); 
	            fetch cc into @f;  
	       end;   
                 return; 
	end;


	--���������
	drop function FacultyReport
go
create function StudentCount(@faculty varchar(50)) returns int
as
begin
	 declare @studentCount int  = 0
	 set @studentCount = 
		(select count(*) from STUDENT
				inner join GROUPS on STUDENT.IDGROUP = GROUPS.IDGROUP
				inner join FACULTY on GROUPS.FACULTY = FACULTY.FACULTY
		where FACULTY.FACULTY = @faculty)
	return @studentCount
end
go

go
create function PulpitCount(@faculty varchar(50)) returns int
as
begin
	 declare @pulpitCount int = 0
	 set @pulpitCount = 
		(select count(*) from PULPIT
		 where PULPIT.FACULTY = @faculty)
	return @pulpitCount
end
go

create function ProfessionCount(@faculty varchar(50)) returns int
as
begin
	 declare @professionCount int = 0
	 set @professionCount = 
		(select count(*) from PROFESSION
		where PROFESSION.FACULTY = @faculty)
	return @professionCount
end
go

go
create function GroupCount(@faculty varchar(50)) returns int
as
begin
	declare @groupCount int = 0
	set @groupCount =
		(select count(*) from GROUPS
		where GROUPS.FACULTY = @faculty)
	return @groupCount
end
go

go
create function FacultyReport(@c int)
returns @result table
		(
		[�������������] varchar(50),
		[����� ������] int,
		[����� �����] int,
		[����� ��������������] int,
		[����� ���������] int
		)

as
begin

	declare @faculty varchar(50)
	declare FacultyCursor cursor local for
		select FACULTY from FACULTY
		where dbo.StudentCount(FACULTY) > @c

	open FacultyCursor
		fetch FacultyCursor into @faculty
		while @@FETCH_STATUS = 0
		begin
			insert into @result values
			(@faculty, dbo.PulpitCount(@faculty), dbo.GroupCount(@faculty), dbo.ProfessionCount(@faculty), dbo.StudentCount(@faculty))
			fetch FacultyCursor into @faculty
		end

	close FacultyCursor
	return
end
go	

select * from dbo.FacultyReport(0)