-- Code360 Top 100 SQL Problem 85: fixTheIssue
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

UPDATE Products SET name = REPLACE(name, 'fixable', 'fixed') WHERE name LIKE '%fixable%';
