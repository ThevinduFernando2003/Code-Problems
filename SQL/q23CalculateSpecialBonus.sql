-- Code360 Top 100 SQL Problem 23: calculateSpecialBonus
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id, CASE WHEN employee_id % 2 = 1 AND SUBSTRING(name, 1, 1) <> 'M' THEN salary ELSE 0 END AS bonus FROM Employees ORDER BY employee_id;
