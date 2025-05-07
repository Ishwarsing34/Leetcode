# Write your MySQL query statement below

SELECT EmployeeUNI.unique_id,Employees.name
From Employees
Left JOIN EmployeeUNI
ON Employees.id = EmployeeUNI.id;