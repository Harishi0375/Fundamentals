# Run the following code cell to import standard Python data science libraries. The NumPy module facilitates efficient processing of numerical arrays, and is usually imported as `np`. From the matplotlib library we import the package `pyplot` using the standard abbreviation `plt`. The magic command `%matplotlib inline` (IPython shell) allows for inline display of graphics.

import numpy as np
import matplotlib.pyplot as plt
# %matplotlib inline #plt.show()  Use plt.show() to display plots in non-Jupyter environments

#Consider a NumPy array `x`. The arrays `x[1:]`  and `x[:-1]` extract sub-arrays with elements `x[1],x[2],...,x[-1]` and `x[0],x[1],x[2],...,x[-2]`, respectively.

x = np.array([1,2,4,6,7,8])
print('Array x=x[:] :',x[:])
print('Array x[1:]  :',x[1:])
print('Array x[:-1] :',x[:-1])


#The set of differences `x[1]-x[0],x[2]-x[1],x[3]-x[2],...` (i.e., x_{j+1}-x_j,j=0,1,2..) are thus elements of the array `x[1:]-x[:-1]`.
x = np.array([1,2,4,6,7,8])   
dx = x[1:] - x[:-1]
print('Array x     : ',x)
print('Differences : ',dx)

#x[1:]: This extracts all elements from index 1 to the end of the array [2, 4, 6, 7, 8].
# x[:-1]: This extracts all elements from the beginning to the second-to-last element [1, 2, 4, 6, 7].
# The differences are calculated element-wise: [2 - 1, 4 - 2, 6 - 4, 7 - 6, 8 - 7], resulting in [1, 2, 2, 1, 1].

#Different example
x = np.array([1,2,4,6,7,8],dtype=float)
xm = 0.5*( x[1:] + x[:-1] )
print('Array x          : ',x)
print('Arithmetic means : ',xm)



#python script ----------------------------

#A Python script consists of a series of instructions that are executed as a block. Python scripts are usually stored as separate files with the extension `.py`, and can then be run, e.g., within an IPython shell (or Jupyter notebook code cell) or from the terminal prompt. Suppose the script is named `script.py`, then in a terminal window enter after the prompt:

# python script.py
# OR
#%run script.py
#OR
#%run script

### Include necessary imports.
import numpy as np

### Define and display numerical grid x and grid function f.
x = np.array([1,2,4,6,7,8],dtype=float)
f = x**2 - 5*x - 8
print('Grid     x : ',x)
print('Function f : ',f)
print()

### Compute arithmetic means and differences.
xm = 0.5*( x[1:] + x[:-1] )
dx = x[1:] - x[:-1]
df = f[1:] - f[:-1]

### Compute approximate and exact derivatives.
dfodx_approx = df/dx
dfodx_exact  = 2*xm - 5

### Print results.
print('First derivative of function f')
print('* Array of arithmetic means         : ',xm)
print('* Finite differencing approximation : ',dfodx_approx)
print('* Evaluation of exact derivative    : ',dfodx_exact)



#functions -----------------------------------------------------------

def numdif(x,f):
    '''
    Centered differencing approximation of the first derivative.
    Arguments
    * x     : numerical grid.
    * f     : grid function.
    On return
    * dfodx : approximation of the first derivative.
    * xm    : arithmetic means of consecutive numerical grid points.
    '''
    dx = x[1:] - x[:-1]
    df = f[1:] - f[:-1]
    dfodx = df/dx
    xm = 0.5*( x[1:] + x[:-1] )
    return dfodx,xm

#After running the above code cell, the function `numdif()` is available in the current Python/notebook session, as can be checked by displaying the docstring.

help(numdif)

#Using `numdif()`, the code to compute approximate derivatives assumes a more compact form.

### Define and display numerical grid x and grid function f.
x = np.array([1,2,4,6,7,8],dtype=float)
f = x**2 - 5*x - 8
print('Grid     x : ',x)
print('Function f : ',f)
print()

### Compute approximate derivatives and arithmetic means.
dfodx_approx,xm = numdif(x,f)

### Compute exact derivatives.
dfodx_exact = 2*xm - 5

### Print results.
print('First derivative of function f')
print('* Array of arithmetic means         : ',xm)
print('* Finite differencing approximation : ',dfodx_approx)
print('* Evaluation of exact derivative    : ',dfodx_exact)




#KEYWORD ARGUNMENTS

#To illustrate the concept of keyword arguments, consider the task of creating an equidistant numerical grid with a total of `N` points starting at an initial position `xinit`. The grid spacing `deltax` is implemented as a keyword parameter defaulting to unity (`deltax=1`).

