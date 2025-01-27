Written by Nik Tsonev

A `transaction` is a set of SQL operations executed atomically
it ensures that DBs remain consistent 

`concurency` doing something one after the other super fast

Transaction need to have an ACID Property

`Atomic` - all transaction need an all or nothing system to prevent falls reads and writes.

`Consitency`  -  a transaction changes the state of the DB, this is why the integrity of the schema must always hold

`Isolation` - Transactions operate independently, changes are not visible to each other until they have been committed 

`Durability` - once a transaction is commit, its changes are permanent unless a new transaction changes the state of the DB

note that for noSQL there is BASE - Basically Available Soft-state Eventually Constant

`Basically Available` - The system guarantees availability even in the presence of failures. Partial responses are better than no response. I.e a website may return stale data instead of nothing

`Soft-state`- The state of the system can change over time, even without new inputs, as data is propagated and eventually reconciled. i.e cache system briefly showing inconsistent data across nodes 

`Eventually Constant` - The system will eventually become consistent, given enough time and the absence of new updates. i.e update to global shopping carts might take a second to update 

### ACID VS BASE



| Feature          | ACID                       | BASE                        |
| ---------------- | -------------------------- | --------------------------- |
| Consistency      | Strictly Consistent        | Eventually Consistent       |
| Availablity      | May sacrifice              | High priority               |
| Performance      | Low in distributed systems | High in distributed systems |
| Scalability      | Limited                    | Highly                      |
| System Type      | Relational                 | noSQL                       |
| Use Case         | Finance, healthcare        | E-commerce, Social media    |
| Failure Handling | Strict failure Rollbacl    | Gracefull degradation       |

**ACID** is ideal for systems that demand accuracy and consistency, where failure must be tightly controlled

**BASE** caters to systems that need to scale massively and tolerate temporary inconsistencies for availability
## SQL Syntax

to begin a transaction you do `START TRANSACTION`
commit changes - `COMMIT`
Rollback to abort the transaction and undo any changes before committing `ROLLBACK`

## Concurrency issues 
### Anomalies from interleaved executions

dirty reads can occur when reading uncommitted data. This can also lead to unpredictable and inconsistent data reads, which (for example in banking) is very bad. 

Another issue is overwriting uncommitted data. With the example of banking imaging your paycheque transaction gets overwritten by an expense transaction causing you to lose money from it being spent and not receiving your paycheque 

## Concurrency Control 

1. Locks - like in multithreading, they can be either shared (for reading) or mutually exclusive for writing
2. **Two-Phase Locking (2PL)**:
	1. **Phase 1 (Growing)**: Locks are acquired.
	2. **Phase 2 (Shrinking)**: Locks are released.
	3. **Strict 2PL**: Locks released only after commit, simplifying abort handling.
3. **Isolation Levels**:
	1. **READ UNCOMMITTED**: Allows dirty reads.
	2. **READ COMMITTED**: Prevents dirty reads but allows unrepeatable reads.
	3. **REPEATABLE READ**: Prevents unrepeatable reads but may allow phantom reads.
	4. **SERIALIsABLE**: Full isolation, ensures serialisable execution.

another way (and a very common one) is to use logs. 

logs are just files that contain the history of every DB action. and what we can do is ahead log which records all of the 'changes' while the data is being fetched from disk, and once we have the data, do all of the operations written in the log in chronological data 

this saves a lot of time as we dont need to wait for the fetched data and can perform everything at once

logs also allow us to rollback and undo transactions super easily as we can see the previous steps. 


logs are also used to recover data before a crash, redo and undo any faulty/needed operations. 

Note that most banks for example, use super big log files and almost never discard them while most other industries do after some time, but they replace them with new logs




