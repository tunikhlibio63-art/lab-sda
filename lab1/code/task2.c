#include<stdio.h>



int main () {
  double x;
  double y;

  printf("x: ");
  scanf("%lf", &x);

  if(x > -15.0 && x <= 3.0) {
    y = 4.0 * x * x * x + 2.0;
    printf("y = %lf\n", y);
  } else if(x <= -30.0 || x > 20.0) {
    y = 3.0 * x * x * x / 4.0 - 5.0;
    printf("y = %lf\n", y);
  } else {
    printf("undefine\n");
  }
  return 0;
}
