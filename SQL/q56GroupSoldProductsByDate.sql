-- Code360 Top 100 SQL Problem 56: Group Sold Products By The Date
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date;
