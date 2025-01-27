Written by Nik Tsonev

stands for Online Analytical Processing and is used for data warehousing. OLAP allows for multidimensional analysis 

its key features are
1. Allows multidimensional data analysis 
2. Uses aggregation functions (like SUM AVG)
3. Easy to use 
4. Multilayered client-server architecture

Note that there is also Online Transaction Processing (OLTP) which is more for transactional data while OLAP is more for analytical queries, trend analysis and decision making

a  question that can be answered using OLAP for a big company like Apple can be 

'How does performance this quarter compare to the same quarter last year?'

'What are the most profitable products this year?'

but also can be more scientific. It all depends on the field and context were in
## Data Warehousing

this is a centralised place for dat storage and analysis. Big Tech companies such as: Google, Apple, Facebook, Amazon and more have plenty of these

these warehouses have an ETL process
1. Extract - retrieve the data from the sources
2. Transform - clean and convert the data into meaning format that the warehouses use
3. Load - load the transfer data into the warehouse

## Datacubes

these are multidimensional data structure for analysis across different perspective (the dimensions)

note that datacubes are often represented by an array database 

Data cubes have a density, note that an average cube is about 3% dense, any more and it usually causes the warehouse to fail 

depending on the dimension but often enough when the dimension is time, the density of the cube relates to the amount of data entries there are. So a cube on the weekend for a shop will be much more `sparse` than a data cube on Tuesday

## OLAP Operatons

`slice` - extracts a sub-cub by selecting specific dimension values (filtering data to only show cubes in the weekend)

`dice` - creates a sub-cub by selecting values across dimensions, for example selecting only the fruits from a shop's product dimension

`roll-up` - aggregate data by hierarchy, for example view the monlthy sales instead of weekly 

`drill-down` - inverse of roll up,  seeing weekly sales instead of monthly

`pivot` - rotate the data axes for different perspective, how in excell you can change the rows, to columns and vice versa 

## OLAP Architecture

Relational OLAP (`ROLAP`) uses relational DBs for multidimensional analysis

with the most common schema types being `star`, `snowflake` and `galaxy` schema

Sorting intermediate results consumes ~70% of CPU time.

Multidimensional OLAP (`MOLAP`) stores the data in the multidimensional arrays as mentioned before, making it more efficient to compute and have pivot-based access


Hybrid OLAP (`HOLAP`) which is a combination of two above giving a more flexible, but more inneficient way to store and query Big Data

## Querying OLAP Systems

basic SQL lacks the tools for multidimensional operations as it was never built for such intent. However there is MDX (Multidimensional Expressions) which is basically an add on to SQL to make it multi dimensional

```SQL
SELECT {[Measures].[Store Sales]} ON COLUMNS,
       {[Date].[2020], [Date].[2021]} ON ROWS
FROM Sales
WHERE ([Store].[USA].[California])
```


