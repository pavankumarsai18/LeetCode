# Write your MySQL query statement below
SELECT Name as Employee
FROM Employee e
WHERE Salary > (SELECT Salary FROM Employee WHERE Employee.ID = e.ManagerID)
