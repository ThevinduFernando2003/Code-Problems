-- Code360 Top 100 SQL Problem 28: gamePlayAnalysis
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT player_id, MIN(event_date) AS first_login FROM Activity GROUP BY player_id;
