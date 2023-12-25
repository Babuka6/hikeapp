/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
    friend std::ostream& operator<<(std::ostream& out, const Hike&);
public:
    Hike() : hikeDurationDays(0), hikeDifficulty('e') {}

    Hike(const std::string& myLocation, const std::string& myHikeName,
        int myHikeDurationDays, char myHikeDifficulty);

    std::string getLocation() const;
    std::string getName() const;
    int getDuration() const;
    char getDifficulty() const;
    bool operator<(const Hike& hikeObjToCompare) const;

    ~Hike() {}
private:
    std::string hikeLocation;
    std::string hikeName;
    int hikeDurationDays;
    char hikeDifficulty;
};
#endif
