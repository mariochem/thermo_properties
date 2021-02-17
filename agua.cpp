#include <iostream> // to use cin e cout
#include<cmath>
#include<iomanip> // to define the accuracy

using namespace std;

class functions
{
    public:
        // calculation of steam pressure at a given temperature
        int P_Vapor (double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of the specific volume of the saturated liquid at a given temperature
        int V_liq( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of the specific volume of saturated steam at a given temperature
        int V_vap( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of the enthalpy of the saturated liquid at a given temperature
        int H_Liq( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of enthalpy of saturated steam at a given temperature
        int H_Vap( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of the entropy of the saturated liquid at a given temperature
        int S_Liq( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of the entropy of saturated steam at a given temperature
        int S_Vap( double  xd, double &yd, double x[], double y[], int n); 
        
        // calculation of enthalpy of evaporation of liquid water at a given temperature
        int H_Evap( double  xd, double &yd, double x[], double y[], double z[], int n); 
        
        // calculation of the entropy of evaporation of liquid water at a given temperature
        int S_Evap( double  xd, double &yd, double x[], double y[], double z[], int n); 
        
        // calculation of the internal energy of water vapor at a given temperature
        int U_Vap( double  xd, double &yd, double x[], double y[], double z[], double w[], int n); 
        
        // calculation of internal energy liquid water at a given temperature
        int U_Liq( double  xd, double &yd, double x[], double y[], double z[], double w[], int n); 

        // calculation of the internal energy of water evaporation at a given temperature
        int U_Evap( double  xd, double &yd, double x[], double y[], double z[], double w[], double t[], double r[], int n); 
        
        // calculating a linear interpolation
        int X_Y( double  xd, double &yd, double x[], double y[], int n);

};

    int functions::P_Vapor (double  xd, double &yd, double x[], double y[], int n)
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::V_liq( double  xd, double &yd, double x[], double y[], int n) 
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::V_vap( double  xd, double &yd, double x[], double y[], int n) 
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::H_Liq( double  xd, double &yd, double x[], double y[], int n) 
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::H_Vap( double  xd, double &yd, double x[], double y[], int n) 
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::S_Liq( double  xd, double &yd, double x[], double y[], int n) 
        {
            return X_Y( xd , yd, x, y, n);
        }

    int functions::S_Vap( double  xd, double &yd, double x[], double y[], int n) 
    {
        return X_Y( xd , yd, x, y, n);
    }

    int functions::H_Evap( double  xd, double &yd, double x[], double y[], double z[], int n) 
    {
        int ret;
        double temp;
        ret = H_Vap( xd , yd, x, y, n);
        temp = yd; 
        H_Liq( xd , yd, x, z, n);
        yd = temp - yd;
        return ret;
    }

    int functions::S_Evap( double  xd, double &yd, double x[], double y[], double z[], int n) 
    {
        int ret;
        double temp;
        ret = S_Vap( xd , yd, x, y, n);
        temp = yd; 
        S_Liq( xd , yd, x, z, n);
        yd = temp - yd;
        return ret;
    }

        int functions::U_Vap( double  xd, double &yd, double x[], double y[], double z[], double w[], int n) 
        {
            int ret;
            double temp1, temp2, temp3;
            ret = H_Vap( xd , yd, x, y, n);
            temp1 = yd; 
            V_vap( xd , yd, x, z, n);
            temp2= yd;
            P_Vapor( xd , yd, x, w, n);
            temp3 = yd;
            yd = temp1 - temp2 * temp3;
            return ret;
        }

        int functions::U_Liq( double  xd, double &yd, double x[], double y[], double z[], double w[], int n) 
        {
            int ret;
            double temp1, temp2, temp3;
            ret = H_Vap( xd , yd, x, y, n);
            temp1 = yd; 
            V_vap( xd , yd, x, z, n);
            temp2= yd;
            P_Vapor( xd , yd, x, w, n);
            temp3 = yd;
            yd = temp1 - temp2 * temp3;
            return ret;
        }

        int functions::U_Evap( double  xd, double &yd, double x[], double y[], double z[], double w[], double t[], double r[], int n) 
        {
            int ret;
            double temp;
            ret = U_Vap( xd , yd, x, y, z, r, n);
            temp = yd;
            U_Liq( xd , yd, x, w, t, r, n);
            yd= temp - yd;
            return ret;
        }
 
        // calculation of linear interpolation
        int functions::X_Y( double  xd, double &yd, double x[], double y[], int n)
        {
            int i=0;
            if ( (xd-x[i]) < 0.0 )
            {
                return 1;
            }
            else if ( (xd-x[i]) == 0.0 )
            {
                yd = y[0];
                return 0;
            }
            else if ( (xd - x[n-1]) == 0.0)
            {
                yd = y[n-1];
                return 0;
            }
    
            else if (  (xd - x[n-1]) > 0.0)
            {
                yd = y[n-1];
                return 1;
            }
            for (i=0; i < n; i++ )
            {
                if (xd==x[i])
                {
                    yd = y[i];
                    return 0;
                }
                else if (xd < x[i])
                {
                    yd = y[i-1] + ( (xd - x[i-1]) * (y[i]-y[i-1]) / (x[i] - x[i-1]) );
                    return 0;
                }
                else
                {
                    continue;
                }
            }
            return 0;    
        }


class saturated: public functions
{
    private:
        
        //
        // Table of saturated water vapor temperatures in celsius
        //
        double temp[71] = { 0.01,5.,10.,15.,20.,25.,30.,35.,40.,45.,50.,55.,60.,65.,70.,75.,
        80.,85.,90.,95.,100.,105.,110.,115.,120.,125.,130.,135.,140.,145.,150.,155.,160.,
        165.,170.,175.,180.,185.,190.,195.,200.,205.,210.,215.,220.,225.,230.,235.,240.,245.,
        250.,255.,260.,265.,270.,275.,280.,285.,290.,295.,300.,305.,310.,315.,320.,330.,
        340.,350.,360.,370.,374.14};

        //
        // Water saturated steam pressure table, pressures in kpa
        //
        double pvap[71] = { 0.6113, 0.8721, 1.2276, 1.7051, 2.339, 3.169, 4.246, 5.628,
        7.384, 9.593, 12.349, 15.758, 19.940, 25.03, 31.19, 38.58, 47.39, 57.83, 70.14, 84.55, 
        101.35, 120.82, 143.27, 169.06, 198.53, 232.1, 270.1, 313.0, 361.3, 415.4,
        475.8, 543.1, 617.8, 700.5, 791.7, 892.0, 1002.1, 1122.7, 1254.4, 1397.8, 1553.8,
        1723.0, 1906.2, 2104.0, 2318.0, 2548.0, 2795.0, 3060.0, 3344.0, 3648.0, 3973.0,
        4319., 4688., 5081., 5499., 5942., 6412., 6909., 7436., 7993., 8581., 9202.,
        9856., 10547., 11274., 12845., 14586., 16513., 18651., 21030., 22090. };

        //
        // Saturated water vapor table, specific volume of liquid water in m3 / kg
        //
        double vliq[71] = { 0.00100001, 0.00100004, 0.00100006, 0.001001, 0.001002, 0.001003,
        0.001004, 0.001006, 0.001008, 0.001010, 0.001012, 0.001015, 0.001017, 0.001020, 
        0.001023, 0.001026, 0.001029, 0.001033, 0.001036, 0.001040, 0.001044, 0.001048, 
        0.001052, 0.001056, 0.001060, 0.001065, 0.001070, 0.001075, 0.001080, 0.001085,
        0.001091, 0.001096, 0.001102, 0.001108, 0.001114, 0.001121, 0.001127, 0.001134,
        0.001141, 0.001149, 0.001157, 0.001164, 0.001173, 0.001181, 0.001190,
        0.001199, 0.001209, 0.001219, 0.001229, 0.001240, 0.001251, 0.001263, 0.001276,
        0.001289, 0.001302, 0.001317, 0.001332, 0.001348, 0.001366, 0.001384, 0.001404,
        0.001425, 0.001447, 0.001472, 0.001499, 0.001561, 0.001638, 0.001740, 0.001893,
        0.002213, 0.003155 };

        //
        // Saturated water vapor table, specific volume of water vapor in m3 / kg
        //
        double vvap[71] = { 206.14, 147.12, 106.38, 77.93, 57.79, 43.36, 32.89, 25.22,
        19.52, 15.26, 12.03, 9.568, 7.671, 6.197, 5.042, 4.131, 3.407, 2.828, 2.361,
        1.982, 1.6729, 1.4194, 1.2102, 1.0366, 0.8919, 0.7706, 0.6685, 0.5822, 0.5089,
        0.4463, 0.3928, 0.3468, 0.3071, 0.2727, 0.2428, 0.2168, 0.19405, 0.17409,
        0.15654, 0.14105, 0.12736, 0.11521, 0.10441, 0.09479, 0.08619, 0.07849,
        0.07158, 0.06537, 0.05976, 0.05471, 0.05013, 0.04598, 0.04221, 0.03877,
        0.03564, 0.03279, 0.03017, 0.02777, 0.02557, 0.02354, 0.02167, 0.019948,
        0.018350, 0.016867, 0.015488, 0.012996, 0.010797, 0.008813, 0.006945, 
        0.004925, 0.003155 };

        //
        // Saturated water vapor table, enthalpy of liquid water in kJ / kg
        //
        double hliq[71] = { 0.01, 20.98, 42.01, 62.99, 83.96, 104.89, 125.79, 146.68, 167.57, 
        188.45, 209.33, 230.23, 251.13, 272.06, 292.98, 313.93, 334.91, 355.90, 376.92, 397.96,
        419.04, 440.15, 461.30, 482.48, 503.71, 524.99, 546.31, 567.69, 589.13, 610.63, 632.20,
        653.84, 675.55, 697.34, 719.21, 741.17, 763.22, 785.37, 807.62, 829.98, 852.45, 875.04, 
        897.76, 920.62, 943.62, 966.78, 990.12, 1013.62, 1037.32, 1061.23, 1085.36, 1109.73,
        1134.37, 1159.28, 1184.51, 1210.07, 1235.99, 1262.31, 1289.07, 1316.3, 1344.0, 1372.4,
        1401.3, 1431.0, 1461.5, 1525.3, 1594.2, 1670.6, 1760.5, 1890.5, 2099.3   };

        //
        // Saturated water vapor table, enthalpy of water vapor in kJ / kg
        //
        double hvap[71] = { 2501.4, 2510.6, 2519.8, 2528.9, 2538.1, 2547.2, 2556.3, 2565.3, 2574.3,
        2583.2, 2592.1, 2600.9, 2609.6, 2618.3, 2626.8, 2635.3, 2643.7, 2651.9, 2660.1, 2668.1, 
        2676.1, 2683.8, 2691.5, 2699.0, 2706.3, 2713.5, 2720.5, 2727.3, 2733.9, 2740.3, 2746.5,
        2752.4, 2758.1, 2763.5, 2768.7, 2773.6, 2778.2, 2782.4, 2786.4, 2790.0, 2793.2, 2796.0, 
        2798.5, 2800.5, 2802.1, 2803.3, 2804.0, 2804.2, 2803.8, 2803.0, 2801.5, 2799.5, 2796.9, 
        2793.6, 2789.7, 2785.0, 2779.6, 2773.3, 2766.2, 2758.1, 2749.0, 2738.7, 2727.3, 2714.5,
        2700.1, 2665.9, 2622.0, 2563.9, 2481.0, 2332.1, 2099.3 };   
        
        //
        // Saturated water vapor table, entropy of liquid water in kJ / kg * K
        //
        double sliq[71] = { 0, 0.0761, 0.1510, 0.2245, 0.2966, 0.3674, 0.4369, 0.5053, 0.5725,
        0.6387, 0.7038, 0.7679, 0.8312, 0.8935, 0.9549, 1.0155, 1.0753, 1.1343, 1.1925, 1.2500,
        1.3069, 1.3630, 1.4185, 1.4734, 1.5276, 1.5813, 1.6344, 1.6870, 1.7391, 1.7907, 1.8418,
        1.8925, 1.9427, 1.9925, 2.0419, 2.0909, 2.1396, 2.1879, 2.2359, 2.2835, 2.3309, 2.3780,
        2.4248, 2.4714, 2.5178, 2.5639, 2.6099, 2.658, 2.7015, 2.7472, 2.7927, 2.8383, 2.8838,
        2.9294, 2.9751, 3.0208, 3.0668, 3.1130, 3.1594, 3.2062, 3.2534, 3.3010, 3.3493, 3.3982,
        3.4480, 3.5507, 3.6594, 3.7777, 3.9147, 4.1106, 4.4298   };  

        // 
        // Saturated water vapor table, entropy of water vapor in kJ / kg * K
        //
        double svap[71] = { 9.1562, 9.0257, 8.9008, 8.7814, 8.6672, 8.5580, 8.4533, 8.3531, 8.2570, 
        8.1648, 8.0763, 7.9913, 7.9096, 7.8310, 7.7553, 7.6824, 7.6122, 7.7545, 7.4791, 7.4159,
        7.3549, 7.2958, 7.2387, 7.1833, 7.1296, 7.0775, 7.0269, 6.9777, 6.9299, 6.8833, 6.8379, 
        6.7935, 6.7502, 6.7078, 6.6663, 6.6256, 6.5857, 6.5465, 6.5079, 6.4698, 6.4323, 6.3952, 
        6.3585, 6.3221, 6.2861, 6.2503, 6.2146, 6.1791, 6.1437, 6.1083, 6.0730, 6.0375, 6.0019,
        5.9662, 5.9301, 5.8938, 5.8571, 5.8199, 5.7821, 5.7437, 5.7045, 5.6643, 5.6230, 5.5804,
        5.5362, 5.4417, 5.3357, 5.2112, 5.0526, 4.7971, 4.4298  };

        //
        // Array size
        //
        int size = sizeof(temp);
        const int SIZE = size / sizeof(temp[0]);

    public:
        int pv(double xd, double & yd); // Functions Declaration
        
        int vl(double xd, double & yd);
        
        int vv(double xd, double & yd);
        
        int hl(double xd, double & yd);
        
        int hv(double xd, double & yd);
        
        int sl(double xd, double & yd);
        
        int sv(double xd, double & yd);
        
        int hevap(double xd, double & yd);
        
        int sevap(double xd, double & yd);
        
        int uv(double xd, double & yd);

        int ul(double xd, double & yd);
        
        int uevap(double xd, double & yd);
     
};

    int saturated::pv(double xd, double & yd)
        {
            return P_Vapor( xd , yd, temp, pvap, SIZE);
        }

    int saturated::vl(double xd, double & yd)
        {
            return V_liq( xd , yd, temp, vliq, SIZE);
        }

    int saturated::vv(double xd, double & yd)
    {
            return V_vap( xd , yd, temp, vvap, SIZE);
    }
    
    int saturated::hl(double xd, double & yd)
        {
            return H_Liq( xd , yd, temp, hliq, SIZE); 
        }
    
    int saturated::hv(double xd, double & yd)
        {
            return H_Vap( xd , yd, temp, hvap, SIZE); 
        }

    int saturated::sl(double xd, double & yd)
        {
            return S_Liq( xd , yd, temp, sliq, SIZE); 
        }

    int saturated::sv(double xd, double & yd)
        {
            return S_Vap( xd , yd, temp, svap, SIZE);
        }

    int saturated::hevap(double xd, double & yd)
        {
            return H_Evap( xd , yd, temp, hvap, hliq, SIZE);
        }

    int saturated::sevap(double xd, double & yd)
        {
            return S_Evap( xd , yd, temp, svap, sliq, SIZE);
        }

    int saturated::uv(double xd, double & yd)
        {
            return U_Vap( xd , yd, temp, hvap, vvap, pvap, SIZE);
        }

    int saturated::ul(double xd, double & yd)
        {
            return U_Liq( xd , yd, temp, hliq, vliq, pvap, SIZE);
        } 

    int saturated::uevap(double xd, double & yd)
        {
            return U_Evap( xd , yd, temp, hvap, vvap, hliq, vliq, pvap,SIZE);
        } 



void show ( double yd, int resp, string titulo);    
void showcab1 ();
void showcab2 ();


int main()
{
    cout.precision(6);        //set the precision
    cout.setf(ios::fixed);
    double xd, temp, yd = 0.0;
    int resp;
    
    saturated water;
    
    showcab1();
    for (xd = 5; xd<375; xd=xd+5)
    
    {
        // direct properties
        show(xd , 0, "");
        show(yd ,water.pv(xd,yd) ,"");
        show(yd ,water.vl(xd,yd) ,"");
        show(yd ,water.vv(xd,yd) ,"");
        show(yd ,water.hl(xd,yd) ,"");
        show(yd ,water.hv(xd,yd) ,"");
        show(yd ,water.sl(xd,yd) ,"");
        show(yd ,water.sv(xd,yd) ,"");
        cout<< endl;
    }
    cout<<endl;

    showcab2();
    for (xd = 5; xd<375; xd=xd+5)
    {
       // derived properties
       show(xd , 0, "");
       show(yd, water.hevap( xd , yd),"");
       show(yd, water.sevap( xd , yd),"");
       show(yd, water.uv( xd , yd),"");
       show(yd, water.ul( xd , yd),"");
       show(yd, water.uevap( xd , yd),"");
       // Evaporation entropy is a derived property given by Evap / T_Evap
       //water.H_Evap( xd , yd, water.temp, water.hvap, water.hliq, SIZE);
       //cout << yd/(xd+273.15);
       //
       cout<<endl;
    }
    cout<<endl;

return 0;
}

void show ( double yd, int resp, string title)
{
    if (resp ==0)
    {
        cout << title + " " <<setw(11)<< yd << " "; //set the width = 11
    }
    else
    {
        cout << "The unknown value is out the range."<<endl;
    }
            
}

void showcab2 ()
{
    cout << setw(8) << "Temp" << setw(14)<< "HEvap"<< setw(15)<<"SEvap"
    <<setw(9)<<"Uv"<<setw(14)<<"Ul" <<setw(13) <<"UEvap" ;
    cout<<endl; 
    cout << setw(8) << "\u2103" << setw(16)<< "kJ/kg"<< setw(14)<<"kJ/kg"<<"\u2103"
    <<setw(11)<<"kJ/kg"<<setw(14)<<"kJ/kg" <<setw(11) <<"kJ/kg" ;
    cout<<endl;           
}

void showcab1 ()
{
    cout << setw(8) << "Temp" << setw(15)<< "Pvap"<< setw(13)<<"Vliq"
    <<setw(12)<<"Vvap"<<setw(14)<<"Hliq" <<setw(11) << "Hvap" << setw(14)<< "Sliq"<<setw(13) <<"Svap"
    << endl;
    cout << setw(8) << "\u2103" << setw(16)<<"kpa"<<setw(15)<<"m3/kg"<<setw(12)<<"m3/kg"<<setw(14)<< 
    "kJ/kg"<< setw(14)<<setw(11)<<"kJ/kg"<<setw(14)<<"kJ/kg"<<"\u2103"<<setw(12) <<"kJ/kg"<<"\u2103" ;
    cout<<endl;       
}
