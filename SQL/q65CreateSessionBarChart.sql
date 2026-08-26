-- Code360 Top 100 SQL Problem 65: createSessionBarChart
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DATE_FORMAT(start_time, '%Y-%m-%d') AS day, COUNT(*) AS total_appointments FROM Appointments WHERE YEAR(start_time) = 2020 AND MONTH(start_time) = 9 GROUP BY day ORDER BY day;
