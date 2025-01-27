Written By Nik Tsonev

## Resource Description Framework (RDF)

this is a framework for the Web with labeled graphs and is specifically designed for computers and not humans. 

RDF statement = resource with properties with values


RDF can be find in URLS and XML files]


## SPARQL

Short for - Simple Protocol and RDF Query Language

extracts information in the form of URIS, blank nodes or plain text 
extracts RDF subgraphs
Construct new RDF graphs based on information in the queried graphs


so for example

```SQL
SELECT name, email
FROM Person
```

would look as follows in SPARQL

```SPARQL
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
SELECT ?name ?email
WHERE {
	?person rdf:type foaf:Person.
	?person foaf:name ?name.
	?person foaf:mbox ?email.
}
```

so the url and then the tag for name and email