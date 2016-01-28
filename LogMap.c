/* Code to print out bifurcation map of logistic function */
/* Written by Matthew Hartfield (matthew.hartfield@utoronto.ca) */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
	
	double rstart;
	double rend;
	double deltar;
	double rcurr;
	double startx = 0.5;
	double xcurr;
	unsigned int g, h;
	unsigned int isdone;
	unsigned int match;
	unsigned int maxrep = 100;
	FILE *ofp_dat;

	/* Reading in data from command line */
	if(argc != 4){
		fprintf(stderr,"Three inputs required (rstart, rend, delta_r).\n");
		exit(1);
	}
	rstart = strtod(argv[1],NULL);
	rend = strtod(argv[2],NULL);
	if(rstart > rend){
		rstart = rend;
	}
	if(rend > 4.0){
		rend = 4.0;
	}
	deltar = strtod(argv[3],NULL);
	
	double *states = calloc(maxrep,sizeof(double));
	
	rcurr = rstart;
	
	/* Creating blank file */
	ofp_dat = fopen("res.dat","w");
	fclose(ofp_dat);
		
	/* Start of main simulation */
	while(rcurr <= rend){
		
		/* Reaching steady-state */
		xcurr = startx;
		for(g = 0; g < 10000; g++){
			xcurr = rcurr*xcurr*(1.0-xcurr);
		}
		
		/* Now checking oscillations */
		isdone = 0;
		g = 0;
		while(isdone != 1){
			xcurr = rcurr*xcurr*(1.0-xcurr);
			/* Checking if oscillatory point reached */
			if(g == 0){
				*(states + g) = xcurr;
			}else if(g > 0){
				match = 0;
				for(h = 0; h < g; h++){
					if(*(states + h) == xcurr){
						match = h;
						isdone = 1;
						break;
					}
				}
				if(isdone != 1){
					*(states + g) = xcurr;
				}
			}
			/* printf("xcurr %lf, g %d, isdone %d\n",xcurr,g,isdone);*/
			g++;
			if(g == maxrep){
				isdone = 1;
			}
		}
		
		/* Write out oscillatory points to file */
		g--;
		ofp_dat = fopen("res.dat","a+");
		for(h = match; h < g; h++){
			fprintf(ofp_dat,"%0.10lf %0.10lf\n",rcurr,*(states + h));
		}
		fclose(ofp_dat);
		
		rcurr += deltar;
	}
	
	free(states);
	return 0;
}

/* End of File */