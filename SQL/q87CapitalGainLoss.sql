-- Code360 Top 100 SQL Problem 87: capitalGainLoss
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT stock_name, SUM(CASE WHEN operation = 'Buy' THEN -price ELSE price END) AS capital_gain_loss FROM Stocks GROUP BY stock_name;
