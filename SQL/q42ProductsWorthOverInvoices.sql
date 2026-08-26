-- Code360 Top 100 SQL Problem 42: productsWorthOverInvoices
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT name FROM Products p WHERE (SELECT SUM(units) FROM Invoices i WHERE i.product_id = p.product_id) > p.price;
