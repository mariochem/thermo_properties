# thermo_properties

This repository contains programs written in C++ to assist people working in projects involving calculations of steam thermodynamics properties for chemical processes and energy production.

The agua.cpp program calculates the properties of saturated water vapor given the temperature. The properties that are calculated in the present version are as follows:<P>

  1 - Steam Pressure in kpa at a given temperature in celsius.<p>
  2 - Specific volume of the saturated liquid in m3 / kg at a given temperature in celsius.<p>
  3 - Specific volume of saturated steam in m3 / kg at a given temperature in celsius.<p>
  4 - Enthalpy of the saturated liquid in kJ / kg at a given temperature in celsius.<p>
  5 - Enthalpy of saturated steam in kJ / kg at a given temperature in celsius.<p>
  6 - Entropy of the saturated liquid in kJ / kg * K at a given temperature in celsius.<p>
  7 - Entropy of saturated steam in kJ / kg * K at a given temperature in celsius.<p>
  8 - Enthalpy of evaporation of liquid water in kJ / kg at a given temperature in celsius.<p>
  9 - Entropy of evaporation of liquid water in kJ / kg * K at a given temperature in celsius.<p>
10 - Internal energy of water vapor in kJ / kg at a given temperature in celsius.<p>
11 - Internal energy liquid water in kJ / kg at a given temperature in celsius.<p>
12 - Internal energy of water evaporation in kJ / kg at a given temperature in celsius.<p>

To perform the calculation of properties in the saturation state that are within the temperature range between **0** to **374.14 ºC**, use the following procedures:<p>

1 - instantiate an object to have access to all the calculation functions present for water, in this case the water object was instantiated.<p>

2 - From there you can use the following direct functions:<p>
  
      a - water.pvt (xd, yd) this function calculates the vapor pressure at a given temperature in celcius that must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the steam pressure in **kpa**.

      b - water.vlt (xd, yd) this function calculates the specific volume of liquid water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within or out of the range for the interval of saturation. The variable yd informs the value obtained for the specific volume in **m3/kg**. 

      c - water.vvt (xd, yd) this function calculates the specific volume of water vapor in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd informs the value obtained for the specific volume in **m3/kg**.

      d - water.hlt (xd, yd) This function calculates the enthalpy of liquid water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd informs the value obtained for the enthalpy of liquid water in **kJ/kg**.

      e - water.hvt (xd, yd) this function calculates the enthalpy of water vapor in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the enthalpy of water vapor in **kJ/kg**.

      f - water.slt (xd, yd) This function calculates the entropy of liquid water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the entropy of liquid water in **kJ/kg*K**.

      g - water.svt (xd, yd) this function calculates the entropy of the water vapor in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd informs the value obtained for the entropy of water vapor in **kJ/kg*K**.

3 - The derived functions present in this work are as follows:

      a - water.hevapt (xd, yd) this function calculates the enthalpy of water evaporation in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd informs the value obtained for the enthalpy of water evaporation in **kJ/kg**.

      b - water.sevapt (xd, yd) this function calculates the entropy in the evaporation of water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the entropy in water evaporation in **kJ/kg*K**.

      c - water.uvt (xd, yd) This function calculates the free energy of water vapor in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the internal energy of water vapor in **kJ/kg**.

      d - water.ult (xd, yd) This function calculates the free energy of liquid water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd informs the value obtained for the internal energy of liquid water in **kJ/kg*K**.

      e - water.uevapt (xd, yd) this function calculates the free energy in the evaporation of water in the saturation condition. The temperature in celsius must be entered in xd.
The function returns an integer 0 or 1 to inform whether the temperature is within the range of the table. The variable yd reports the value obtained for the internal energy in water evaporation in **kJ/kg**.
