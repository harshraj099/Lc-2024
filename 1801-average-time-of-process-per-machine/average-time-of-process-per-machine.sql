# Write your MySQL query statement below
select a1.machine_id as machine_id , round(avg(a2.timestamp - a1.timestamp ),3)
 as processing_time from Activity as a1 left join Activity as a2
 on a1.machine_id   = a2.machine_id  where a1.activity_type = "start"
 and a2.activity_type = "end" group by machine_id;
-- ROUND(..., 3) ensures result is to 3 decimal places.