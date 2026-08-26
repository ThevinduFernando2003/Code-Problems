-- Code360 Top 100 SQL Problem 32: shortestDistanceInLine
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT MIN(ABS(p1.x - p2.x)) AS shortest FROM Point p1 JOIN Point p2 ON p1.x <> p2.x;
