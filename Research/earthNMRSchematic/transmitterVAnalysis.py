import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

names = ['time', 'signal', 'op1', 'output']
data = pd.read_excel('transmitterV.xlsx', header=1,names=names).values

time = data[1:,0]; signal = data[1:,1]; output = data[1:,3]


plt.plot(time, signal)
plt.xlabel('time (s)')
plt.ylabel('V')
plt.ticklabel_format(axis='y', style='sci',scilimits=(-2,2))
plt.xlim(500, 3500)
plt.title('Bode Plot for Receiver')



plt.show()
