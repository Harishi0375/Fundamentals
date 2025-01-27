written by Nik Tsonev

## Core DB design steps

- conceptual design
	- construct description of the info the enterprise uses 
	- Focus on documenting customer intention no tech in mind
- Logical design
	- Construct a description based on a specific db model
	- focus on abstract tech, disregard implementation
- Physical design
	- Describe the implementation using a DBMS, files structures, indexes security and more

## Conceptual design

When it comes to conceptual design we use entity relation models, which are diagrams and models that show how one type of data is related to other data, usually visualised using UML

**Issues in Conceptual design**
- What are the entities and relationships in the enterprise?
- What information about these entities and relationships should we store in the database?
- What are the integrity constraints or business rules that hold?

### Basics of Entity-relationship models

Entity: Real-world object distinguishable from other objects

Entities have attributes the same way a class has variables. These attributes describe their properties and reflect on how they work in the real world. 

Simple attributes are strings, ints, but can go as far as being other entities, the same way a class School, will have an entity Student.

Entity set: collection of similar entities
- E.g., all employees
- All entities in an entity set have the same set of attributes
	- Until we consider ISA hierarchies, anyway!
- Each entity set has a key
- Each attribute has a domain = data type
- 
![[er-relations.png]]

**Relationship** - an association among two or more entities
**Relationship set** - collection of similar relationships

![[Screenshot 2024-09-09 at 12.11.17.png]]

### Constraints

Multiplicity classification:
- one to one
- one to many
- many to many

![[Screenshot 2024-09-09 at 12.14.45.png]]

### Weak Entities

entities that are identifies by considering the primary key of another owner entity. 

the owner entity set and weak set must be in a one-to-many relationship (i.e one owner but many weak entities)

weak entities cannot have their own identification and must always be identified by the primary key of the owner entity 

### ISA (is a) Hierarchies

- A ISA B: every A entity is also a B entity (A inherits from B)
	- A must have attributes like be and more 
	- A is a called a subclass and B is called a superclass

This is similar to inheritance in OOP

The purpose is the same as in OOP where you can have a general entity and make a new one with the same attributes and more specific functions 

![[Screenshot 2024-09-09 at 12.28.07.png]]

### Aggregation

Aggregation = relationship involving (entity sets and) a relationship set

- Aggregation allows us to treat a relationship set as an entity set for purposes of participation in (other) relationships
