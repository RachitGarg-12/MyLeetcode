# Write your MySQL query statement below
select name,population,area
from World
where (World.area >=3000000) or (World.population >=25000000) ;