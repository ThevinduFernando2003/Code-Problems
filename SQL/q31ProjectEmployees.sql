-- Code360 Top 100 SQL Problem 31: projectEmployees
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years FROM Project p JOIN Employee e ON p.employee_id = e.employee_id GROUP BY project_id;
