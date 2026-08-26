-- Code360 Top 100 SQL Problem 81: theLatestLoginIn2020
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT user_id, MAX(time_stamp) AS last_stamp FROM Logins WHERE YEAR(time_stamp) = 2020 GROUP BY user_id;
