-- Code360 Top 100 SQL Problem 64: pairsWithMaxCommonFollowers
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT r1.user_id, r2.user_id FROM Relations r1 JOIN Relations r2 ON r1.follower_id = r2.follower_id AND r1.user_id < r2.user_id GROUP BY r1.user_id, r2.user_id ORDER BY COUNT(*) DESC LIMIT 1;
