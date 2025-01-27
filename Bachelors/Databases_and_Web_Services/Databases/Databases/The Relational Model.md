Written by Nik Tsonev

A relation is a set of rows or tuples

and so a relational database is a set of relations 

Example

![[example_of_db.png]]

the cardinality is 3 and degree 4, since we have 3 rows and 4 columns 

## Querying RB

The strength of the relational model is that it makes it simple and easy to query its data

the query itself describes what we are obtaining from the DB without focusing on the how

### Structured Query Language (SQL)

SQL was written by IBM and is designed to be an easy querying language allowing almost anyone to understand what it is written thanks to it's English like structure 

for example, given the data above, we can find people who have a GPA lesser than 3.6

```SQL
SELECT *
FROM Students S
WHERE S.gpa < 3.6
```

which will give us Jones and Smith (eecs)

the * is a wildcard, meaning that it will return every column, but if we want to only know the name or login, we can specify which column we want to be returned. 

![[sql_add_updt_del.png]]

Data definition Language (DDL)
- Create / delete / change relations definitions
- type domain of each attribute is specified (this is enforced by DBMS)
- Standard attributes tend to be, int, float, char, varchar, long 

### Integrity Constraints

these are the conditions that must be true for any instance of the DB. 

for example, cant have two variables in the same column with different data types.

these ICs are specified when the schema has been created, and are checked when the relations are modified 


### Primary Key Constraints

A key must satisfy the following:
1. Now two distinct tuples can have the same values
2. This is not true for any subset of the key

Superkey - when you use more than 1 fields for the primary key. In the case above, a superkey would be the set of {Sid, name}

usually one of the keys is chosen by the DBA to be the primary key


### Primary and candidate Keys in SQL

many candidate keys are specified using UNIQUE, and if you have many, one of them gets chosen as the primary key

```SQL
CREATE TABLE Enrolled(
	sid char(20),
	cid char(20),
	grade char(2),
	PRIMARY KEY (cid, sid)
	UNIQUE (cid, grade)
)
```

## UML

Stands for Unified Model Language, and is a visual way to represent objects in OOP and entities in ER models

here is an example in OOP

![[UML-diagram.png]]


and here is one for ER diagrams

![[UML-ER-diagram.png]]