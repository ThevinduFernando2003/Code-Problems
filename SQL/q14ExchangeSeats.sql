-- Code360 Top 100 SQL Problem 14: exchangeSeats
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT CASE WHEN id % 2 = 1 AND id = (SELECT MAX(id) FROM Seat) THEN id ELSE id + 1 - 2 * (id % 2) END AS id, student FROM Seat ORDER BY id;
