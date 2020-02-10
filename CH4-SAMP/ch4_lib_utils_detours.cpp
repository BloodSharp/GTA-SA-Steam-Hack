#include "CH4.h"

typedef struct _t_res
{
    unsigned char*address;
    unsigned long offset;
    unsigned long value;
}t_res;

typedef struct _t_cmddata
{
    unsigned long mask;
    unsigned long code;
    unsigned char len;
    unsigned char bits;
    unsigned char arg1,arg2,arg3;
}t_cmddata;

#define WW             0x01
#define SS             0x02
#define WS             0x03
#define W3             0x08
#define CC             0x10
#define FF             0x20
#define LL             0x40
#define PR             0x80
#define WP             0x81

#define NOS            0xFF
#define NNN            0x00
#define REG            0x01
#define MRG            0x02
#define IMM            0x03
#define IM1            0x04
#define IM2            0x05
#define IMA            0x06
#define JOB            0x07
#define JOW            0x08
#define JMF            0x09

const t_cmddata cmddata[] = {
  { 0x0000FF, 0x000090, 1,00,  NNN,NNN,NNN},
  { 0x0000FE, 0x00008A, 1,WW,  REG,MRG,NNN},
  { 0x0000F8, 0x000050, 1,00,  NNN,NNN,NNN},
  { 0x0000FE, 0x000088, 1,WW,  MRG,REG,NNN},
  { 0x0000FF, 0x0000E8, 1,00,  JOW,NNN,NNN},
  { 0x0000FD, 0x000068, 1,SS,  IMM,NNN,NNN},
  { 0x0000FF, 0x00008D, 1,00,  REG,MRG,NNN},
  { 0x0000FF, 0x000074, 1,CC,  JOB,NNN,NNN},
  { 0x0000F8, 0x000058, 1,00,  NNN,NNN,NNN},
  { 0x0038FC, 0x000080, 1,WS,  MRG,IMM,NNN},
  { 0x0000FF, 0x000075, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000EB, 1,00,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000E9, 1,00,  JOW,NNN,NNN},
  { 0x0000FE, 0x000084, 1,WW,  MRG,REG,NNN},
  { 0x0038FE, 0x0000C6, 1,WW,  MRG,IMM,NNN},
  { 0x0000FE, 0x000032, 1,WW,  REG,MRG,NNN},
  { 0x0000FE, 0x00003A, 1,WW,  REG,MRG,NNN},
  { 0x0038FC, 0x003880, 1,WS,  MRG,IMM,NNN},
  { 0x0038FF, 0x0010FF, 1,00,  MRG,NNN,NNN},
  { 0x0000FF, 0x0000C3, 1,00,  NNN,NNN,NNN},
  { 0x0000F0, 0x0000B0, 1,W3,  NOS,IMM,NNN},
  { 0x0000FE, 0x0000A0, 1,WW,  NOS,IMA,NNN},
  { 0x00FFFF, 0x00840F, 2,CC,  JOW,NNN,NNN},
  { 0x0000F8, 0x000040, 1,00,  NNN,NNN,NNN},
  { 0x0038FE, 0x0000F6, 1,WW,  MRG,IMM,NNN},
  { 0x0000FE, 0x0000A2, 1,WW,  IMA,NNN,NNN},
  { 0x0000FE, 0x00002A, 1,WW,  REG,MRG,NNN},
  { 0x0000FF, 0x00007E, 1,CC,  JOB,NNN,NNN},
  { 0x00FFFF, 0x00850F, 2,CC,  JOW,NNN,NNN},
  { 0x0000FF, 0x0000C2, 1,00,  IM2,NNN,NNN},
  { 0x0038FF, 0x0030FF, 1,00,  MRG,NNN,NNN},
  { 0x0038FC, 0x000880, 1,WS,  MRG,IMM,NNN},
  { 0x0038FC, 0x002880, 1,WS,  MRG,IMM,NNN},
  { 0x0000F8, 0x000048, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00BF0F, 2,00,  REG,MRG,NNN},
  { 0x0000FF, 0x00007C, 1,CC,  JOB,NNN,NNN},
  { 0x0000FE, 0x000002, 1,WW,  REG,MRG,NNN},
  { 0x0038FC, 0x002080, 1,WS,  MRG,IMM,NNN},
  { 0x0000FE, 0x00003C, 1,WW,  NOS,IMM,NNN},
  { 0x0038FF, 0x0020FF, 1,00,  MRG,NNN,NNN},
  { 0x0038FE, 0x0010F6, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0028C0, 1,WW,  MRG,IM1,NNN},
  { 0x0000FE, 0x000038, 1,WW,  MRG,REG,NNN},
  { 0x0000FF, 0x00007D, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x00007F, 1,CC,  JOB,NNN,NNN},
  { 0x0038FE, 0x0020C0, 1,WW,  MRG,IM1,NNN},
  { 0x0000FE, 0x00001A, 1,WW,  REG,MRG,NNN},
  { 0x0038FE, 0x0018F6, 1,WW,  MRG,NNN,NNN},
  { 0x0000FF, 0x0000C9, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000060, 1,00,  NNN,NNN,NNN},
  { 0x0038FF, 0x00008F, 1,00,  MRG,NNN,NNN},
  { 0x0000FF, 0x000061, 1,00,  NNN,NNN,NNN},
  { 0x0000F8, 0x000090, 1,00,  NNN,NNN,NNN},
  { 0x0000FE, 0x000086, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000000, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000010, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000012, 1,WW,  REG,MRG,NNN},
  { 0x0000FE, 0x000020, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000022, 1,WW,  REG,MRG,NNN},
  { 0x0000FE, 0x000008, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x00000A, 1,WW,  REG,MRG,NNN},
  { 0x0000FE, 0x000028, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000018, 1,WW,  MRG,REG,NNN},
  { 0x0000FE, 0x000030, 1,WW,  MRG,REG,NNN},
  { 0x0038FC, 0x001080, 1,WS,  MRG,IMM,NNN},
  { 0x0038FC, 0x001880, 1,WS,  MRG,IMM,NNN},
  { 0x0038FC, 0x003080, 1,WS,  MRG,IMM,NNN},
  { 0x0000FE, 0x000004, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x000014, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x000024, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x00000C, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x00002C, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x00001C, 1,WW,  NOS,IMM,NNN},
  { 0x0000FE, 0x000034, 1,WW,  NOS,IMM,NNN},
  { 0x0038FE, 0x0000FE, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0008FE, 1,WW,  MRG,NNN,NNN},
  { 0x0000FE, 0x0000A8, 1,WW,  NOS,IMM,NNN},
  { 0x0038FE, 0x0020F6, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0028F6, 1,WW,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00AF0F, 2,00,  REG,MRG,NNN},
  { 0x0000FF, 0x00006B, 1,00,  REG,MRG,IM1},
  { 0x0000FF, 0x000069, 1,00,  REG,MRG,IMM},
  { 0x0038FE, 0x0030F6, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0038F6, 1,WW,  MRG,NNN,NNN},
  { 0x0000FF, 0x000098, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000099, 1,00,  NNN,NNN,NNN},
  { 0x0038FE, 0x0000D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0008D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0010D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0018D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0020D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0028D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0038D0, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0000D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0008D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0010D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0018D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0020D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0028D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0038D2, 1,WW,  MRG,NNN,NNN},
  { 0x0038FE, 0x0000C0, 1,WW,  MRG,IM1,NNN},
  { 0x0038FE, 0x0008C0, 1,WW,  MRG,IM1,NNN},
  { 0x0038FE, 0x0010C0, 1,WW,  MRG,IM1,NNN},
  { 0x0038FE, 0x0018C0, 1,WW,  MRG,IM1,NNN},
  { 0x0038FE, 0x0038C0, 1,WW,  MRG,IM1,NNN},
  { 0x0000FF, 0x000070, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000071, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000072, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000073, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000076, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000077, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000078, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x000079, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x00007A, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x00007B, 1,CC,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000E3, 1,00,  JOB,NNN,NNN},
  { 0x00FFFF, 0x00800F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00810F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00820F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00830F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00860F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00870F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00880F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x00890F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008A0F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008B0F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008C0F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008D0F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008E0F, 2,CC,  JOW,NNN,NNN},
  { 0x00FFFF, 0x008F0F, 2,CC,  JOW,NNN,NNN},
  { 0x0000FF, 0x0000F8, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000F9, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000F5, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000FC, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000FD, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000FA, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000FB, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00008C, 1,FF,  MRG,REG,NNN},
  { 0x0000FF, 0x00008E, 1,FF,  REG,MRG,NNN},
  { 0x0000FE, 0x0000A6, 1,WW,  NNN,NNN,NNN},
  { 0x0000FE, 0x0000AC, 1,WW,  NNN,NNN,NNN},
  { 0x0000FE, 0x0000A4, 1,WW,  NNN,NNN,NNN},
  { 0x0000FE, 0x0000AE, 1,WW,  NNN,NNN,NNN},
  { 0x0000FE, 0x0000AA, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00A4F3, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00ACF3, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00AAF3, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00A6F3, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00AEF3, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00A6F2, 1,WW,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00AEF2, 1,WW,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000EA, 1,00,  JMF,NNN,NNN},
  { 0x0038FF, 0x0028FF, 1,00,  MRG,NNN,NNN},
  { 0x0000FF, 0x00009A, 1,00,  JMF,NNN,NNN},
  { 0x0038FF, 0x0018FF, 1,00,  MRG,NNN,NNN},
  { 0x0000FF, 0x0000CB, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000CA, 1,00,  IM2,NNN,NNN},
  { 0x00FFFF, 0x00A40F, 2,00,  MRG,REG,IM1},
  { 0x00FFFF, 0x00AC0F, 2,00,  MRG,REG,IM1},
  { 0x00FFFF, 0x00A50F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00AD0F, 2,00,  MRG,REG,NNN},
  { 0x00F8FF, 0x00C80F, 2,00,  NNN,NNN,NNN},
  { 0x00FEFF, 0x00C00F, 2,WW,  MRG,REG,NNN},
  { 0x0000FF, 0x0000E2, 1,LL,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000E1, 1,LL,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000E0, 1,LL,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000C8, 1,00,  IM2,IM1,NNN},
  { 0x0000FE, 0x0000E4, 1,WP,  NOS,IM1,NNN},
  { 0x0000FE, 0x0000EC, 1,WP,  NNN,NNN,NNN},
  { 0x0000FE, 0x0000E6, 1,WP,  IM1,NNN,NNN},
  { 0x0000FE, 0x0000EE, 1,WP,  NNN,NNN,NNN},
  { 0x0000FE, 0x00006C, 1,WP,  NNN,NNN,NNN},
  { 0x0000FE, 0x00006E, 1,WP,  NNN,NNN,NNN},
  { 0x00FEFF, 0x006CF3, 1,WP,  NNN,NNN,NNN},
  { 0x00FEFF, 0x006EF3, 1,WP,  NNN,NNN,NNN},
  { 0x0000FF, 0x000037, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00003F, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x000AD4, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000D4, 1,00,  IM1,NNN,NNN},
  { 0x00FFFF, 0x000AD5, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000D5, 1,00,  IM1,NNN,NNN},
  { 0x0000FF, 0x000027, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00002F, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000F4, 1,PR,  NNN,NNN,NNN},
  { 0x0000FF, 0x00000E, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000016, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00001E, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000006, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A00F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A80F, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00001F, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000007, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x000017, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A10F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A90F, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000D7, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00BE0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00B60F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00B70F, 2,00,  REG,MRG,NNN},
  { 0x0000FF, 0x00009B, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00009F, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00009E, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00009C, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00009D, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000CD, 1,00,  IM1,NNN,NNN},
  { 0x0000FF, 0x0000CC, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000CE, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000CF, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00900F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00910F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00920F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00930F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00940F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00950F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00960F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00970F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00980F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00990F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009A0F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009B0F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009C0F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009D0F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009E0F, 2,CC,  MRG,NNN,NNN},
  { 0x00FFFF, 0x009F0F, 2,CC,  MRG,NNN,NNN},
  { 0x38FFFF, 0x20BA0F, 2,00,  MRG,IM1,NNN},
  { 0x38FFFF, 0x28BA0F, 2,00,  MRG,IM1,NNN},
  { 0x38FFFF, 0x30BA0F, 2,00,  MRG,IM1,NNN},
  { 0x38FFFF, 0x38BA0F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00A30F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00AB0F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00B30F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00BB0F, 2,00,  MRG,REG,NNN},
  { 0x0000FF, 0x0000C5, 1,00,  REG,MRG,NNN},
  { 0x0000FF, 0x0000C4, 1,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00B40F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00B50F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00B20F, 2,00,  REG,MRG,NNN},
  { 0x0000FF, 0x000063, 1,00,  MRG,REG,NNN},
  { 0x0000FF, 0x000062, 1,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00BC0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00BD0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00060F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00400F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00410F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00420F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00430F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00440F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00450F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00460F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00470F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00480F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x00490F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004A0F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004B0F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004C0F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004D0F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004E0F, 2,CC,  REG,MRG,NNN},
  { 0x00FFFF, 0x004F0F, 2,CC,  REG,MRG,NNN},
  { 0x00FEFF, 0x00B00F, 2,WW,  MRG,REG,NNN},
  { 0x38FFFF, 0x08C70F, 2,00,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00A20F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00080F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00020F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00030F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x38010F, 2,PR,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00090F, 2,PR,  NNN,NNN,NNN},
  { 0x38FFFF, 0x10010F, 2,PR,  MRG,NNN,NNN},
  { 0x38FFFF, 0x00010F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x18010F, 2,PR,  MRG,NNN,NNN},
  { 0x38FFFF, 0x08010F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x10000F, 2,PR,  MRG,NNN,NNN},
  { 0x38FFFF, 0x00000F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x18000F, 2,PR,  MRG,NNN,NNN},
  { 0x38FFFF, 0x08000F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x30010F, 2,PR,  MRG,NNN,NNN},
  { 0x38FFFF, 0x20010F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x20000F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x28000F, 2,00,  MRG,NNN,NNN},
  { 0xC0FFFF, 0xC0220F, 2,PR,  REG,MRG,NNN},
  { 0xC0FFFF, 0xC0200F, 2,00,  MRG,REG,NNN},
  { 0xC0FFFF, 0xC0230F, 2,PR,  REG,MRG,NNN},
  { 0xC0FFFF, 0xC0210F, 2,PR,  MRG,REG,NNN},
  { 0x00FFFF, 0x00310F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00320F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00300F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00330F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AA0F, 2,PR,  NNN,NNN,NNN},
  { 0x00FFFF, 0x000B0F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00340F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00350F, 2,PR,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000D6, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F0D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E0D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E1D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E2DB, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E3DB, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F6D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F7D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E4D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FAD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FED9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FFD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FBD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F2D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F3D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F8D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F5D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F1D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F9D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FCD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E8D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E9D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00EAD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00EBD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00ECD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00EDD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00EED9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00FDD9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00D0D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E0DF, 2,FF,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E5D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00F4D9, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00D9DE, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E9DA, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0DD, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0DA, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8DA, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D0DA, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D8DA, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D0DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D8DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F0DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F0DF, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8DB, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8DF, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E0D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E0DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E0DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D0D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D8D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E0DD, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00E8DD, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F0D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F8DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F8DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F8D8, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F0DC, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00F0DE, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C0D9, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D0DD, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00D8DD, 2,00,  NNN,NNN,NNN},
  { 0x00F8FF, 0x00C8D9, 2,00,  NNN,NNN,NNN},
  { 0x0038FF, 0x0000D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0008D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0008DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0008DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0008DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038D8, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DC, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DE, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DA, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DB, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DB, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DB, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DF, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0000DD, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028DB, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0010DD, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0018DD, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DB, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0028D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030D9, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0020DD, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0030DD, 1,00,  MRG,NNN,NNN},
  { 0x0038FF, 0x0038DD, 1,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x08AE0F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x00AE0F, 2,00,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00E0DB, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00E1DB, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00770F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006E0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x007E0F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x006F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x007F0F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00630F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x006B0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00670F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00FC0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00FD0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00FE0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00F80F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00F90F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00FA0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00EC0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00ED0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E80F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E90F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DC0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DD0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00D80F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00D90F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DB0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DF0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00740F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00750F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00760F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00640F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00650F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00660F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00F50F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E50F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00D50F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00EB0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00F10F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x30710F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00F20F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x30720F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00F30F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x30730F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00E10F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x20710F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00E20F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x20720F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00D10F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x10710F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00D20F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x10720F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00D30F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x10730F, 2,00,  MRG,IM1,NNN},
  { 0x00FFFF, 0x00680F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00690F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x006A0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00600F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00610F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00620F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00EF0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x000E0F, 2,00,  NNN,NNN,NNN},
  { 0x38FFFF, 0x000D0F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x080D0F, 2,00,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00F70F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E70F, 2,00,  MRG,REG,NNN},
  { 0x00FFFF, 0x00E00F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E30F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00C50F, 2,00,  MRG,REG,IM1},
  { 0x00FFFF, 0x00C40F, 2,00,  REG,MRG,IM1},
  { 0x00FFFF, 0x00EE0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DE0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00EA0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00DA0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00D70F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00E40F, 2,00,  REG,MRG,NNN},
  { 0x38FFFF, 0x00180F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x08180F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x10180F, 2,00,  MRG,NNN,NNN},
  { 0x38FFFF, 0x18180F, 2,00,  MRG,NNN,NNN},
  { 0x00FFFF, 0x00F60F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x00700F, 2,00,  REG,MRG,IM1},
  { 0xFFFFFF, 0xF8AE0F, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0xBF0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x9E0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x9A0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xAA0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xAE0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x900F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xA00F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xB00F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x940F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xA40F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x0D0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x1D0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x960F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x970F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xB40F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xA60F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xA70F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xB60F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xB70F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x1C0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x8A0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x8E0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0x0C0F0F, 2,00,  REG,MRG,NNN},
  { 0x00FFFF, 0xBB0F0F, 2,00,  REG,MRG,NNN},
  { 0x0000FF, 0x0000A6, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A766, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000A7, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AC, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AD66, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AD, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000A4, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A566, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000A5, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AE, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AF66, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AF, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AA, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AB66, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000AB, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A4F3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xA5F366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A5F3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00ACF3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xADF366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00ADF3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AAF3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xABF366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00ABF3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A6F3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xA7F366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A7F3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AEF3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xAFF366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AFF3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A6F2, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xA7F266, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00A7F2, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AEF2, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0xAFF266, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00AFF2, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00006C, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006D66, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00006D, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00006E, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006F66, 2,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x00006F, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006CF3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0x6DF366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006DF3, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006EF3, 1,00,  NNN,NNN,NNN},
  { 0xFFFFFF, 0x6FF366, 2,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x006FF3, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000E1, 1,00,  JOB,NNN,NNN},
  { 0x0000FF, 0x0000E0, 1,00,  JOB,NNN,NNN},
  { 0x0000FF, 0x00009B, 1,00,  NNN,NNN,NNN},
  { 0x0000FF, 0x0000D7, 1,00,  NNN,NNN,NNN},
  { 0x00FFFF, 0x00C40F, 2,00,  REG,MRG,IM1},
  { 0x00FFFF, 0x0020CD, 2,00,  NNN,NNN,NNN},
  { 0x0000F0, 0x000070, 1,CC,  JOB,NNN,NNN},
  { 0x00F0FF, 0x00800F, 2,CC,  JOW,NNN,NNN},
  { 0x00F0FF, 0x00900F, 2,CC,  MRG,NNN,NNN},
  { 0x00F0FF, 0x00400F, 2,CC,  REG,MRG,NNN},
  { 0x000000, 0x000000, 0,00,  NNN,NNN,NNN}
};

