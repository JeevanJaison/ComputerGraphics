import cv2
import numpy as np
import matplotlib.pyplot as plt

image=cv2.imread("flower.jpeg")

c=1
normalizedImage=image/255.0
gamma=2.0
powerlaw_trans=c*np.power(normalizedImage,gamma)

powerlaw_trans=np.uint8(powerlaw_trans*255)

plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.imshow(image)
plt.subplot(1,2,2)
plt.imshow(powerlaw_trans)
plt.show()
