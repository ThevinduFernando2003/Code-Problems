-- Code360 Top 100 SQL Problem 68: primaryFlagDepartment
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id, department_id FROM Employee WHERE primary_flag = 'Y';
