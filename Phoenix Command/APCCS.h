#pragma once

#ifndef APCCS_H
#define APCCS_H

#include "main.h"
#include <map>

#define FIREMODE_SINGLESHOT							0
#define FIREMODE_BURSTFIRE							1
#define FIREMODE_EXPLOSIVE							2

#define SHOOTER_SITUATION(x)						APCCS.table4B[#x]
#define VISIBILITY(x)								APCCS.table4C[#x]
#define TARGET_SIZE(x, y)							APCCS.table4E[#x][y]
#define TARGET_STATIONARY							0
#define TARGET_MOVING(x, y)							APCCS.table4D[TARGET_MOVING_SPEED_INDEX(x)][TARGET_MOVING_RANGE_INDEX(y)]
#define TARGET_MOVING_SPEED_INDEX(x)				find_index(x, APCCS.table4DSpeedIndex)
#define TARGET_MOVING_RANGE_INDEX(x)				find_index(x, APCCS.table4DRangeIndex)
#define TARGET_RANGE_MODIFIER(x)					APCCS.table4A[find_index(x, APCCS.table4Aindex)]

#define SINGLESHOT_HITCHANCE(x)						APCCS.table4GSingleShot[find_index(x, APCCS.table4GEALIndex)]
#define BURSTFIRE_HITCHANCE(x)						APCCS.table4GBurstFire[find_index(x, APCCS.table4GEALIndex)]

#define TARGET_EXPOSED								0
#define TARGET_COVER								1

#define FIND_RECOVERY_CTP(x)						APCCS.table8ACTP[find_index(x, APCCS.table8AIndex)]
#define FIND_RECOVERY_RR(x)							APCCS.table8ARR[find_index(x, APCCS.table8AIndex)]




struct APCCS
{
	vector<int> table4A; // Range Table
	vector<int> table4Aindex; // Range Index


	map<string, int> table4B;

	map<string, int> table4C;


	vector<vector<int>> table4D;				// Movement
	vector<float> table4DSpeedIndex;
	vector<int> table4DRangeIndex;
	vector<int> table4DNoAimRestriction;

	map<string, vector<int>> table4E;

	int table4F; // DON'T NEED RIGHT NOW
	vector<int> table4GSingleShot;
	vector<int> table4GBurstFire;
	vector<int> table4GEALIndex;

	struct Shock
	{
		string loc;
		int SP;

		Shock(string SPloc, int SPdam);
		Shock();
	};

	struct damloc
	{
		vector< vector<int> > DC;
		vector< vector<float> > EPENindex;
		string hitloc;
		vector<int> Open;
		vector<int> Fire;
		vector<int> Disable;
		int SP;
		string SPloc;

		damloc(vector<vector<int>>, initializer_list<int>, initializer_list<int>, string, Shock, initializer_list<int>);
	};
	vector<damloc> DamLocs;

	vector<int> table8ACTP = {79 * 3600, 75 * 3600, 72 * 3600, 68 * 3600, 65 * 3600, 62 * 3600, 59 * 3600, 56 * 3600, 53 * 3600, 51 * 3600, 46 * 3600, 41 * 3600, 37 * 3600, 34 * 3600, 31 * 3600, 11 * 3600, 4 * 3600, 93 * 60, 35 * 60, 13 * 60, 6 * 60, 5 * 60, 4 * 60, 90 * 2, 85 * 2, 81 * 2, 76 * 2, 71 * 2, 67 * 2, 62 * 2, 57 * 2, 52 * 2, 38 * 2, 25 * 2, 1 * 2, 1 * 2, 1 * 2, 1 * 2, 1 * 2};
	vector<int> table8ARR = { 94, 89, 85, 81, 77, 73, 69, 66, 63, 60, 54, 49, 44, 40, 36, 12, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int> table8AIndex = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 12000, 16000, 20000, 40000, 60000, 80000, 100000};

	APCCS();
	void ConstructDamLocs();



};

static struct APCCS APCCS;

#endif // APCCS_H