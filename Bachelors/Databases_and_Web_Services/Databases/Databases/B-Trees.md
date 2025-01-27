Written by Nik Tsonev

B-Trees are a type of tree that can have up to `m` elements per node. This is useful for indexing and is the basis of how databases search for stuff from disk

![[B-trees.png]]

note that every none root node must have $Round(\frac{m}{2})$ nodes

so if m = 5, every non-root node must have 3 nodes. 

note that when inserting, if you have exceeded the capacity of of m, that would cause the node to split in have making the median (middle node), become the parent. This can be recursive up to the root, in which case the tree would `grow` by a height of 1


### Properties of a B-Tree

1. Balanced - all leaf nodes are at the same depth
2. 
3. Minimum keys - each non-root node must have at least $Round(\frac{m}{2})$ keys, to ensure that its dense
4. They keys within a node must be sorted 

note that the `fan out` of these trees are big, meaning that they become super wide


## B+trees

it is similar to a B tree, but every leaf element is actually a pointer to some value in disk. They are one of the best Data structures for systems with slow disk access as they minimise I/O operations

B+trees contains two types of nodes

`internal nodes` - nodes that are presents in $\frac{m}{2}$ record pointers but not in the root

`lead nodes` - are the nodes that have n pointers

![[b+tree.png]]

and this is how they points to disk

![[b+tree-continuted.png]]
### Properties

1. Balanced - self balancing
2. Multi-level - 
3. Ordered - range queries are super easy as they are order in asc or desc
4. Fan-out - because its super wide it makes it very efficient as the access complexity  is $\log(height)$
5. Cache-friendly - this prevents more disk I/O making it faster as we dont need to fetch the data

the properties asked for on the exam

1. Separation of Keys and Data 
2. Balanced
3. Doubly linked leaf nodes, allows for more efficient range queries as data is sequential
4. Dynamic Node Utilisation - making the tree always dense
### Querying ranges

imagine now you are asked how does the DB find the range of 43 to  73?

![[b+tree-querying.png]]

first you know its between 30 and 80 so you go in that subtree, than between 42 and the rest, you grab everything in the subtrees but the last node `79` in the last subtree as it is greater than 37

