-- Code360 Top 100 SQL Problem 45: marvelCities
-- Source list: https://www.naukri.com/code360/problem-lists/top-100-sql-problems

SELECT DISTINCT c.city FROM City c JOIN Superhero s ON c.id = s.city_id WHERE s.superhero_name LIKE '%Spider%';
