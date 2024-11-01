import cv2
import numpy as np
import matplotlib.pyplot as plt

image=cv2.imread("flower.jpeg",cv2.IMREAD_GRAYSCALE )

def logt():
    global trans
    c=255/np.log(1+np.max(image))
    trans=c*np.log(1+image)
    trans=np.array(trans,dtype=np.uint8)

def inv():
    global trans
    c=255/(np.e-1)
    trans=c*np.exp(image/c) -1
    trans=np.array(trans,dtype=np.uint8)

def invColor():
    global trans
    image=cv2.imread("flower.jpeg")
    image=cv2.cvtColor(image,cv2.COLOR_BGR2RGB)

    r,g,b=cv2.split(image)
    c=255/(np.e-1)
    rinv=c*(np.exp(r/c)-1)
    ginv=c*(np.exp(g/c)-1)
    binv=c*(np.exp(b/c)-1)

    trans=cv2.merge((rinv,ginv,binv))
    trans=np.array(trans,dtype=np.uint8)
    plt.figure(figsize=(12,6))
    plt.subplot(1,2,1)
    plt.imshow(image)
    plt.subplot(1,2,2)
    plt.imshow(trans)
    plt.show()

def powerlaw():
    global trans
    norma=image/255
    gamma=2
    c=1
    trans=np.power(norma,gamma)
    trans=np.uint8(trans*255)
n=int(input())
if n==1:
    logt()
elif n==2:
    inv()
elif n==3:
    invColor()
else:
    powerlaw()
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.imshow(image,cmap='gray')
plt.subplot(1,2,2)
plt.imshow(trans,cmap='gray')
plt.show()