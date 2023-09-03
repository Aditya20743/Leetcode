# Write your MySQL query statement below
Select e.name 
From Employee e
inner join Employee e2
on e.id= e2.managerId
group by e.id
having count(e.id)>=5



# Select m.name
# from employee as e
# inner join employee as m
# on e.managerId=m.id
# group by e.managerId 
# having count(e.id)>=5


# select name from employee 
# where id in 
# (select managerId from Employee
# group by managerId
# having count(managerId)>=5) 