# Write your MySQL query statement below

SELECT w.id as Id
FROM Weather as w , Weather as we
WHERE (DATEDIFF(w.recordDate , we.recordDate) = 1 and w.temperature> we.temperature );