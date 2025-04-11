# Write your MySQL query statement below
select case 
    when id%2=1 and id+1 in (select id from Seat) then id+1 
    -- means when id is odd and id+1 exist in "id" then select id+1 ie next id
    -- since we wanna swap in this case 
    when id%2=0 then id-1
    -- if id is even ie we wanna give it to id -1 person 
    else id
    -- if none case exist siply return same id
    end as id,student
 from Seat order by id