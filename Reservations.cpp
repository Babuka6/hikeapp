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

using namespace std;

int Reservations::addReservation(int idNumber, const string& hikeName)
{
	if (first == nullptr)
	{
		first = last = new Node(RSVN_NUMBER, idNumber, hikeName,
			nullptr, nullptr);
	}
	else
	{
		last->setNext(new Node(RSVN_NUMBER + count, idNumber, hikeName,
			last, nullptr));
		last = last->getNext();
	}
	++count;
	return last->getRsvnNum();
}

void Reservations::cancelReservation(int rsvnNumber)
{
	if (count == 1)
	{
		delete first;
		first = last = nullptr;
	}
	else
	{
		Node* pNode = findReservation(rsvnNumber);
		if (pNode == first)
		{
			first = first->getNext();
			delete first->getPrev();
			first->setPrev(nullptr);
		}
		else if (pNode == last)
		{
			last = last->getPrev();
			delete last->getNext();
			last->setNext(nullptr);
		}
		else
		{
			(pNode->getPrev())->setNext(pNode->getNext());
			(pNode->getNext())->setPrev(pNode->getPrev());
			delete pNode;
		}
		pNode = nullptr;
	}
	//--count;
}

void Reservations::printReservation(int rsvnNumber, const HikeList& hikeList,
	const MemberList& memberList) const
{
	if (findReservation(rsvnNumber) == nullptr)
		cout << "This reservation does not exist." << endl;
	else
	{
			Node* pNode = findReservation(rsvnNumber);
			hikeList.printByHikeName(pNode->getHikeName());
			int point = memberList.getPoints(pNode->getIdNumber());
			if (point > 0)
			{
				cout << "\n\tDiscounted price using points: $"
					<< hikeList.getPrice(pNode->getHikeName()) -
					(point / 100) << endl;
			
			}
	}
}

void Reservations::clearList()
{
	Node* temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}

Node* Reservations::findReservation(int rsvnNumber) const
{
	Node* curr = first;
	bool found = false;
	while (!found && curr != nullptr)
	{
		if (curr->getRsvnNum() == rsvnNumber)
		{
			found = true;
		}
		else
		{
			curr = curr->getNext();
		}
	}
	return curr;
}