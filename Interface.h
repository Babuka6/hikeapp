/*
    NCN Corporation

    Chapov, Anthony
    Nguyen, Benjamin
    Nguyen, Viet

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "HikeList.h"
#include "MemberList.h"
#include "Reservations.h"

#include <string>

void displayMenu();
void processReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void chooseByLocation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void chooseByDuration(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void chooseByDifficulty(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void chooseByPrice(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
int askIfMember(MemberList& memberListObj);
int addNewMember(MemberList& memberListObj);
void makeReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void viewReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void cancelReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);
void askToReserve(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj);

#endif
