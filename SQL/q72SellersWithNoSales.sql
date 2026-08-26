-- Code360 Top 100 SQL Problem 72: sellersWithNoSales
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT seller_name FROM Sellers s WHERE s.seller_id NOT IN (SELECT seller_id FROM Orders);
