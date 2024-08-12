# Write your MySQL query statement below
select two.unique_id, one.name from Employees one left join EmployeeUNI two on one.id = two.id;