-- Code360 Top 100 SQL Problem 47: directorsActor
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT d.director FROM Director d JOIN Actor a ON d.person_id = a.person_id;
