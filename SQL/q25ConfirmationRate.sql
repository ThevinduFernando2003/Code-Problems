-- Code360 Top 100 SQL Problem 25: confirmationRate
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT s.user_id, ROUND(IFNULL(AVG(CASE WHEN a.action = 'confirmed' THEN 1 ELSE 0 END), 0), 2) AS confirmation_rate FROM Signups s LEFT JOIN Confirmations a ON s.user_id = a.user_id AND DATEDIFF(a.action_date, s.time) BETWEEN 0 AND 1 GROUP BY s.user_id;
