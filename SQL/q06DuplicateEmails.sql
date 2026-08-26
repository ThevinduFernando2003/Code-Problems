-- Code360 Top 100 SQL Problem 6: duplicateEmails
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT email FROM Person GROUP BY email HAVING COUNT(*) > 1;
