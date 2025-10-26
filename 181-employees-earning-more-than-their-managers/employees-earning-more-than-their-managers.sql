# Write your MySQL query statement below
SELECT E.name as Employee FROM Employee as E INNER JOIN Employee as Emp ON E.managerId=Emp.id WHERE E.salary>Emp.salary;