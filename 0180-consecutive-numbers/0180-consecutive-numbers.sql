# Write your MySQL query statement below
/* Write your T-SQL query statement below */
with rnk as(
    select *,
    lag(num) over(order by id) prev_num,
    lead(num) over(order by id) next_num
    from Logs
)
select distinct num as ConsecutiveNums
from rnk
where num = prev_num and num = next_num