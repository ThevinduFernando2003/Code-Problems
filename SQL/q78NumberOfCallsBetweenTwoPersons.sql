-- Code360 Top 100 SQL Problem 78: numberOfCallsBetweenTwoPersons
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT from_id, to_id, COUNT(*) AS call_count, DATEDIFF(MAX(call_time), MIN(call_time)) AS duration_days FROM Calls GROUP BY LEAST(from_id, to_id), GREATEST(from_id, to_id);
