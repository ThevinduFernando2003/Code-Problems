-- Code360 Top 100 SQL Problem 9: departmentHighestSalary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT d.name AS Department, e.name AS Employee, e.salary FROM Employee e JOIN Department d ON e.departmentId = d.id WHERE (e.departmentId, e.salary) IN (SELECT departmentId, MAX(salary) FROM Employee GROUP BY departmentId);
