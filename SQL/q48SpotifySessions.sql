-- Code360 Top 100 SQL Problem 48: spotifySessions
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT session_id FROM Sessions GROUP BY session_id HAVING MAX(TIMESTAMPDIFF(MINUTE, start_time, end_time)) >= 30;
