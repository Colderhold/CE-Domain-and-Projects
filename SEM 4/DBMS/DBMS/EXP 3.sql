create table emp(
empno int,
ename varchar(20),
sal int,
city varchar(20),
constraint emp_id primary key(empno)
);

create table assigned(
eid int,
pid int
);

create table project(
pid int,
pname varchar(20),
budget int,
loc varchar(20),
constraint pro_id primary key(pid)
);

select * from emp;
select * from assigned;
select * from project;

alter table emp
add telno int

alter table project
add pro_file varchar(20)

alter table emp
alter empno type varchar(30)

alter table project
alter pid type varchar(30)

alter table emp
drop city

alter table project
drop loc

drop table assigned

insert into emp
values(101,'Dhruv',10000,1234,10)

insert into emp
values(100,'Ovaiz',2000,5678,20)

insert into emp 
values(99,'Najeeb',30000,2468,30)

update emp
set sal=sal*1.1

update emp
set sal=0 where deptno=10

update emp
set ename='NULL' where ename='Najeeb'

delete from emp where deptno=20

delete from emp where ename='NULL'

delete from emp