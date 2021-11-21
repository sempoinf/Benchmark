import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('/home/sempoinf/project3/results.csv')

fig, (ax1, ax2, ax3) = plt.subplots(3)

ax1.plot(df[['size']], df[['quick sort']], 'r')
ax2.plot(df[['size']], df[['counting sort']], 'b') 
ax3.plot(df[['size']], df[['quick sort']], 'r', df[['size']], df[['counting sort']], 'b')

ax1.set_title('Quick sort')
ax2.set_title('Counting sort')
ax3.set_title('Comparison')

plt.tight_layout()
plt.savefig('plot.png')
