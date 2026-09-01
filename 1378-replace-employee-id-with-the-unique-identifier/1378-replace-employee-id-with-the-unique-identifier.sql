# Write your MySQL query statement below
select e.unique_id ,f.name
from EmployeeUNI e
right join Employees f
on e.id=f.id;