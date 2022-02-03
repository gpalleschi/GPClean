# GPClean

----

## Description :

LC Tool to replace special characters from text file in format utf8.  

This tool acept a txt file in UTF8 format in stdin and produce in stdout, same file with special characters cleaned.  

Specifically characters will be managed in this way :  

from 00 to 7F hex  ==> Not Modified  
form C2 to DF hex  ==> Substituted by ? (2 input bytes 1 output byte)  
form E0 to EF hex  ==> Substituted by ? (3 input bytes 1 output byte)  
form F0 to FF hex  ==> Substituted by ?? (4 input bytes 2 output byte)  

Execution example :  

GPClean < Input_File.txt > Output_File.txt  

Ej.  

**Input_File.txt**  :  

🙊MICA🙊

**Output_File.txt** : 

??MICA??


## UTF8 Specification :  

See here [UTF8 Specification](https://www.fileformat.info/info/unicode/utf8.htm)  

The value of each individual byte indicates its UTF-8 function, as follows:  

00 to 7F hex (0 to 127): first and only byte of a sequence.  
80 to BF hex (128 to 191): continuing byte in a multi-byte sequence.  
C2 to DF hex (194 to 223): first byte of a two-byte sequence.  
E0 to EF hex (224 to 239): first byte of a three-byte sequence.  
F0 to FF hex (240 to 255): first byte of a four-byte sequence.  

## Coding With :  

Visual Code Editor   

----  

## Build :  

make -f GPClean.c    

----  


## Authors  

* **Giovanni Palleschi** - [gpalleschi](https://github.com/gpalleschi)  

----  

## Prerequisites :  

N.A.   

## License :  

This project is licensed under the GNU GENERAL PUBLIC LICENSE 3.0 License - see the [LICENSE](LICENSE) file for details  