unsigned long GetInstructionSize(unsigned char*src,t_res*res)
{
    unsigned long hasrm,hassib,dispsize,immsize,operand,arg,code,datasize,addrsize,repprefix;
    bool isprefix,repeated,segprefix,lockprefix;
    const t_cmddata*pd;
    int c;

    datasize=addrsize=4;repprefix=hasrm=hassib=dispsize=immsize=0;
    segprefix=repeated=lockprefix=false;

    unsigned char*cmd=src;
    for(;;)
    {
        isprefix=true;
        switch(*cmd)
        {
            case 0x2E:case 0x26:case 0x36:case 0x3E:case 0x64:case 0x65:
                if(!segprefix)segprefix=true;
                else repeated=true;
                break;
            case 0x67:case 0x66:
                if(datasize==4)datasize=2;
                else repeated=true;
                break;
            case 0xF0:
                if(!lockprefix)lockprefix=true;
                else repeated=true;
                break;
            case 0xF2:
                if(!repprefix)repprefix=0xF2;
                else repeated=true;
                break;
            case 0xF3:
                if(!repprefix)repprefix=0xF3;
                else repeated=true;
                break;
            default:
                isprefix=false;
                break;
        }
        if(isprefix==false||repeated!=false)break;
        cmd++;
    }
    if(repeated)
        return 1;
    code=0;
    *(((char*)&code)+0)=cmd[0];
    *(((char*)&code)+1)=cmd[1];
    *(((char*)&code)+2)=cmd[2];
    if(repprefix!=0)
        code=(code<<8)|repprefix;

    for(pd=cmddata;pd->mask!=0;pd++)
    {
        if(((code^pd->code)&pd->mask)!=0)
            continue;
        break;
    }

    if(pd->mask!=0)
    {
        if(pd->len==2)cmd++;
        if((pd->bits&WW)!=0&&(*cmd&WW)==0)
            datasize=1;
        else if((pd->bits&W3)!=0&&(*cmd&W3)==0)
            datasize=1;
        else if((pd->bits&FF)!=0)
            datasize=2;
        for(operand=0;operand<3;operand++)
        {
            if(operand==0)arg=pd->arg1;
            else if(operand==1)arg=pd->arg2;
            else arg=pd->arg3;
            if(arg==NNN)break;
            switch(arg)
            {
                case MRG:
                    c=cmd[1]&0xC7;hasrm=1;
                    if((c&0xC0)==0xC0)
                        break;
                    if(addrsize==2)
                    {
                        if(c==0x06)
                            dispsize=2;
                        else
                        {
                            if((c&0xC0)==0x40)
                                dispsize=1;
                            else if((c&0xC0)==0x80)
                                dispsize=2;
                        }
                    }
                    else if(c==0x05)
                        dispsize=4;
                    else if((c&0x07)==0x04)
                    {
                        hassib=1;
                        if(c==0x04&&(cmd[2]&0x07)==0x05)
                            dispsize=4;
                        else
                        {
                            if((c&0xC0)==0x40)
                                dispsize=1;
                            else if((c&0xC0)==0x80)
                                dispsize=4;
                        };
                    }
                    else if((c&0xC0)==0x40)
                        dispsize=1;
                    else if((c&0xC0)==0x80)
                        dispsize=4;
                    break;
                case IMM:
                    if((pd->bits&SS)!=0&&(*cmd&0x02)!=0)
                        immsize+=1;
                    else
                        immsize+=datasize;
                    break;
                case IM1:
                    immsize+=1;
                    break;
                case IM2:
                    immsize+=2;
                    break;
                case JOB://can't resolve short offsets
                    dispsize=1;
                    res->address=(unsigned char*)-1;
                    break;
                case IMA:
                    dispsize=addrsize;
                    break;
                case JOW:
                {
                    if(datasize==4)
                    {
                        //resolve full offset
                        res->address=cmd;
                        res->value=(unsigned long)cmd+*(unsigned long*)(cmd+1)+5;
                    }
                    else
                        //can't resolve short offsets
                        res->address=(unsigned char*)-1;
                    dispsize=datasize;
                }
                break;
                case JMF:
                    dispsize=addrsize;
                    immsize=2;
                case REG:
                    hasrm=1;
                    break;
                default:
                    break;
            }
        }
    }
    cmd+=1+hasrm+hassib+dispsize+immsize;
    return(cmd-src);
}

