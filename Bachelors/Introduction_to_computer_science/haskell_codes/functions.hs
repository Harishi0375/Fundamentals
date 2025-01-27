maps :: (a -> b) -> [a] -> [b]
maps f [] = []
maps f (x:xs) = f x : maps f xs

