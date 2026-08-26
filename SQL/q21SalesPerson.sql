-- Code360 Top 100 SQL Problem 21: salesPerson
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT name FROM SalesPerson WHERE sales_id NOT IN (SELECT sales_id FROM Orders o JOIN Company c ON o.com_id = c.com_id WHERE c.name = 'RED');