unsigned long CalcRequiredSize(unsigned char*src,unsigned int lenNeed,t_res*res)
{
    unsigned char*tmp=src;
    do
    {
        if(*tmp==0xC3)
            return(tmp-src+1);
        if(*tmp==0xC2)
            return(tmp-src+3);
        tmp+=GetInstructionSize(tmp,res);
        if(res->address)
        {
            if(res->address==(unsigned char*)-1)
                return 0;
            res->offset=(res->address-src);
        }
    }while(((unsigned int)(tmp-src))<lenNeed);
    return(tmp-src);
}

#ifdef __linux__
void*LinuxVirtualProtect(void*address,size_t size,int protections)
{
    long pagesize;
    pagesize=sysconf(_SC_PAGESIZE);
    address=(void*)((long)address&~(pagesize-1));
    if(mprotect(address,size,protections)==0)
        return address;
    return 0;
}

void*fake_malloc(size_t size)
{
    void *retadd=mmap(0,size,PROT_READ|PROT_WRITE|PROT_EXEC,MAP_ANON|MAP_PRIVATE,-1,0);
    if(retadd==MAP_FAILED)
        return 0;
    return retadd;
}
#endif//__linux__

void*CH4::Utils::DetourFunction(unsigned char*orig,unsigned char*hook)
{
    int len;
    t_res res={0};
    #ifdef __linux__
    len=CalcRequiredSize(orig,5,&res);
    unsigned char*jmp=(unsigned char*)fake_malloc(len+5);
    LinuxVirtualProtect(orig,len,PROT_READ|PROT_WRITE|PROT_EXEC);
    #endif//__linux__
    #ifdef _WIN32
    DWORD dwOldProtections;
    len=CalcRequiredSize(orig,5,&res);
    //unsigned char*jmp=(unsigned char*)malloc(len+5);
    unsigned char*jmp=(unsigned char*)VirtualAlloc(NULL,len+5,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READWRITE);
    VirtualProtect(orig,len,PAGE_EXECUTE_READWRITE,&dwOldProtections);
    #endif//_WIN32
    memcpy(jmp,orig,len);
    jmp+=len; // increment to the end of the copied bytes
    jmp[0]=0xE9;
    *(unsigned int*)(jmp+1)=(unsigned int)(orig+len-jmp)-5;
    memset(orig,0x90,len);
    orig[0]=0xE9;
    *(unsigned int*)(orig+1)=(unsigned int)(hook-orig)-5;
    #ifdef __linux__
    //LinuxVirtualProtect(orig,len,PROT_READ|PROT_EXEC);
    #endif//__linux__
    #ifdef _WIN32
    //VirtualProtect(orig,len,dwOldProtections,0);
    #endif//_WIN32
    return(jmp-len);
}
