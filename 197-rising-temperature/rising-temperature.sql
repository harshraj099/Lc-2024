# Write your MySQL query statement below
select w1.id as id  from Weather as w1 left join Weather as w2 
on dateDiff(w1.recordDate,w2.recordDate)=1 where w1.temperature>w2.temperature ;
-- DATEDIFF(w1.recordDate, w2.recordDate) = 1 ensures w2 is the previous day's record.