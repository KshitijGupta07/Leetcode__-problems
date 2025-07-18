# Write your MySQL query statement below
SELECT W.id FROM Weather W  LEFT JOIN Weather M ON  W.recordDate = DATE_ADD(M.recordDate, INTERVAL 1 DAY) WHERE M.temperature<W.temperature;
