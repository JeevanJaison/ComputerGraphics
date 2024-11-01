import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load the image in grayscale
image = cv2.imread('flower.jpeg', cv2.IMREAD_GRAYSCALE)

# Apply log transformation
c = 255 / np.log(1 + np.max(image))
log_transformed = c * np.log(1 + image)

# Convert to 8-bit unsigned integer type
log_transformed = np.array(log_transformed, dtype=np.uint8)

# Display the original and log-transformed images
plt.figure(figsize=(12, 6))
plt.subplot(1, 2, 1), plt.imshow(image, cmap='gray'), plt.title('Original Image')
plt.subplot(1, 2, 2), plt.imshow(log_transformed, cmap='gray'), plt.title('Log Transformed Image')
plt.show()