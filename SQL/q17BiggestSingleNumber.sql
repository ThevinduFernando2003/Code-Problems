-- Code360 Top 100 SQL Problem 17: biggestSingleNumber
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT MAX(num) AS num FROM MyNumbers GROUP BY num HAVING COUNT(*) = 1;
