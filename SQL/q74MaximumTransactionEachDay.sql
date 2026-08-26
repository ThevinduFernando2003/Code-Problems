-- Code360 Top 100 SQL Problem 74: maximumTransactionEachDay
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT transaction_date, SUM(amount) AS total FROM Transactions GROUP BY transaction_date;
