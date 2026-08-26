-- Code360 Top 100 SQL Problem 22: rearrangeProductsTable
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT product_id, 'store1' AS store, store1 AS amount FROM Products UNION ALL SELECT product_id, 'store2', store2 FROM Products UNION ALL SELECT product_id, 'store3', store3 FROM Products;
