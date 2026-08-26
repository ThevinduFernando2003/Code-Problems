-- Code360 Top 100 SQL Problem 53: investments2016Tiv
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT ROUND(SUM(tiv_2016), 2) FROM Insurance WHERE (lat, lon) IN (SELECT lat, lon FROM Insurance GROUP BY lat, lon HAVING COUNT(*) > 1);
