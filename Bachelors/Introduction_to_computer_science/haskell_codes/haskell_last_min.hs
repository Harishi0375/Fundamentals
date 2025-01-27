head [1...10] = 1
last [1...10] = 10

tail[1...10] = [2...10]
init[1...10] = [1...9]

--infix
myfunc x y
[1,2] ++ [2,3] = [1,2,2,3]
-- prefix
x 'myfunc' y 
(++) [1,2] [2,1]

take 10 [1..] = [1...10] --takes first 10 elements removes
drop 10 [1...20] = [11...20]  -- last 10 elements 


--two return multiple values
myfunc :: Int -> Int -> Int -> (Int,Int)
myfunc x y z = (x + y + z, x - y - z) --(sum,sub)

--CHURCH BOOLEANS
sum = \x -> \y -> x + y 
sum 5 3 = 8 


-- map: to apply each function on each value of a list
map (+3) [1,2,3] = [4,5,6]
map (<) [1,2,3] = [(<1),(<2),(<3)]
map isEven [1,2,3] = [False,true,False]


--filter: returns the values that are true for the function 
filter isEven [1,2,3] = [2]

data Maybe x = Nothing | Just x

data Result x = Error | Ok x
divide x y 
    | y == 0 = Nothing -- in lambda notation: | (\x -> \y -> y == 0) = Nothing 
    | x == 0 = Just 0
    | otherwise = Just (div x y)



--FUNCTORS

divide 4 2 = Just 2 
5 + (divide 4 2)
5 + (extract ( Nothing ))

extract :: Maybe Int -> Int
extract Nothing = 0
extract (Just myvar) = myvar


-- class Functor f where
--     fmap :: (a -> b) -> f a -> f b

-- example with binary tree 
instance Functor BTree where
    fmap _ Nil = Nil 
    fmap f (Node x left right) = Node (f x) (fmap f left) (fmap f right)


-- FOR THIS EXAMPLE:
data Maybe x = Nothing | Just x

instance Functor Maybe where
    fmap f Nothing = Nothing 
    fmap f (Just num) = Just (f num)
    