
Extended ERD is one which includes the ISA relation. The ISA relation is similar to inheritance in OOP and shows how entities inherit all of attributes from the parent entity. 

![[ISA_EERD.png]]

There are 2 types, top down  (`Specialisation`) and bottom up
(`Generalisation`)

## Specialisation

This is when you divide a superclass into two more specialised classes. Classic inheritance in OOP

       Person
         |
      ∆ ISA
       /      \
 Student      Employee

### Benefits
1. More specific
2. Easier and more optimised queries
3. Easier to model real-world variability
4. Best for broad data

```SQL
CREATE TABLE Person(
	PID INT PRIMARY KEY,
	Name VARCHAR(100) NOT NULL
	Age INT NOT NULL
);

CREATE TABLE Student(
	PID INT PRIMARY KEY,
	GPA FLOAT NOT NULL
	Major VARCHAR(100) NOT NULL,
	FOREIGN KEY PID REFERENCES Person(PID),
);

CREATE TABLE Employe(
	PID INT PRIMARY KEY
	Salary INT NOT NULL,
	FOREIGN KEY PID REFERENCES Person(PID)
);

```

now student and employe must also have a Person table to exist and therefore must have a name and and Age

## Generalisation

this is where you have multiple entities with overlapping attributes so you can merge the into a more general entity

Car    Bike
  \        /
   \      /
Vehicle

### Benefits
1. Reduces redundancy
2. Simplifies Schema Maintenance
3. Improves scalability as you can keep on adding entities
4. Best for Fragmented data


## Constraints

Two main types of constraints `Overlap` and `Complete-coverage`

### Overalp

this constrains is basically saying that a parent entity and to how many subclasses it can belong

`allowed overlap` - when a parent entity can belong to two or more child entities

for example if we have a parents vehicle and children truck and car a pickup truck would be both a car and a truck

`disjoint` is when vehicle can belong only to a car or only to a truck

### Complete-coverage

specifies whether every instance of the parent entity **must** belong to at least one subclass

`complete` every person must be an employee or student or both 