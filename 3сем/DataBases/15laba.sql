/*Разработать сценарий создания XML-документа в режиме PATH из таблицы TEACHER для преподавателей 
кафедры ИСиТ. */
select TEACHER [препод], TEACHER_NAME [имя], GENDER [пол], PULPIT [кафедра] from TEACHER
where PULPIT = 'ИСиТ'
for xml path('препод'), root('списокПреподов'), elements

/*Разработать сценарий создания XML-документа в режиме AUTO на основе SELECT-запроса к таблицам 
AUDITORIUM и AUDI-TORIUM_TYPE, который содержит следую-щие столбцы: наименование аудитории, 
наиме-нование типа аудитории и вместимость. Найти только лекционные аудитории. */
select AUDITORIUM_TYPE.AUDITORIUM_TYPENAME [имяАуд],
		  AUDITORIUM.AUDITORIUM_NAME [НазвАуд],
		  AUDITORIUM.AUDITORIUM_CAPACITY [вместимостьАуд]
		  from AUDITORIUM
		  inner join AUDITORIUM_TYPE on AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE
where AUDITORIUM_TYPE.AUDITORIUM_TYPE like '%ЛК%'
order by [ИмяАуд]
for xml auto, root('списокАуд'), elements

/*Разработать XML-документ, содержащий дан-ные о трех новых учебных дисциплинах, кото-рые следует 
добавить в таблицу SUBJECT. 
Разработать сценарий, извлекающий данные о дисциплинах из XML-документа и добавля-ющий их в таблицу 
SUBJECT. 
При этом применить системную функцию OPENXML и конструкцию INSERT… SELECT. 
*/
declare @xmlHandle int = 0,
      @xml varchar(2000) = '<?xml version="1.0" encoding="windows-1251" ?>
					<SUBJECTS> 
						<SUBJECT SUBJECT="БД" SUBJECT_NAME="Базы данных" PULPIT="ИСиТ" /> 
						<SUBJECT SUBJECT="ЛВ" SUBJECT_NAME="Лесоводство" PULPIT="ЛЗиДВ" /> 
						<SUBJECT SUBJECT="ЭП" SUBJECT_NAME="Экономика природопользования" PULPIT="МиЭП"  />  
					</SUBJECTS>'
exec sp_xml_preparedocument @xmlHandle output, @xml
select * from openxml(@xmlHandle, '/SUBJECTS/SUBJECT', 0)
	with(SUBJECT char(10), SUBJECT_NAME varchar(100), PULPIT char(20))       

begin tran
insert into SUBJECT select * from openxml(@xmlHandle, '/SUBJECTS/SUBJECT', 0)
	with(SUBJECT char(10), SUBJECT_NAME varchar(100), PULPIT char(20)) 
select * from SUBJECT where SUBJECT LIKE '%Í'
rollback tran
exec sp_xml_removedocument @xmlHandle

select * from SUBJECT

