-- Code360 Top 100 SQL Problem 22: Rearrange Products Table
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT product_id, 'store1' AS store, store1 AS price
FROM Products
WHERE store1 IS NOT NULL
UNION ALL
SELECT product_id, 'store2', store2
FROM Products
WHERE store2 IS NOT NULL
UNION ALL
SELECT product_id, 'store3', store3
FROM Products
WHERE store3 IS NOT NULL;
