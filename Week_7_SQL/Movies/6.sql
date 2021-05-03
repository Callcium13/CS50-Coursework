-- find average rating of all movies from 2012
DROP VIEW IF EXISTS [avg rate 2012];
CREATE VIEW [avg rate 2012] AS
SELECT AVG(rating) FROM movies
JOIN ratings r on movies.id = r.movie_id
WHERE year = 2012;