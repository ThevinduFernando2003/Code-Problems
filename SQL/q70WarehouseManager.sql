-- Code360 Top 100 SQL Problem 70: warehouseManager
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT w.name AS warehouse_name, SUM(p.units * p.Width * p.Length * p.Height) AS volume FROM Warehouse w JOIN Products p ON w.product_id = p.product_id GROUP BY w.name, w.product_id HAVING volume <= w.units;
