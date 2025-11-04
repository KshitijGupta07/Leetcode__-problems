SELECT name FROM (SELECT  M.name as name ,COUNT(E.managerId) FROM Employee as E INNER JOIN  Employee as M ON E.managerId=M.id GROUP BY E.managerId HAVING COUNT(E.managerId) >=5) AS Emp ;

-- -- (SELECT DISTINCT E.id , E.name FROM Employee as E INNER JOIN Employee as M ON E.id=M.managerId) X   ;



-- select managerId, name as C from Employee group by managerId ;