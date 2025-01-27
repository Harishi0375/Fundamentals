-- Lambda Calculus
-- Church encoding of Booleans
--
-- Constructor University
-- Introduction to Computer Science
-- Joaquin Aguado

{-# LANGUAGE RankNTypes #-}

type Boolean = forall a. a -> a -> a 

-- Translates from Church encoding into regular Bool type
eval :: Boolean -> Bool
eval bool = bool True False

-- constants
true, false :: Boolean
true    = \t -> \_ -> t 
false   = \_ -> \f -> f

-- negation
neg :: Boolean -> Boolean
neg = \b -> b false true

-- conjunction, disjunction
conj, disj :: Boolean -> Boolean -> Boolean
conj = \x -> \y -> x y x
disj = \x -> \y -> x x y

imp :: Boolean -> Boolean -> Boolean
imp = \x -> \y -> x y (neg x)

xor :: Boolean -> Boolean -> Boolean
xor = \x -> \y -> x (neg y) y 

contrapositive :: Boolean -> Boolean -> Boolean
contrapositive = \x -> \y -> imp (neg x) (neg y)

nand :: Boolean -> Boolean -> Boolean
nand = \x -> \y -> conj (neg x) (neg y)
