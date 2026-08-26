-- Code360 Top 100 SQL Problem 67: findTotalTimeSpentByEmployees
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT event_day AS day, emp_id, SUM(out_time - in_time) AS total_time FROM Employees GROUP BY day, emp_id;
