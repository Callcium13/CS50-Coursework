--directors of movies with a rating of at least 9
DROP VIEW IF EXISTS [good directors];
CREATE VIEW [good directors] AS
SELECT name FROM people
WHERE id IN
(
SELECT DISTINCT person_id FROM directors
JOIN movies m on m.id = directors.movie_id
JOIN ratings r on m.id = r.movie_id
WHERE rating >= 9
)
ORDER BY name;