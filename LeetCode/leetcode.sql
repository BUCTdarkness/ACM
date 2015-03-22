
--Rank Scores 
select Score,Rank from (
	select Score,@curRank := @curRank+if(@preScore = Score,0,1) as Rank,@preScore := Score
	from Scores s,(select @curRank := 0) r,(select @preScore := NULL) p
	order by Score desc
) t;

--Consecutive Numbers 
select distinct Num from (
	select Num,count(Rank) as Cnt from 
	(
	select Num,@curRank:=@curRank+if(@preNum=Num,0,1) as Rank,@preNum:= Num from Logs s,(select @curRank:=0) r ,(select @preNum:=NULL) p order by ID asc
	) t group by Rank having Cnt>=3
) n;

--Nth Highest Salary
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary from Employee order by Salary desc limit M,1
  );
END


