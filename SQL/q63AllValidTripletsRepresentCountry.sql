-- Code360 Top 100 SQL Problem 63: allValidTripletsRepresentCountry
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT a.person_name AS member_A, b.person_name AS member_B, c.person_name AS member_C FROM SchoolA a, SchoolB b, SchoolC c WHERE a.country <> b.country AND a.country <> c.country AND b.country <> c.country;
