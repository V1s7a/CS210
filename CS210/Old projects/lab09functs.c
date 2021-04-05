

// *** function header example *** //
/**   ----------------------------------------------------------
* <high level description of purpose of the function
* including what the parameters are used for>
* @param <explanation of each of the function parameters>
* @return <explanation of what the function returns>
*/ 
//#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
//#include "lab09functs.h"

double volumeCylinder(double radius, double height){
    double volume = M_PI * pow(radius, 2) * height;
    return volume;
} 

double volumeBox(double depth, double width, double height){
    double volume = depth * width * height;
    return volume;
}

double degToRad(int x){
    double rad = x /( M_PI * 180.0);
    return rad;
}