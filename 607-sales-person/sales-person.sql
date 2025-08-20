# Write your MySQL query statement below
-- select * from SalesPerson s left join Orders o 
-- on s.sales_id =o.sales_id join Company c on
-- o.com_id =c.com_id
SELECT s.name
FROM Salesperson s
WHERE s.sales_id NOT IN(
    select o.sales_id from Orders o where o.com_id=(
        select c.com_id from Company c where c.name='RED'
    )
)