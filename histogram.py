import cv2
import numpy as np
import matplotlib.pyplot as plt

def histocalc(image):
    histogram=np.zeros(256)
    rows,cols=image.shape
    for i in range(rows):
        for j in range(cols):
            intensity=image[i,j]
            histogram[intensity]+=1
    pdf=histogram/(rows*cols)
    return histogram,pdf

def cdfcalc(pdf):
    cdf=np.cumsum(pdf)
    cdf=cdf*255
    cdf=cdf.astype('uint8')
    return cdf

def equaizationl(cdf,image):
    eq=np.zeros_like(image)
    rows,cols=image.shape
    for i in range(rows):
        for j in range(cols):
            eq[i,j]=cdf[image[i,j]]
    return eq

image=cv2.imread("flower.jpeg",cv2.IMREAD_GRAYSCALE)
hist,pdf=histocalc(image)
cdf=cdfcalc(pdf)
equ=equaizationl(cdf,image)

plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.imshow(image)
plt.subplot(1,2,2)
plt.imshow(equ)
plt.show()

#calculate histogram and pdf
