#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void reverse(char * str) {
  size_t len_input = strlen(str);
  int i, j;
  for (i = 0, j = len_input-1; i < j; i ++, j--){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}
*/
void reverse(char* str) {
  char* end = str;
  char tmp = 0;
  if(str) {
    while(*end) {
      end++;
    }
    --end;
    while(end>str) {
      tmp = *end;
      *end-- = *str;
      *str++ = tmp;
    }
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
