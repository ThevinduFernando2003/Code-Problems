-- Code360 Top 100 SQL Problem 92: groupEmployeesSameSalary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT salary, COUNT(*) AS employee_count FROM Employee GROUP BY salary HAVING COUNT(*) >= 2;
