/*
 * Implement the heron algorithm to efficiently find the
 * inverse 1 / x of multple numbers x.
 * - a = estimated 1 / x
 * - x = x
 * - prod = x * a
 */

/* broad upper and lower bounds */
static double const broad_upper_bound = 1.0 + 0x1P-01; // 1.5
static double const broad_lower_bound = 1.0 - 0x1P-01; // 0.5

/* accurate upper and lower bounds */
static double const fine_upper_bound = 1.0 + 0x1P-24;
static double const fine_lower_bound = 1.0 - 0x1P-24;

double heron(double x) {
  double a = 1.0;
  double prod;

  for (;;) {
    prod = a * x;
    if (prod > broad_upper_bound) {
      a *= 0.5;
    } else if (prod < broad_lower_bound) {
      a *= 2.0;
    } else {
      break;
    }
  }

  for (;;) {
    prod = a * x;
    if ((prod > fine_upper_bound || prod < fine_lower_bound)) {
      // if `prod` too big (`a` too big), makes `a` smaller and vice versa
      a *= 2.0 - prod;
    } else {
      break;
    }
  }

  return a;
}
/*
 * The plan of attack here is to find the inverse `1/x` by multiplying
 * the input double by our continuously refined estimate `a` until
 * such time as their product is sufficiently close to 1.0.
 *
 * We make big adjustments to begin with by multiplying `a`
 * by 2 or 0.5 until such time as `prod` is within our broad
 * upper and lower bounds.
 *
 * We then take `a` and multiply it by `2 - prod` until such time as
 * `prod` lies within our fine upper and lower bounds.
 */
// Comment out so this can be used as a libary
// int main(int argc, char *argv[argc + 1]) {
//   for (int i = 1; i < argc; ++i) { // `i = 0` is the program name
//     double const x = strtod(argv[i], 0);
//     double a = 1.0;
//     double prod;
//
//     for (;;) {
//       prod = a * x;
//       if (prod > broad_upper_bound) {
//         a *= 0.5;
//       } else if (prod < broad_lower_bound) {
//         a *= 2.0;
//       } else {
//         break;
//       }
//     }
//
//     for (;;) {
//       prod = a * x;
//       if ((prod > fine_upper_bound || prod < fine_lower_bound)) {
//         // if `prod` too big (`a` too big), makes `a` smaller and vice versa
//         a *= 2.0 - prod;
//       } else {
//         break;
//       }
//     }
//
//     printf("heron: a=%.5e,\tx=%.5e,\ta*x=%.12f\n", a, x, a * x);
//   }
//   return EXIT_SUCCESS;
// }
