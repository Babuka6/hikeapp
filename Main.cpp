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
#include "Member.h"
#include "Hike.h"
#include "HikeList.h"
#include "Interface.h"
#include "Reservations.h"
#include "MemberReader.h"
#include "HikeReader.h"
#include "ReservationReader.h"

int main()
{
	MemberList myMemberList;
	HikeList myHikeList;
	Reservations myReservationList;

	getHikeData(myHikeList);
	getMemberData(myMemberList);
	getReservationData(myReservationList);
	displayMenu();
	processReservation(myHikeList, myMemberList, myReservationList);
	//cout << endl;
	//system("Pause");
	return 0;
}