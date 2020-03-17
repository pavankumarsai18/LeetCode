# Write your MySQL query statement below
SELECT a.Id as 'Id'
FROM Weather a JOIN Weather b ON DATEDIFF(a.RecordDate, b.RecordDate) = 1 AND a.Temperature > b.Temperature;
