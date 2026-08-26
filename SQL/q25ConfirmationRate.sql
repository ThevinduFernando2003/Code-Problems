-- Code360 Top 100 SQL Problem 25: Confirmation Rate
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    s.user_id,
    ROUND(AVG(IF(c.action = 'confirmed', 1, 0)), 2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c ON s.user_id = c.user_id
GROUP BY s.user_id;
