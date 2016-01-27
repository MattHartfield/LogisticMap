LOGISTIC MAP README

Simple program for producing bifurcation plot of logistic map (http://en.wikipedia.org/wiki/Logistic_map).

Code written in C. After compilation, run by:

LogMap rin rout rspace

Where:
- rin is the start 'r' value 
- rout is the end 'r' value
- rspace is the increment for different 'r' values.

For an individual r value, the code evaluates function r x (1-x) 10,000 times, then continues for 100 generations or until a fixed or oscillating point is reached. Results are printed out to file 'res.dat'.

Program starts at the 'rin' value and proceeds in increments of 'rspace', until the end point 'rout' is exceeded. Will automatically stop at r = 4 since the function diverges for higher values. If 'rin' is set as greater than 'rout', then 'rin' is set to be equal to 'rout'.

The output file 'res.dat' contains a series of co-ordinates that be used to plot the bifurcation map, when loaded into a program of your choosing.

Comments to matthew.hartfield@utoronto.ca.

Happy chaos-ing!