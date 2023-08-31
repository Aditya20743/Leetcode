CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      # Write your MySQL query statement below.
      
      SELECT DISTINCT SALARY
      FROM Employee 
      ORDER by SALARY DESC
      LIMIT N, 1
      
      
#       Select DISTINCT salary
#       from employee e
#       where n = ( Select COUNT(DISTINCT e2.salary) 
#                    from employee e2 
#                    where e2.salary >= e.salary
#                   )
      
  );
END