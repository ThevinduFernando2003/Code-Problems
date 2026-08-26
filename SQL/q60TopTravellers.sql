-- Code360 Top 100 SQL Problem 60: topTravellers
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT u.name, IFNULL(SUM(r.distance), 0) AS travelled_distance FROM Users u LEFT JOIN Rides r ON u.id = r.user_id GROUP BY u.id ORDER BY travelled_distance DESC, u.name;
