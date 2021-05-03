DROP VIEW IF EXISTS[kevin bacon's coworkers];
CREATE VIEW [kevin bacon's coworkers] AS
SELECT DISTINCT name FROM people
JOIN stars s on people.id = s.person_id
WHERE NOT name = 'Kevin Bacon' AND movie_id IN
      (
      SELECT movie_id
      FROM stars
      JOIN people p on p.id = stars.person_id
      WHERE name = 'Kevin Bacon' AND birth = 1958
      )
ORDER BY name;