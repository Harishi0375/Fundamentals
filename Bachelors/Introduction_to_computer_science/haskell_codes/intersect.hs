intersect :: Eq a => [a] -> [a] -> [a]
intersect [] _ = []
intersect (x:xs) (y : ys)
    | elem x ys = x : intersect xs (filter (/=x) ys)
    | otherwise = intersect xs ys