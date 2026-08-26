-- Code360 Top 100 SQL Problem 71: ordersWithMaxQuantityAboveAverage
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT order_id FROM OrdersDetails GROUP BY order_id HAVING MAX(product_id) > (SELECT AVG(product_id) FROM Products);
