# Write your MySQL query statement below
SELECT E.name as Employee FROM Employee E LEFT JOIN Employee M ON E.managerId=M.id WHERE E.salary>M.salary;
