--all movies released in 2010
--sorted by ratings descending, then alphabetical descending
DROP VIEW IF EXISTS [2010 sorted ratings];
CREATE VIEW [2010 sorted ratings] AS
SELECT title, rating FROM movies
JOIN ratings r ON movies.id = r.movie_id
WHERE year = 2010
ORDER BY rating DESC,title ASC;