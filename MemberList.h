/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <set>

const int ID_NUMBER = 111; //global constant

class MemberList
{
public:
	MemberList() : pointerToSet(new std::set<Member>) {}

	void addMember(const std::string& firstName, 
										const std::string& lastName);
	void addMember(const std::string& firstName, 
							const std::string& lastName, int addPoints);

	int getLastID() const;
	int getPoints(int searchID) const;

	void printMember(int searchID, const std::string& lastName) const;

	void clearList();
	~MemberList();
private:
	 std::set<Member> * pointerToSet;	 
};
#endif



