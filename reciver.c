#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define PIPE1 "/tmp/pipe1"
#define PIPE2 "/tmp/pipe2"
int countWords(char* str) {
int count = 0;
char* token = strtok(str, " \n");
while (token != NULL) {
count++;
token = strtok(NULL, " \n");
}
return count;
}
int countLines(char* str) {
int count = 0;
for (int i = 0; str[i] != '\0'; i++) {
if (str[i] == '\n') {
count++;
}
}
return count;
}
int main() {
int fd1, fd2;
char input[1000], output[1000];
int charCount, wordCount, lineCount;
FILE* file;
// Open PIPE1 for reading
fd1 = open(PIPE1, O_RDONLY);
read(fd1, input, sizeof(input));
close(fd1);
// Count characters, words, and lines
charCount = strlen(input);
wordCount = countWords(input);
lineCount = countLines(input);
// Write the results to a file
file = fopen("output.txt", "w");
fprintf(file, "Characters: %d\nWords: %d\nLines: %d\n", charCount,
wordCount,
lineCount);
fclose(file);
// Read the content of the file and send it through PIPE2
file = fopen("output.txt", "r");
fread(output, sizeof(char), sizeof(output), file);
fclose(file);
// Open PIPE2 for writing
fd2 = open(PIPE2, O_WRONLY);
write(fd2, output, strlen(output) + 1);
close(fd2);
return 0;
}
