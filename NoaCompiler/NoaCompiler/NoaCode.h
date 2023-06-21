#ifndef NOAVM_NOACODE_H
#define NOAVM_NOACODE_H

//Ö¸ÁîÇø0xff00-0xffff
#define ver  0xff00
#define prts 0xff01	
#define mov  0xff02
#define add  0xff03
#define prt  0xff04
#define sub  0xff05
#define AND  0xff06
#define mst  0xff07
#define wtm  0xff08
#define OR   0xff09
#define mul  0xff0a
#define div  0xff0b
#define loop 0xff0c
#define call 0xff0d
#define recall 0xff0e
#define quit 0xff48

//¼Ä´æÆ÷Çø
#define eax 0x00
#define ebx 0x01
#define ecx 0x02
#define edx 0x03

#define ax  0x04
#define qx  0x05
#define spc 0x06

#endif // !NOAVM_NOACODE_H
