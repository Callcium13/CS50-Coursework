--make table of all movies from 2008
DROP VIEW IF EXISTS [2008 movies];
CREATE VIEW [2008 movies] AS
SELECT title
FROM movies
WHERE year = 2008 ORDER BY title;