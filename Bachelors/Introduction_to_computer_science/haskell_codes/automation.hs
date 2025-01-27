-- finite state automation

data Alphabet = X | Y
    deriving(Show) -- to show X and Y

type Sequence = [Alphabet]

-- old version
data State = S | SX | SY

-- new version
-- data State a = State a

-- instance Functor State where
--     --fmap :: (a -> b) -> state a -> state b
--     fmap f (State s) = State (f s)

transition :: Alphabet -> Int -> Int
transition X 0 = 1
transition Y 0 = 2
transition X 2 = 1
transition Y 1 = 2
transition _ _ = 3

--new version
-- automation :: State Int -> Sequence -> Bool
-- automation s (x:xs) = automation (fmap (transition x ) s) xs
-- automation (State 1) [] = True
-- automation (State 2) [] = True
-- automation _ [] = False

--old version
automation :: State -> Sequence -> Bool 
automation S (X : xs) = automation SX xs
automation S (Y : xs) = automation SX xs
automation SX (Y : xs) = automation SY xs
automation SX [] = True
automation SY (X : xs) = automation SX xs
automation SY [] = True
automation _ _ = False

accept :: Sequence -> Bool
accept sequence = automation S sequence
-- accept sequence = automation (State 0) sequence


ex1 = []
ex2 = [X,Y,X,Y]
ex3 = [X,Y,Y]