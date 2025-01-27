map :: (a -> b) -> Tree a -> Tree b
map f Empty = Empty
map f (Leaf x) = Leaf (f x)
map f (Branch x l r) = Branch (f x) (map f l) (map f r)


foldr :: (a -> b -> b) -> b -> Tree a -> b
foldr _ z Empty = z
foldr f z (Leaf x) = f x z
foldr f z (Branch x l r) = foldr f (f x (foldr f z r)) l

