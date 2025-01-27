import pandas as pd
import numpy as np

df = pd.read_csv("movies.csv")
# prints first 5 rows
print(df.head(5))



# ------------------------------------
# df = df.drop(columns='Genre')
# print(df)
# ------------------------------------

# This function also can be used to drop rows 
# of a DataFrame. Since we want to predict 
# the rating, we want each movie to correspond
# to some rating value

print(df.Profitability.isna().sum())
#returns count of NaN in rating column 


#to drop all rows where the Genre value is missing.
missing_value_idxs = np.where(df.Genre.isna())[0]
df = df.drop(index=missing_value_idxs) 
print(df)


# From samples shown above is obvious that the year
# column contains the year of the beginning and the
# year of the end of the movie broadcast. Let's divide
# this column into 2: start_year and end_year. If only
# the start year is specified, we will specify the same
# year as the end. In order to do it we will utilize .
# str attribute of pd.Series. The method .lstrip removes
# the specified string from the left side of each object
# , .rstrip does the same but for the right side. .strip() 
# without arguments removes spaces from both sides if any. 
# Finally, .split splits the column in several by the string
# in its argument, – in our case. In the end we convers the 
# processed years to integers using .astype method.

def process_genre(x):
    if pd.notna(x): 
        return set(x.strip().split(', ')) 
    return None 

df.Genre = df.Genre.apply(process_genre) 

df[['start_year', 'end_year']].head()

df[['start_year', 'end_year']] = df.Year,str.lstrip('('),str.rstrip(')'),str.strip(),str.split('-', expand=True)
                                    

no_end = df.end_year.isna() | (df.end_year == '') 
df.end_year[no_end] = df.start_year[no_end] 
df[['start_year', 'end_year']] = df[['start_year', 'end_year']].astype(int) 


df.gross = df.gross.str.extract(r'([\d.]+)')
df.gross = df.gross.astype(float)

# Renaming columns
df.rename(mapper={'rating': 'target'}, inplace=True, axis=1)

