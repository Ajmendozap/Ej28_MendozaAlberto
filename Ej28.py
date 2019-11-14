import numpy as np
import matplotlib.pylab as plt

datos= np.loadtxt('data.dat')
datosf= np.loadtxt('dataf.dat')

plt.plot(datos[:,0],datos[:,1])
plt.plot(datosf[:,0],datosf[:,1])
plt.title('Movimiento parabólico')
plt.xlabel('$x$(m)')
plt.ylabel('$y$(m)')
plt.axvline(c='k',lw=1.3)
plt.axhline(c='k',lw=1.3)
plt.savefig('MovimientoParabólico.png')
plt.show()