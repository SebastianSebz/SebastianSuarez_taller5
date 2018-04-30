import matplotlib.pyplot as plt
import numpy as np

Campo = np.loadtxt("campoE.txt")
n = np.size(Campo,1)
n2 = int(n/2)

Campox = Campo[:,:n2]
Campoy = Campo[:,n2:]

DataV = np.loadtxt("placas.txt")
X,Y = np.meshgrid(range(n2),range(n2))

plt.figure()
plt.imshow(DataV,cmap='PuRd')
plt.colorbar()
plt.ylim(0,510)
plt.xlim(0,510)
plt.streamplot(X,Y,Campox,Campoy, density=1.0, linewidth=0.8,color='k')
plt.savefig('placas.pdf')
