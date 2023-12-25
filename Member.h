/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
public:
	Member() : idNumber(0), points(0) {}
	Member(const std::string& newFirstName, 
									const std::string& newLastName) :
		idNumber(0), points(0), firstName(newFirstName),
									lastName(newLastName) {}

	void addPoints(int pointsToAdd); //does not reset value of points, ca
	void setID(int newID); //overwritesv the ID of calling object with ID 

	int getID() const;
	std::string getLastName() const;
	int getPoints() const;

	friend bool operator<(const Member& firstObj,
											const  Member& secondObj);

	void printMember() const;

	~Member() {};

 private:
	 int idNumber, points;
	 std::string firstName, lastName;
};
#endif
