#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <Windows.h>

const int BUF_SIZE = 100;

int main(int argc, char* argv[]){
  char username_buf[BUF_SIZE];
  memset(username_buf, 0, BUF_SIZE);
  
  printf("Please enter your desired username: \n");
  fgets(username_buf, BUF_SIZE - 1, stdin);
  
  char* username_it = (char*)username_buf;
  uint32_t sum = 0;
  while(*username_it != '\0' && *username_it != '\n'){
    sum += (int)(*username_it);
    ++username_it;
  }
  
  unsigned char* sum_as_char = (unsigned char*)&sum;
  
  printf("Your password is: HEX: 0x%02x%02x%02x%02x | ASCII: \"", (int)(sum_as_char[3]), (int)(sum_as_char[2]), (int)(sum_as_char[1]),(int)(sum_as_char[0]));
  printf("%c%c%c%c\"\n", sum_as_char[3], sum_as_char[2], sum_as_char[1],sum_as_char[0]);
  
  system("PAUSE");
  
  return EXIT_SUCCESS;
}