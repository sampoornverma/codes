SELECT s.user_id,
       COALESCE(ROUND(AVG(e.x),2), 0) AS confirmation_rate
FROM Signups s
LEFT JOIN (
    SELECT user_id,
           CASE
               WHEN action = 'confirmed' THEN 1
               WHEN action = 'timeout' THEN 0
           END AS x
    FROM Confirmations
) e
ON s.user_id = e.user_id
GROUP BY s.user_id
order by confirmation_rate ASC;