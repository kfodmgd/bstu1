use UNIVER;

/*����������� ������������� � ������ �������-������. ������������� 
������ ���� ��������� �� ������ SELECT-������� � ������� TEACH-ER � 
��������� ��������� �������: ��� (TEACHER), ��� ������������� 
(TEACHER_NAME), ��� (GENDER), ��� ������� (PULPIT). */
go
create view [�������������]
	as select TEACHER[�������],
			  TEACHER_NAME[���],
			  GENDER[���],
			  PULPIT[��� �������] from TEACHER;

go
select * from �������������;
select * from ������������� order by [���];

go
alter view [�������������]
	as select TEACHER_NAME[���],
			  GENDER[���],
			  PULPIT[��� �������] from TEACHER;
go
select * from [�������������]
drop view [�������������];

/*����������� � ������� ������������� � ������ ���������� ������. 
������������� ������ ���� ��������� �� ������ SELECT-������� � 
�������� FACULTY � PULPIT*/
go
create view [����� ������]
	as select FACULTY.FACULTY_NAME[��� ����������],
			  count(*)[����� ������]
			  from FACULTY join PULPIT
				on FACULTY.FACULTY=PULPIT.FACULTY
				group by FACULTY.FACULTY_NAME;
go
select * from [����� ������];

/*����������� � ������� ������������� � ������ ���������. 
������������� ������ ���� ��-������� �� ������ ������� AUDITORIUM � 
��������� �������: ��� (AUDITORIUM), ������������ ��������� 
(AUDITORI-UM_NAME). */
go
alter view [���������](���, ���, ���)
	as select AUDITORIUM[���],
			  AUDITORIUM_NAME[���],
			  AUDITORIUM_TYPE[���] from AUDITORIUM
			  where AUDITORIUM.AUDITORIUM_TYPE like '��%';
go
select * from [���������];
insert ��������� values('210-3','210-3','��');

/*����������� � ������� ������������� � ������ ����������_���������. 
������������� ������ ���� ��������� �� ������ SELECT-������� � 
������� AUDITO-RIUM � ��������� ��������� �������: ��� (AUDITORIUM), 
������������ ��������� (AUDITORIUM_NAME). 
������������� ������ ���������� ������ ���������� ��������� (� 
������� AUDITO-RIUM_TYPE ������, ������������ � �����-��� ��). 
���������� INSERT � UPDATE ���������-��, �� � ������ �����������, 
����������� ��-���� WITH CHECK OPTION. */
go
alter view [����������_���������](���, ���, ���)
	as select AUDITORIUM[���],
			  AUDITORIUM_NAME[���],
			  AUDITORIUM_TYPE[���] from AUDITORIUM
			  where AUDITORIUM.AUDITORIUM_TYPE like '��%' with check option;
go
select * from ����������_���������;
insert ����������_��������� values('210-4','210-4','��');

/*5. ����������� ������������� � ������ ���-�������. ������������� 
������ ���� ��-������� �� ������ SELECT-������� � ������� SUBJECT, 
���������� ��� ���������� � ��-�������� ������� � ��������� 
��������� �������: ��� (SUBJECT), ������������ ���-������� 
(SUBJECT_NAME) � ��� ������� (PULPIT). ������������ TOP � ORDER BY.
*/
go
alter view [����������]
	as select top 10 SUBJECT[���],
		SUBJECT_NAME[���],
		PULPIT[�������] from SUBJECT
		order by SUBJECT_NAME;
go
select * from ����������;

/*�������� ������������� ����������_������, ��������� � ������� 2 
���, ����� ��� ���� ��������� � ������� ��������. ������������������ 
�������� ������������� ��������-����� � ������� ��������. 
����������: ��-���������� ����� SCHEMABINDING. */
go
alter view [����� ������] with SCHEMABINDING
	as select fc.FACULTY_NAME[���������],
			  count(*) [����� ������]
			  from dbo.FACULTY fc join dbo.PULPIT pl
			  on fc.FACULTY=pl.FACULTY
			  group by fc.FACULTY_NAME;
go
select * from [����� ������];

