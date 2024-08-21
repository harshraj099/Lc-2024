# Write your MySQL query statement below
select emp.unique_id as unique_id,e.name as name from Employees as e left join EmployeeUNI as emp on e.id=emp.id;
-- select 
-- eu.unique_id as unique_id, e.name as name
-- from Employees e left join EmployeeUNI eu on e.id = eu.id