

import matplotlib.image as mpimg
import matplotlib.pyplot as plt 
import numpy as np
from scipy import ndimage

from scipy import signal

s = mpimg.imread("/Users/kakarlakeerthy/Desktop/cameraman.jpg")
plt.imshow(s, cmap='gray')
h = np.matrix('0.111 0.111 0.111; 0.111 0.111 0.111; 0.111 0.111 0.111')
print(h)
y1=signal.convolve2d(s,h) 
plt.figure()
plt.imshow(y1, cmap='gray')
plt.savefig("/Users/kakarlakeerthy/Desktop/y1.jpg")
y2=ndimage.convolve(s,h)
plt.figure()
plt.imshow(y2, cmap='gray')
plt.savefig("/Users/kakarlakeerthy/Desktop/y2.jpg")
hcol = np.matrix('-0.333 -0.333 -0.333');
print(hcol);
c=np.zeros((258,256),dtype=float);
y3=np.zeros((258,258),dtype=float);
l=256; p=3;  
hcol=np.array([1/3.,1/3.,1/3.])        
for x in range (l+p-1):
    for y in range (l):
        c[:,y]=signal.convolve(s[:,y],hcol)
    y3[x,:]=signal.convolve(c[x,:],hcol)
plt.figure()
plt.imshow(y3, cmap='gray')
plt.savefig("/Users/kakarlakeerthy/Desktop/y3.jpg")
hk=np.zeros((3,3),dtype=float)
hk[0,0]=1.0
h2=hk-h
y4=signal.convolve2d(s,h2) 
plt.figure()
plt.imshow(y4, cmap='gray')
plt.savefig("/Users/kakarlakeerthy/Desktop/y4`.jpg")
    
 