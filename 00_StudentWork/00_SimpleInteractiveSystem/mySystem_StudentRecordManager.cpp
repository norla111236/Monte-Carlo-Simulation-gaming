//
// Instructor: Sai-Keung WONG
// Email:	cswingo@cs.nctu.edu.tw
//			wingo.wong@gmail.com
//
// National Chiao Tung University, Taiwan
// Computer Science
// Date: 2018/02/27
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	//Show the scores in an ascending order
	//
	//Show the system title
	cout << "STUDENT_RECORD_MANAGER" << endl;

	//Ask to input the number of students
	cout << "input the number of students" << endl;
	cin >> mNumStudents;

	//Ask to input the score of each student
	cout << "input the score of each student" << endl;
	int test;
	for(int i=0;i<mNumStudents;i++){
		cin>>test;
		mScore.push_back(test);
	}

	//Show the average
	computeAverage( );
	cout << "Average:" << mAverageScore << endl;

	//Show the standard deviation
	computeStandardDeviation( );
    cout << "Standard Deviation:" << mStandardDeviation << endl;

	sortScores( );
	//sortScores( );
	//for(int i=0;i<mNumStudents;i++){
	//cout << mScore[i] << endl;
	//}

	showSortedScores( );
	//showSortedScores( );

}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
	int totalScore=0;
	for(int i=0;i<mNumStudents;i++){
	totalScore += mScore[i];
	}
	mAverageScore = totalScore/mNumStudents;
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation
	int totalScore=0,totalScore2=0;
	for(int i=0;i<mNumStudents;i++){
	totalScore += mScore[i];
	}
	for(int i=0;i<mNumStudents;i++){
	totalScore2 += mScore[i]*mScore[i];
	}
	double sum;
	sum = totalScore2-(totalScore*totalScore/mNumStudents);
	mStandardDeviation = sqrt( sum / mNumStudents );
	//mStandardDeviation = sqrt( sum / mNumStudents );
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	//Sorting in an ascending order
///	for(int i=0;i<mNumStudents;i++){
///	mSortedScore[i] = mScore[i];
///	}


	int buffer=0;
	int test = mNumStudents-1;
	for(int i=0;i<test;i++){
	 for(int j=i;j<mNumStudents;j++){
		if(mScore[i]>mScore[j]){
		buffer = mScore[i];
		mScore[i] = mScore[j];
		mScore[j] = buffer;
		}
	  }
	}

}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order
	cout<<"sorted score"<<endl;
	for(int i=0;i<mNumStudents;i++){
	cout << mScore[i] << endl;
	}
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	// 
	int num = 0;

	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	for(int i=0;i<mNumStudents;i++){
		if(mScore[i] >= s0 && mScore[i] <= s1){
		num++;
		}
		else{
		num = num+0;
		}
	}

	return num;
}
