-- Code360 Top 100 SQL Problem 38: investmentsIn2016
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT tiv_2016 FROM Insurance GROUP BY tiv_2016 HAVING COUNT(*) > 1;
