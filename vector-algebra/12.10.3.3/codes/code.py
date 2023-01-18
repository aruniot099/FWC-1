import numpy as np

# Define the vector
a = np.array([1,-1,0])
b  = np.array([1,1,0])
# Find the magnitude of the vector
mag = np.linalg.norm(b)

# Divide the vector by its magnitude to find the direction cosines
x = ((a.T)@b) / mag

print(x)
