-- Code360 Top 100 SQL Problem 84: cnBanned
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT user_id FROM Audit WHERE action = 'banned' AND user_id IN (SELECT user_id FROM Audit WHERE action = 'authorized');
