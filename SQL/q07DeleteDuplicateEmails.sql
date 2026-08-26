-- Code360 Top 100 SQL Problem 7: deleteDuplicateEmails
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

DELETE p1 FROM Person p1 JOIN Person p2 ON p1.email = p2.email AND p1.id > p2.id;
