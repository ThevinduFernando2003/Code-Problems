-- Code360 Top 100 SQL Problem 66: numberOfCommentsPerPost
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT s.sub_id AS post_id, COUNT(c.sub_id) AS number_of_comments FROM Submissions s LEFT JOIN Submissions c ON s.sub_id = c.parent_id WHERE s.parent_id IS NULL GROUP BY s.sub_id;
