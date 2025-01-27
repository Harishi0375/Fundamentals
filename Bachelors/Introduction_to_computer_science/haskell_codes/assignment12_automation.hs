data Alphabet = A | B
    deriving(Show)

type Sequence = [Alphabet]

data State = W | X | Y | Z

automation :: State -> Sequence -> Bool
automation W (B : xs) = automation X xs
automation X [] = True
automation X (A : xs) = automation Y xs


automation Y (B : xs) = automation W xs || automation Z xs

automation Z (A : xs) = automation Z xs
automation Z (B : xs) = automation Y xs
automation _ _ = False

accept :: Sequence -> Bool
accept sequence = automation W sequence


ex1 = [A]
ex2 = [B,A,B,B,B,B]
ex3 = [B,A,B,B]
ex4 = []
ex5 = [B]




