-- Code360 Top 100 SQL Problem 17: Biggest Single Number
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) t;
