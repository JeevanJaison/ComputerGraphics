import cv2
import numpy as np
import matplotlib.pyplot as plt

image=cv2.imread("flower.jpeg",cv2.IMREAD_GRAYSCALE)

#applying inverse transformation
c=255/(np.e-1)
inv_trans=c*np.exp((image/c)-1)

#conver to 8 bit
inv_trans=np.array(inv_trans,dtype=np.uint8)

#display
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.imshow(image,cmap="gray")
plt.subplot(1,2,2)
plt.imshow(inv_trans,cmap="gray")
plt.show()