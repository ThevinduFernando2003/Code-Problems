-- Code360 Top 100 SQL Problem 96: Combine Two Tables
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT p.firstName, p.lastName, a.city, a.state
FROM Person p
LEFT JOIN Address a ON p.personId = a.personId;
