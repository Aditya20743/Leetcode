# Write your MySQL query statement below

# Select a1.machine_id , a1.timestamp as start, a2.timestamp as end
Select a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp),3) as processing_time
From Activity a1
Join Activity a2 on
a1.machine_id = a2.machine_id and a1.process_id = a2.process_id 
and a1.timestamp < a2.timestamp
group by a1.machine_id

