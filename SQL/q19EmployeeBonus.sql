-- Code360 Top 100 SQL Problem 19: employeeBonus
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT e.name, b.bonus FROM Employee e LEFT JOIN Bonus b ON e.empId = b.empId WHERE b.bonus IS NULL OR b.bonus < 1000;
