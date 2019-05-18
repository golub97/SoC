#define SC_INCLUDE_FX
#include <iostream>
#include <iostream>
#include <cmath>
#include <vector>
#include <systemc>
 
typedef std::vector<double> array;
typedef sc_dt::sc_fix_fast fixx;
 
double fact(double num)
{
    double temp = 1;
 
    for(int i = 1; i <= num; ++i)
        temp *= i;
     
    return temp;
}
void no_of_members(const array &true_values,const array &arguments, array &res_tay_series, int &no_members)
{
    int i, j, counter;
   
    do
    {
        counter = 0;
 
        for(i = 0; i < 5; ++i)
            res_tay_series[i] = 0;
 
   
        for(i = 0; i <= no_members; ++i)
            for(j = 0; j < 5; ++j)
                res_tay_series[j] += (pow(-1, i)*pow(arguments[j], 2*i + 1))/(fact(2*i + 1));
   
        for(j = 0; j < 5; ++j) 
            if(std::abs(res_tay_series[j] - true_values[j]) < 1e-5)
            {
                ++counter;
            }
       
        ++no_members;  
    } while(counter != 5);
}
 
int no_bits_fixed_point(const array &true_values, int &no_bits_W, const int &no_bits_I)
{
	int i;
	int no_bit[5];

	for(i = 0; i < 5; ++i)
	{
		no_bits_W = 2;
		while(1)
		{
			fixx fix_point(no_bits_W, no_bits_I);

			fix_point = true_values[i];
			
			if(std::abs(fix_point - true_values[i]) < 1e-5)
			{
				no_bit[i] = no_bits_W;
				break;
			}
			++no_bits_W;
		}
	}
	
	int max = no_bit[0];

	for(i = 1; i < 5; ++i)
	{
		if(no_bit[i] > max)
		{
			max = no_bit[i];
		}
	}		
			
	 return max;
   
}
 
int sc_main(int argc, char* arvg[])
{
    array true_values = {sin(M_PI/6), sin(M_PI/4), sin(M_PI/3), sin(M_PI/2), sin(M_PI)};
        array arguments = {M_PI/6, M_PI/4, M_PI/3, M_PI/2, M_PI};  
    array res_tay_series = {0, 0, 0, 0, 0};
 
    int no_members = 0;
 
    int no_bits_W = 2; //no bits
    int no_bits_I = 2; //position of point
 
    no_of_members(true_values, arguments, res_tay_series, no_members);
 
    int no_bitt = no_bits_fixed_point(true_values, no_bits_W, no_bits_I); 
 
    std::cout<<"No members: "<< no_members<<std::endl;
    std::cout<<"No bits: "<< no_bitt<<std::endl;
    std::cout<<"No bits before point: "<< no_bits_I<<std::endl;
    std::cout<<"No bits after point: "<< no_bitt - no_bits_I <<std::endl;
   
    return 0;
 
}
