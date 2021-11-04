#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
  assert(!argv[argc]);
  if (argc != 2) {
    printf("argc = %d, Argument Error!\n", argc);
    return 0;
  }
  for (int i = 0; i < argc; i++) {
    assert(argv[i]);
    if (i == 1) {
      printf("argv[%d] = %s\n", i, argv[i]);
    }
  }
  return 0;
}
