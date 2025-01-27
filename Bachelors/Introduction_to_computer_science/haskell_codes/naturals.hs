data Naturals = Zero | Succ Naturals
    --deriving(Show)

--tpye 'Naturals' to strings for display purposes
instance Show Naturals where
    show n = show (iterate n) where -- iterate :: Natural -> Integer
        iterate Zero = 0
        iterate (Succ m) = 1 + iterate m

zero,one,two,three,four :: Naturals
zero = Zero
one = Succ zero
two = Succ one
three = Succ two
four = Succ (Succ (Succ (Succ zero)))

--Addition
infixl 6
plus :: Naturals -> Naturals -> Naturals
n plus Zero = n
n plus (Succ m) = Succ(n plus m)

infixl 2 (<*>)
(<*>) :: Naturals -> Naturals -> Naturals 
n <*> Zero = Zero
n <*> Succ m  = (n <*> m) <+> n

(</>) :: Naturals -> Naturals -> Naturals 
n </> Zero = error
Zero </> _ = Zero
n </> (Succ m) = (<*>) m (1/Succc m)