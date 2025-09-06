# Write your MySQL query statement below
select 
(select distinct salary from Employee 
order by salary desc limit 1,1) 
as SecondHighestSalary 

-- another wrapper is to check the null condition
-- without it null condition wont show 