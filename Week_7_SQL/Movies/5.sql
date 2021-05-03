DROP VIEW IF EXISTS [harry potter];
CREATE VIEW [harry potter] AS
SELECT title,year FROM movies
WHERE title LIKE 'Harry Potter and%'
ORDER BY year;