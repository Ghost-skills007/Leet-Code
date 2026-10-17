# Write your MySQL query statement below

with etl as (
        select  e.id,
                d.name as department, 
                e.name employee, e.salary,
                dense_rank() over(partition by e.departmentId order by e.salary desc) as rankk
        from employee e
        left join Department d
        on e.departmentId = d.id
)

select  department, 
        employee, 
        salary 
from etl 
where rankk <= 3