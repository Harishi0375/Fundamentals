-- Define a binary tree data type
data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Eq, Ord)

-- Define the insert function
insert :: (Ord a) => a -> Tree a -> Tree a
insert x EmptyTree = Node x EmptyTree EmptyTree
insert x (Node y left right)
    | x == y = Node x left right
    | x < y  = Node y (insert x left) right
    | x > y  = Node y left (insert x right)

-- Create an empty tree
emptyTree :: Tree Int
emptyTree = EmptyTree

-- Insert some values into the tree
tree :: Tree Int
tree = foldr insert emptyTree [5, 3, 8, 2, 4, 7, 9]

-- Print the resulting tree
main :: IO ()
main = print tree
main2 :: IO ()
main2 = print emptyTree


inOrder :: Tree a -> [a]
inOrder EmptyTree = []
inOrder (Node n l r) = inOrder l ++ [n] ++ inOrder r