/*Используя таблицу STUDENT разработать XML-структуру, содержащую паспортные данные студента: 
серию и номер паспорта, личный номер, дата выдачи и адрес прописки. 
Разработать сценарий, в который включен оператор INSERT, добавляющий строку с XML-столбцом.
Включить в этот же сценарий оператор UPDATE, изменяющий столбец INFO у одной строки таблицы 
STUDENT и оператор SELECT, формирующий результирующий набор, аналогичный представленному на 
рисунке. 
В SELECT-запросе использовать методы QUERY и VALUEXML-типа.*/
begin tran
insert into dbo.STUDENT (IDGROUP,NAME,BDAY,INFO)
	values (	1, 'Qwe afda dsgsd', '1994-07-12', 
	'<студент>
		<паспорт серия="AB" номер="1111111"дата="05.09.2017"/>
		<телефон>1234567</телефон>
		<адрес>
			<студент>беларусь</студент>
			<город>минск</город>
			<улица>свердлова</улица>
			<дом>13</дом>
			<квартира>156</квартира>
		</адрес>
	</студент>');
update STUDENT set INFO=	
'<студент>
		<паспорт серия="MP" номер="1234567"дата="15.10.2007"/>
		<телефон>1234567</телефон>
		<адрес>
			<студент>беларусь</студент>
			<город>гродно</город>
			<улица>свердлова</улица>
			<дом>45</дом>
			<квартира>789</квартира>
		</адрес>
	</студент>' where INFO.value('(студент/адрес/город)[1]','varchar(10)')='минск';
select IDGROUP,NAME,BDAY, 
INFO.value('(/студент/паспорт/@серия)[1]','varchar(10)') [серия],
INFO.value('(/студент/паспорт/@номер)[1]', 'varchar(10)') [номер],
INFO.query('/студент/город')[город]
from  STUDENT;
rollback

/*Изменить (ALTER TABLE) таблицу STUDENT в базе данных UNIVER таким образом, 
чтобы значения типизированного столбца с именем INFO контролировались 
коллекцией XML-схем (XML SCHEMACOLLECTION), представленной в правой части. 
Разработать сценарии, демонстрирующие ввод и корректировку данных (операторы 
INSERT и UPDATE) в столбец INFO таблицы STUDENT, как содержащие ошибки, так и 
правильные.
Разработать другую XML-схему и добавить ее в коллекцию XML-схем в БД UNIVER.*/
drop xml schema collection Student;

begin tran
create xml schema collection Student as 
N'<?xml version="1.0" encoding="utf-16" ?>
<xs:schema attributeFormDefault="unqualified" 
   elementFormDefault="qualified"
   xmlns:xs="http://www.w3.org/2001/XMLSchema">
<xs:element name="студент">
<xs:complexType><xs:sequence>
<xs:element name="паспорт" maxOccurs="1" minOccurs="1">
  <xs:complexType>
    <xs:attribute name="серия" type="xs:string" use="required" />
    <xs:attribute name="номер" type="xs:unsignedInt" use="required"/>
    <xs:attribute name="дата"  use="required"  >
	<xs:simpleType>  <xs:restriction base ="xs:string">
		<xs:pattern value="[0-9]{2}.[0-9]{2}.[0-9]{4}"/>
	 </xs:restriction> 	</xs:simpleType>
     </xs:attribute>
  </xs:complexType>
</xs:element>
<xs:element maxOccurs="3" name="номер" type="xs:unsignedInt"/>
<xs:element name="адрес">   <xs:complexType><xs:sequence>
   <xs:element name="студент" type="xs:string" />
   <xs:element name="город" type="xs:string" />
   <xs:element name="улица" type="xs:string" />
   <xs:element name="дом" type="xs:string" />
   <xs:element name="квартира" type="xs:string" />
</xs:sequence></xs:complexType>  </xs:element>
</xs:sequence></xs:complexType>
</xs:element></xs:schema>'

alter table STUDENT 
alter column INFO xml(Student)

begin tran
insert into STUDENT (IDGROUP,NAME,BDAY,INFO)
values (	1,
			'Альбина Иванова Ивановна', '1978-07-28',
'<студент>
<паспорт серия="CI" номер="1111111" дата="05.09.2017"/>
<номер>1234567</номер>
<адрес>
       <студент>беларусь</студент>
       <город>Минск</город>
       <улица>черыбряка</улица>
       <дом>330</дом>
       <квартира>18</квартира>
</адрес>
</студент>')

update STUDENT set INFO= '
<студент>
	<паспорт серия="MP" номер="1234567" дата="13.03.2022"/>
	<номер>1234567</номер>
	<адрес>
		   <студент>беларусь</студент>
		   <город>гомель</город>
		   <улица>некая</улица>
		   <дом>21</дом>
		   <квартира>414</квартира>
	</адрес>
</студент>' where INFO.value('(студент/адрес/город)[1]','varchar(10)')='минск';

select IDGROUP,NAME,BDAY, 
INFO.value('(/студент/адрес/студент)[1]','varchar(10)') [студент],
INFO.query('/студент/адрес')[адрес]
from  STUDENT;
rollback