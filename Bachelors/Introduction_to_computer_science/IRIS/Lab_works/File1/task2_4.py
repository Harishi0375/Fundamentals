import matplotlib . pyplot as plt
fig = plt. figure () # an empty figure with no Axes
fig ,ax = plt. subplots () # a figure with a single Axes
fig , axs = plt. subplots (2, 2) # a figure with a 2x2 grid of Axes
ax. plot ([1 ,2 ,3 ,4] ,[4 ,3 ,2 ,1])
axs [0][0]. plot ([1 ,2 ,3 ,4] ,[1 ,2 ,3 ,4])
axs [0][1]. plot ([1 ,2 ,3 ,4] ,[1 ,6 ,4 ,2])
plt.show()