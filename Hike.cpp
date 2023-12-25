/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(std::ostream& out, const Hike& myHike)
{
    string printedDifficulty;
    if (myHike.hikeDifficulty == 'e')
        printedDifficulty = "easy";
    else if (myHike.hikeDifficulty == 'm')
        printedDifficulty = "moderate";
    else if (myHike.hikeDifficulty == 's')
        printedDifficulty = "strenuous";
    out << '\t' << myHike.hikeName <<
        " (" << myHike.hikeLocation << ")" << endl;
    out << "\t  Difficulty: " << printedDifficulty << endl;
    out << "\t  Duration: " << myHike.hikeDurationDays << " day(s)"
        << endl;

    return out;
}

Hike::Hike(const string& myLocation, const string& myHikeName,
    int myHikeDurationDays, char myHikeDifficulty)
{
    hikeLocation = myLocation;
    hikeName = myHikeName;
    hikeDurationDays = myHikeDurationDays;
    hikeDifficulty = myHikeDifficulty;
}

string Hike::getLocation() const
{
    return hikeLocation;
}

string Hike::getName() const
{
    return hikeName;
}

int Hike::getDuration() const
{
    return hikeDurationDays;
}

char Hike::getDifficulty() const
{
    return hikeDifficulty;
}

bool Hike::operator<(const Hike& hikeObjToCompare) const
{
    return (this->hikeLocation < hikeObjToCompare.hikeLocation);
}