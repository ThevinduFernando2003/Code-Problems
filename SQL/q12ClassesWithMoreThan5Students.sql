-- Code360 Top 100 SQL Problem 12: classesWithMoreThan5Students
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT class FROM Courses GROUP BY class HAVING COUNT(DISTINCT student) >= 5;
