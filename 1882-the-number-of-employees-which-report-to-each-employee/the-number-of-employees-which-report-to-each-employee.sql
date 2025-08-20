# Write your MySQL query statement below
select 
    E1.employee_id,
    E1.name,
    count(E2.reports_to) as reports_count,
    round(avg(E2.age)) as average_age
from employees as E1 
inner join employees as E2
on E1.employee_id = E2.reports_to
group by E1.employee_id, E1.name
order by E1.employee_id