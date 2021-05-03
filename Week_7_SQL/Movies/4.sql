--find the count of movies with a rating of 10
DROP VIEW IF EXISTS [ratings 10];
CREATE VIEW [ratings 10] AS
SELECT COUNT(rating) FROM ratings
WHERE rating = 10;