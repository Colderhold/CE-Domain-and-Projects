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


select * from empnew

select dname,loc from DEPTtest

select distinct job from empnew

select * from empnew where ename like 'SMITH'

select ename,job from empnew where deptno = 20

select * from empnew where deptno = 30

select ename,empno from empnew where job = 'MANAGER'

select ename from empnew where comm > sal

select ename,job from empnew where sal > 2000

select ename,sal from empnew

select ename,count(*) from empnew where deptno = 10 group by ename
select count(*) from empnew where deptno = 10

select dname as department ,deptno as department_number from DEPTtest

select ename,deptno,job from empnew where job = 'MANAGER'

select * from empnew where empno > mgr

select * from empnew where job = 'ANALYST' and sal > 1000

select * from empnew where job = 'MANAGER' and deptno !=10

select * from empnew where job not in('SALESMAN','CLERK')

select ename,sal,job from empnew order by job

select ename,sal,job from empnew order by job asc,sal desc

select * from empnew order by job asc,ename desc