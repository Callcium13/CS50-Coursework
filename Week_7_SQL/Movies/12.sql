DROP VIEW IF EXISTS [Depp+Carter];
CREATE VIEW [Depp+Carter] AS
SELECT title  From Movies
JOIN stars s on movies.id = s.movie_id
JOIN people p on p.id = s.person_id
WHERE name = 'Helena Bonham Carter' OR name = 'Johnny Depp'
GROUP BY title
HAVING COUNT(title)>1;

