#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
from scipy.signal import convolve2d as conv2d
import scipy.stats as stats



# In[2]:


class Fractal():
    def __init__(self, X):
        self.X  = X
        
    def countConv(self, k):
        x =  self.X
        stride =  k

        count  = 0

        for i in range(0, x.shape[0] - k + 1, k):
            for j in range(0, x.shape[1] -k + 1, k):


                X =  x[i:i+k, j:j+k]

                if np.sum(X.ravel()) != 0:
                    count += 1




        return count
    
    def fractDimGS(self):
        "geometric step method"
        
        x =  self.X

        size = x.shape[0]

        box =  [2 ** i for i in range(0, int(np.sqrt(size))) if 2**i <= size/2]

        count = []
        delta = []

        for k in box:
            count.append(self.countConv(k))
            delta.append(k)
        delta = list(reversed(delta))


        slope = stats.linregress(np.log(1/np.array(delta)), np.log(count))[0]

        D =  1 - slope


        return D
    
    
    def lacunarity(self):
        
        x =  self.X


    
        box_size = [1,2,4,8,16,32,64,128]

        LAMBDA = []

        for box in box_size:

            count, edge= np.histogram(np.ravel(conv2d(x, np.ones((box, box)), mode = 'valid')),
                                      bins = [i for i in range(0, (box**2) + 2)])
            q = count/(x.shape[0] - box + 1)**2
            s = np.array([i for i in range(0,box**2 + 1)])
            lam_bda =  sum((s**2)*q)/(sum(q*s))**2

            LAMBDA.append(lam_bda)




        return np.mean(LAMBDA)
    

    
    
    
    
    
            
        
    


# In[8]:


L = 512
x = np.random.choice([1,0], size=((L,L)), replace=True, p=[0.5,0.5])


# In[9]:


f1 = Fractal(x)


# In[10]:


f1.countConv(200)


# In[11]:


f1.fractDimGS()


# In[12]:


f1.lacunarity()


# In[ ]:




