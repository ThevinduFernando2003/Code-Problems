-- Code360 Top 100 SQL Problem 56: groupSoldProductsByDate
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT sell_date, COUNT(DISTINCT product_id) AS num_sold FROM Activities GROUP BY sell_date;
