-- Code360 Top 100 SQL Problem 95: employeesWithoutManager
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id FROM Employees WHERE manager_id IS NULL;
