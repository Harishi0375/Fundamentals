
ERDs are how we represent the DB and its entity relations in an easy manner 

## Benefits of Using ERDs
1. Easy to convert into SQL schemas
2. provides real world modelling of the objects
3. Require no tech knowledge to understand
4. Provides a standard solution for visualising data logically 

##  Symbols and their meaning


![[ER-symbols.png]]

## Components of an ERD

![[ERD-components.png]]

## Relations

This is the most important part of the ERD, it describes how entities are related to each other and the number of relations per Entity. 

![[ER-Models.png]]

This is an example of a basic set where we have a `customer` `orders` and `product` on Amazon.

The rectangle describes the relationship and the "arrows" show the amount of relationships. for example 0 : M means that a customer can have 0 or many orders, but an order may only have one customer. 

also please not that real diagrams display all of the attributes, I am just lazy. 

note that when you have a many to many relationship its used as M : N to show that the numbers can differ from each other

| Relationship Type | Symbol |     |
| ----------------- | ------ | --- |
| One to One        | 1  : 1 |     |
| One to Many       | 1  : M |     |
| Many to One       | M : 1  |     |
| Many to Many      | M : N  |     |
| Zero to One       | 0  : 1 |     |
| Zero to Many      | 0 : N  |     |

![[relations-symbols.png]]

1 : 1 - one entity can have only 1 other relation, think of person and their age or wife

1 : M - one entity can have 1 or M amounts , teach and student(S)

M : 1 - products to customer

M : N, websites and customers

0 : 1 - a person can have 0 to 1 death

0 : n  - a person can have 0 or many kids
### SQL Code

1 : N

```SQL
CREATE TABLE Prof(
	ProfID INT PRIMARY KEY,
	Name VARCHAR(100) NOT NULL,
	Surname VARCHAR(100) NOT NULL
);

CREATE TABLE Course(
	CourseID INT PRIMARY KEY,
	Name VARCHAR(100) NOT NULL,
	ProfID INT,
	FOREIGN KEY (ProfID) REFERENCES Prof(ProfID)
);
```

M : N

```SQL
CREATE TABLE Student(
	SID INT PRIMARY KEY, 
	name VARCHAR(100) NOT NULL,
	Major VARCHAR(100) NOT NULL,
);

CREATE TABLE Course(
	CID INT PRIMARY KEY,
	title VARCHAR(100) NOT NULL
);

CREATE TABLE Enrollment(
	SID INT,
	CID INT,
	PRIMARY KEY (SID, CID),
	FOREIGN KEY (SID) REFERENCES Student(SID),
	FROEIGN KEY (CID), REFERENCES Course(SID)
);
```