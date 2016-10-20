#pragma once
#include "main.h"
#include "Character.h"
#include "APCCS.h"
#include <initializer_list>

using namespace std;

int roll(int sides, int times, int mod)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, sides);
	int result = 0;
	for (int i = 0; i < times; i++)
	{
		result += dis(gen) + mod;
	}
	return result;
}

ostream& operator<< (ostream& os, vector<int> vector)
{
	for (auto item : vector)
		cout << item << endl;
	return os;
}

ostream& operator<< (ostream& os, vector<vector<int>> vector)
{
	for (auto secondLevel : vector)
		for (auto item : secondLevel)
			cout << item << endl;
	return os;
}


vector<int> repeater(int number, int times)
{
	vector<int> list;
	for (int i = 0; i < times; i++)
	{
		list.push_back(number);
	}
	int * ptr = list.data();
	return list;
}

int find_index(float number, vector<float> array)
{
	int best = 0;
	for (int i = 1; i < array.size(); i++)
	{
		best = fabs(array[i] - number) < fabs(array[best] - number) ? i : best;

	}
	return best;
}

int find_index(double number, vector<double> array)
{
	int best = 0;
	for (int i = 1; i < array.size(); i++)
	{
		best = fabs(array[i] - number) < fabs(array[best] - number) ? i : best;

	}
	return best;
}

int find_index(int number, vector<int> array)
{
	int best = 0;
	for (int i = 1; i < array.size(); i++)
	{
		best = abs(array[i] - number) < abs(array[best] - number) ? i : best;

	}
	return best;
}

int main()
{
	char a = '1';

	Character Player("Josh", "Soldier");

	Weapon AKM_47(37, 8.7, 30, 1.8, 7,
	{ 11, 11, 9.8, 8.6, 7.5, 4.8, 3.1, 2},
	{ 11, 10, 9.4, 8.3, 7.2, 4.7, 3.0, 1.9},
	{ 16, 15, 14, 12, 11, 6.8, 4.4, 2.8},
	{ 6, 6, 6, 6, 5, 4, 3, 2},
	{ 8, 8, 7, 7, 7, 6, 4, 3},
	{ 6, 6, 6, 5, 5, 4, 3, 2},
	{ 0.3, 0.6, 1, 2, 3, 6, 10, 13},
	{ 58, 50, 40, 33, 28, 18, 13, 9},
	{ 0, 1, 1, 2, 3, 6, 10, 14},
		6, 9, 8, 5, 5, true, true, "AKM 47",
		"Modernized AK 47, fully automatic rifle",
		"Assault Rifle",
		"USSR",
		"Mag",
		{ -23, -12, -9, -7, -6, -4, -3, -2, -1},
		"7.62x39mm");

	cout << "Skill level: " << Player.skill_level << endl;
	cout << "Base Speed: " << Player.base_speed << endl;
	cout << "Max Speed: " << Player.max_speed << endl;
	cout << "SAL: " << Player.SAL << endl;
	cout << "ISF: " << Player.ISF << endl;
	cout << "CA: " << Player.CA << endl;
	cout << "Knockout Value: " << Player.KV << endl;
	cout << "===============Actions per Impulse===============" << endl;
	for (int i = 1; i < 5; i++)
	{
		cout << "Impulse " << i << ": " << Player.CAPI[i] << endl;
	}
	cout << "=================================================" << endl;
	cout << "======================STATS======================" << endl;
	cout << "Strength: " << Player.strength << endl;
	cout << "Intelligence: " << Player.intelligence << endl;
	cout << "Agility: " << Player.agility << endl;
	cout << "Will: " << Player.will << endl;
	cout << "Health: " << Player.health << endl;
	cout << "=================================================" << endl;
	cout << endl;
	Player.Weapons.push_back(AKM_47);
	//Player.get_Weapon("SIG P226");
	Player.calc_SA(Player.Weapons[0]);
	cout << "TEST" << endl;

	Player.FireWeapon(4, {SHOOTER_SITUATION(StandingBraced)}, {TARGET_SIZE(StandingExposed, FIREMODE_SINGLESHOT)}, VISIBILITY(Dusk), TARGET_STATIONARY, 594, FIREMODE_SINGLESHOT, FMJ_AMMO, TARGET_EXPOSED);

	return 1;
}
