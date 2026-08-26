-- Code360 Top 100 SQL Problem 44: imdbGenre
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT g.genre FROM Movies m JOIN Ratings r ON m.id = r.movie_id JOIN Genres g ON m.genre = g.id WHERE r.rating = 5;
