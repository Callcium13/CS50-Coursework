DROP TABLE IF EXISTS [avg rate 2012];
CREATE TABLE [avg rate 2012] AS
SELECT rating FROM ratings
JOIN movies m on m.id = ratings.movie_id;