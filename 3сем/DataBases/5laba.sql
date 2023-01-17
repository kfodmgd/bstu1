use UNIVER;

/*�� ������ ������ FACULTY, PULPIT � PROFESSION ������������ ������
������������ ������ (������� PUL-PIT_NAME), ������� ��������� �� 
���������� (������� FACULTY), ��������-������ ���������� �� 
�������������, � ������������ (������� PROFESSION_ NAME) �������� 
���������� ����� ���������� ��� ����������.*/
select PULPIT.PULPIT_NAME [�������],FACULTY.FACULTY_NAME[���������], PROFESSION.PROFESSION_NAME [�������������]
	from PULPIT,PROFESSION,FACULTY
	where FACULTY.FACULTY=PULPIT.FACULTY and FACULTY.FACULTY=PROFESSION.FACULTY and 
	PROFESSION_NAME in (select PROFESSION_NAME from PROFESSION where PROFESSION_NAME like '%����������%')

/*���������� ������ ������ 1 ����� �������, ����� ��� �� ��������� 
��� ������� � ����������� INNER JOIN ������ FROM �������� �������. 
��� ���� ��������� ���������� ������� ������ ���� ����������� 
���������� ��������� �������. */
select PULPIT.PULPIT_NAME [�������],FACULTY.FACULTY_NAME[���������], PROFESSION.PROFESSION_NAME [�������������]
	from PULPIT inner join FACULTY on FACULTY.FACULTY=PULPIT.FACULTY 
		inner join PROFESSION on FACULTY.FACULTY=PROFESSION.FACULTY
		where PROFESSION_NAME in (select PROFESSION_NAME from PROFESSION where PROFESSION_NAME like '%����������%')

/*���������� ������, ����������� 1 ����� ��� ������������� 
����������. ����������: ������������ ���������� INNER JOIN ���� 
������*/
select PULPIT.PULPIT_NAME [�������],FACULTY.FACULTY_NAME[���������], PROFESSION.PROFESSION_NAME [�������������]
	from PULPIT inner join FACULTY on FACULTY.FACULTY=PULPIT.FACULTY 
		inner join PROFESSION on FACULTY.FACULTY=PROFESSION.FACULTY
		where PROFESSION_NAME like '%����������%';

/*�� ������ ������� AUDITORIUM ������������ ������ ��������� ����� 
������� ������������ (������� AUDITORIUM_CAPACITY) ��� ������� ����
��������� (AUDITORIUM_TYPE).��� ���� ��������� ������� ������������� 
� ������� �������� �����������. ����������: ������������ 
������������� ��������� c �������� TOP � ORDER BY*/
select AUDITORIUM.AUDITORIUM_CAPACITY,AUDITORIUM.AUDITORIUM_TYPE
	from AUDITORIUM
	where AUDITORIUM_CAPACITY=(select top(1) AUDITORIUM_CAPACITY
	where AUDITORIUM.AUDITORIUM_TYPE=AUDITORIUM.AUDITORIUM_TYPE
	order by AUDITORIUM_CAPACITY desc)

/*�� ������ ������ FACULTY � PULPIT ������������ ������ 
������������ ����������� (������� FACULTY_NAME) �� ������� ��� �� 
����� ������� (������� PULPIT). ����������: ������������ �������� 
EXISTS � ��������������� ���������. */
select FACULTY.FACULTY_NAME from FACULTY
	where exists (select * from PULPIT
	where FACULTY.FACULTY = PULPIT.FACULTY)

/*�� ������ ������� PROGRESS ������������ ������, ���������� 
������� �������� ������ (������� NOTE) �� �����������, ������� 
��������� ����: ����, �� � ����. ����������: ������-������ ��� 
����������������� ���������� � ������ SELECT; � ����������� 
��������� ���������� ������� AVG*/
select top 1
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like '����')[����],
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like '��')[��],
	(select avg(PROGRESS.NOTE) from PROGRESS
		where SUBJECT like '����')[����]
	from PROGRESS

/*����������� SELECT-������, ��������������� ������� ���������� 
ALL ��������� � �����������*/
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM.AUDITORIUM_CAPACITY
FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM_CAPACITY >= all (SELECT AUDITORIUM.AUDITORIUM_CAPACITY 
	FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM like '4%')

/*����������� SELECT-������, ���������-������ ������� ���������� 
ANY ��������� � �����������.*/
SELECT AUDITORIUM.AUDITORIUM, AUDITORIUM.AUDITORIUM_CAPACITY
FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM_CAPACITY >= any (SELECT AUDITORIUM.AUDITORIUM_CAPACITY 
	FROM AUDITORIUM
	WHERE AUDITORIUM.AUDITORIUM like '4%')
