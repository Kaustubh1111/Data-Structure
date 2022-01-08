#include <stdio.h>
#include <string.h>

void main (void) {
   char s1[100];
   char s2[100];
   printf("Enter 1st string: ");
   scanf("%s",s1);
   printf("Enter 2nd string: ");
   scanf("%s",s2);

   char temp;

   int i, j;
   int n  = strlen(s1);
   int n1 = strlen(s2);

   if( n != n1) {
      printf("%s and %s are not anagrams! \n", s1, s2);
      return 0;
   }

   for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (s1[i] > s1[j]) {
            temp  = s1[i];
            s1[i] = s1[j];
            s1[j] = temp;
         }
         if (s2[i] > s2[j]) {
            temp  = s2[i];
            s2[i] = s2[j];
            s2[j] = temp;
         }
      }
   }
   for(i = 0; i<n; i++) {
      if(s1[i] != s2[i]) {
         printf("Strings are not anagram.\n");
         exit(0);
      }
   }
   printf("Strings are anagram. \n");

}
