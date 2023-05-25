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

select ename,sal from empnew where sal>=2000 and sal<=3000
select ename,sal from empnew where sal between 2000 and 3000

select ename,sal from empnew where hiredate between '1982-01-01' and '1982-12-31'

select ename from empnew where deptno in (10,20)

select ename from empnew where comm = 0

select ename from empnew where comm!= 0

select ename from empnew where deptno = 10 and hiredate >= '1981-09-01'

select ename from empnew where deptno!= 10

select count(empno) as "Number of Employees"from empnew

select count(empno) from empnew where hiredate>'1981-01-13'

select sum(sal) as "Total Salary" from empnew

select avg(sal) as "Average Salary" from empnew

select min(sal) as "Minimum Salary" from empnew

select max(sal) as "Maximum Salary" from empnew

select deptno, avg(sal) as "Average Salary", min(sal) as "Minimum Salary", max(sal) as "Maximum Salary" from empnew group by deptno

select deptno, avg(sal) as "Average Salary", min(sal) as "Minimum Salary", max(sal) as "Maximum Salary" from empnew group by deptno having avg(sal)>2000

select job,min(sal) as "Minimum Salary" from empnew group by job

select deptno,min(sal) as "Minimum Salary" from empnew where job = 'MANAGER' group by deptno

select job,deptno,min(sal) as "Minimum Salary" from empnew group by deptno,job

select count(distinct job) as "Job Opportunities" from empnew

select 12*avg(sal) as "12 Times Average Salary" from empnew

select deptno,count(empno) as "Employees in each Department" from empnew group by deptno

select deptno,sum(sal) as "Total Salary" from empnew group by deptno

select job,sum(sal) as "Total Salary" from empnew group by job

select job,12*avg(sal) as "Average Salary" from empnew group by job having count(*)>1

select deptno,count(*) from empnew where job='CLERK' group by deptno having count(*)>1

select job, avg(sal) as "Average Salary" from empnew group by job having avg(sal)>(select avg(sal) from empnew where job = 'MANAGER')

select job,deptno,count(job) as "Job Opportunities" from empnew group by job,deptno

select job,deptno,count(job) as "Job Opportunities" from empnew group by job,deptno having count(*)>=2
