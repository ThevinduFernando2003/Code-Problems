-- Code360 Top 100 SQL Problem 46: swapSalary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

UPDATE Salary SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END;
