-- Code360 Top 100 SQL Problem 62: pageRecommendations
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT u2.user_id AS recommended_id FROM Friendship f JOIN Likes l ON f.user1_id = l.user_id JOIN Friendship f2 ON f.user2_id = f2.user1_id JOIN Likes l2 ON f2.user2_id = l2.user_id JOIN Users u2 ON l2.user_id = u2.user_id WHERE u2.user_id NOT IN (SELECT user_id FROM Likes) AND u2.user_id <> f.user1_id;
