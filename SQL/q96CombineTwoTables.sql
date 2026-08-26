-- Code360 Top 100 SQL Problem 96: combineTwoTables
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT firstName, lastName, city, state FROM Person p JOIN Address a ON p.personId = a.personId;
