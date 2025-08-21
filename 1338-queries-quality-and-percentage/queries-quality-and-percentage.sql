# Write your MySQL query statement below
-- (select count(*) from Queries where rating <3 group by query_name)
-- This returns multiple rows because GROUP BY query_name is in the subquery.
select query_name,round(avg(rating/position),2) as quality
,round(sum(case when rating <3 then 1 else 0 end)/count(*)* 100.0, 2) as poor_query_percentage 
from Queries group by query_name;