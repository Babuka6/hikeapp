/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "MemberList.h"

#include <algorithm>

#include <iostream>

using namespace std;

void MemberList::addMember(const string& firstName, 
												const string& lastName)
{
	Member temp(firstName, lastName);                                       
	if (static_cast<int>(pointerToSet->size()) == 0) //ask Professor about implement
	{
		temp.setID(ID_NUMBER);
	}
	else
	{
		temp.setID(ID_NUMBER + static_cast<int>(pointerToSet->size()));
	}
	pointerToSet->insert(temp);	
}

void MemberList::addMember(const std::string & firstName,
						  const std::string & lastName, int pointsToAdd)
{
	Member temp(firstName, lastName);
	temp.addPoints(pointsToAdd);
	if (static_cast<int>(pointerToSet->size()) == 0) //if set is emmpty 
	{
		temp.setID(ID_NUMBER);
	}
	else
	{
		temp.setID(ID_NUMBER + static_cast<int>(pointerToSet->size()));
	}
	pointerToSet->insert(temp); //ITEM 113 ERROR

}

int MemberList::getLastID() const
{
	//auto current = pointerToSet->rbegin();
	//return current->getID(); //ITEM 114 ERROR
	return pointerToSet->rbegin()->getID();
}

int MemberList::getPoints(int searchID) const
{   
	auto iter = find_if(pointerToSet->begin(), pointerToSet->end(),
		[&](const Member& memberInList) 
						{return searchID == memberInList.getID();} );
	return iter->getPoints();
}

void MemberList::printMember(int searchID,
									const std::string& lastName) const
{
	auto iter = find_if(pointerToSet->begin(), pointerToSet->end(),
		[&](const Member& memberInList) //item 115 2)variable name???
		{ return searchID == memberInList.getID(); });
	if (lastName == iter->getLastName())
		iter->Member::printMember();
	cout << "\tMembership # " << iter->getID() << endl;
}

void MemberList::clearList()
{
	pointerToSet->clear();
}

MemberList::~MemberList()
{
    delete pointerToSet;
    pointerToSet = nullptr;
}

