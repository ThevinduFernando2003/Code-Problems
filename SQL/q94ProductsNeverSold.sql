-- Code360 Top 100 SQL Problem 94: productsNeverSold
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT p.product_id, p.product_name FROM Products p LEFT JOIN Sales s ON p.product_id = s.product_id WHERE s.product_id IS NULL;
