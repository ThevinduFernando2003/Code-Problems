-- Code360 Top 100 SQL Problem 8: employeesEarningMoreThanManagers
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT e1.name AS Employee FROM Employee e1 JOIN Employee e2 ON e1.managerId = e2.id WHERE e1.salary > e2.salary;
