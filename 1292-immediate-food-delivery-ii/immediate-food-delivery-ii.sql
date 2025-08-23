# Write your MySQL query statement below
select  ROUND(
        SUM(order_date = customer_pref_delivery_date) * 100.0 / COUNT(customer_id)
    , 2) AS immediate_percentage from Delivery where(customer_id,order_date) in (SELECT customer_id, MIN(order_date)  from Delivery  group by customer_id)