# Write your MySQL query statement below
-- right join -> means right table first
-- just main the order of table
select product_name, year , price from Product  join 
Sales on Sales.product_id=Product.product_id;