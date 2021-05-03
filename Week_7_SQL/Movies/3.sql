--find the title of movies released after 2018
DROP VIEW IF EXISTS [release dates after 2018];
CREATE VIEW [release dates after 2018] AS
SELECT title
FROM movies
WHERE year >= 2018;