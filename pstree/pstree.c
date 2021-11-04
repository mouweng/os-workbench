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
  if (strcmp(argv[1], "-V") == 0 || strcmp(argv[1], "--version") == 0) {
    printf("version\n");
  } else if (strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--numeric-sort") == 0) {
    printf("numeric-sort\n");
  } else if (strcmp(argv[1], "-p") == 0 || strcmp(argv[1], "--show-pids") == 0) {
    printf("show-pids\n");
  } else {
    printf("There Is No Such Argument Named %s\n", argv[1]);
  }
  return 0;
}
