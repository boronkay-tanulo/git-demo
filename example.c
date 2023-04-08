#define _XOPEN_SOURCE 700

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static int
xstrtou(unsigned *val, const char *str)
{
  char *endptr;
  long result;

  errno = 0;
  result = strtol(str, &endptr, 0);
  if (errno != 0 || *endptr != '\0' || *str == '\0' ||
      result < 0 || (long unsigned)result > UINT_MAX) {
    return -1;
  }
  *val = (unsigned)result;
  return 0;
}

int
main(int argc, char **argv)
{
  unsigned a;
  unsigned b;
  unsigned result;

  if (argc != 3 ||
      xstrtou(&a, argv[1]) == -1 ||
      xstrtou(&b, argv[2]) == -1) {
    (void)fprintf(stderr, "specify two unsigned ints\n");
    return EXIT_FAILURE;
  }

  (void)fprintf(stdout, "a=%u b=%u\n", a, b);

  result = a * b;
  (void)fprintf(stdout, "a*b=%u\n", result);

  result = a + b;
  (void)fprintf(stdout, "a+b=%u\n", result);

  return fflush(stdout) == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
