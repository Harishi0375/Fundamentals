data Boolean = Trues | Falses

instance Show Boolean where
    show Trues = "is a student"
    show Falses = "is not a student"

data Person a = Person String a Boolean

instance Show a => Show (Person a) where
    show (Person x y z) = "[ " ++ show x ++ " is " ++ show y ++ " years old and " ++ show z ++ " ]"


newAge :: Person a -> a -> Person a 
newAge (Person name _ status) newAgeValue = Person name newAgeValue status
