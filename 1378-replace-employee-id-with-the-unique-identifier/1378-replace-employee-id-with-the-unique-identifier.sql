-- Write your PostgreSQL query statement below
select unique_id,name
from Employees e
left join EmployeeUNI x 
on e.id=x.id;