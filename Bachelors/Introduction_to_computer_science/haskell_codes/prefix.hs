prefix :: Eq a => a -> [a] -> [a]
prefix _ [] = []
prefix e (x:xs) 
    | e == x = [x]
    | otherwise = x : prefix e xs