# Write your MySQL query statement below
SELECT name,unique_id FROM Employees AS e LEFT JOIN EmployeeUNI AS eu ON e.id = eu.id;