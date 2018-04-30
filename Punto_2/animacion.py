from numpy import genfromtxt, size, shape
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

U = genfromtxt('data.txt', delimiter=' ')
frms,points = shape(U)

def one_frame(i):
	Ui = U[i,:]
	plt.cla()
	plt.plot(Ui)
	plt.ylim([-2.0,1.5])

fig = plt.figure()
anim = FuncAnimation(fig, one_frame, frames=int(frms/2), interval=20)
anim.save('cuerda.gif', writer='imagemagick', fps=int(frms/4))
