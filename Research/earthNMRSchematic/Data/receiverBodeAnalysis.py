import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

names = ['Frequency', 'Gain (dB)', 'Gain', 'Phase']
data = pd.read_excel('receiverBode.xlsx', header=1,names=names).values


freq = data[1:,0]; gainDb = data[1:,1]; gainRaw = data[1:,2]; phase = data[1:,3]

plt.plot(freq,gainRaw)
plt.xlabel('Frequency (Hz)')
plt.ylabel('Gain')
plt.ticklabel_format(axis='y', style='sci',scilimits=(-2,2))
plt.xlim(500, 3500)
#plt.ylim(50, 100)
plt.title('Bode Plot for Receiver')
peakIdx = np.argmax(gainDb)
peakFrq = freq[peakIdx]

plt.show()

plt.plot(freq,gainDb)
plt.xlabel('Frequency (Hz)')
plt.ylabel('gain (dB)')
plt.ticklabel_format(axis='y', style='sci',scilimits=(-2,2))
plt.xlim(500, 3500)
#plt.ylim(50, 100)
plt.title('Bode Plot for Receiver')
peakIdx = np.argmax(gainDb)
peakFrq = freq[peakIdx]


'''
for i in range(len(gainDb)):
    if

'''


print('Maximum Gain = ' + str(gainRaw[peakIdx]) + ' (' + str(gainDb[peakIdx]) + ' dB)')
print('Peak at ' + str(peakFrq) + ' Hz')


plt.show()
