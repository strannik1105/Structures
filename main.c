#include <stdio.h>
#include "algorithms/stack.c"

int main()
{
  int var1 = 1;
  int var2 = 2;
  int var3 = 3;
  Stack* stack = stack_create();
  stack_push(stack, &var1);
  stack_push(stack, &var2);
  stack_push(stack, &var3);
  printf("%d\n", (*(int*) (pop(stack))));
  printf("%d\n", (*(int*) (pop(stack))));
  printf("%d\n", (*(int*) (pop(stack))));
  return 0;
}
