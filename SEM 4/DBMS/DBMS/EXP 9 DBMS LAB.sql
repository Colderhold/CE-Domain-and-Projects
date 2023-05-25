create table emp3
(
	ename text,
	salary int,
	last_date timestamp, 
	last_user text
);

create or replace function emp_st()
returns trigger as $emp3$
begin 
--check ename and sal not null
if new.ename is null then raise exception 'ename cannot be null';
end if;
if new.salary is null then raise exception '% cannot have null salary',new.ename;
end if;
if new.salary < 0 then raise exception '% cannot have negative salary',new.ename;
end if;
new.last_date := current_timestamp;
new.last_user := current_user;
return new;
end;
$emp3$ language 'plpgsql';

create trigger emp_st before insert or update on emp3
for each row execute procedure emp_st();

insert into emp3 values (null,100)

insert into emp3 values ('ABC',null)

insert into emp3 values ('ABC',-500)

insert into emp3 values('ABC',1000)
insert into emp3 values('DEF',2000)
insert into emp3 values('XYZ',3000)

select * from emp3


create table emp4
(
	ename varchar(20),
	sal int
);

create table emp_audit
(
	operation char not null,
	ename varchar(20),
	sal int
);

create or replace function update_emp()
returns trigger as $emp_audit$
begin
--check operation on emp4 table
if(TG_OP = 'DELETE') then
insert into emp_audit values('D',old.*);
return old;
elsif(TG_OP = 'INSERT') then
insert into emp_audit values('I',new.*);
return new;
elsif(TG_OP = 'UPDATE') then
insert into emp_audit values('U',new.*);
return new;
end if;
end;
$emp_audit$ language 'plpgsql';

create or replace trigger emp_audit after insert or update or delete on emp4
for each row execute procedure update_emp();

insert into emp4 values('ABC',100)
insert into emp4 values('XYZ',200)
insert into emp4 values('XYZ',200)

update emp4 set sal = 1000 where ename ='ABC'
update emp4 set sal = 2000 where ename ='XYZ'

delete from emp4 where ename ='ABC'

select * from emp_audit
select * from emp4