/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "MemberList.h"
#include "HikeList.h"

#include <string>

const int RSVN_NUMBER = 50001;

class Node
{
public:
	Node() : rsvnNum(0), idNumber(0), prev(nullptr), next(nullptr) {}
	Node(int theRsvnNum, int theIdNumber, std::string theHikeName,
		Node* prevLink, Node* nextLink)
		: rsvnNum(theRsvnNum), idNumber(theIdNumber), hikeName(theHikeName)
		, prev(prevLink), next(nextLink) {}
	int getRsvnNum() const { return rsvnNum; }
	void setRsvnNum(int theRsvnNum) { rsvnNum = theRsvnNum; }
	int getIdNumber() const { return idNumber; }
	void setIdNumber(int theIdNumber) { idNumber = theIdNumber; }
	std::string getHikeName() const { return hikeName; }
	void setHikeName(std::string theHikeName) { hikeName = theHikeName; }
	Node* getPrev() const { return prev; }
	Node* getNext() const { return next; }
	void setPrev(Node* prevLink) { prev = prevLink; }
	void setNext(Node* nextLink) { next = nextLink; }
	~Node() {}
private:
	int rsvnNum, idNumber;
	std::string hikeName;
	Node* prev;
	Node* next;
};

class Reservations
{
public:
	Reservations() : first(nullptr), last(nullptr), count(0) {}

	int addReservation(int idNumber, const std::string& hikeName);
	void cancelReservation(int rsvnNumber);

	void printReservation(int rsvnNumber, const HikeList& myHikeList,
		const MemberList& myMemberList) const;
	void clearList();
	~Reservations();
private:
	Node* findReservation(int rsvnNumber) const;
	Node* first;
	Node* last;
	int count;
};
#endif
