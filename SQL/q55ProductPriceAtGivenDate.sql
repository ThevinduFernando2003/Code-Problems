-- Code360 Top 100 SQL Problem 55: Product Price at a Given Date
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    p.product_id,
    IFNULL((
        SELECT new_price
        FROM Products
        WHERE product_id = p.product_id
          AND change_date <= '2019-08-16'
        ORDER BY change_date DESC
        LIMIT 1
    ), 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) p;
