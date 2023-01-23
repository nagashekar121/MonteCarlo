
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <math.h>

double func(double);
double error(double);
double randomNumGen();

int main(int argc, char **argv){
  int N = atoi(argv[1]);
  double a = -1.0;
  double b = 1.0;
  double const_val = (b - a)/N;
  double sol = 0.0;
  srand(time(NULL));
  for (int i=0;i<N;++i){
    
    sol = sol + func(randomNumGen());
  }
  double solution = const_val * sol;
  
  printf("%i   %1.16f  %1.16f\n",N,solution,error(solution));
  return 0;
}

double func(double x) {
  double fx = 1.0/(1.0 + x*x);
  return fx;
}

double error(double integral) {
  const double pi = 3.1415926535897932;
  double absolute_error = fabs(integral - pi / 2.);
  return absolute_error;
}

double randomNumGen() {

  double x = ((double)(rand()/(double)RAND_MAX)*2)-1 ;  
  return x;
}
