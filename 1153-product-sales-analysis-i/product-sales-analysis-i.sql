# Write your MySQL query statement below
select prd.product_name,sal.year,sal.price from Product as prd right join sales as sal on prd.product_id=sal.product_id;