Written by Nik Tsonev

There are many ways to connect and communicate with a DB

for this class we look at
1. PHP
2. JDBC
3. Embedded SQL

## PHP

because you can insert php tags within you html page, you can straight up have a php tag that connects to the DB and sets up the queries

```php
// html code
<?php
	$mysql = mysql=connect("localhost", "name", "password")
	or die("Could not connect to mySQL");
?>
//html code
```

you can perform queries the same way using

```php
<?php
	$result = mysql_db_query("YOUR_QUERY") or die("no query made");
>/
```

not that for performance and data safety avoid using `SELECT *` and instead select the specific attributes that you need 

## JDBC

stands for Java Database Connectivity and is a static way to connect to a DB. note that the statements cannot have variables as they are compiled into the java byte-code

steps to submits a DB query:
1. the JDBC is loaded to the JDBC driver
2. Connect to the data source
3. Execute the SQL query


example

```Java
String sql = "INSERT INTO Sailors VALUES(?,?,?,?)";
PreparedStatement pstmt=con.prepareStatement(sql);

// bind the variables
pstmt.clearParameters(); // reset parameter list
pstmt.setInt(1, sid); 
pstmt.setString(2, sname); 
pstmt.setInt(3, rating);
pstmt.setFloat(4, age); 
// INSERT belongs to the family of UPDATE operations
// (no rows are returned), thus we use executeUpdate()
int numRows = pstmt.executeUpdate();

```

the problem with this is that JDBC is vulnerable to`SQL injections `attacks

note that the result is called a `cursor` which is a DB Object returned from the executed query. This cursors allows use to navigate through the rows of the returned data and retrieve one row at a time for processing 

All error handling of JDBC is done in a very Java way, using two exceptions
1. SQLException if an error occurs
2. SQLWarning which has to be explicitly tested


## Embedded SQL

SQL that is directly written in the source code of the program

### SQLJ

this is Java + embedded JDBC access


### SQLJ vs. JDBC

its way shorter and more concise. SQL j is fully static and precompiled while JDBC can be both static and dynamic and also is at runtime

## Stored Procedures

A stored procedure is program that runs on the database server and can be
called with a single SQL statement.

1. **Precompiled**:
	1. Stored procedures are compiled and optimized by the database when they are created, leading to improved performance during execution.
2. **Reusable**:
	1. They can be called multiple times by applications or users, reducing code duplication and simplifying maintenance.
3. **Encapsulation**:
	1. Complex logic can be encapsulated within the database, keeping client applications simpler and reducing the need for redundant SQL code.
4. **Parameterization**:
	1. Stored procedures can accept input parameters, return output parameters, and pass results back to the calling program.
5. **Control Flow**:
	1. They support procedural constructs like loops (WHILE, FOR), conditionals (IF, CASE), and error handling (TRY...CATCH).

example

```MySql
CREATE PROCEDURE GetTotalSales(IN EmployeeID INT, OUT TotalSales DECIMAL(10,2))
BEGIN
    SELECT SUM(SaleAmount)
    INTO TotalSales
    FROM Sales
    WHERE SalesPersonID = EmployeeID;
END;
```