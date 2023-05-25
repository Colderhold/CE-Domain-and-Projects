select * from empnew
select * from depttest

insert into empnew values(8000,'DHRUV','MANAGER',null,'2023-03-20',1000,null,50)
insert into empnew values(8001,'AAYUSH','PRESIDENT',null,'2023-04-21',2000,null,60)
insert into empnew values(8002,'NAJEEB','CLERK',null,'2023-05-25',3000,null,80)

insert into depttest values(90,'IT','MUMBAI')
insert into depttest values(100,'CE','PUNE')
insert into depttest values(120,'AIML','NASHIK')

select * from empnew e inner join depttest d on e.deptno=d.deptno

select * from empnew e right join depttest d on e.deptno=d.deptno

select * from empnew e left join depttest d on e.deptno=d.deptno

select * from empnew e full join depttest d on e.deptno=d.deptno