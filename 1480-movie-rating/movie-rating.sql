# Write your MySQL query statement below
(select u.name as results
from users as u
inner join movierating as m on u.user_id = m.user_id
group by name
order by count(rating) desc, name
limit 1)

union all

(select m.title as results
from movies as m
inner join movierating as mr on m.movie_id = mr.movie_id
where month(created_at) = '02' and year(created_at) = '2020'
group by title
order by avg(rating) desc, title
limit 1)