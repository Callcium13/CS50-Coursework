DROP VIEW IF EXISTS [ChadBos best movies];
CREATE VIEW [ChadBos best movies] AS
SELECT title FROM movies
JOIN stars s on movies.id = s.movie_id
JOIN people p on p.id = s.person_id
JOIN ratings r on movies.id = r.movie_id
WHERE name = 'Chadwick Boseman'
ORDER BY rating DESC LIMIT 5;