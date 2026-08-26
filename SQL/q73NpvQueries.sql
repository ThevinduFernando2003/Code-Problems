-- Code360 Top 100 SQL Problem 73: npvQueries
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT q.id, IFNULL(SUM(p.paid), 0) AS npv FROM Queries q LEFT JOIN Purchases p ON q.id = p.query_id GROUP BY q.id;
