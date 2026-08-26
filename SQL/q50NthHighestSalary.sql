-- Code360 Top 100 SQL Problem 50: nthHighestSalary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN SET N = N - 1; RETURN (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT N, 1); END;
