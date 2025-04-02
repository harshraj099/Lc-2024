# Write your MySQL query statement below
select name, population,area from World group by name,population,area  having area>=3000000 or population>=25000000;