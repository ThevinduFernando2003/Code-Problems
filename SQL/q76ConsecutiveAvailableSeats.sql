-- Code360 Top 100 SQL Problem 76: consecutiveAvailableSeats
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT c1.seat_id FROM Cinema c1 JOIN Cinema c2 ON ABS(c1.seat_id - c2.seat_id) = 1 AND c1.free = 1 AND c2.free = 1 ORDER BY c1.seat_id;
