"""Simple demonstration of MatPlotLib plotting."""
 
from matplotlib import pyplot
 
X = range(0,100)
Y = [ i*i for i in X ]
 
pyplot.plot( X, Y, '-' )
pyplot.title( 'Plotting x*x' )
pyplot.xlabel( 'X Axis' )
pyplot.ylabel( 'Y Axis' )
pyplot.savefig( 'Simple.png' )
pyplot.show()
