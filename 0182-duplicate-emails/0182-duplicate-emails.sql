# Write your MySQL query statement below
SELECT DISTINCT email AS Email  FROM Person
WHERE email IN
(SELECT CASE WHEN COUNT(id)>1 THEN email
END
FROM Person
GROUP BY email);