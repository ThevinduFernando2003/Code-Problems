-- Code360 Top 100 SQL Problem 18: customersWhoBoughtAllProducts
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT customer_id FROM Customer GROUP BY customer_id HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);
