import numpy as np;
import matplotlib.pyplot as plt;


sigma = np.array([0.25, 0.5, 1, 2, 4]);
y1 = np.array([0.150000, 0.170000, 0.160000, 0.150000, 0.160000]);
y2 = np.array([0.090000, 0.190000, 0.440000, 1.390000, 4.810000]);



plt.plot(sigma, y1, label="convolution par FFT");
plt.plot(sigma, y2, label="convolution spatiale");
plt.legend();
plt.xlabel("sigma");
plt.ylabel("temps de calcul");
plt.show();
