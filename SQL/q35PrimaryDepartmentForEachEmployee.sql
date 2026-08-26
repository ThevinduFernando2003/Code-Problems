-- Code360 Top 100 SQL Problem 35: primaryDepartmentForEachEmployee
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id, department_id FROM Employee WHERE primary_flag = 'Y' UNION SELECT employee_id, department_id FROM Employee e WHERE (SELECT COUNT(*) FROM Employee e2 WHERE e2.employee_id = e.employee_id) = 1;
