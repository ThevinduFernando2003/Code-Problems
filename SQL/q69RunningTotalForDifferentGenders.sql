-- Code360 Top 100 SQL Problem 69: runningTotalForDifferentGenders
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT gender, day, SUM(score_points) OVER (PARTITION BY gender ORDER BY day) AS total FROM Scores;
