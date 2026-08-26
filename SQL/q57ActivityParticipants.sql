-- Code360 Top 100 SQL Problem 57: activityParticipants
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users FROM Activity GROUP BY activity_date;
