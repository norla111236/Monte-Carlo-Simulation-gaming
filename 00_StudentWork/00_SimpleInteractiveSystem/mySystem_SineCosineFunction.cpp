//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2018/02/21
//
#include "mySystem_SineCosineFunction.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

namespace {
#define MIN_NUM_SAMPLES 100
};

SINECOSINE_FUNCTION::SINECOSINE_FUNCTION( )
{
	x0 = -20.0;
	x1 = 20.0;
	mNumSamples = MIN_NUM_SAMPLES;
	a = b = 1;
}

void SINECOSINE_FUNCTION::increaseA(double increasedAmount)
{
	increasedAmount=0.03125;
    a += increasedAmount;

}

    void SINECOSINE_FUNCTION::decreaseA(double decreasedAmount)
{
	decreasedAmount=0.03125;
    a -= decreasedAmount;
}

    void SINECOSINE_FUNCTION::increaseB(double increasedAmount)
{
	increasedAmount=0.03125;
    b += increasedAmount;
}

void SINECOSINE_FUNCTION::decreaseB(double decreasedAmount)
{
	decreasedAmount=0.03125;
    b -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseSampleNum(int increasedAmount )
{
	increasedAmount=100;
    mNumSamples += increasedAmount;

}

    void SINECOSINE_FUNCTION::decreaseSampleNum(int decreasedAmount)
    {
		decreasedAmount=100;
		mNumSamples -= decreasedAmount;
    if (mNumSamples < MIN_NUM_SAMPLES) {
		mNumSamples = MIN_NUM_SAMPLES;
	}

    }


void SINECOSINE_FUNCTION::reset()
{
    a = b = 1;
}

void SINECOSINE_FUNCTION::askForInput( )
{
	//Show the system name
	//Ask to input a, b
	cout << "SINECOSINE_FUNCTION" << endl;
	cout << "Input the coeffients, a and b: a sin(b*x)" << endl;
	cin >> a;
	cin >> b;

	//Ask to input the range of x in [-20, 20]
	cout << "input the range of x in [-20, 20](from small to big) " << endl;
	cin >> x0;
	cin >> x1;

	//Ask to input the number of sample points
	cout << "input the number of sample points" << endl;
	cin >> mNumSamples;
	if(mNumSamples<2 || mNumSamples>100){
		cout<<"over limit"<<endl;
	cin >> mNumSamples;
	}

	//
	//cout << "SINECOSINE_FUNCTION" << endl;
	//cout << "Input the coeffients, a and b: a sin(b*x)" << endl;
}

   //by-reference
   //(x0, x1) formal parameters
void SINECOSINE_FUNCTION::getRangeOfX( double &x0, double &x1 ) const
{
	//Return the range of x in x0 and x1.
	//x0 = this->x0;;

	x0 = this->x0;
	//x1 = this->x1;
	x1 = this->x1;
	//cout<<x0<<endl;
	//cout<<x1<<endl;
}

int SINECOSINE_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	//return mNumSamples;
    return mNumSamples;
}

double SINECOSINE_FUNCTION::getValue( double x ) const
{
	// a sin(b*x)
	//double low  , up , rndf, result;
	//low=x0;
	//up=x1;
	//srand((unsigned)time(NULL));
   // rndf = (double) rand() / (RAND_MAX + 1.0); // 產生 [0, 1) 浮點亂數
   // x = (up - low) * rndf + low;  // 產生 [low, up) 浮點亂數
	//x=a*sin(b*x);

	//cout<<x<<endl;//test

	return (1-x,(a*sin(b*x)));
}