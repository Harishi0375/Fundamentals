
ISA constraints
no nested queries
know about joins and aggregates, group by, `having?`
set operations ~ maybe
no fronted 
- no ajax
- no http
- no xml

output table from query

for each = group by

relational algebra
- select
- project
- cross product

Query trees
logical optimisation 
must know b+ tree 
- key properties
	- balanced
	- ordered
	- n-array tree with large block size
	- leaf chain that allows for efficient range queries 

normal form

Why need transaction + ACID + BASE
- ACID vs BASE
what is a dirty and unrepeatable read
2-phase locking protocol

security
- 3 key aspects
- SQL injections
- how to prevent such attack

noSQL
- array DB

no array queries
no MapReduce Queries but know theory

tip - YAP as much as possible 

Biga data
- give the 4v

OLAP
- data cubes
	- multi-dimensional
	- facts in the cells of the cubes
	- give an example
- dimension hierarchy
- know the functions?
- ROLAP
	- star schemas
	- primary keys
- no MOLAP
- basic ETL

Parallel DBs
- need to partition data + what does it mean
- how to partition data (i.e range)
- operators and their parallelisation
	- Sort/merger
	- filter
	- partitioned join
- what data Skew Means
- types of parallel processing of DBs
	- pipeline VS partition 


Heres some quick notes i took on my phone yesterday for whats gonna be on the DB test in case anyone still wants to compare with the other file

What is a database system, what is it for and what is it good for

Entity and relationship design, translate anything to ER diagram (Overlap and covering constraints cant be captured by ER but should be written down), UML not necessary. Be able to reverse engineer ER diagram to natural language.

Queries, Primary keys and their usage. Referential integrity, making refrences in database with keys. Questions may require code. ISA relations (map to schema and assess advantages and dissatvatages of table schema, explain tradr off between different implementations)

No nested queries. Yes SELECT from WHERE, joins, aggregates, group by and having. if for each use group by. Set operations, conceptual evaluation. No null values, no assertions, no last thing? No different types of joins.

How to operate database queries from query language.

No frontend. No http. No html. No ajax. No xml requests n stuff. Nothing client side.
Maybe make output table from query with html. No restful apps.

3 tier architectures, no specific technologies. Just an idea what it is.

Relational algebra. 3 basic operations important.

Query processing. Query tree. Transform query into query tree. No physical query tree/plan and all related to it. No open/close. Optimisation -> on logical level, not on physical. No cost based optimisation, only suoerficial stuff.

Physical design: must know indexing (b+ tree specifically), b+ tree associated with 4 properties -> balanced tree, ordered, memory?? Tree, leaf chain. No multidimentional queries and r trees. Need to know how to operate b+ tree.

Database tuning -> NO

Normal forms necessary -> 4 forms. Why normalisation important and how it works. Pocket guide helpful to figure it out. How to get anything into normal form.

Transaction managment -> dirty read/ unrepeatable read. Bad situations that can happen. ACID important.

No multiple choice, contructive and relroduction tasks.

Two phase locking and basic protocol.

Deadlock? No

Intro to DB & web service security slidr important. How to hack a database slide explain. How can you prevent an attack from the previous slide. Mandatory access control No. Role based access control No.

Know what nosql is. Know the basics.

Skip squery, sparkle and array queries, no map reduce, just know the concept.

Make detailed, concise and complete answers.

Big Data -> definition slide important, what the 4 Vs mean.

OLAP databases -> DSS: architecture, data cubes, core temlrminology -> multidimentional, facts/measures in cells, if cant describe give example. Dimention hierarchies important, operations YES. ROLAP YES. Star schema yes. Other schemas, also yes. MOLAP no., hybrid OLAP no. ETL no.

Architectures for parallel databases no. Know about partitioning data, give example, types. Operators yes. Sort-merge with range-partitioning yes. Partitioned join yes. Data Skew yes. Concequences of skew for query processing. Histograms for partitioning. Parallel query evaluation - parralelisation variants.

ACID VS BASE