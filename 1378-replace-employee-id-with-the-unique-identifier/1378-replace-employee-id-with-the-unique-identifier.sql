# Write your MySQL query statement below

Select eu.unique_id as unique_id , e.name as name
FROM Employees e LEFT JOIN EmployeeUNI eu on e.id = eu.id;

# select 
# eu.unique_id as unique_id, e.name as name
# from Employees e left join EmployeeUNI eu on e.id = eu.id
