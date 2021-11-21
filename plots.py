import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('/home/eugeneknvlv/flita/results.csv')

fig, (ax1, ax2, ax3) = plt.subplots(3)

ax1.plot(df[['size']], df[['merge sort']], 'r')
ax2.plot(df[['size']], df[['selection sort']], 'b') 
ax3.plot(df[['size']], df[['merge sort']], 'r', df[['size']], df[['selection sort']], 'b')

ax1.set_title('Merge sort')
ax2.set_title('Selection sort')
ax3.set_title('Comparison')

plt.tight_layout()
plt.savefig('plot.png')
