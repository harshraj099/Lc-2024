# Write your MySQL query statement below
select d.name as Department , e.name as Employee ,
e.salary as Salary  from Employee e inner join
Department d on e.departmentId = d.id 
where (
    select count(distinct e2.salary) from  Employee e2
    where e2.salary>e.salary and e2.departmentId = e.departmentId
)<3

-- this checks how many employee has more salary than me and if 
-- less than 3 has more then automatically i am at top