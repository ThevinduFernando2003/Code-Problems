-- Code360 Top 100 SQL Problem 88: calculateSalaries
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id, CASE WHEN worked_hours > 8 THEN (worked_hours - 8) * overtime_rate + 8 * hourly_rate ELSE worked_hours * hourly_rate END AS salary FROM Employees;
