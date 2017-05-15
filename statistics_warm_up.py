import numpy as np
import sys
import scipy as sp
from scipy import stats
def mean_confidence_interval(data, confidence=0.95):
    num_data = len(data)
    std = np.std(data)
    boundary_threshold = 1.96*std/(np.sqrt(num_data))
    return boundary_threshold

n = int(input())
x=np.array([])
s=input()
for num in s.split():
    x=np.append(x,float(num))
print("%.1f" %x.mean())
print("%.1f" %np.median(x))
print("%.0f" %stats.mode(x)[0][0])
print("%.1f" %np.std(x))
boundry=mean_confidence_interval(x)
a= np.mean(x) - boundry
b= np.mean(x) + boundry
print("%.1f" %a, "%.1f"%b)
