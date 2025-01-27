import pandas as pd 
import numpy as np

movie_database =  {"movie": ["The Shawshank Redemption",
                             "The Godfather",
                             "The Godfather: Part II",
                             "The Dark Knight",
                             "Pulp Fiction",
                             "12 Angry Men",
                             "The Good, the Bad and the Ugly",
                             "The Lord of the Rings: The Return of the King",
                             "Schindler's List",
                             "Fight Club",
                             "The Lord of the Rings: The Fellowship of the Ring",
                             "Inception",
                             "Star Wars: Episode V - The Empire Strikes Back",
                             "Forrest Gump"],
                   "duration": [142, 175, 200, 152, 154, 96, 161,
                                201, 195, 139, 178, 148, 124, 142],
                   "rating": [9.3, 9.2, 9.1, 9, 8.9, 8.9, 8.9, 8.9,
                              8.9, 8.9, 8.8, 8.8, 8.8, 8.8],
                   "genre": [ "Crime", "Crime", "Crime", "Action",
                              "Crime", "Drama", "Western",
                              "Adventure", "Biography", "Drama",
                              "Adventure", "Action", "Action", "Drama"]
                   }

movie_reviews = pd.DataFrame(movie_database)
print(movie_reviews)

print("------------------------")
print(movie_reviews.head())
#head provides to look at the first few rows
#for readability

print("------------------------")
movie_reviews.tail()
# shows the last few elements

print("------------------------")
print(movie_reviews.columns)
# prints the headers

print("------------------------")
# list of lists
print(pd.DataFrame([[1,2,3],[4,5,6],[4,3]]))

print("------------------------")
#two dim numpy arr (3*4)
print(pd.DataFrame(np.random.rand(3,4)))

# Adding New Columns to DataFrame -----------------------
print("------------------------")
print(pd.DataFrame(movie_database , columns=["movie", "year", "duration"]))

# Accessing Data from a DataFrame
print("------------------------")
print(movie_reviews["movie"])

print("------------------------")
movie_reviews[["movie", "genre", "duration"]]
#order changed 


# In order to access a row loc is used with labels passes within square brackets, as follows.
print(movie_reviews.loc[2]) #accessing row with index 1
print("---------------")
print(movie_reviews.iloc[2])  # Accessing row with integer index 1
print("------------------------")
# print(movie_reviews.loc[[2, "t"]])

#slicing
print("------------------------")
print(movie_reviews.loc[1:5], ["movie", "duration", "rating"])

# In order to select a particular element from the DataFrame, we use at as follows
print("------------------------")
print(movie_reviews.at[2, "movie"])


#slicing
print("------------------------")
print(movie_reviews.iloc[0:5,0:2]) 


# Accessing Data using Boolean Series
print("------------------------")
ratings_for_filter = (movie_reviews["rating"] > 9.0)
print(movie_reviews[ratings_for_filter]) # True selects rows

# Arithmetic with DataFrame
print("------------------------")
movie_ratings = movie_reviews[["movie", "rating", "genre"]]
print(movie_ratings)
print(movie_ratings * 2)


print("")
#----------------------------------------
df1 = pd.DataFrame(np.random.rand(3,2),columns=['a', 'b'])
print(df1)

df2 = pd.DataFrame(np.random.rand(2,3),columns=['a', 'c', 'd']) 
print(df2) #ONLY ADDS WITH SAME COLUMN NAME

print(df1 + df2)

print(df1.add(df2))

print(df1.add(df2, fill_value=0))


print("")
#----------------------------------------
ds = movie_ratings["rating"]    # pandas Series
df = pd.DataFrame(ds)           # Series to DataFrame
df["movie"] = ""                # Add column with empty strings
df["genre"] = ""                # Add column with empty strings
df["duration"] = 0              # Add column with zero value
movie_reviews.add(df)           # Add two data frames

#Function and Mapping
df = pd.DataFrame(np.random.rand(3,2), columns=['A', 'B'])

print(df)

print(df.min())                 # DataFrame's method min.

print(df.apply(np.min)) # Numpy function min using apply.

print(df.apply(np.min, axis="columns"))


print("")
#----------------------------------------
def double_value_maybe(x):
    if type(x) == float:
        return 2*x
    else:
        return x

print(movie_reviews.applymap(double_value_maybe))
