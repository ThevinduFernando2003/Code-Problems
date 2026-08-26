-- Code360 Top 100 SQL Problem 89: findTheTeamSize
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT employee_id, COUNT(*) OVER (PARTITION BY team_id) AS team_size FROM Employee;
