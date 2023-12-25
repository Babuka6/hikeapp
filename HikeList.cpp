/*
	NCN Corporation

	Chapov, Anthony
	Nguyen, Benjamin
	Nguyen, Viet

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "HikeList.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

HikeList::HikeList() {};

void HikeList::addHike(const Hike& myHike, double price)
{
	hikeList.insert(make_pair(myHike, price));
}

void HikeList::addHike(const string& hikeLocation, const string& hikeName,
	int hikeDuration, char hikeDifficulty, double price)
{
	Hike newHike(hikeLocation, hikeName, hikeDuration, hikeDifficulty);
	hikeList.insert(make_pair(newHike, price));
}

double HikeList::getPrice(const string& hikeName) const
{
	auto iter = find_if(hikeList.begin(), hikeList.end(), [&]
	(const auto& element) {return element.first.getName() == hikeName; });
	return iter->second;
}

void HikeList::printAllLocations() const
{
	auto iter2 = hikeList.begin();
	while (iter2 != hikeList.end())
	{
		cout << "\t" << iter2->first.getLocation() << endl;
		iter2 = hikeList.upper_bound(iter2->first);
	}
}

void HikeList::printByLocation(const string& hikeLocation) const
{
	auto iter3 = find_if(hikeList.begin(), hikeList.end(), [&]
	(const auto& elem) {return elem.first.getLocation() == hikeLocation; });
	while (iter3 != hikeList.end())
	{
		cout << iter3->first;
		cout << "\t  Price (per person): $ " << fixed << setprecision(2)
			<< iter3->second << "\n" << endl;

		iter3 = find_if(++iter3, hikeList.end(), [&](const auto& elem)
			{return elem.first.getLocation() == hikeLocation; });
	}
}

void HikeList::printByDuration() const
{
	cout << "\t(days)" << endl;
	multimap <int, string> temp;
	for (const auto& pair : hikeList)
	{
		string str = pair.first.getName() + ", " + pair.first.getLocation();
		temp.insert(make_pair(pair.first.getDuration(), str));
	}
	for_each(temp.begin(), temp.end(), [](const auto& element)
		{
			cout << "\t(" << element.first << ") " << element.second << endl;
		});
}

void HikeList::printByDuration(int hikeDuration) const
{
	for (const auto& pair : hikeList)
	{
		if (pair.first.getDuration() == hikeDuration)
		{
			cout << pair.first;
			cout << " " << endl;
		}
	}
}

void HikeList::printByDifficulty(char hikeDifficulty) const
{
	for (const auto& pair : hikeList)
	{
		if (pair.first.getDifficulty() == hikeDifficulty)
			cout << "\t(" << pair.first.getDifficulty() << ") "
			<< pair.first.getName() << ", " << pair.first.getLocation()
			<< endl;
	}
}

void HikeList::printByPrice() const
{
	multimap<double, pair<string, string>> tempMultiMap2;
	for (const auto& pair : hikeList)
		tempMultiMap2.emplace(pair.second,
			make_pair(pair.first.getLocation(), pair.first.getName()));
	for (const auto& pair2 : tempMultiMap2)
		cout << "\t$ " << fixed << setprecision(2) << pair2.first << " - "
		<< pair2.second.first << " (" << pair2.second.second << ")" << endl;
}

void HikeList::printByHikeName(const string& hikeName) const
{
	auto iter4 = find_if(hikeList.begin(), hikeList.end(), [&]
	(const auto& element) { return element.first.getName() == hikeName; });
	cout << iter4->first;
	cout << "\t  $" << fixed << setprecision(2) << iter4->second << endl;
}

void HikeList::clearList()
{
	hikeList.clear();
}

HikeList::~HikeList() {}