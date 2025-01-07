#include <stdio.h>
#include <unistd.h>

#include <cstring>

int main(int argc, char **argv) {
  char *s = strdup("hello");
  unsigned long i = 0;
  if (s != NULL) {
    while (true) {
      printf("[%ld] s = %s\n", i++, s);
      sleep(1);
    }
  }

  return 0;
}