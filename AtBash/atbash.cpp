#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include "atbash.hpp"

#define  CODE_ATBASH       "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define  DECODE_ATBASH    "ZYXWVUTSRQPONMLKJIHGFEDCBA"

// функция кодирования
char* code_atbash(char* src) {
   char* dst = src;
   const char* cch, *dch;

   while( *src ) {
        if(isalpha(*src)) {
                  for(dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                       if( *cch == toupper(*src) ) {
                            *src = (isupper(*src)) ?  *dch : tolower(*dch);
                             break;
                       }
                  }
         }
         *src++;
   }
   return dst;
}

// функция декодирования
char* decode_atbash(char* src) {
   char* dst = src;
   const char* cch, *dch;

   while( *src ) {
         if(isalpha(*src)) {
               for(dch = DECODE_ATBASH, cch = CODE_ATBASH; *cch; *cch++, *dch++) {
                    if( *dch == toupper(*src) ) {
                          *src = (isupper(*src)) ?  *cch : tolower(*cch);
                            break;
                     }
                }
         }
         *src++;
   }
   return dst;
}
