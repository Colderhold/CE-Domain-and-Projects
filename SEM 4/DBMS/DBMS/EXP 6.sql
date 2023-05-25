create table emp2
( 
empno int,
ename varchar(20),
sal int,
city varchar(25),
constraint empid primary key(empno)
);

create table assign2
(
empid int,
pid varchar(20)
);

create table proj2
(
proj_no varchar(10),
proj_name varchar(20),
loc varchar(20),
budget int,
manager int,
constraint p_id primary key(proj_no)
);


insert into emp2
values(101, 'Rahul', 10000, 'Mumbai');

insert into emp2
values(103, 'Sachin', 20000, 'Pune');

insert into emp2
values(104, 'Ashish', 15000, 'Nashik');

insert into emp2
values(106, 'Sumit', 20000, 'Nagpur');

insert into emp2
values(107, 'Anil', 10000, 'Mumbai');

insert into emp2
values(110, 'Kapil', 12000, 'Pune');

insert into emp2
values(112, 'Vipul', 25000, 'Mumbai');
;

insert into assign2
values(101, 'C453'), 
(103, 'C354'),(104, 'C353'), (104, 'C354'), (106,'C231'), (106,'C278'),
(106,'C353'), (106,'C354'), (106, 'C453'), (107, 'C231'), (107, 'C353'), (110, 'C278'),
(112, 'C353'), (112, 'C354');

insert into proj2
values('C231', 'Oracle', 'Mumbai', 10000000, 106),
('C278', 'Java', 'Mumbai', 25000000, 107),
('C353', 'OS', 'Pune', 2000000, 112),
('C354', 'C', 'Nashik', 1000000, 112),
('C453', 'VB', 'Nagpur', 15000000, 106)

select * from emp2
select * from assign2
select * from proj2

select empno from emp2
where empno IN(select empid from assign2 where pid = 'C353')

select e.* from emp2 e,assign2 a1
where e.empno = a1.empid and pid = 'C353'

select * from emp2
where empno IN(select empid from assign2 where pid IN (select proj_no from proj2 where proj_name = 'OS'))

select e.* from emp2 e, assign2 a1, proj2 p
where e.empno = a1.empid and a1.pid = p.proj_no and proj_name = 'OS'

select e.* from assign2 a1, assign2 a2 ,emp2 e
where a1.empid = a2.empid and a1.pid = 'C353' and a2.pid = 'C354' and a1.empid = e.empno

select * from emp2
where empno in((select empid from assign2 where pid = 'C353') intersect (select empid from assign2 where pid = 'C354'))

select empno from emp2
where empno in((select empno from emp2) except (select empid from assign2 where pid = 'C453'))

select empno from emp2
where empno in (select distinct empid from assign2 a1 where not exists((select proj_no from proj2) except (select pid from assign2 a2 where a1.empid = a2.empid)))

select empno from emp2
where empno in(select distinct empid from assign2 a1 where not exists((select pid from assign2 where empid = 107) except (select pid from assign2 a2 where a1.empid = a2.empid)))

select empno from emp2
where empno in((select distinct empid from assign2 where pid in(select pid from assign2 where empid = 107)and empid != 107))