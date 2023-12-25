/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Member.h"

#include <iostream>

using namespace std;

void Member::addPoints(int pointsToAdd)
{
	points += pointsToAdd;
}

void Member::setID(int newID)
{
	idNumber = newID;
}

int Member::getID() const
{
	return idNumber;
}

string Member::getLastName() const
{
	return lastName;
}

int Member::getPoints() const
{
	return points;
}

bool operator<(const Member& firstObj, const Member& secondObj)
{
	return (firstObj.getID() < secondObj.getID());
}

void Member::printMember() const
{
	cout << "\t" << lastName << ", " << firstName << "\n"
		<< "\tPoints available: " << points << endl;

}