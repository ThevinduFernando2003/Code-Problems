-- Code360 Top 100 SQL Problem 91: Get the Second Most Recent Activity
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT username, activity, startDate, endDate
FROM (
    SELECT
        username,
        activity,
        startDate,
        endDate,
        RANK() OVER (PARTITION BY username ORDER BY startDate DESC) AS rnk,
        COUNT(*) OVER (PARTITION BY username) AS cnt
    FROM UserActivity
) t
WHERE rnk = 2 OR cnt = 1;
