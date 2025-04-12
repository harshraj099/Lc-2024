# Write your MySQL query statement below
select requester_id as id, sum(friends) as num from(
select requester_id , count(accepter_id ) as friends from RequestAccepted group by requester_id
union all
select accepter_id  , count(requester_id) as friends from RequestAccepted group by accepter_id
) as newTable group by id order by num desc limit 1;