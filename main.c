#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int readField(const char *, int *, char *, int);
int main(void) {
   const int MAX_TITLE_CHARS = 44;  // Maximum length of movie titles
   const int LINE_LIMIT = 100;   // Maximum length of each line in the text file
   char line[LINE_LIMIT];
   char inputFileName[25];
   scanf("%s", inputFileName);
   FILE *inputFile = fopen(inputFileName, "r");
   if (inputFile != NULL) {
      char lastTitle[MAX_TITLE_CHARS];
      strcpy(lastTitle, "");
      while (fgets(line, LINE_LIMIT, inputFile)) {
         char showtime[6];
         char title[MAX_TITLE_CHARS];
         char rating[6];
         int i = 0;
         readField(line, &i, showtime, 6);
         readField(line, &i, title, MAX_TITLE_CHARS);
         readField(line, &i, rating, 6);
         if (strcmp(title, lastTitle) == 0) {
            printf(" %s", showtime);
         } else {
            if (strcmp(lastTitle, "") != 0) {
               printf("\n");
            }
            printf("title: %s\tlast title: %s\n", title, lastTitle);
            printf("%-44.44s | %5s | %s", title, rating, showtime);
         }
         strcpy(lastTitle, title);
      }
   } else {
      printf("Could not open file. Check the file name & try again.");
   }
   printf("\n");
   return 0;
}
int readField(const char *buffer, int *i, char *fieldOut, int outLength) {
   const int iOffset = *i;
   while (buffer[*i] != ',' && buffer[*i] != '\n' && buffer[*i] != '\0') {
      if (*i - iOffset < outLength) {
         fieldOut[*i - iOffset] = buffer[*i];
      }
      (*i)++;
   }
   fieldOut[*i - iOffset] = '\0';
   (*i)++;
   return strlen(fieldOut);
}
