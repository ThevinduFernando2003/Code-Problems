-- Code360 Top 100 SQL Problem 37: findUsersWithValidEmails
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT user_id FROM Users WHERE email REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode.com$';
