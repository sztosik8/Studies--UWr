# Katarzna Trzos
# Lista 10
# Zadnaie 5
import matplotlib.image as mpimg
import matplotlib.pyplot as plt
import numpy as np


def difference(pix1, pix2):
    val1 = (pix1[0]+pix1[1]+pix1[2])/3  # value in grayscale
    val2 = (pix2[0]+pix2[1]+pix2[2])/3
    return abs(val2-val1)


def contour_next(img, treshold):
    black = (0, 0, 0)
    white = (1, 1, 1)
    new_img = np.zeros((img.shape[0], img.shape[1], 3))

    for i in range(img.shape[0] - 1):
        for j in range(img.shape[1] - 1):
            if difference(img[i, j], img[i, j+1]) > treshold:
                new_img[i, j] = black
            else:
                new_img[i, j] = white

    return new_img


def contour_down(img, treshold):
    black = (0, 0, 0)
    white = (1, 1, 1)
    new_img = np.zeros((img.shape[0], img.shape[1], 3))

    for i in range(img.shape[0] - 1):
        for j in range(img.shape[1] - 1):
            if difference(img[i, j], img[i+1, j]) > treshold:
                new_img[i, j] = black
            else:
                new_img[i, j] = white

    return new_img


def contour_both(img, treshold):
    black = (0, 0, 0)
    white = (1, 1, 1)
    new_img = np.zeros((img.shape[0], img.shape[1], 3))

    for i in range(img.shape[0] - 1):
        for j in range(img.shape[1] - 1):
            if difference(img[i, j], img[i, j+1]) > treshold or difference(img[i, j], img[i+1, j]) > treshold:
                new_img[i, j] = black
            else:
                new_img[i, j] = white

    return new_img

# 180.png     cte.png 
img = mpimg.imread("cte.png")
threshold_value = 0.125
# how sensitive, precise

plt.subplot(1, 4, 1)
plt.imshow(img)

plt.subplot(1, 4, 2)
# checking only pixlels on the right
plt.imshow(contour_next(img, threshold_value))

plt.subplot(1, 4, 3)
# checking only pixels below
plt.imshow(contour_down(img, threshold_value))

plt.subplot(1, 4, 4)
# checking both conditions
plt.imshow(contour_both(img, threshold_value))

plt.tight_layout()
plt.show()