def eqdistgrid(xinit,N,deltax=1):
    '''
    Create equidistant numerical grid.
    Arguments
    * xinit  : initial grid coordinate.
    * N      : total number of grid points.
    Keyword arguments
    * deltax : grid spacing.
    On return
    * grid   : equidistant numerical grid.
    '''
    grid = np.linspace(xinit,xinit+(N-1)*deltax,N)
    return grid

#After running the code cell above, the function `eqdistgrid()` can be called in any way indicated in the following cell. Study the instructions and anticipate the results. Which statement produces an error message? Uncomment individual lines to check your prediction.

print(eqdistgrid(1,5,deltax=3))
#print(eqdistgrid(1,5,2))
#print(eqdistgrid(1,5))


#In addition to the `def` syntax, Python offers also the so-called `lambda` mechanism for defining functions. The definitions in the two code cells below implement the same function.

def f(x,y,z=0): return x**2-y+z
f = lambda x,y,z=0: x**2-y+z
print(f(1,7,2))

#other way to look at lambda mechanism---------------------------------------

# Regular function definition
def add(x, y):
    return x + y

# Equivalent lambda function
add_lambda = lambda x, y: x + y

# Using both functions
result1 = add(2, 3)
result2 = add_lambda(2, 3)

print(result1)  # Output: 5
print(result2)  # Output: 5

# ----------------------------------------------------------------

# In the code cell below, replace the `pass` statement in the function `boxcar()` with an implementation of the filtering operation. Run the cell to plot the filtered signal together with the input time series.

def boxcar(u,h=1):
    '''
    Boxcar filtering in the interior of a time series u.
    Arguments
    * u : input time series.
    Keyword arguments
    * h : filter half-width.
    On return
    * v : filtered time series.
    '''
    v = u.copy()
    #.. Implement boxcar filter using a for loop.
    for k in range(h,len(u)-h+1):
        pass
    return v

### Define uniform time array.
t = np.linspace(0,2,201)

### Generate sinusoidal signal contaminated by noise.
u = np.sin(2*np.pi*t) + 0.2*np.random.randn(len(t))

### Produce the filtered signal.
halfwidth = 5
v = boxcar(u,h=halfwidth)

### Plot input and filtered signal.
plt.figure(figsize=(8,4))
plt.plot(t,u,label='Input time series')
plt.plot(t,v,label='Filtered time series')
plt.title('Boxcar filtering exercise (half-width: {})'.format(halfwidth))
plt.xlabel('Time [s]')
plt.ylabel('Signal [arb. units]')
plt.legend()


#FUNCTION IMPORTS ----------------------------------------------------

#This formula is implemented in the function `eqdistdif1()` as part of the file `eqdist.py`, representing a minimal module (with two functions) available through the `import` mechanism. As before, select the browser tab showing the working directory (in the Classic Notebook interface; in JupyterLab use the directory/file menu on the left) and click on the file `eqdist.py`. Importing the module creates a dedicated namespace.

import eqdist
#help(eqdist)

### Define and display numerical grid x and grid function f.
x = eqdist.eqdistgrid(-5,21,deltax=0.5)
f = x**3 - 20*x + 25

### Compute approximate and exact derivatives.
dfodx_approx = eqdist.eqdistdif1(f,deltax=0.5)
xint = x[1:-1]
dfodx_exact  = 3*xint**2 - 20

### Plot results.
fig,axs = plt.subplots(1,2,figsize=(10,4))
axs[0].plot(x,f,'b--')
axs[0].set_title('Grid function')
axs[0].set_xlabel('Numerical grid coordinate')
axs[1].plot(xint,dfodx_exact,'g--',label='Exact derivative')
axs[1].plot(xint,dfodx_approx,'rx',label='Approximate derivative')
axs[1].set_title('First derivative')
axs[1].set_xlabel('Numerical grid coordinate')
axs[1].legend()


#FUNCTION IMPORTS -------------------------------------------------------

#Create a module file named `myfilter.py` containing the two functions `eqdistgrid()` and `boxcar()`. Run the following cell to check if the module was correctly saved.

### Import the newly created module myfilter.
import myfilter

### Generate time array and noisy sinusoidal signal.
t = myfilter.eqdistgrid(0,201,deltax=0.01)
u = np.sin(2*np.pi*t) + 0.2*np.random.randn(len(t))

### Apply boxcar filter to the noisy signal.
halfwidth = 5
v = myfilter.boxcar(u,h=halfwidth)

### Plot noisy input signal and filtered time series.
plt.figure(figsize=(8,4))
plt.plot(t,u,label='Input time series')
plt.plot(t,v,label='Filtered time series')
plt.title('Boxcar filtering exercise (half-width: {})'.format(halfwidth))
plt.xlabel('Time [s]')
plt.ylabel('Signal [arb. units]')
plt.legend()



