# ratings is pandas series created above
import numpy as np
import pandas as pd


idx = ["The Shawshank Redemption",
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
       "Forrest Gump"]

lst = [9.3, 9.2, 9.1, 9, 8.9, 8.9, 8.9, 8.9, 8.9, 8.9, 8.8, 8.8, 8.8, 8.8]

ratings = pd.Series(lst, index=idx)

print(np.count_nonzero(ratings == 8.9))
print("------------------------")
print(np.log(ratings))
print("------------------------")
print(ratings + ratings[ratings > 9])
print("------------------------")
ratings_added_maybe = ratings + ratings[ratings > 9]
print(pd.isna(ratings_added_maybe))
print("------------------------")
