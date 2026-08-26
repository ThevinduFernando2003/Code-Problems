-- Code360 Top 100 SQL Problem 40: Bank Account Summary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    u.name,
    u.account,
    SUM(t.amount) AS balance
FROM Users u
JOIN Transactions t ON u.account = t.account
GROUP BY u.account, u.name
HAVING SUM(t.amount) > 10000;
