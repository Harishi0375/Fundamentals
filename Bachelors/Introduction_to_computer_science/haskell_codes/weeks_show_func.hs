-- Define a custom data type representing days of the week
data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday

-- Define a Show instance for the Day data type
instance Show Day where
    -- Convert a Day value to a string for display purposes
    show d = show (getWeekdayIndex d) where
        -- Helper function to get the index of the day in the week
        getWeekdayIndex :: Day -> Int
        getWeekdayIndex Monday    = 1
        getWeekdayIndex Tuesday   = 2
        getWeekdayIndex Wednesday = 3
        getWeekdayIndex Thursday  = 4
        getWeekdayIndex Friday    = 5
        getWeekdayIndex Saturday  = 6
        getWeekdayIndex Sunday    = 7
