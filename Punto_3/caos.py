from numpy import *

D = genfromtxt("datos_caos.txt")
print(shape(D))

from matplotlib.pyplot import *
figure()
for i in range(size(D,1)):
	plot(D[:,i])
xlabel('I'); ylabel('variable')
legend(['Q1','Q2','P1','P2'])
savefig('caos_auxiliar.pdf')


D = genfromtxt("datos_caos_cambio_s.txt")
print(shape(D))

from matplotlib.pyplot import *
figure()
plot(D[:,0],D[:,1], 'o-')
xlabel('Q2'); ylabel('P2')
savefig('caos.pdf')