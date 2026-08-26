-- Code360 Top 100 SQL Problem 93: moviesAverageRating
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT m.title, ROUND(AVG(r.rating), 2) AS avg_rating FROM Movies m JOIN Ratings r ON m.id = r.movie_id GROUP BY m.id ORDER BY avg_rating DESC;
