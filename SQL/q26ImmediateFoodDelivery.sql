-- Code360 Top 100 SQL Problem 26: immediateFoodDelivery
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT ROUND(100 * SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END) / COUNT(*), 2) AS immediate_percentage FROM Delivery;
