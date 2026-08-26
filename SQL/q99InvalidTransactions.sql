-- Code360 Top 100 SQL Problem 99: invalidTransactions
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT * FROM Transactions WHERE amount < 0 OR created_at > '2020-01-01';
