-- Code360 Top 100 SQL Problem 80: secondDegreeFollower
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT f.user_id FROM follow f JOIN follow f2 ON f.follower_id = f2.user_id GROUP BY f.user_id;
