Written by Nik Tsonev

## Introduction

`Secrecy` - Almost all of internet security is based on secrecy, the right for your information and identity to remain hidden

`Integrity` - users should not be able to modify data that they dont have access to, for example me modifying your bank account balance

`Availability` - Uses should be able to read and modify their data whenever they want

these are the cornerstones of internet security 


## Internet Security

the main issues are User authentication and trust. For a DB access, it need to come from a trusted location and a password based user to know only the right people can see and manipulate sensitive data

the problem is that over the internet, everything is visible, this is why people have invented encryption, which hides the data into unreadable shit. 

Note that malicious players can still read the data, it just wont make sense. 

there are two main types of encryption, `symetric` and `asymetric`

symmetric uses only one key to decrypt and encrypt messages, which leaded to the problem, how do you share said key

this is where `asymetric` encryption comes, where you use a `public` and `private` key. You give the public key to your friends and they can encrypt messages that only you can decrypt. 

TLDR.  the most common encryption is SHA256 

another way is to have levels of privilege such as admin and user 
## Database Access Control

Database access control refers to the mechanisms and policies implemented to manage and restrict access to the database, ensuring only authorised users can perform permitted operations. 

1. Authentication
2. Authorisation
3. Security Policies
4. Access Rights or Privileges

when it comes to access rights, the least privilege is the most secure, giving minimal to no privilege to the user 

## How to hack a database

`SQL Injection` - input SQL code into input fields so they get executed in the backend 

this can be anything from syntax errors to `DROP TABLE;` which would lead to data loss

a way to prevent this is to use parameters queries and to validate the input in the fronted or backend before being ran in the DB

`Buffer overflow` - when you add more data in than expected (usually exceeding the length of a string )

for example if username is VARCHAR(5); but in the string is 6 letters long, this would cause a buffer overflow

again this is prevented with filtering and data validation on the front/back-end

`Exploiting Error Messages` - checking what has failed to understand and manipulate the schema of the DB

this can be prevented by logging the errors but not displaying them to the user

`password exploitaion` - very common

if your admin password is admin, you will most likely get hacked

to prevent this, have long and random passwords that you change periodically 

To prevent most you must do the following
1. Use input validation
2. Minimise privileges
3. Encrypt sensitive data on the DB
4. Log any errors
5. Update and patch your code regularly 

