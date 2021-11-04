#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
  assert(!argv[argc]);
  if (argc != 2) {
    printf("argc = %d, Argument Number Error!\n", argc);
    return 0;
  }
  assert(argv[1]);
  // printf("argv = %s\n", argv[1]);
  if (*argv[1] == "-V" || *argv[1] == "--version") {
    printf("version\n");
  } else if (*argv[1] == "-n" || *argv[1] == "--numeric-sort") {
    printf("numeric-sort\n");
  } else if (*argv[1] == "-p" || *argv[1] == "--show-pids") {
    printf("show-pids\n");
  } else {
    printf("There Is No Such Argument Named %s\n", argv[1]);
  }
  return 0;
}
