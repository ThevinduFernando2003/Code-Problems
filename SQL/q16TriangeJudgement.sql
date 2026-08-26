-- Code360 Top 100 SQL Problem 16: triangeJudgement
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT x, y, z, CASE WHEN x + y > z AND x + z > y AND y + z > x THEN 'Yes' ELSE 'No' END AS triangle FROM Triangle;
