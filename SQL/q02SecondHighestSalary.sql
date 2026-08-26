-- Code360 Top 100 SQL Problem 2: secondHighestSalary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT MAX(salary) AS SecondHighestSalary FROM Employee WHERE salary < (SELECT MAX(salary) FROM Employee);
