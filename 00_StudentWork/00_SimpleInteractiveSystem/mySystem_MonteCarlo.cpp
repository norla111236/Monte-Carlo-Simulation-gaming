//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2018/02/27
//
#include "mySystem_MonteCarlo.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAX_NUM_SAMPLES 1000000
#define MIN_NUM_SAMPLES 2
#define DFT_NUM_SAMPLES 10000

MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM( )
{
	cout.precision(8);
    mRadius = 5.0f;
	mNumSamples = DFT_NUM_SAMPLES;
	reset();
}

void MONTE_CARLO_SYSTEM::reset()
{
    generateSamples( );
    computePI();

}

//increase the number of sample points
void MONTE_CARLO_SYSTEM::increase(int increasedAmount)
{
    mNumSamples += increasedAmount;
    if ( mNumSamples > MAX_NUM_SAMPLES)
     mNumSamples = MAX_NUM_SAMPLES;
    generateSamples( );
    computePI();
}

//decrease the number of sample points
void MONTE_CARLO_SYSTEM::decrease(int decreasedAmount)
{
		 mNumSamples -= decreasedAmount;
    if ( mNumSamples < MIN_NUM_SAMPLES)
        mNumSamples = MIN_NUM_SAMPLES;
   generateSamples( );
   computePI();
}

void MONTE_CARLO_SYSTEM::askForInput( )
{
	//
	//Show the system name
	cout << "This is a Monte Carlo Simulation." << endl;

	//Ask to input the radius of the circle
	cout << "Please input the radius of the circle:" << endl;
	cin >> mRadius;

	//Ask to input the number of sample points
	cout<<"input the number of sample points"<<endl;
	cin >> mNumSamples;
	if(mNumSamples<2 || mNumSamples>1000000){
		cout<<"over limit"<<endl;
		cin >> mNumSamples;
	}

	reset();
	//getSample(mNumSamples,0.0,0.0);

	//computeSamples( ) to compute the sample points and pi
	//

}

void MONTE_CARLO_SYSTEM::generateSamples( )
{
	//
		srand((unsigned)time(NULL));
	double low , up, rndf,x,y;
	low=-(mRadius);
	up=mRadius;
	//Compute the coordinates of the sample points.
	for(int i=0;i<mNumSamples;i++){
	 rndf = (double) rand() / (RAND_MAX + 1.0); // 
      x = (up - low) * rndf + low; 
		mX.push_back(x);
     rndf = (double) rand() / (RAND_MAX + 1.0); // ｲ｣･ﾍ [0, 1)
      y = (up - low) * rndf + low;  // 
		mY.push_back(y);
	}
	mX.clear( );
	mY.clear( );
	//There are mNumSamples samples.
	//Compute pi which is equal to:
	int point=0;
	for(int i=0;i<mNumSamples;i++){
	if(sqrt((mX[i]*mX[i])+(mY[i]*mY[i])) <= mRadius){
	     point++;
	  }
	}
	// 4*(number of samples inside the circle / total samples)
	float Pi;
	float Samples=(float)mNumSamples;
	cout<<4*point/Samples<<endl;
	//
    // Show the value of pi
    //
	mX.clear( );
	mY.clear( );
}

double MONTE_CARLO_SYSTEM::computePI() const
{
	int point=0;
	for(int i=0;i<mNumSamples;i++){
	if(sqrt((mX[i]*mX[i])+(mY[i]*mY[i])) <= mRadius){
	     point++;
	  }
	}
    float pi = 0.0;
	float Samples = (float)mNumSamples;
	float points = (float)point;
	pi = 4*points/mNumSamples;
	cout << 4*points/mNumSamples << endl;
    return pi;
}



double MONTE_CARLO_SYSTEM::getRadius( ) const
{
	//Return the radius of the circle
	return mRadius;
}

int MONTE_CARLO_SYSTEM::getNumSamples( ) const
{
	//Return the number of sample points

	return mNumSamples;

}

bool MONTE_CARLO_SYSTEM::getSample(int sampleIndex, float &x, float &y) const
{
	//
	//Return the sample coordinates in (x, y).
	//Return the boolean value indicating whether the sample lying inside the circle.
	//
	sampleIndex--;
	 bool flgInside = false;
		x=mX[sampleIndex];
		y=mY[sampleIndex];

	if(sqrt((mX[sampleIndex]*mX[sampleIndex])+(mY[sampleIndex]*mY[sampleIndex])) <= mRadius){
		 flgInside =true;
	}
	     return flgInside;
	

  


}
