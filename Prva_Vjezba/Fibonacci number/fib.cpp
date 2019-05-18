#define SC_INCLUDE_FX
#include <iostream>
#include <systemc>
#include <vector>
 
typedef sc_dt::sc_int<50> num;
typedef std::vector<num> array;
typedef sc_dt::sc_ufix_fast fixx;
 
num fib(num &fib_num)
{
    array a;
    a.push_back(0);
    a.push_back(1);
   
    int i;
 
    for(i = 2; i <= fib_num; ++i)
    {
        a.push_back(a[i-1] + a[i-2]);
    }
   
    return a[i-1];
}
int no_bits(const num &fib_num)
{
    int bit = 1;
 
    while(1)
    {
   
    fixx fix_point(bit, bit);
   
    fix_point = fib_num;   
 
    if(!fix_point.overflow_flag())
        break; 
 
    ++bit;
   
    }
 
   
    return bit;
}
 
 
int sc_main(int argc, char* arvg[])
{
    num fib_num = 63;
   
    fib_num = fib(fib_num);
 
    std::cout << fib_num << std::endl;
 
    int number_of_bits;
 
    number_of_bits = no_bits(fib_num);
 
    std::cout << "No bits :" << number_of_bits << std::endl;
 
    return 0;
}
