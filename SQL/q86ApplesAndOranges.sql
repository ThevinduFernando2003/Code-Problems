-- Code360 Top 100 SQL Problem 86: applesAndOranges
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT sale_date, SUM(CASE WHEN fruit = 'apples' THEN sold_num ELSE 0 END) AS apples, SUM(CASE WHEN fruit = 'oranges' THEN sold_num ELSE 0 END) AS oranges FROM Sales GROUP BY sale_date;
