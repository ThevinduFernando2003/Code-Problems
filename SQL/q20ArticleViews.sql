-- Code360 Top 100 SQL Problem 20: Article Views
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT author_id AS id
FROM Views
WHERE author_id = viewer_id
ORDER BY id;
