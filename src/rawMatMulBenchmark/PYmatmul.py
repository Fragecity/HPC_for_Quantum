import numpy as np
import random
import time

for i in range(8, 13):
    N = 2**i
    A = np.random.rand(N, N)
    B = np.random.rand(N, N)

    start = time.time()
    C = A @ B
    end = time.time()

    print(f"N = {N}, Time taken: {(end - start)*1000} ms")
