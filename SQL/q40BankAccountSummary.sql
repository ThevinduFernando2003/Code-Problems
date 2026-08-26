-- Code360 Top 100 SQL Problem 40: bankAccountSummary
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT account, SUM(amount) AS balance FROM Transactions GROUP BY account HAVING balance > 0;
