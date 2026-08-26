-- Code360 Top 100 SQL Problem 20: articleViews
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT a1.author_id AS id FROM Views a1 JOIN Views a2 ON a1.author_id = a2.viewer_id AND a1.viewer_id = a2.author_id WHERE a1.author_id < a1.viewer_id;
