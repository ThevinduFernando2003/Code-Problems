-- Code360 Top 100 SQL Problem 11: consecutiveNumbers
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT l1.num AS ConsecutiveNums FROM Logs l1 JOIN Logs l2 ON l1.id = l2.id - 1 JOIN Logs l3 ON l2.id = l3.id - 1 WHERE l1.num = l2.num AND l2.num = l3.num;
