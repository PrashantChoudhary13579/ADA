import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns

x = np.array((10,100,1000,10000,100000,1000000,10000000,100000000))
y = np.array((0,0,0,3014000,6047000,60420000,472104000,4425808000))
z = x ** 2
plt.plot(x,y)
# plt.plot(x,)
plt.xlabel("Multiple of 10 ")
plt.ylabel("Time taken")
plt.xscale("log")
plt.yscale("log")
plt.ticklabel_format(useOffset=False,style ="plain")
plt.show()
