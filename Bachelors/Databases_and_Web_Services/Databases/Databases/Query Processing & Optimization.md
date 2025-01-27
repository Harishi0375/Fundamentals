Written by Nik Tsonev

The SQL code that you write, just line any other code, goes through a bunch of steps, before its ran. Things like syntax checking, optimisations compiling errors and so on happen before your query is performed


![[SQL-process.png]]

This is the process of turning your query into the output that you get

Assuming we have the following tables
- Student(ID, Name, Major)
- Course(Num, Dept)
- Taking(ID, Num)

and do the following query

```SQL
SELECT Name
FROM Student, Course, Taking
WHERE Taking.ID = Student.ID AND
      Taking.Num = Course.Num AND
	  Major = 'EE' AND
	  Dept = 'Cs'  
```

The first step is to expand the query to what it actually is, multiple semi-nested queries

```SQL
SELECT Name 
FROM Course, Taking, Student AS (
	SELECT StudName.ID, Name, Major
	FROM StudName, StudMajor WHERE StudName.ID = StudMajor.ID
)
WHERE Taking.ID = Student.ID AND Taking.Num = Course.Num AND
      Student.Major = 'EE' AND
      Course.Dept = 'CS' AND
      StudName.ID = StudMajor.ID
```

which as you can see is m much bigger


Then this query gets processed into a `Logical Tree` which is where all of the queries are converted to linear algebra and checking each step of the way

![[logica-tree.png]]

Then the DBMS tries to optimise this by rearranges the order of the queries as sometimes it is more efficient to do it in one order than another due to caching. 

so the final logic tree might look completely different from the one your query has created. And that is the nice thing, that in SQL we often don't have to think of query optimisations as the DBMS can perform a lot of the heavy liftin