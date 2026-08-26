-- Code360 Top 100 SQL Problem 1: recyclableAndLowFatProducts
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y';
