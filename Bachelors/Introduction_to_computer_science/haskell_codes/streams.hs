data Stream a = a :| Stream a  

instance (Show a) => Show (Stream a) where
    -- show :: Show a => Stream a -> String
    show (x :| xs) = show x ++ " : " ++ show xs

lift0 :: a -> Stream a 
lift0 x = x :| lift0 x

-- --explaining lift1
-- lets say op is (+1) 
-- it adds +1 to all the elements

lift1 :: (a -> a) -> (Stream a -> Stream a)
lift1 op (x :| xs) = op x :| lift1 op xs

lift2 :: (a -> a -> a) -> Stream a -> Stream a -> Stream a 
lift2 op (x :| xs) (y :| ys) = (x `op` y) :| lift2 op xs ys

lift3 :: (a -> a -> a -> a) -> Stream a -> Stream a -> Stream a -> Stream a
lift3 fn (x :| xs) (y :| ys) (z :| zs) = (fn x y z) :| lift3 fn xs ys zs

-- followed by
fby :: a -> Stream a -> Stream a
fby x ys = x :| ys

trues, falses :: Stream Bool
trues = lift0 True
falses = lift0 False

nots :: Stream Bool -> Stream Bool
nots = lift1 not

ands, ors :: Stream Bool -> Stream Bool -> Stream Bool
ands = lift2 (&&)
ors = lift2 (||)

tf :: Stream Bool
tf = fby True (nots tf)

fftt :: Stream Bool
fftt = fby False (fby False (nots fftt))

jk :: Bool -> Bool -> Bool -> Bool
jk q False False = q
jk q True True = not q 
jk _ True False = True
jk _ False True = False

jks :: Stream Bool -> Stream Bool -> Stream Bool -> Stream Bool
jks = lift3 jk

-- JK Flip Flop
jkFlipFlop :: Stream Bool -> Stream Bool -> Stream Bool 
jkFlipFlop js ks = tailStream qs where
        qs = fby False (jks qs js ks)

-- auxiliary functions on Streams
tailStream :: Stream a -> Stream a
tailStream (_ :| xs) = xs

headStream :: Stream a -> a
headStream (x :| _) = x 

giveme :: Int -> Stream a -> [a]
giveme 0 _          = []
giveme n (x :| xs)  = x : (giveme (n-1) xs)

