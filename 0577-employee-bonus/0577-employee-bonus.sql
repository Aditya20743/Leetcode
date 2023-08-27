# Write your MySQL query statement below
Select e.name as name , b.bonus as bonus
From Employee e LEFT JOIN Bonus b on e.empID = b.empID
Where b.bonus <1000 or b.bonus is NULL;

