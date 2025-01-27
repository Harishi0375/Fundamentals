Written by Nik Tsonev

relational algebra is the algebra that describes the relations amongst entities and the steps needed to get the data from the DB. DBMS uses relational algebra to convert your SQL code into it and optimise the queries it makes. 

Relational Algebra is also used to analyse queries and prove their correctness.

Note that Relational Algebra is `imperative` meaning that you need to describe every step of the process for your queries

### Benefits of RA

1. Unambiguous 
2. Allows for complex queries to be built from simpler operations
3. Allows the DBMS to optimise queries 
4. Abstract and allows to focus on the logic of the query

### RA symbols and their meaning

| Relational Algebra Symbol | SQL Keyword           |
| ------------------------- | --------------------- |
| Selection $\sigma$        | WEHRE                 |
| Protection $\pi$          | SELECT                |
| Cartesian Product $x$     | CROSS JOIN            |
| Union $\cup$              | INTERSECT             |
| Difference -              | EXCEPT                |
| Rename $\rho$             | AS                    |
| Join $\Join$              | JOIN                  |
| Theta Join $\Join \theta$ | INNER JOIN ... ON ... |
| Grouping γ                | GROUP BY              |

## Relational Calculus

Relational Calculus is the `declarative` equivalent of RA, it describes what we want to get but does not say how

for example:

```SQL
SELECT *
FROM Employe
WHERE Department = 'HR';
```

in RC

$\{t | t \in Employe \land t.Department = HR\}$


### Some RC operations and their meaning

| Set Operation                            | SQL Keyword |
| ---------------------------------------- | ----------- |
| $\{t\ \|\ t\in S_{1} \lor t\in S_2 \}$   | UNION       |
| $\{t\| t\in s_{1} \land t\in S_2 \}$     | INTERSECT   |
| $\{t\| t\in S_{1} \land t \notin S_2 \}$ | EXCEPT      |

queries are expressed in Set notation 

### Benefits of RC

1.  Focuses on the data and not how to get it 
2. Closer to SQL code
3. Uses predicates (logical conditions) to filter data
4. Can be used to verify SQL queries

Note that is has been proven that both are of equal value, as in everything expressed in `RA` can be expressed  `RC` but DBMS do use `RA` because they need the step by step instructions to actually retrieve the data from disk  



