Written by Nik Tsonev

## Internet and Web Concepts

the internet had originally 4 basic services
1. telnet
2. ftp
3. mail
4. news

Each computer has a unique ID
- IP address n.n.n.n (32 bit for IPv4 or 128 bit for IPv6)
- Domain name
- DNS to link the Domain name to the corresponding IP address

The World Wild Web (WWW) was just another internet service that provided
1. HTTP - HyperText Transfer Protocol
2. HTML - HyperText Markup Language
3. URIs - Uniform Resource Identifiers

### HTTP

HTTP is just another transfer protocol like TCP or IP that define a set of rules and structure that computers must use when communicating to make sense, the same way we have grammatical rules in languages 

every time you click on a link, you send connect to a server, send that HTTP request, hopefully get on back from the server and then you both disconnect

#### HTTP Response Structure
- status Code 
	- 200 - Success
	- 400 - could not do the request
	- 404 - the request does not exists (page not found)
	- 505 - HTTP version is not supported
- Date of object creation
- Number of bytes sent
- Type of the object
- the object itself

Note that HTTP does not remember so we use cookies for that 

The standard convention is that index.html / htm / php is the default page of a server

## HTML Forms

this is a common way to send data to the backend,  for example

```HTML
<form action="back_end.php", method="GET" name="loginForm" >
	<input type=input value=0 name=formInput>
</form>
```

## HTML and Document Object Model (DOM)

every HTML has a DOM tree which shows the hierarchical structure of the page which always resembles some sort of tree 

![[HTML-Dom-tree.png]]

