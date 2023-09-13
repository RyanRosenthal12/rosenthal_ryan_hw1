#include <stdio.h>
#include <stdlib.h>
//Q1
char* print_any_base(unsigned long num, unsigned int base) {
    char* p = NULL;
    int index = 0;

    if (base < 2 || base > 36) {
        char* err = "Illegal Base";
        return err;
    }

    if (num == 0) {
        p = (char*)malloc(2);
        if (p == NULL) {
            printf("Poor memory allocation\n");
        }
        p[index] = '0';
        index++;
    } else {
        unsigned long temp = num;
        int maxDigits = 0;
        while (temp > 0) {
            temp /= base;
            maxDigits++;
        }

        p = (char*)malloc(maxDigits + 1); 
        if (p == NULL) {
            printf("Poor memory allocation\n");
        }

        while (num > 0) {
            unsigned long remainder = num % base;
            char curNum;
            if (remainder < 10) {
                curNum = remainder + '0';
            } else {
                curNum = remainder - 10 + 'A';
            }
            p[index] = curNum;
            index++;
            num /= base;
        }
    }

    p[index] = '\0';

    //Reverse
    int s = 0;
    int e = index - 1;
    while (s < e) {
        char temp = p[s];
        p[s] = p[e];
        p[e] = temp;
        s++;
        e--;
    }

    return p;
}
//Q2
int count_vowels(char *str)
{
  int count = 0;
  while (*str)
    {
      char h = *str;
      if (h  == 'a' || h == 'A' || h == 'e' || h == 'E' || h == 'i' || h == 'I' || h == 'o' || h == 'O' || h == 'u' || h == 'U')
	{ count++;}
      str++
    }
  return count;
}
//Q3
char *reverse_words(char *str) {
  int length = strlen(str);
  char *reversed = (char *)malloc(length * sizeof(char));


  int startWord = 0;
  int endWord = 0;
  int rIndex = 0;

   for (int i = length - 1; i >= 0; i--) {
       if (str[i] == ' ' || str[i] == '\0') {
          startWord = i + 1;
           for (int j = startWord; j <= endWord; j++) {
               reversed[rIndex] = str[j];
	       rIndex ++;}
            if (i > 0) {
                reversed[rIndex] = ' ';
		rIndex ++;
            }
            endWord = i - 1;
        } else if (i == 0) {
            startWord = i;
            for (int j = startWord; j <= endWord; j++) {
                reversed[rIndex] = str[j];
		rIndex ++;
            }
        } 
	else {
            endWord = i;
        }
    }

    reversed[rIndex] = '\0';

    return reversed;
}
//Q4
void *rotate_string_in_place(char *str, unsigned int disp)
{
  while (*str)
    {
  
  if (*str >= 'a' && *str<='z')
    {
     *str = 'a' + ((*str - 'a' + disp) % 26);
    }
    
    if ( >='A' && <= 'Z')
    {
      *str = 'A' + ((*str - 'A' + disp) % 26);
    }
    str ++;
    }
}


