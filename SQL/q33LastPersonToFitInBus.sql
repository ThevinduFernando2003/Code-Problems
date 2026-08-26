-- Code360 Top 100 SQL Problem 33: lastPersonToFitInBus
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT person_name FROM Queue q1 WHERE (SELECT SUM(q2.turn) FROM Queue q2 WHERE q2.turn <= q1.turn) <= 1000 ORDER BY q1.turn DESC LIMIT 1;
