-- # Write your MySQL query statement below
-- select customer_id from customer
-- group by customer_id
-- having count(distinct product_key) = (select count(product_key) from product);

select c.customer_id
from Customer as c
group by customer_id
having count(distinct c.product_key) = (
    select count(product_key)
    from product
)