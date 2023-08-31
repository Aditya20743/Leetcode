CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      Select DISTINCT salary
      from employee e
      where n = ( Select COUNT(DISTINCT e2.salary) 
                   from employee e2 
                   where e2.salary >= e.salary
                  )
      
  );
END