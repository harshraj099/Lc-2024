# Write your MySQL query statement below
select vis.customer_id,count(vis.customer_id) as count_no_trans from Visits as vis left join 
Transactions as tran on vis.visit_id=tran.visit_id where tran.transaction_id is NULL group by customer_id;