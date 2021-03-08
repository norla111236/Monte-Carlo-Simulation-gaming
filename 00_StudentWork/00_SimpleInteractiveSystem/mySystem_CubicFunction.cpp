//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2018/02/27
//
#include "mySystem_CubicFunction.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

CUBIC_FUNCTION::CUBIC_FUNCTION( )
{
	x0 = -20.0;
	x1 = 20.0;
	mNumSamples = 100;
    
	a = b = c = d = 0.5;
    a = 0.03;
    b = 0.3;
}

void CUBIC_FUNCTION::askForInput( )
{
	//
	//ax^3 + bx^2 + cx + d
	//Show the system name
	cout << "CUBIC_FUNCTION" << endl;

	//Ask to input a, b, c, d
	cout << "please input a,b,c,d" << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	//Ask to input the range of x in [-20, 20]
	cout << "input the range of x in [-20, 20](from small to big) " << endl;
	cin >> x0;
	cin >> x1;
	if(x0 < -20 || x1 > 20){
		cout<<"over limit"<<endl;
	cin >> x0;
	cin >> x1;
	}

	//Ask to input the number of sample points
	cout << "input the number of sample points" << endl;
	cin >> mNumSamples;
	if(mNumSamples<2 || mNumSamples>100){
		cout<<"over limit"<<endl;
	cin >> mNumSamples;
	}

	//
	//cout << "CUBIC_FUNCTION" << endl;
	
}

void CUBIC_FUNCTION::getRangeOfX( double &x0, double &x1 ) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
    //x0 = 0;
    //x1 = 0;

}

int CUBIC_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	return mNumSamples;
}

double CUBIC_FUNCTION::getValue( double x ) const
{
	//Compute ax^3 + bx^2 + cx + d
	//i.e., compute the value a*x*x*x + b*x*x + c*x + d
	//return a*x*x*x + b*x*x + c*x + d;


	x=(a*x*x*x) + (b*x*x) + (c*x) + d;
	return (x,(a*x*x*x) + (b*x*x) + (c*x) + d);
}