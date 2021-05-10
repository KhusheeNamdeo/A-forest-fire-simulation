# Fun with a 1D forest fire simulation.

 forestfire.c takes as input the probability of a living tree being hit by fire and runs a simulation over many generations of tree birth and death in the forest.
 The growth simulations are run for different probabilities of tree birth and the output is a table of three columns: 
 fire probability, birth probability, average number of trees in a generation. 
 Compile and run the program as ./a.out > forestfire1d.0.05.out and enter 0.05 for the input, to produce a table with fire probability 0.05. 
 Similarly run as ./a.out > forestfire1d.0.25.out and enter 0.25 to produce a table with fire probability 0.25. Do the same for fire probabilities of 0.50 and 0.75. 
 Then use forestfire.plot to plot the graph by starting gnuplot, and type load "forestfire.plot" in gnuplot.
