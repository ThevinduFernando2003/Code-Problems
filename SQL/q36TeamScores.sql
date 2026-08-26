-- Code360 Top 100 SQL Problem 36: teamScores
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT team_id, SUM(points) AS score FROM Scores GROUP BY team_id ORDER BY score DESC;
