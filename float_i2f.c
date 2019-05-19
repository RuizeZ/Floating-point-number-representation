#include "float_i2f.h"
float_bits float_i2f(int i) {
        int sign = i>>31&1;
        int exp;
        int fraction;
        if(i==0)
                return i;
        else if(i==0x80000000)
                exp = 158;
        else{
                if (sign == 1)
                        i = -i;
                int x = 31;
                while((i>>x)==0)
                        x--;
                exp = x+127;
                i = i<<(31-x);
                int comparefraction = 0x7fffff;
                fraction =(i>>8)&comparefraction;
                int y = i&0xff;
                if (y>128 || ((y==128)&&(fraction&1)))
                        fraction++;
                if(fraction>>23){
                        fraction = fraction&comparefraction;
                        exp+=1;
                }
        }
        return (sign<<31)|(exp<<23)| fraction;
}