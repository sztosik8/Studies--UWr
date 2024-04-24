import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

# Load the image
img = mpimg.imread("cte.png")

# Convert the image to grayscale
gray_img = np.mean(img, axis=-1)
img= (gray_img, cmap='gray')
# Display the grayscale image without specifying the colormap
plt.imshow(gray_img, cmap='gray')  # Specify the colormap to ensure grayscale representation
plt.title('Grayscale Image')
plt.show()
