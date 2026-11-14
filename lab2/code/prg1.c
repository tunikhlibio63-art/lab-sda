#include<stdio.h>
#include<math.h>



int main () {
  int n;
  int ops = 0;
  
  printf("n = ");
  scanf("%d", &n);
  
  double x = 0.5;
  double P = 1.0;
  double s;
  
  for(int i = 1; i <= n; ++i) {
    s = 0.0;
    for(int j = 1; j <= i; ++j) {
      s += 2 * j - 1;
      ops += 6;
    }
    P *= (1.0 - ((x * x) / (M_PI * M_PI * s)));
    ops += 10;
  }
  ops += 1;

  printf("P = %.7f\n", P);
  printf("operations = %d\n", ops);
  
  return 0;
}
