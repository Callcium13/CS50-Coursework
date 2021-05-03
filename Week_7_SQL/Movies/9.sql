--actors in movies released 2004
DROP VIEW IF EXISTS [actors in 2004];
CREATE VIEW [actors in 2004] AS
SELECT name FROM people
WHERE id IN
(
SELECT DISTINCT person_id FROM stars
JOIN movies m on m.id = stars.movie_id
WHERE year = 2004
)
ORDER BY birth;