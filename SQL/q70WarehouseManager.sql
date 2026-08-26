-- Code360 Top 100 SQL Problem 70: Warehouse Manager
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    w.name AS warehouse_name,
    SUM(p.Width * p.Length * p.Height * w.units) AS volume
FROM Warehouse w
JOIN Products p ON w.product_id = p.product_id
GROUP BY w.name;
