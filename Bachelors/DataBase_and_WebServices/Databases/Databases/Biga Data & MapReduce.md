Written by Nik Tsonev

Big Data isa term used for data that is so big that it is hardly humanly understandable and therefore not applicable to our current data tools

Big data can be summarised by the `4Vs`
1. Volume - Large quantities of Data
2. Velocity - high-speed data generation and processing
3. Variety  -  diverse data types
4. Veracity - Data accuracy and reliability 

Big Data now is applied almost in every field, from natural sciences, to business, medicine and more

## Most Common Big Data Tools

`MapReduce` is a big one, invented by Google that allows for data to be split and computed in parallel (Hadoop and Spark are some examples)

`NoSQL` DBs are ones that can handle big data because of how lightweight they are, at the cost of functionality

for the exam, you mostly need to know `MapReduce` and the `4V`

## MapReduce

mapRedce is inspired by functional programming and its lack of side effects making it instantly ready to be run in parallel 

the programming model is based on sets of key/value pairs and  has two main functions:

map(inKey, inValue) -> (outKey, intermidiateValueList)

reduce(outKey, intermediateValuelist) -> outValuelist)

which are the equivalent of `group by` and `aggregation` in SQL
