#include<stdio.h>
#include<math.h>



int main () {
  int n;
  int ops = 0;

  printf("n = ");
  scanf("%d", &n);
  
  double P = 1.0;
  double x = 0.5;
  double s = 0.0;
  
  for(int i = 1; i <= n; ++i) {
    s += 2.0 * i - 1;
    P *= 1.0 - ((x * x) / (M_PI * M_PI * s));
    ops += 11;
  }

  printf("P = %.7f\n", P);
  printf("operations = %d\n", ops);

  return 0;
}
