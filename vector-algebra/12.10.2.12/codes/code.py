import numpy as np

# Define the vector
vec = np.array([1, 2, 3])

# Find the magnitude of the vector
mag = np.linalg.norm(vec)

# Divide the vector by its magnitude to find the direction cosines
dir_cos = vec / mag

print(dir_cos)

