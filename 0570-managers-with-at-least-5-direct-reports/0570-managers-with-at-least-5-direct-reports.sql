# Write your MySQL query statement below
select e.name
from (
    select managerId ,count(managerId) as counti
    from Employee
    group by managerId
) x
inner join  Employee e
on e.id=x.managerId
where counti > 4;

