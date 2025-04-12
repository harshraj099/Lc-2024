# Write your MySQL query statement below
select result as results from(
select name as result from (
select  u.user_id,u.name , count(distinct m.movie_id) as no_moveies_rated 
 from MovieRating as m join Users as u on m.user_id=u.user_id 
group by m.user_id order by no_moveies_rated desc,u.name asc limit 1
) as top_user
union all
select title as result from(
select m.movie_id,mov.title, avg(m.rating) as average from MovieRating as m 
join Movies as mov on m.movie_id=mov.movie_id  where m.created_at 
between '2020-02-01' and '2020-02-29' group by m.movie_id order by
 average desc, mov.title asc limit 1)
as top_movie
) as combined_result;