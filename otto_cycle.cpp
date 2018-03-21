// =================================================================================
// Assignment: Otto Cycle Simultaion
// =================================================================================
// Programmer: Cameron Perry
// Instructor: Dr. Bhattacharya
// Class: PHY-4C
// =================================================================================
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    float vol_a, vol_b, vol_c, vol_d;
    float press_a, press_b, press_c, press_d;
    float temp_a, temp_b, temp_c, temp_d;
    float work_ab, work_cd, total_work;
    float heat_yield, heat_input, heat_output;
    float gamma, burn_eff, eff, eff_temp;
    float litr_cycle, moles, capacity;

    heat_yield = 2.88e+7;
    litr_cycle = 0.01;
    burn_eff = 0.3;
    capacity = 20.785;
    moles = 0.025;
    gamma = 1.4;
    vol_a = 0.5;
    vol_b = 0.01;
    press_a = 1.0; 
    temp_a = 300;


    vol_c = vol_b;
    vol_d = vol_a;

    press_b = press_a*pow((vol_a/vol_b), gamma);
    press_c = (press_b*temp_c)/temp_b;
    press_d = press_c*pow((vol_c/vol_d), gamma);
    
    temp_b = temp_a*pow((vol_a/vol_b),( gamma-1));
    temp_c = temp_b + (heat_yield*litr_cycle*burn_eff/(moles*capacity));
    temp_d = temp_c*pow((vol_c/vol_d),( gamma-1));

    work_cd = (1/(gamma-1))*(press_c*vol_c - press_d*vol_d)*1.01e5*.001;
    work_ab = (1/(gamma-1))*(press_a*vol_a - press_b*vol_b)*1.01e5*.001;
    total_work = work_ab + work_cd;
    
    heat_input = litr_cycle*heat_yield*burn_eff;
    heat_output = moles*capacity*(temp_d - temp_a);
    
    eff = (work_cd + work_ab)/(heat_input);
    eff_temp = (heat_input - heat_output)/heat_input;

    cout << endl << " press_b = " << press_b << " temp_b = " << temp_b << endl
    	 << " press_c = " << press_c << " temp_c = " << temp_c << endl
    	 << " press_d = " << press_d << " temp_d = " << temp_d << endl
    	 << " work_cd = " << work_cd << " work_ab = " << work_ab << endl
         << " heat_input = " << heat_input << " heat_output = " << heat_output
		 << " total_work = " << total_work << endl
    	 << " eff = " << eff << " eff_temp = " << eff_temp << endl << endl;
    return 0;
}
/* ==== OUTPUT =====================================================================

press_b = 239.088 temp_b = 1434.53
press_c = 119.5 temp_c = 167708
press_d = 0.499816 temp_d = 35072.5
work_cd = 238.636 work_ab = -477.447
heat_input = 86400 heat_output = 18068.7 total_work = -238.812
eff = -0.00276402 eff_temp = 0.790872

================================================================================= */
