# Write your MySQL query statement below
SELECT P.firstName,P.lastName,A.city,A.state FROM Person as P LEFT OUTER JOIN Address as A ON P.personId=A.personId;