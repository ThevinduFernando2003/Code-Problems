-- Code360 Top 100 SQL Problem 82: newUsersDailyCount
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DATE(first_login) AS login_date, COUNT(*) AS user_count FROM (SELECT user_id, MIN(event_date) AS first_login FROM Traffic GROUP BY user_id) t GROUP BY login_date;
