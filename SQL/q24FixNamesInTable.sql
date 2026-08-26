-- Code360 Top 100 SQL Problem 24: fixNamesInTable
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT user_id, CONCAT(UPPER(SUBSTRING(name,1,1)), LOWER(SUBSTRING(name,2))) AS name FROM Users ORDER BY user_id;
