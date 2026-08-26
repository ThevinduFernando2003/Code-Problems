-- Code360 Top 100 SQL Problem 75: managersWithAtLeast5DirectReports
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT e.name FROM Employee e JOIN Employee r ON e.id = r.managerId GROUP BY e.id HAVING COUNT(*) >= 5;
