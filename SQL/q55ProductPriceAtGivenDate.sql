-- Code360 Top 100 SQL Problem 55: productPriceAtGivenDate
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT product_id, new_price AS price FROM Products WHERE (product_id, change_date) IN (SELECT product_id, MAX(change_date) FROM Products WHERE change_date <= '2019-08-16' GROUP BY product_id);
