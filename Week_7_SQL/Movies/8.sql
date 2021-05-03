-- names of all who starred in toy story
DROP VIEW IF EXISTS [toy story actors];
CREATE VIEW [toy story actors] AS
SELECT name FROM people
JOIN stars s on people.id = s.person_id
JOIN movies m on m.id = s.movie_id
WHERE title  = 'Toy Story';