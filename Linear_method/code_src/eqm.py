import numpy as np;
import matplotlib.pyplot as plt;

sigma = 1;
sigmax = np.array([1, 2, 3, 4, 5]);
y1 = np.array([0.046291, 0.001044, 0.000002, 0.000000, 0.000000]);
y2 = np.array([1.279765, 0.010565, 0.000154, 0.000150, 0.000150]);
'''
sigma = 5;
#sigmax = np.linspace(1, 6*sigma,5);
sigmax = np.array([1, 4, 7, 10, 13, 16, 19, 22, 25, 28]);

y3 = np.array([25.856152, 10.577223, 2.278708, 0.263411, 0.015286, 0.000429, 0.000006, 0.000000, 0.000000, 0.000000]);
y4 = np.array([60.962272, 14.633584, 2.553826, 0.256359, 0.013346, 0.000341, 0.000004, 0.000000, 0.000000, 0.000000]);
'''
'''
sigma = 10;
sigmax = np.array([1, 8, 15, 22, 29, 36, 40, 43, 50, 57]);
y5 = np.array([95.682588, 32.123351, 5.123325, 0.379750, 0.010554, 0.000099, 0.000002, 0.000000, 0.000000, 0.000000]);
y6 = np.array([127.487006, 27.211457, 3.620288, 0.217553, 0.005134, 0.000045, 0.000004, 0.000000, 0.000000, 0.000000]);
'''
#127.487006, 12.431002, 0.343498, 0.001468, 0.000001, 0.000000
'''
sigma = 20;
sigmax = np.array([]);
y7 = np.array([]);
y8 = np.array([]);

'''
plt.plot(sigmax, y1, label="formes2g");
plt.plot(sigmax, y2, label="radio1024");
'''
plt.plot(sigmax, y3, label="formes2g");
plt.plot(sigmax, y4, label="radio1024");
'''
'''
plt.plot(sigmax, y5, label="formes2g");
plt.plot(sigmax, y6, label="radio1024");
'''
'''
plt.plot(sigmax, y7, label="formes2g");
plt.plot(sigmax, y8, label="radio1024");
'''

plt.legend();
plt.xlabel("n");
plt.ylabel("eqm");
plt.show();
