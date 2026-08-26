-- Code360 Top 100 SQL Problem 100: Second Highest Distinct Salary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) AS SecondHighestSalary;
