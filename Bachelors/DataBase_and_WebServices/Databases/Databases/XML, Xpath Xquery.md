Written by Nik Tsonev

## eXtensible Markup Language (XML)

a flexible mechanism for specifying `domain-specific` data formats

its structor is very similar to HTML with the same hierarchy of parent to nested children 

![[XML-example.png]]


The benefit of XML is that it can represent entities, it is atomic, but does not really have relations

```XML
<?xml=version="10?>
<catalog>
	<price>10.9</price>
	<price>231.1</price>
	<price>23.1</price>
</catalog>
```

## XQuery

this is the act of retrieving data from an XML file 

this is what SQL is to tables

XPath - extra from the DOM tree: 
XQuery - derive new structure
stored in DB or files

example code, where we want to get all the book titles that have been published after 1995

```XQuery
FOR $x IN document("name.xml")
WHERE $x/year > 1995
RETURN $x/title
```

assuming the file has the tags, Year and title. 

Note that like in SQL XQuery can also have aggregate functions like sum or distinct 