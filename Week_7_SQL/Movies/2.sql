DROP VIEW IF EXISTS [Emma Stone];
CREATE VIEW [Emma Stone] AS
SELECT name, birth
FROM people
WHERE name = 'Emma Stone';