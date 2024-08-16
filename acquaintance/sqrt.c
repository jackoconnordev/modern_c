#include <stdio.h>
#include <stdlib.h>

#include "heron.h"

/* accurate upper and lower bounds */
static double const fine_epsilon = 0x1P-24;

double sqrt(double x) {
  double low = 0.0;
  double high = x;
  double sqrt_approximation = 0.0;

  for (;;) {
    if (x + fine_epsilon < sqrt_approximation * sqrt_approximation) {
      high = sqrt_approximation;
    } else if (x - fine_epsilon > sqrt_approximation * sqrt_approximation) {
      low = sqrt_approximation;
    } else {
      break; // We are in the bounds so break and return sqrt_approximation.
    }

    sqrt_approximation = (high + low) * 0.5;
  }

  return sqrt_approximation;
}

double sqrt_derivative(double x) {
  double sqrt_x = sqrt(x);
  double inverse_sqrt_x = heron(sqrt_x);
  return inverse_sqrt_x;
}

int main(int argc, char *argv[argc + 1]) {
  if (argc > 2) {
    printf("sqrt takes one argument only.\n");
    return EXIT_FAILURE;
  }

  char *err = NULL;
  double x = strtod(argv[1], &err);

  if (err == argv[1]) {
    printf("Not a number.\n");
    return EXIT_FAILURE;
  }

  double sqrt_x = sqrt(x);
  double derivative_sqrt_x = sqrt_derivative(x);

  printf("sqrt(%f) is %f\n", x, sqrt_x);
  printf("sqrt'(%f) is %f\n", x, derivative_sqrt_x);

  return EXIT_SUCCESS;
}
