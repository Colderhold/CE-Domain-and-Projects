create table empnew
(empno int primary key,
ename varchar(10),
job varchar(10),
mgr int,
hiredate date,
sal int,
comm int,
DEPTno int
 );



create table DEPTtest
(DEPTno int primary key,
dname varchar(14),
loc varchar(13)
)


insert into empnew
values(7369,'SMITH','CLERK',7902,'17-DEC-1980',800,NULL,20);

insert into empnew
values(7499,'ALLEN','SALESMAN',7698,'20-FEB-1981',1600,300,30);

insert into empnew
values(7521,'WARD','SALESMAN',7698,'22-FEB-1981',1250,500,30);

insert into empnew
values(7566,'JONES','MANAGER',7839,'2-APR-1981',2975,NULL,20);

insert into empnew
values(7654,'MARTIN','SALESMAN',7698,'28-SEP-1981',1250,1400,30);

insert into empnew
values(7698,'BLAKR','MANAGER',7839,'1-MAY-1981',2850,NULL,30);

insert into empnew
values(7782,'CLARK','MANAGER',7839,'9-JUN-1981',2450,NULL,10);

insert into empnew
values(7788,'SCOTT','ANALYST',7566,'19-APR-1987',3000,NULL,20);

insert into empnew
values(7839,'KING','PRESIDENT',NULL,'17-NOV-1981',5000,NULL,10);

insert into empnew
values(7844,'TURNER','SALESMAN',7698,'8-SEP-1981',1500,0,30);

insert into empnew
values(7876,'ADAMS','CLERK',7788,'23-MAY-1987',1100,NULL,20);

insert into empnew
values(7900,'JAMES','CLERK',7698,'3-DEC-1980',950,NULL,30);

insert into empnew
values(7902,'FORD','ANALYST',7566,'3-DEC-1981',3000,NULL,20);

insert into empnew
values(7934,'MILLER','CLERK',7782,'23-JAN-1982',1300,NULL,10);

INSERT INTO DEPTTEST VALUES (10, 'ACCOUNTING', 'NEW YORK');
INSERT INTO DEPTTEST VALUES (20, 'RESEARCH', 'DALLAS');
INSERT INTO DEPTTEST VALUES (30, 'SALES', 'CHICAGO');
INSERT INTO DEPTTEST VALUES (40, 'OPERATIONS', 'BOSTON');


select ename from empnew where ename like '_D%'

select ename from empnew where ename like '_____'
select ename from empnew where length(ename)=5

select * from DEPTtest

select concat(dname,' ', loc)"Department" from DEPTtest
select concat(dname,' ', loc) as Department from DEPTtest

select upper(ename)"Uppercase", lower(ename)"Lowercase", initcap(ename)"Title Case" from empnew

select lpad(ename, 15, '')"Left Pad", rpad(ename, 15, '')"Right Pad" from empnew
select lpad(ename, 15, '~')"Left Pad", rpad(ename, 15, '~')"Right Pad" from empnew

select rtrim(ename, 'T')"Right Trim T" from empnew

select dname, length(dname)"Length of Dept name" from DEPTtest

select substring(ename, 1, 3)"First 3 Letters" from empnew

select substring(ename, length(ename)-2, 3)"Last 3 Letters" from empnew

select dname, position('A'in dname)"Position" of 'A'" from DEPTtest