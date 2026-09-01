SELECT ROUND(AVG(
    CASE
        WHEN next_date = event_date + INTERVAL 1 DAY THEN 1
        ELSE 0
    END
), 2) AS fraction
FROM (
    SELECT
        event_date,
        LEAD(event_date) OVER (
            PARTITION BY player_id
            ORDER BY event_date
        ) AS next_date,
        ROW_NUMBER() OVER (
            PARTITION BY player_id
            ORDER BY event_date
        ) AS rn
    FROM Activity
) t
WHERE rn = 1;