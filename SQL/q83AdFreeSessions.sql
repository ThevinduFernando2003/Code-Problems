-- Code360 Top 100 SQL Problem 83: adFreeSessions
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT session_id FROM Playback WHERE customer_id NOT IN (SELECT customer_id FROM Ads);
