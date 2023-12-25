/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	cout << "****************************************************\n"
		<< "\t\tHIKING IN THE US\n"
		<< "****************************************************\n\n"
		<< "\t1. Browse by location\n"
		<< "\t2. Browse by duration\n"
		<< "\t3. Browse by difficulty\n"
		<< "\t4. Browse by price\n"
		<< "\t5. Make a reservation\n"
		<< "\t6. View reservation\n"
		<< "\t7. Cancel resvation\n"
		<< "\t8. Exit\n" << endl;
}
void processReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	bool exitChoice = true;
	while (exitChoice)
	{
		cout << "Please make a selection : ";
		int userChoice = 1;
		cin >> userChoice;
		cout << endl;
		if (userChoice == 1)
		{
			chooseByLocation(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 2)
		{
			chooseByDuration(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 3)
		{
			chooseByDifficulty(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 4)
		{
			chooseByPrice(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 5)
		{
			makeReservation(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 6)
		{
			viewReservation(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else if (userChoice == 7)
		{
			cancelReservation(hikeListObj, memberListObj,
				reservationsObj);
			system("Pause");
			cout << endl;
			displayMenu();
		}
		else
		{
			cout << "Thank you for visiting!" << endl;
			exitChoice = false;
		}
	}
}
void chooseByLocation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	hikeListObj.HikeList::printAllLocations();
	cout << "\nChoose a location : ";
	string locationChoice;
	cin >> locationChoice;
	cout << endl;
	hikeListObj.HikeList::printByLocation(locationChoice);
	askToReserve(hikeListObj, memberListObj, reservationsObj);
}
void chooseByDuration(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	hikeListObj.HikeList::printByDuration();
	cout << endl;
	cout << "How many days are you considering? ";
	int numOfDays = 1;
	cin >> numOfDays;
	cout << endl;
	hikeListObj.HikeList::printByDuration(numOfDays);
	askToReserve(hikeListObj, memberListObj, reservationsObj);
}
void chooseByDifficulty(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	cout << "Choose difficulty level:\n\n\te. easy\n"
		<< "\tm. moderate\n\ts. strenous\n" << endl;
	cout << "Your choice: ";
	char difficultyChoice = 'e';
	cin >> difficultyChoice;
	cout << "\n\t(difficulty level)" << endl;
	hikeListObj.HikeList::printByDifficulty(difficultyChoice);
	cout << endl;
	askToReserve(hikeListObj, memberListObj, reservationsObj);
}
void chooseByPrice(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	hikeListObj.HikeList::printByPrice();
	cout << endl;
	askToReserve(hikeListObj, memberListObj, reservationsObj);
}
int askIfMember(MemberList& memberListObj)
{
	cout << "Are you a member? (y/n) ";
	char memberChoice = 'n';
	cin >> memberChoice;
	cout << endl;
	int memberIDNum = 0;
	if (memberChoice == 'y')
	{
		cout << "What is your member ID number? ";
		cin >> memberIDNum;
		cout << "\nWhat is your last name? ";
		string memberLastName;
		cin >> memberLastName;
		cout << endl;
		memberListObj.MemberList::printMember(memberIDNum,
			memberLastName);
		cout << endl;
	}
	else
	{
		memberIDNum = addNewMember(memberListObj);
	}
	return memberIDNum;
}
int addNewMember(MemberList& memberListObj)
{
	cout << "\tLet's add you to the member list!" << endl;;
	cout << "\t\tWhat is your first name? ";
	string firstName;
	cin >> firstName;
	cout << "\t\tWhat is your last name? ";
	string lastName;
	cin >> lastName;
	memberListObj.addMember(firstName, lastName);
	cout << "\n\tWelcome to the club!" << endl;
	int clientID = memberListObj.getLastID();
	cout << "\t\tYour member ID number is: " << clientID << "\n" << endl;
	return clientID;
}
void makeReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	int memberID = askIfMember(memberListObj);
	cout << "Which hike would you like to reserve (hike name)? ";
	string hikePicked;
	cin >> hikePicked;
	cout << endl;
	hikeListObj.HikeList::printByHikeName(hikePicked);

	if (memberListObj.MemberList::getPoints(memberID) > 0)
	{
		cout << "\n\tDiscounted price using points: "
			<< "$" << fixed << setprecision(2)
			<< (hikeListObj.HikeList::getPrice(hikePicked) -
				(memberListObj.MemberList::getPoints(memberID) / 100))
			<< endl;
	}
	cout << "\n\tBefore proceeding, please make a note of your "
		<< "reservation number.\n\t Reservation #: "
		<< reservationsObj.Reservations::addReservation(memberID,
			hikePicked)
		<< "\n\n( *** Will continue to scheduling and payment. *** )\n"
		<< endl;
}
void viewReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	cout << "Enter reservation #: ";
	int resNum = 0;
	cin >> resNum;
	cout << endl;
	reservationsObj.printReservation(resNum, hikeListObj, memberListObj);
	cout << endl;
}
void cancelReservation(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	cout << "Enter reservation #: ";
	int resNum = 0;
	cin >> resNum;
	cout << endl;
	reservationsObj.printReservation(resNum, hikeListObj, memberListObj);
	cout << endl;
	cout << "Are you sure you want to cancel this reservation? (y/n) ";
	char memberChoice = 'n';
	cin >> memberChoice;
	cout << endl;
	if (memberChoice == 'y')
	{
		reservationsObj.cancelReservation(resNum);
		cout << "Reservation #" << resNum << " has been canceled."
			<< "\n" << endl;
	}
}
void askToReserve(HikeList& hikeListObj, MemberList& memberListObj,
	Reservations& reservationsObj)
{
	cout << "Would you like to make a reservation? (y/n) ";
	char reservationChoice = 'n';
	cin >> reservationChoice;
	cout << endl;
	if (reservationChoice == 'y')
	{
		makeReservation(hikeListObj, memberListObj, reservationsObj);
	}
}