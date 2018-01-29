#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;



/*********** main  ***********
Purpose: Take argc and argv as defult arguments, and read *.in file, to 
	implement an election that uses cumulative voting.
************************************/



int main  ( int argc, char *argv[]) {
	
	const int MAXCAN = 10;
	int Number_of_voters = 0;
	int Number_of_valid_ballots = 0;
	int Number_of_spoilt_ballots = 0; 
	int Number_of_candidates = 0;
	int Number_of_votes = 0;


	for ( int i = 1; i < argc; i++ ) {
		string args = argv[i];
		
		istringstream ss(args);
	        int value;
	        ss >> value;  
		Number_of_votes = value;
	} // for 

	string ballot;

	string name;
	int voteLine;

	string candidatesArr[MAXCAN];
	int voteArr[MAXCAN - 1] = {0};
	

	while ( getline(cin, ballot)) {

		stringstream ss(ballot);
                
                if ( ss >> voteLine || Number_of_voters!= 0 ) {
		

			Number_of_voters++;

			int  voteNum;
			stringstream s1(ballot);

			int voteTime = 0;
			int voteTotall = 0;
			

			if (Number_of_votes == 0)  Number_of_votes = Number_of_candidates;
			
			
			while ( s1 >> voteNum ) {

				voteTime++;
				voteTotall += voteNum;	
			} //while


			if ( voteTime != Number_of_candidates ) {
				Number_of_spoilt_ballots++;
			} // if 


			else if ( voteTotall > Number_of_votes) {
				Number_of_spoilt_ballots++;
                        } // else if
				
				
			else {
				Number_of_valid_ballots++;

				stringstream s2(ballot);
				int voteNum2;
				int i = 0;
				while ( s2 >> voteNum2) { 
                                	voteArr[i] += voteNum2;
					i++;
				} //while
			} // else


		} // if

		else {

			Number_of_candidates++;
				

			if (Number_of_candidates  == MAXCAN + 1)  {
                                return 1;
                        }

			candidatesArr[Number_of_candidates - 1] = ballot;
			

		} // else 

	} //while
	
	cout << "Number of voters: " << Number_of_voters << endl;
	cout << "Number of valid ballots: " << Number_of_valid_ballots << endl;
	cout << "Number of spoilt ballots: " << Number_of_spoilt_ballots << endl;
   	cout << endl;
   	cout << "Candidate      Score" << endl;
   	cout << endl;
	
	for (int i =0; i< Number_of_candidates; i++) {
        	cout << setw(15) << left << candidatesArr[i]
             	     << setw(3) << right << voteArr[i] << endl;    
    } //for



} //main
