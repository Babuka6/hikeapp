/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef HIKELIST_H
#define	HIKELIST_H

#include "Hike.h"

#include <map>
#include <string>

class HikeList
{
public:
	HikeList();

	void addHike(const Hike& myHike, double price);
	void addHike(const std::string& hikeLocation,
		const std::string& hikeName, int hikeDuration,
		char hikeDifficulty, double price);

	double getPrice(const std::string& hikeName) const;

	void printAllLocations() const;
	void printByLocation(const std::string& hikeLocation) const;
	void printByDuration() const;
	void printByDuration(int hikeDuration) const;
	void printByDifficulty(char hikeDifficulty) const;
	void printByPrice() const;
	void printByHikeName(const std::string& hikeName) const;

	void clearList();
	~HikeList();
private:
	std::multimap<Hike, double> hikeList;
};
#endif;
