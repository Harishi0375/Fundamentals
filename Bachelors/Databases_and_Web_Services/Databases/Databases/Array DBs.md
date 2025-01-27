Written by Nik Tsonev

an Array DB process multi-dimensional arrays such as images, sensor data and more 

Note that these dimensions do not mimic real world dimensions and can be almost anything, with many array DBs having 9 or more dimensions 

This provides us with a neighbourhood relationship in the data set telling us more than what a tradition DB could

these are commonly used in:
1. Earth sciences 
2. Space
3. Engineering
4. Statistics 


The Core Elements are 
1. Cells - individual data values within some range
2. Dimensions

to query these DBs we can sue `rasql` which is an extension for SQL 

Note that with Array Dbs we can perform `Linear Algebra` and is very useful for parallel computing  

1. **Adaptive Partitioning (Tiling)**:
	1. Arrays are partitioned into tiles for efficient storage and processing.
	2. Example: Define tiles based on areas of interest.
2. **Query Optimization**:
	1. Minimize data transfer using optimized evaluation pipelines.
3. **Integration with Big Data Frameworks**:
	1. Layers on top of Hadoop and Spark enable scalability.


