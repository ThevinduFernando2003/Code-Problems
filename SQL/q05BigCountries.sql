-- Code360 Top 100 SQL Problem 5: bigCountries
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT name, population, area FROM World WHERE area >= 3000000 OR population >= 25000000;
