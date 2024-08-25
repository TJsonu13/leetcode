# Write your MySQL query statement below
select name,unique_id from Employees e1
left join
EmployeeUNI e2 on e1.id=e2.id;