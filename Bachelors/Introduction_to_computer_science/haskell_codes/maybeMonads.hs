safeHead :: [a] -> Maybe a
safeHead [] = Nothing
safeHead (x:xs) = Just x
safeTail :: [a] -> Maybe [a]
safeTail [] = Nothing
safeTail (x:xs) = Just xs