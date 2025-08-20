# Write your MySQL query statement below
SELECT s.name
FROM SalesPerson s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'RED'
);
-- SELECT s.name
-- FROM Salesperson s
-- WHERE s.sales_id NOT IN(
--     select o.sales_id from Orders o where o.com_id=(
--         select c.com_id from Company c where c.name='RED'
--     )
-- )