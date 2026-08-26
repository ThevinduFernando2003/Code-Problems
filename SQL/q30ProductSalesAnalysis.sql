-- Code360 Top 100 SQL Problem 30: productSalesAnalysis
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT p.product_name, s.year, s.price FROM Sales s JOIN Product p ON s.product_id = p.product_id;
