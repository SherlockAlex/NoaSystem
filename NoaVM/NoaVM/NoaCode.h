#ifndef NOAVM_NOACODE_H
#define NOAVM_NOACODE_H

//指令区0xfc00-0xfcff
#define fun		0xfc			//函数标志位
#define _start	0x00			//开始
#define _end	0xff			//返回
#define prts	0x01	
#define mov		0x02
#define add		0x03
#define prt		0x04
#define sub		0x05
#define ANDB	0x06
#define mst		0x07
#define wtm		0x08
#define ORB		0x09
#define mul		0x0a
#define div		0x0b
#define loop	0x0c
#define call	0x0d
#define IF		0x0f
#define AND		0x10
#define OR		0x11
#define CMP		0x12
#define rfm     0x13
#define ELSE    0x14             //和if相反

//定义数据类型
#define BYTE		0x15		//1B
#define SHORT		0x16		//2B
#define INT			0x17		//4B
#define FLOAT		0x18		//4B
#define LONG		0x19		//8B
#define DOUBLE		0x1a		//8B
#define STRING		0x1b		//1B
#define STRREADER	0x1c
#define INTREADER   0x1d
#define FLOATREADER 0x1e


#define quit 0xe0

//寄存器区
#define eax 0x00
#define ebx 0x01
#define ecx 0x02
#define edx 0x03

#define ax  0x04
#define qx  0x05//逻辑寄存器，用于存放逻辑运算的结果
#define loopcounter 0x06//循环计数器,记录剩余要循环的次数

#endif // !NOAVM_NOACODE_H
