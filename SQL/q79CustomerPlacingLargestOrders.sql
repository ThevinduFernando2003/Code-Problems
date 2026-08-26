-- Code360 Top 100 SQL Problem 79: customerPlacingLargestOrders
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT customer_number FROM Orders GROUP BY customer_number ORDER BY COUNT(*) DESC LIMIT 1;
