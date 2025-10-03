# Write your MySQL query statement below
SELECT IFNULL(( SELECT DISTINCT salary FROM Employee  ORDER BY SALARY DESC LIMIT 1 OFFSET 1 ) ,null)as SecondHighestSalary;