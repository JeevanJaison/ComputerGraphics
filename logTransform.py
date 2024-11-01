import cv2
import numpy as np
import matplotlib.pyplot as plt

#read image
image=cv2.imread('flower.jpeg',cv2.IMREAD_GRAYSCALE)

#applying log transform
c=255/np.log(1+np.max(image))
log_transformed=c*np.log(1+image)

# Convert to 8-bit unsigned integer type
log_transformed = np.array(log_transformed,dtype=np.uint8)

#display
plt.figure(figsize=(12,6))
plt.title("Logarthmic transformation")
plt.subplot(1,2,1)
plt.imshow(image)
plt.title("Orginal image")
plt.subplot(1,2,2)
plt.imshow(log_transformed)
plt.title("Transformed image")
plt.show()
