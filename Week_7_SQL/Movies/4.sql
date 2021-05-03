DROP VIEW IF EXISTS [ratings 10];
CREATE VIEW [ratings 10] AS
SELECT COUNT(rating) FROM ratings
WHERE rating = 10;