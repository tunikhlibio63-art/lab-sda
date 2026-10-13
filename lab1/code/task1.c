#include<stdio.h>



int main () {
  double x;
  double y;
  int def = 0;

  printf("x: ");
  scanf("%lf", &x);

if(x <= -30.0) {
  y = 3.0 * x * x * x / 4.0 - 5.0;
  def = 1;
} else if(x > -15.0) {
  if (x <= 3.0) {
    y = 4.0 * x * x + 2.0;
    def = 1;
  } else if (x > 20.0) {
    y = 3.0 * x * x * x / 4.0 - 5.0;
    def = 1;
  } 
} else if (x > 20.0) {
  y = 3.0 * x * x * x / 4.0 - 5.0;
  def = 1;
}

if(def) {
  printf("y = %lf\n", y);
} else {
  printf("undefine\n");
}

  return 0;
}
