from tkinter.tix import DisplayStyle

import numpy as np
import matplotlib.pyplot as plt

import pandas as pd #importing pandas

## Pandas DataFrame ------------------------------------------------------------------------------

#Pandas DataFrame objects can be constructed in many different ways, e.g., from a dictionary of lists or NumPy arrays having the same length. Column titles are automatically generated from the keys of the dictionary.

df1 = pd.DataFrame( {'City':['Bremen','Dresden','Essen','Stuttgart'],
                     'Residents in 1970':[592533,502432,696419,634202],
                     'Residents in 1990':[551219,490571,626973,579988],
                     'Residents in 2010':[547340,523058,574635,606588]} )
DisplayStyle(df1)
print('Index : ',df1.index)


#can also be written like this 
df2 = pd.DataFrame( {'Residents in 1970':[592533,502432,696419,634202],
                     'Residents in 1990':[551219,490571,626973,579988],
                     'Residents in 2010':[547340,523058,574635,606588]},
                   index=['Bremen','Dresden','Essen','Stuttgart'])
display(df2)
print('Index : ',df2.index)


#also like this 
cities = ['Bremen','Dresden','Essen','Stuttgart']
ser1970 = pd.Series([592533,502432,696419,634202],index=cities)
ser1990 = pd.Series([551219,490571,626973,579988],index=cities)
ser2010 = pd.Series([547340,523058,574635,606588],index=cities)
df3 = pd.DataFrame({'Residents in 1970':ser1970,
                    'Residents in 1990':ser1990,
                    'Residents in 2010':ser2010})
display(df3)
print('Index : ',df3.index)


#coloums
res2d = np.array([[592533,551219,547340],
                  [502432,490571,523058],
                  [696419,626973,574635],
                  [634202,579988,606588]])
df4 = pd.DataFrame(res2d,index=['Bremen','Dresden','Essen','Stuttgart'],
                   columns=['Residents in 1970','Residents in 1990','Residents in 2010'])
display(df4)