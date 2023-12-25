/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservationList(ifstream& infile, Reservations& reservationList)
{
	string hikeName;
	int idNumber = 0;
	
	while (!infile.eof())
	{
		infile >> idNumber >> hikeName;
		reservationList.addReservation(idNumber, hikeName);
	}
}

void getReservationData(Reservations& reservationList)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservationList(infile,reservationList);

	infile.close();
}

