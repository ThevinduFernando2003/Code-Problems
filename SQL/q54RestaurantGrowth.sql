-- Code360 Top 100 SQL Problem 54: restaurantGrowth
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT visited_on, SUM(amount) AS amount, ROUND(100 * (SUM(amount) - LAG(SUM(amount), 1) OVER (ORDER BY visited_on)) / LAG(SUM(amount), 1) OVER (ORDER BY visited_on), 2) AS average_amount FROM CustomerVisits GROUP BY visited_on;
