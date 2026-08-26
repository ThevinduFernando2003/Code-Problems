-- Code360 Top 100 SQL Problem 78: Number of Calls Between Two Persons
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT
    LEAST(from_id, to_id) AS person1,
    GREATEST(from_id, to_id) AS person2,
    COUNT(*) AS call_count,
    SUM(duration) AS total_duration
FROM Calls
GROUP BY person1, person2;
