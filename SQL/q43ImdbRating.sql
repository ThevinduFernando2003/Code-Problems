-- Code360 Top 100 SQL Problem 43: imdbRating
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT m.title FROM Movies m JOIN Ratings r ON m.id = r.movie_id JOIN Reviewers rev ON r.reviewer_id = rev.id WHERE rev.name = 'Chris' AND r.rating > 3 ORDER BY m.title;
