-- Code360 Top 100 SQL Problem 91: getTheSecondMostRecentActivity
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT activity FROM UserActivity WHERE (user_id, activity_start) IN (SELECT user_id, MAX(activity_start) FROM UserActivity GROUP BY user_id);
