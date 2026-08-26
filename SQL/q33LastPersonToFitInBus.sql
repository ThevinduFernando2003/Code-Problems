-- Code360 Top 100 SQL Problem 33: Last Person to Fit in the Bus
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT q1.person_name
FROM Queue q1
JOIN Queue q2 ON q2.turn <= q1.turn
GROUP BY q1.turn, q1.person_name
HAVING SUM(q2.weight) <= 1000
ORDER BY SUM(q2.weight) DESC
LIMIT 1;
