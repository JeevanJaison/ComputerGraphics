import cv2
import numpy as np
import matplotlib.pyplot as plt

image=cv2.imread("girl1.webp",cv2.IMREAD_GRAYSCALE)

rmin,rmax=np.min(image),np.max(image)
smin,smax=0,255
contrast=((image-rmin)/(rmax-rmin))*(smax-smin)+smin
contrast=np.array(contrast,dtype=np.uint8)


plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.imshow(image,cmap='gray')
plt.subplot(1,2,2)
plt.imshow(contrast,cmap='gray')
plt.show()