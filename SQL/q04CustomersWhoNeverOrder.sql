-- Code360 Top 100 SQL Problem 4: customersWhoNeverOrder
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT c.name AS Customers FROM Customers c LEFT JOIN Orders o ON c.id = o.customerId WHERE o.id IS NULL;
