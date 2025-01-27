Written by Nik Tsonev

The intention was that our CPUs have many cores and it would be stupid not to utilise all of them. Also in Data centres, the transmission of data via LAN is much cheaper than disk I/O 

the main challenge is how to prevent data corruption and synchronisation of the paralleled processes 

## Main types of Parallelisation

`Pipeline` is when machines each doing one step of the process in a multi processor 

![[pipeline-parallel.png]]

`Partion` is when many machines are doing the exact same task but on different chunks of the data
![[partition-parallel.png]]


## Architecture for Parallel DBs

![[p-db-arch.png]]

note that the Shared nothing architectures is the most scaleable but also the most difficult one to implement 

## Data partitioning 

there are 3 main ways to partition
1. Round Robin
2. Hash Partitioning
3. Range Partitioning

Each one is quite self explanatory but here is a diagram to help out 

![[types-of-partition.png]]

## Parallelisation of Query Operators

this discussion assumes that
1. these are read-only queries
2. its in a Shared-nothing architecture
3. There are N processors and N disks where $D_i$ is associated with $P_i$

### Filter
How is work distribution among processors?
- Point query σA=v(R), range query σv1<A<v2(R)
- Load balancing

Round robin: all servers do the work

Hash partition:
- One server for σA=v(R)
- All servers for σv1<A<v2(R)

 Range partition: one server does the work
 
 ![[p-filter.png]]

## Sort-Merge with Range-partitioning

Choose a `partition vector`

Scan table in parallel

each partition sorts locally and then you merge 

the biggest problem is that the data can be unevenly skewed (think of a normal distribution) and so some processors are destined to do way more work while the others lay around doing nothing causing a `bottleneck`

![[data-skew.png]]

### Partitioned Join

For Equi-Join  $R_{R.A=S.B}$ S :
- partition input relations, distribute
- compute join partitions
- recollect

Partition R, S on join attrs R.A & S.B
- No need to sort
- Range, hash partitioning all fine

Corresponding partitions $R_i$ & $S_i$ -> processor $P_i$,

Pi locally computes $R_i$ join $_{Ri.A=Si.B}$  $S_1$
- Any standard join method

![[p-equi-join.png]]

## Summary

very good on performance if done correctly. The biggest is is data partitioning and data skew and that it is complex to optimise 