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
print(ratings)

print(ratings > 9.0)

# ratings is a pandas series defined above
ratings_greater_than_9_mask = (ratings > 9.0) # pandas series with boolean dtype

ratings_greater_than_9 = ratings[ratings_greater_than_9_mask]

print(ratings_greater_than_9)

#list of indices as a slice
lst2 = ["The Shawshank Redemption", "The Godfather"]
ratings_greater_than_9[lst2]
