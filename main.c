#include <stdio.h>
#include <string.h>

int main() {
  char tmp[20];
  char output[26] = "Hello ";

  printf("Hello what?\n");
  scanf("%s", tmp);
  strcat(output, strcat(tmp, "\n"));
  printf(output);
  return 0;
}