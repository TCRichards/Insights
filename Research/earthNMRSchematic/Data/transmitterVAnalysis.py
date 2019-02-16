import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

names = ['time', 'signal', 'op1', 'output']
data = pd.read_excel('transmitterV.xlsx', header=1,names=names).values

time = data[1:,0]; signal = data[1:,1]; output = data[1:,3]


plt.plot(time[0:1000], signal[0:1000], label='Input Signal')
plt.plot(time[0:1000], output[0:1000], label='Output Signal')
plt.xlim(time[0], time[1000])
plt.xlabel('time (s)')
plt.ylabel('V')
plt.ticklabel_format(axis='y', style='sci',scilimits=(-2,2))
plt.title('Transmitter Input and Output Signals')

plt.legend()

plt.show()
