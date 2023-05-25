create or replace function dept_detail(dno int, out dname varchar, out loc varchar)
returns setof record
as 
$$
begin return query select d.dname,d.loc from depttest d where d.deptno = dno;
end;
$$
language 'plpgsql'

select * from dept_detail(10);


create or replace function merge_db(key int, data text)
returns void as 
$$
begin update depttest set dname = data where deptno = key;
if found then return;
end if;
begin
insert into depttest values(key,data);
return;
end;
end;
$$
language 'plpgsql'

select merge_db(50,'IT');
select merge_db(40,'CE');


create or replace procedure emp_details(in p_eno int, inout p_ename varchar, inout p_sal int)
language 'plpgsql'
as
$$
begin select ename,sal into p_ename,p_sal from empnew where empno = p_eno;
commit;
end;
$$

do
$$
declare pename varchar;
declare psal int;
begin
call emp_details(7369,pename,psal);
raise notice '%',pename;
raise notice '%',psal;
end;
$$

create or replace function concat_lower_or_upper(a text, b text, uppercase boolean default false)
returns text
as 
$$
declare mytext text;
begin
if($3 = true) then
select into mytext upper($1 || ' ' || $2);
else 
select into mytext lower($1 || ' ' || $2);
end if;
return mytext;
end;
$$
language 'plpgsql'

select concat_lower_or_upper('Hello','World',true);