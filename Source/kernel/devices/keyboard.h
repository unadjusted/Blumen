#include "../arch/i386/io.h"

int keymap[2][28]={{0x39,0x1C,0x1E,0x30,0x2E,0x20,0x12,0x21,0x22,0x23,0x17,0x24,0x25,0x26,0x32,0x31,0x18,0x19,0x10,0x13,0x1F,0x14,0x16,0x2F,0x11,0x2D,0x15,0x2C},
                  {32  ,10  ,65  ,66  ,67 ,68  ,69  ,70  ,71  ,72  ,73  ,74  ,75  ,76  ,77  ,78  ,79  ,80  ,81  ,82  ,83  ,84  ,85  ,86  ,87  ,88   ,89  ,90  }};

int get_keyboard(void)
{
    return inb(0x60);
}
char readchar()
{   int i = 0;
    int result=0;
    for(i=0;;i++)
    {
        if(keymap[i][1]==get_keyboard())
        {
            result=keymap[i][2];
        }
        if (result!=0)
        {
            break;
        }
    }
    return result;
}

