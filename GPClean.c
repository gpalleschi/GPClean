#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

char version[40] = "1.0 - 03.02.2022";

void help() {
     printf("\n GPClean by Giovanni Palleschi - 2022 \n");
     printf("\n https://github.com/gpalleschi/GPClean \n");
     printf("\n --------------------------------------------------------------- ");
     printf("\n Version : %s",version);
     printf("\n --------------------------------------------------------------- \n");
     printf("\n LC Tool to replace special characters from text file in format utf8.\n");  
     printf("\n This tool acept a txt file in UTF8 format in stdin and produce in stdout, same file with special characters cleaned.\n");
     printf("\n Specifically characters will be managed in this way :  \n");
     printf("\n from 00 to 7F hex  ==> Not Modified");
     printf("\n form C2 to DF hex  ==> Substituted by ? (2 input bytes 1 output byte)");
     printf("\n form E0 to EF hex  ==> Substituted by ? (3 input bytes 1 output byte)");
     printf("\n form F0 to FF hex  ==> Substituted by ?? (4 input bytes 2 output byte)\n");
     printf("\n Execution example :  \n");
     printf("\n         GPClean < Input_File.txt > Output_File.txt       \n\n");
     return;
}

int readBytes(int nBytes) {
  int b = 0;
  int iLoop =0;
  while((b = getchar()) != EOF) {
	iLoop++;   
	if ( nBytes == iLoop ) break;
  }
  return iLoop;
}



void main(int argc, char **argv) {
    int c = 0;
    char hexValue[3];

    if (argc > 1 && !strcmp(argv[1], "help")) {
        help();
        return;
    }

    while((c = getchar()) != EOF) {
        if (c <= 126) {
            printf( "%c",c);
        }
        else {
/*
The value of each individual byte indicates its UTF-8 function, as follows:

00 to 7F hex (0 to 127): first and only byte of a sequence.
80 to BF hex (128 to 191): continuing byte in a multi-byte sequence.
C2 to DF hex (194 to 223): first byte of a two-byte sequence.
E0 to EF hex (224 to 239): first byte of a three-byte sequence.
F0 to FF hex (240 to 255): first byte of a four-byte sequence.
*/
            sprintf(hexValue,"%0x",c);
            if (c >= 194 && c <= 223) {
                readBytes(1);
                printf( "?");
            }
            else if (c >= 224 && c <= 239) {
                readBytes(2);
                printf( "?");
            }
            else if (c >= 240 && c <= 255) {
                readBytes(3);
                printf( "??");
            }
            else {
                printf( "?");
            }
        }
    }

    return;
}
