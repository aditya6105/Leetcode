# Write your MySQL query statement below
SELECT eu.unique_id, e.name FROM Employees AS e LEFT JOIN EmployeeUNI as eu ON eu.id = e.id