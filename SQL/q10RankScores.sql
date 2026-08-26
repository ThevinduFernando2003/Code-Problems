-- Code360 Top 100 SQL Problem 10: rankScores
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) AS `rank` FROM Scores;
