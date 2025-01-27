data Car = Car {brand::String, model::String, year::Int} 
    deriving(Show)
-- year :: Car -> Int
-- year (Car _ _ y) = y

data List a = Empty | Cons a (List a) 
    deriving(Ord)

instance (Show a) => Show (List a) where
    -- show :: Show a => List a -> String
    show Empty          = "."
    show (Cons x xs)    = show x ++ " " ++ show xs

instance (Eq a) => Eq (List a) where
    -- (==) :: Eq a => List a -> List a -> Bool
    Empty == Empty = True
    (Cons x xs) == (Cons y ys) = (x == y) && (xs == ys)
    _ == _ = False

data BinTree a = EmptyTree | Node a (BinTree a) (BinTree a) 
    deriving(Show)

insertTree :: (Ord a) => a -> BinTree a -> BinTree a
insertTree x EmptyTree = Node x (EmptyTree) (EmptyTree)
insertTree x (Node y left right) 
    | x == y    = Node x left right
    | x < y     = Node y (insertTree x left) right
    | x > y     = Node y left (insertTree x right)

tree :: BinTree Integer
tree = foldr insertTree EmptyTree [8,6,4,1,7,3,5,42,3,-42,0]