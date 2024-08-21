# Write your MySQL query statement below
-- select prd.product_name,sal.year,sal.price from Product as prd right join sales as sal on prd.product_id=sal.product_id;
-- or
-- select Product.product_name , Sales.year, Sales.price from Product , Sales 
-- where Product.product_id=Sales.product_id ;
-- or
select Prd.product_name , Sal.year, Sal.price from Product as prd , Sales  as sal
where Prd.product_id=Sal.product_id ;