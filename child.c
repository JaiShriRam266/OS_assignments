#include <stdio.h>
int main(int argc, char *argv[]) {
printf("Array in reverse order:\n");
for (int i = argc - 1; i > 0; i--) {
printf("%s ", argv[i]);
}
printf("\n");
return 0; }