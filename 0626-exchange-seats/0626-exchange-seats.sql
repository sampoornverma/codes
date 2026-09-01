# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT id,
CASE
    WHEN id%2 != 0 THEN IFNULL(LEAD(student,1) OVER(), student)
    WHEN id%2 = 0 THEN LAG(student,1) OVER() 
END as student
FROM Seat
ORDER BY id