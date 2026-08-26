-- Code360 Top 100 SQL Problem 59: queriesQualityAndPercentage
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT query_name, ROUND(AVG(rating / position), 2) AS quality, ROUND(100 * SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*), 2) AS poor_query_percentage FROM Queries WHERE query_name IS NOT NULL GROUP BY query_name;
