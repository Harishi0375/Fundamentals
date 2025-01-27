-- Algebraic Data Types
-- Encoding of Boolean Expressions
--
-- Constructor University
-- Introduction to Computer Science
-- Joaquin Aguado

data Variable = X | Y | Z -- set of Boolean variables
    deriving(Show)

data BExp = Var Variable 
            | F   
            | T  
            | Not BExp 
            | BExp :/\ BExp 
            | BExp :\/ BExp

instance Show BExp where
    -- show :: BExp -> String
    show (Var x) = show x
    show (F) = "0"
    show (T) = "1"
    show (Not e) = "(~" ++ show e ++ ")"
    show (e0 :/\ e1) = "(" ++ show e0 ++ " /\\ " ++ show e1 ++ ")"
    show (e0 :\/ e1) = "(" ++ show e0 ++ " \\/ " ++ show e1 ++ ")"

-- some expressions
f0 = Var X :/\ Not (Var X)
f1 = (Var X :/\ Var Y) :\/ (Not (Var X) :/\ Not (Var Y) :\/ F)
f2 = (Var X :/\ Not (Var Y)) :/\ (Var Z :/\ Not (Var X))

-- interpretations
type Interpretation = Variable -> Bool

i0 :: Interpretation 
i0 X = True
i0 Y = True
i0 Z = False

i1 :: Interpretation 
i1 X = False
i1 Y = True
i1 Z = False

eval :: Interpretation -> BExp -> Bool
eval _ F = False
eval _ T = True
eval i (Var x) = i x
eval i (Not e) = not (eval i e)
eval i (e1 :/\ e2) = eval i e1 && eval i e2
eval i (e1 :\/ e2) = eval i e1 || eval i e2
