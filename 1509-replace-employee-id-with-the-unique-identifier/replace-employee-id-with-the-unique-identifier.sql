# Write your MySQL query statement below
select EmployeeUNI.unique_id as unique_id,Employees.name as name from EmployeeUNI right join  Employees
on Employees.id=EmployeeUNI.id;