-- Code360 Top 100 SQL Problem 61: marketAnalysis
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT u.user_id AS seller_id, u.join_date, COUNT(o.order_id) AS orders_in_2019 FROM Users u LEFT JOIN Orders o ON u.user_id = o.seller_id AND YEAR(o.sale_date) = 2019 GROUP BY u.user_id;
