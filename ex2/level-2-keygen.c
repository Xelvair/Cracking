#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

const int PW_BUF_SIZE = 33;

int parity_even(uint32_t val){
  int has_parity = 1;
  
  int i = 0;
  for(i = 0; i < 32; ++i){
    has_parity ^= ((val >> i) & 1);
  }
  
  return has_parity;
}

int main(int argc, char* argv[]){
  uint32_t username;
  printf("Enter username: ");
  scanf("%d", &username);
  
  uint8_t pw_buf[PW_BUF_SIZE];
  memset(pw_buf, 'O', PW_BUF_SIZE - 1);
  pw_buf[PW_BUF_SIZE - 1] = '\0';
  
  uint8_t* pw_buf_it = (char*)pw_buf;
  
  if(((signed)username) >= 0)
    *pw_buf_it = '*';
  ++pw_buf_it;
  
  if(username < 0xB16B00B5)
    *pw_buf_it = '*';
  ++pw_buf_it;
  
  if(parity_even(username))
    *pw_buf_it = '*';
  ++pw_buf_it;
    
  *pw_buf_it = '*';
  
  int32_t i;
  for(i = 28; i > 0; --i){
    username = username >> 1;
    
    uint8_t username_mod = username % 26;
    if(i % 2 == 1){
      username_mod += 0x41;
      *pw_buf_it = username_mod;
    } else {
      username_mod += 0x61;
      *pw_buf_it = username_mod;
    }
    ++pw_buf_it;
  }
  printf("%s", pw_buf);
  
}