-- Code360 Top 100 SQL Problem 97: notBoringMovies
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT * FROM Cinema WHERE description <> 'boring' AND id % 2 = 1 ORDER BY rating DESC;
