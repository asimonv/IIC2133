#include <stdio.h>

int sum(int *a, int b){
  *a+=b;
  return *a;
}

int main(int argc, char const *argv[]) {
  int num = 2;
  int res = sum(&num,3);
  printf("%i\t %i", res, num);
  return 0;
}
