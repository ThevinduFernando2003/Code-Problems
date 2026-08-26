-- Code360 Top 100 SQL Problem 3: risingTemperature
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT w1.id FROM Weather w1 JOIN Weather w2 ON DATEDIFF(w1.recordDate, w2.recordDate) = 1 WHERE w1.temperature > w2.temperature;
