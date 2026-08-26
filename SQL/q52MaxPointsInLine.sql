-- Code360 Top 100 SQL Problem 52: maxPointsInLine
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT x, y, COUNT(*) AS cnt FROM Points GROUP BY x, y;
