#include "APCCS.h"


APCCS::APCCS()
{
	table4A = { 33, 28, 25, 23, 22, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -19, -20, -21, -22, -23, -24, -25, -26, -27 }; // Range Table
	table4Aindex = { 1 * 2, 2 * 2, 3 * 2, 4 * 2, 5 * 2, 6 * 2, 7 * 2, 8 * 2, 9 * 2, 11 * 2, 12 * 2, 14 * 2, 16 * 2, 19 * 2, 22 * 2, 25 * 2, 30 * 2, 35 * 2, 40 * 2, 45 * 2, 50 * 2, 55 * 2, 65 * 2, 75 * 2, 85 * 2, 100 * 2, 115 * 2, 130 * 2, 150 * 2, 170 * 2, 200 * 2, 230 * 2, 250 * 2, 300 * 2, 350 * 2, 400 * 2, 450 * 2, 500 * 2, 600 * 2, 700 * 2, 800 * 2, 950 * 2, 1100 * 2, 1250 * 2, 1400 * 2, 1650 * 2, 1900 * 2, 2150 * 2, 2500 * 2, 2850 * 2, 3300 * 2, 3800 * 2, 4350 * 2}; // Range Index


	table4B =                      // Stance and Situation
	{
		{ "Standing",  0 },
		{ "Kneeling", 3 },
		{ "Prone", 6 },
		{ "StandingBraced", 4 },
		{ "KneelingBraced", 5 },
		{ "ProneBraced", 7 },
		{ "SlingSupport", 1 },
		{ "HipFire", -6 },
		{ "OneHandRifle", -7 },
		{ "OneHandPistol", -4 },
		{ "FoldingStockNotUsed", -4 },
		{ "PistolDoubleAction", -3 },
		{ "DeployedBipodNotBraced", -2 },
		{ "BipodMounted", 3 },
		{ "TripodMounted", 5 },
		{ "TurretMounted", 11 },
		{ "PistolShoulderStock", 3 } };

	table4C	=									// Visibility
	{
		{ "Good", 0 },
		{ "Dusk", -2 },
		{ "FullMoon", -4 },
		{ "HalfMoon", -6 },
		{ "NoMoon  ", -12 },
		{ "FireAtMuzzleFlash", -10 },
		{ "SmokeHazeFog", -6 },
		{ "LookingIntoLight", -8 },
		{ "ScopeCloseRange", -6 },									// Under 8 hexes
		{ "OpticalScopeBroken", -4 },
		{ "AdvancedAimSystemBroken", -8 },
		{ "WeaponSightBroken", -4 },
		{ "FiringFromTearGas", -8 },
		{ "ShooterNotLooking", -14 }
	};


	table4D = {
		{ -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -8,  -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -10,  -8,  -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -10, -10,  -7,  -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -10, -10,  -8,  -6,  -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -10, -10, -10, -10,  -8,  -6,  -5,  -5,  -5,  -5,  -5,  -5,  -5 },
		{ -10, -10, -10, -10, -10,  -8,  -7,  -6,  -5,  -5,  -5,  -5,  -5 },
		{ -10, -10, -10, -10, -10, -10,  -8,  -7,  -6,  -6,  -5,  -5,  -5 },
		{ -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -6,  -5,  -5,  -5 },
		{ -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -6,  -6,  -5 },
		{ -10, -10, -10, -10, -10, -10, -10, -10,  -8,  -7,  -6,  -6,  -6 },
		{ -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -6,  -6 },
		{ -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -7,  -6 },
		{ -10, -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -6 },
		{ -10, -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7,  -7 },
		{ -10, -10, -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -7 },
		{ -10, -10, -10, -10, -10, -10, -10, -10, -10, -10,  -9,  -8,  -8 }
	};																			// Movement
	table4DSpeedIndex = { 0.5, 1, 2, 3, 4, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120 };
	table4DRangeIndex = { 10 * 2, 20 * 2, 40 * 2, 70 * 2, 100 * 2, 200 * 2, 300 * 2, 400 * 2, 600 * 2, 800 * 2, 1000 * 2, 1200 * 2, 1500 * 2};
	table4DNoAimRestriction = { 2, 3, 4, 5, 6, 9, 11 };

	table4E = {
		{ "LookOverCover", { -4, -3, -3 } },
		{ "FireOverCover", { 0, 2, 2 } },
		{ "StandingExposed", { 7, 14, 1 } },
		{ "KneelingExposed", { 6, 11, 3 } },
		{ "Prone", { 2, 2, 2 } },
		{ "Running", { 8, 14, 1 } },
		{ "LowCrouch", { 7, 11, 2 } },
		{ "HandsAndKnees", { 6, 8, 1 } },
		{ "LowProne", { 1, 0, 5 } },
		{ "Head", { -3, 0, -3 } },
		{ "Body", { 5, 8, 3 } },
		{ "Legs", { 4, 8, 0 } }
	};

	//int table4F; // DON'T NEED RIGHT NOW
	table4GSingleShot = { 99, 98, 96, 94, 90, 86, 80, 74, 67, 60, 53, 46, 39, 33, 27, 22, 18, 15, 12, 9, 7, 6, 5, 4, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	table4GBurstFire = { 99, 98, 98, 97, 95, 92, 90, 86, 82, 77, 73, 68, 62, 57, 52, 47, 43, 38, 34, 31, 27, 24, 21, 19, 17, 15, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0 };
	table4GEALIndex = { 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -8, -10, -15, -17, -22 };

	ConstructDamLocs();



}

APCCS::Shock::Shock(string SPloc, int SPdam)
{
	loc = SPloc;
	SP = SPdam;
}

APCCS::Shock::Shock()
{
	loc = "";
	SP = 0;
}


APCCS::damloc::damloc(vector<vector<int>> DamageClass,
	initializer_list<int> fire,	initializer_list<int> open,
	string loc, Shock shock, initializer_list<int> disabling = {0})
{

	SP = shock.SP;
	SPloc = shock.loc;
	
	DC = DamageClass;

	EPENindex = { { 0.5, 1, 1.5, 2, 3, 5, 10 },{ 1, 1.5, 2, 2.5, 3, 5, 10 },{ 1, 1.5, 2, 2.5, 3, 5, 10 },{ 1, 2, 2.5, 3, 5, 10 },
	{ 1, 2, 3, 5, 10 },{ 1, 2, 3, 5, 10 },{ 1, 2, 3, 5, 10 },{ 1, 3, 5, 10 },{ 1, 3, 5, 10 },{ 1, 3, 5, 10 } };

	hitloc = loc;

	Disable = disabling;

	Fire = fire;
	Open = open;
}

void APCCS::ConstructDamLocs()
{
	Shock Noshock;
	Shock ShockNeck("Neck", 400);
	Shock ShockSpine("Spine", 400);
	Shock ShockShoulder("Shoulder", 10);
	Shock ShockThigh("Thigh", 80);
	Shock ShockArm("Arm", 20);
	Shock ShockKneeShin("Knee - Shin", 50);
	Shock ShockHand("Hand", 10);
	Shock ShockAnkleFoot("Ankle - Foot", 20);

	damloc HeadGlance(	{ { 1, 5, 7, 7, 7, 7, 7 },{ 16, 24, 24, 24, 24, 24, 24 },{ 57, 83, 83, 83, 83, 83, 83 }, { 1H, 2H, 2H, 2H, 2H, 2H },
	{ 2H, 3H, 3H, 3H, 3H },{ 3H, 4H, 4H, 4H, 4H }, { 7H, 1K, 1K, 1K, 1K },{ 1K, 2K, 2K, 2K },{ 3K, 4K, 4K, 4K }, { 6K, 8K, 8K, 8K } },
	{ 0, 2 }, { 0, 0 },
		"Head - Glance", Noshock);

	damloc HeadForehead(
	{ { 11, 1K, 2K, 2K, 2K, 2K, 2K}, {4K, 5K, 6K, 8K, 8K, 8K, 8K}, { 1T, 2T, 2T, 3T, 3T, 3T, 3T}, { 3T, 5T, 6T, 6T, 6T, 6T},
	{ 5T, 8T, 9T, 9T, 9T}, {7T, 1X, 1X, 1X, 1X}, { 2X, 3X, 3X, 3X, 3X}, {3X, 5X, 6X, 6X}, { 5X, 8X, 1M, 1M}, {7X, 1M, 1M, 1M}},
	{3, 16}, {1, 2},
		"Head - Forehead", Noshock);

	damloc HeadEyeNose(
	{ { 4, 1K, 2K, 3K, 3K, 3K, 3K}, {4K, 5K, 1T, 1T, 1T, 1T, 1T}, { 1T, 2T, 4T, 4T, 4T, 4T, 4T}, { 3T, 8T, 8T, 8T, 8T, 8T},
	{5T, 1X, 1X, 1X, 1X}, { 8T, 2X, 2X, 2X, 2X}, { 2X, 4X, 4X, 4X, 4X}, { 3X, 8X, 8X, 8X}, { 6X, 1M, 1M, 1M}, { 1M, 2M, 2M, 2M}},
	{ 17, 21}, { 3, 3},
		"Head - Eye & Nose", Noshock);

	damloc HeadMouth(
	{ { 1, 3, 3, 45, 2H, 2H, 2H}, {11, 12, 2H, 8H, 8H, 8H, 8H}, { 37, 40, 5H, 3K, 3K, 3K, 3K}, { 77, 1K, 5K, 6K, 6K, 6K, 6K},
	{ 1H, 2K, 9K, 1T, 1T}, { 2H, 3K, 1T, 1T, 1T}, { 4H, 7K, 3T, 3T, 3T}, { 8H, 1T, 6T, 6T}, { 1K, 2T, 1X, 1X}, { 2K, 4T, 2X, 2X}},
	{ 22, 32}, { 4, 5},
		"Head - Mouth - Neck", ShockNeck, {4, 5, 5, 5, 4, 4, 4, 3, 3, 3});

	damloc NeckFlesh(
	{ { 1, 1, 1, 1, 1, 1, 1}, { 5, 5, 5, 5, 5, 5, 5}, { 11, 11, 11, 11, 11, 11, 11}, { 19, 19, 19, 19, 19, 19}, { 29, 29, 29, 29, 29},
	{ 39, 39, 39, 39, 39}, { 79, 79, 79, 79, 79}, { 1H, 1H, 1H, 1H}, { 3H, 3H, 3H, 3H}, { 6H, 6H, 6H, 6H}},
	{ 33, 34}, { 6, 6},
		"Neck - Flesh", Noshock);

	damloc NeckSpine(
	{ { 3, 4, 5, 2H, 2H, 2H, 2H}, { 5, 17, 6H, 8H, 8H, 8H, 8H}, { 54, 60, 3K, 3K, 3K, 3K, 3K}, { 1H, 5K, 6K, 6K, 6K, 6K},
	{ 2H, 9K, 1T, 1T, 1T, 1T}, { 3H, 1T, 1T, 1T, 1T}, { 7H, 3T, 3T, 3T, 3T}, { 1K, 5T, 6T, 6T}, { 2K, 1X, 1X, 1X}, { 3K, 2X, 2X, 2X}},
	{ 35, 36}, { 7, 7},
		"Neck - Spine", ShockSpine, { 5, 6, 6, 5, 4, 4, 4, 3, 3, 3});

	damloc ShoulderGlance(
	{ repeater(1, 7), repeater(2, 7), repeater(3, 7), repeater(5, 6),
		repeater(6, 5),	repeater(7, 5), repeater(11, 5), repeater(15, 4), repeater(22, 4), repeater(32, 4)},
		{ 37, 48}, { 8, 8},
		"Arm - Shoulder - Glance", Noshock);

	damloc Shoulder(
	{ { 1, 2, 2, 4, 4, 4, 4}, { 7, 8, 14, 14, 14, 14, 14}, { 23, 27, 49, 49, 49, 49, 49}, { 48, 1H, 1H, 1H, 1H, 1H},
	{ 80, 2H, 2H, 2H, 2H}, { 1H, 3H, 3H, 3H, 3H}, { 3H, 6H, 6H, 6H, 6H}, { 4H, 9H, 9H, 9H}, { 8H, 2K, 2K, 2K}, { 2K, 3K, 3K, 3K}},
	{ 49, 60}, { 9, 9},
		"Shoulder", ShockShoulder, {0, 6, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ArmGlance(
	{ repeater(1, 7), repeater(2, 7), repeater(3, 7), repeater(5, 6),
		repeater(6, 5),	repeater(7, 5),	repeater(11, 5), repeater(15, 4), repeater(22, 4), repeater(32, 4)},
	{ 61, 65}, { 10, 10},
		"Arm - Glance", Noshock);

	damloc ArmFlesh(
	{ repeater(1, 7), repeater(3, 7), repeater(9, 7), repeater(18, 6),
		repeater(31, 5), repeater(46, 5), repeater(1H, 5), repeater(1H, 4), repeater(1H, 4), repeater(1H, 4)},
	{ 82, 87}, { 14, 14},
		"Arm - Flesh", ShockArm, { 0, 0, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ArmBone(
	{ {1, 1, 1, 1, 1, 7, 7}, { 1, 2, 3, 4, 5, 23, 23}, { 5, 7, 9, 13, 16, 81, 81}, { 10, 20, 28, 34, 1H, 1H},
	{ 17, 33, 57, 1H, 1H}, { 26, 49, 85, 1H, 1H}, { 60, 1H, 1H, 1H, 1H}, repeater(1H, 4), repeater(1H, 4), repeater(1H, 4)},
	{ 72, 74}, { 12, 12},
		"Arm - Bone", ShockArm, {5, 6, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ArmElbow(
	{ { 1, 1, 2, 3, 3, 3, 3}, { 4, 7, 9, 10, 10, 10, 10}, { 14, 25, 30, 34, 34, 34, 34}, { 29, 62, 71, 71, 71, 71},
	{ 48, 1H, 1H, 1H, 1H}, { 72, 1H, 1H, 1H, 1H}, repeater(1H, 5), repeater(1H, 4), repeater(1H, 4), repeater(1H, 4)},
	{ 75, 78}, { 13, 13},
		"Arm - Elbow", ShockArm, {6, 7, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ForearmFlesh(
	{ repeater(1, 7), repeater(2, 7), repeater(6, 7), repeater(12, 6),
		repeater(20, 5), repeater(31, 5), repeater(50, 5), repeater(50, 4), repeater(50, 4), repeater(50, 4)},
	 { 79, 81}, { 14, 14},
		"Forearm - Flesh", ShockArm, { 0, 0, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ForearmBone(
	{ { 1, 1, 1, 1, 6, 6, 6}, { 1, 1, 2, 4, 20, 20, 20}, { 4, 6, 8, 15, 60, 60, 60}, {8, 17, 38, 60, 60, 60},
	{ 13, 29, 60, 60, 60}, { 20, 43, 60, 60, 60}, { 47, 60, 60, 60, 60}, { 60, 60, 60, 60}, { 60, 60, 60, 60}, {60, 60, 60, 60}},
	{ 82, 87}, { 15, 15},
		"Forearm - Bone", ShockArm, { 6, 7, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ArmHand(
	{ repeater(1, 7), repeater(1, 7), repeater(4, 7), repeater(8, 6),
		repeater(14, 5), repeater(15, 5), repeater(15, 5), repeater(15, 4), repeater(15, 4), repeater(15, 4)},
		{ 88, 93}, { 16, 16},
		"Hand", ShockHand, { 0, 0, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc WeaponCrit( 
		{ repeater(0, 7), repeater(0, 7), repeater(0, 7), repeater(0, 6),
		repeater(0, 5), repeater(0, 5), repeater(0, 5), repeater(0, 4), repeater(0, 4), repeater(0, 4) },
	{ 94, 99}, { 17, 17},
		"Weapon", Noshock);

	damloc TorsoGlance({
		repeater(1, 7), repeater(3, 7), repeater(5, 7), repeater(7, 6),
		repeater(9, 5), repeater(11, 5), repeater(16, 5), repeater(22, 4), repeater(32, 4), repeater(47, 4)},
		{ 1H, 1H}, { 18, 19},
		"Torso - Glance", Noshock);

	damloc NeckBase({
		{ 1, 3, 6, 7, 2H, 3H, 3H}, { 12, 21, 24, 5H, 8H, 8H, 9H}, { 40, 74, 83, 2K, 3K, 3K, 3K}, { 83, 2H, 3K, 6K, 6K, 6K},
		{ 1H, 3H, 1T, 1T, 1T}, { 2H, 4H, 2T, 2T, 2T}, { 5H, 1K, 4T, 4T, 4T}, { 9H, 2K, 6T, 7T}, { 2K, 4K, 1X, 1X}, { 4K, 8K, 3X, 3X}},
		{ 1H, 1H}, { 20, 21},
		"Base of Neck", ShockNeck, { 4, 5, 5, 5, 4, 4, 4, 3, 3, 3});

	damloc LungRib({
		{ 1, 1, 64, 71, 79, 79, 79}, { 1, 79, 87, 98, 98, 98, 98}, { 2, 1H, 1H, 1H, 1H, 1H, 1H}, { 2, 2H, 2H, 2H, 2H, 2H},
		{ 3, 2H, 2H, 2H, 2H}, {3, 3H, 3H, 3H, 3H}, {6, 5H, 5H, 5H, 5H}, { 9, 7H, 8H, 8H}, { 17, 1K, 1K, 1K}, { 32, 3K, 3K, 3K}},
		{1H, 1H}, { 22, 22},
		"Lung - Rib", Noshock);

	damloc Lung({
		{ 37, 40, 51, 51, 51, 51, 51}, { 50, 62, 62, 62, 62, 62, 62}, { 71, 89, 89, 89, 89, 89, 89}, { 96, 1H, 1H, 1H, 1H, 1H},
		{ 1H, 2H, 2H, 2H, 2H}, {2H, 2H, 2H, 2H, 2H}, { 3H, 3H, 3H, 3H, 3H}, {4H, 5H, 5H, 5H}, { 7H, 9H, 9H, 9H}, { 1K, 2K, 2K, 2K}},
		{ 1H, 1H}, { 23, 24},
		"Torso - Lung", Noshock);

	damloc Heart({
		{ 1, 2K, 3K, 3K, 4K, 4K, 4K}, { 8K, 1T, 1T, 1T, 1T, 1T, 1T}, { 3T, 3T, 3T, 4T, 5T, 5T, 5T}, { 6T, 7T, 9T, 1X, 1X, 1X},
		{ 1X, 1X, 2X, 2X, 2X}, { 2X, 2X, 3X, 3X, 3X}, { 4X, 4X, 6X, 6X, 6X}, { 6X, 7X, 1M, 1M}, { 1M, 2M, 2M, 2M}, { 3M, 3M, 5M, 5M}},
		{ 1H, 1H}, { 25, 25},
		"Torso - Heart", ShockSpine, { 4, 5, 5, 5, 4, 4, 4, 3, 3, 3});

	damloc LiverRib({
		{ 1, 6, 31, 42, 49, 49, 49}, { 21, 1H, 1H, 2H, 2H, 2H, 2H}, { 75, 4H, 5H, 6H, 6H, 6H, 6H}, { 2H, 1K, 1K, 1K, 1K, 1K},
		{ 3H, 2K, 2K, 2K, 2K}, { 4H, 3K, 3K, 3K, 3K}, { 9H, 6K, 7K, 7K, 7K}, { 2K, 1T, 1T, 1T}, {3K, 2T, 3T, 3T}, { 6K, 4T, 5T, 5T}},
		{ 1H, 1H}, { 26, 26},
		"Liver - Rib", Noshock);

	damloc Liver({
		{ 4, 27, 28, 35, 35, 35, 35}, { 94, 98, 1H, 1H, 1H, 1H, 1H}, { 3H, 3H, 4H, 4H, 4H, 4H, 4H}, { 7H, 9H, 9H, 9H, 9H, 9H},
		{ 1K, 1K, 1K, 1K, 1K}, {2K, 2K, 2K, 2K, 2K}, { 4K, 5K, 5K, 5K, 5K}, { 7K, 9K, 9K, 9K}, { 1T, 2T, 2T, 2T}, { 3T, 3T, 3T, 3T}},
		{ 1H, 1H}, { 27, 27},
		"Torso - Liver", Noshock);

	damloc StomachRib({
		{ 1, 4, 19, 27, 38, 38, 38}, { 6, 27, 37, 45, 53, 53, 53}, { 11, 46, 63, 89, 89, 89, 89}, { 16, 95, 1H, 1H, 1H, 1H},
		{ 22, 1H, 2H, 2H, 2H}, { 29, 2H, 2H, 2H, 2H}, { 56, 3H, 5H, 5H, 5H}, { 90, 5H, 8H, 8H}, { 2H, 1K, 1K, 1K}, { 3H, 2K, 2K, 2L}},
		{ 1H, 1H}, { 28, 28},
		"Stomach - Rib", Noshock);

	damloc Stomach({
		{ 3, 17, 19, 28, 28, 28, 28}, { 24, 27, 40, 40, 40, 40, 40}, { 41, 45, 67, 67, 67, 67, 67}, { 62, 1H, 1H, 1H, 1H, 1H},
		{ 87, 1H, 1H, 1H, 1H}, { 1H, 2H, 2H, 2H, 2H}, { 2H, 4H, 4H, 4H, 4H}, { 4H, 6H, 6H, 6H}, { 7H, 1K, 1K, 1K}, { 1K, 2K, 2K, 2K}},
		{ 1H, 1H}, { 29, 29},
		"Stomach", Noshock);

	damloc StomachSpleen({
		{ 1, 2, 25, 41, 50, 50, 50}, { 6, 64, 1H, 1H, 1H, 1H, 1H}, { 19, 2H, 3H, 4H, 4H, 4H, 4H}, { 37, 6H, 8H, 8H, 8H, 8H},
		{ 60, 1K, 1K, 1K, 1K}, {88, 2K, 2K, 2K, 2K}, { 2H, 4K, 4K, 4K, 4K}, { 4H, 6K, 8K, 8K}, { 8H, 1T, 2T, 2T}, { 2K, 3T, 3T, 3T}},
		{ 1H, 1H}, { 30, 30},
		"Stomach - Spleen", Noshock);

	damloc StomachKidney({
		{ 2, 47, 49, 58, 58, 58, 58}, { 1H, 1H, 2H, 2H, 2H, 2H, 2H}, { 4H, 4H, 5H, 5H, 5H, 5H, 5H}, { 7H, 9H, 9H, 9H, 9H, 9H},
		{ 1K, 1K, 1K, 1K, 1K}, { 2K, 2K, 2K, 2K, 2K}, { 4K, 5K, 5K, 5K, 5K,}, { 7K, 9K, 9K, 9K}, { 2T, 2T, 2T, 2T}, { 3T, 4T, 4T, 4T}},
		{ 1H, 1H}, { 31, 31},
		"Stomach - Kidney", Noshock);

	damloc LiverKidney({
		{ 4, 44, 45, 53, 53, 53, 53}, { 2H, 2H, 2H, 2H, 2H, 2H, 2H}, { 5H, 6H, 6H, 6H, 6H, 6H, 6H}, { 1K, 1K, 1K, 1K, 1K, 1K},
		{ 2K, 2K, 2K, 2K, 2K}, { 3K, 3K, 3K, 3K, 3K}, { 6K, 8K, 8K, 8K, 8K}, { 1T, 1T, 1T, 1T}, { 3T, 3T, 3T, 3T}, { 5T, 7T, 7T, 7T}},
		{ 1H, 1H}, { 32, 33},
		"Liver - Kidney", Noshock);

	damloc LiverSpine({
		{ 4, 12, 12, 2H, 3H, 3H, 3H}, { 41, 43, 7H, 9H, 9H, 1K, 1K}, { 1H, 2H, 2K, 3K, 3K, 3K, 3K}, { 3H, 5K, 7K, 7K, 7K, 7K},
		{ 5H, 9K, 1T, 1T, 1T}, { 7H, 1T, 2T, 2T, 2T}, { 2K, 3T, 4T, 4T, 4T}, { 3K, 5T, 7T, 7T}, { 7K, 1X, 2X, 2X}, { 1T, 2X, 3X, 3X}},
		{ 1H, 1H}, { 34, 35},
		"Liver - Spine", ShockSpine, { 5, 6, 6, 5, 4, 4, 4, 3, 3, 3});

	damloc Intestines({
		{ 3, 17, 21, 21, 21, 21, 21}, { 23, 28, 28, 28, 28, 28, 28}, { 37, 45, 45, 45, 45, 45, 45}, { 53, 66, 66, 66, 66, 66},
		{ 73, 89, 89, 89, 89}, { 95, 1H, 1H, 1H, 1H}, { 2H, 2H, 2H, 2H, 2H}, { 3H, 3H, 3H, 3H}, { 5H, 7H, 7H, 7H}, { 1K, 1K, 1K, 1K}},
		{ 1H, 1H}, { 36, 39},
		"Intestines", Noshock);

	damloc Spine({
		{ 1, 3, 3, 2H, 2H, 3H, 3H}, { 41, 43, 7H, 9H, 9H, 1K, 1K}, { 1H, 2H, 2K, 3K, 3K, 3K, 3K}, { 3H, 5K, 7K, 7K, 7K, 7K},
		{ 1H, 7K, 9K, 9K, 9K}, { 2H, 1T, 1T, 1T, 1T}, { 4H, 2T, 3T, 3T, 3T}, { 7H, 4T, 5T, 5T}, { 2K, 9T, 1X, 1X}, { 3K, 2X, 2X, 2X}},
		{ 1H, 1H}, { 40, 42},
		"Spine", ShockSpine, { 5, 6, 6, 5, 4, 4, 4, 3, 3, 3});

	damloc Pelvis({
		{ 3, 10, 11, 19, 21, 21, 21}, { 18, 19, 32, 35, 35, 35, 35}, { 37, 40, 67, 73, 73, 73, 73}, { 63, 1H, 1H, 1H, 1H, 1H},
		{ 94, 2H, 2H, 2H, 2H}, { 1H, 2H, 3H, 3H, 3H}, { 3H, 5H, 5H, 5H, 5H}, { 5H, 8H, 9H, 9H}, { 1K, 2K, 2K, 2K}, { 2K, 4K, 4K, 4K}},
		{ 1H, 1H}, { 43, 56},
		"Pelvis", Noshock);

	damloc LegGlance({
		repeater(1, 7), repeater(3, 7), repeater(5, 7), repeater(7, 6),
		repeater(9, 5), repeater(11, 5), repeater(16, 5), repeater(22, 4), repeater(32, 4), repeater(47, 4) },
		{ 1H, 1H}, { 57, 61},
		"Leg - Glance", Noshock);

	damloc ThighFlesh({
		{ 1, 2, 3, 3, 3, 3, 3}, { 6, 12, 12, 12, 12, 12, 12}, { 22, 42, 42, 42, 42, 42, 42}, { 46, 88, 88, 88, 88, 88},
		{ 78, 1H, 1H, 1H, 1H}, { 1H, 2H, 2H, 2H, 2H}, { 3H, 5H, 5H, 5H, 5H}, { 5H, 6H, 6H, 6H}, { 6H, 6H, 6H, 6H}, { 6H, 6H, 6H, 6H}},
		{ 1H, 1H}, { 62, 75},
		"Thigh - Flesh", ShockThigh, { 0, 6, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ThighBone({
		{ 1, 1, 1, 1, 1, 5, 16}, { 3, 3, 4, 4, 5, 16, 57}, { 10, 10, 14, 15, 18, 55, 2H}, { 21, 28, 31, 38, 1H, 4H},
		{ 35, 48, 63, 2H, 7H}, { 53, 72, 95, 3H, 7H}, { 1H, 2H, 2H, 7H, 7H}, { 2H, 3H, 4H, 7H}, { 5H, 7H, 7H, 7H}, { 7H, 7H, 7H, 7H}},
		{ 1H, 1H}, { 76, 79},
		"Thigh - Bone", ShockThigh, { 4, 5, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc Knee({
		{ 1, 1, 2, 2, 3, 4, 4}, { 3, 7, 9, 10, 12, 13, 13}, { 12, 25, 30, 35, 41, 47, 47}, { 24, 62, 73, 86, 97, 97},
		{ 40, 1H, 1H, 2H, 2H}, { 60, 2H, 2H, 2H, 2H}, { 1H, 2H, 2H, 2H, 2H}, { 2H, 2H, 2H, 2H}, { 2H, 2H, 2H, 2H}, { 2H, 2H, 2H, 2H}},
		{ 1H, 1H}, { 80, 83},
		"Knee", ShockKneeShin, { 6, 7, 7, 6, 5, 5, 5, 4, 4, 4});

	damloc ShinFlesh({
		repeater(1, 7), repeater(3, 7), repeater(9, 7), repeater(18, 6),
		repeater(31, 5), repeater(46, 5), repeater(1H, 5), repeater(1H, 4), repeater(1H, 4), repeater(1H, 4)},
		{1H, 1H}, {84, 88},
		"Shin - Flesh", ShockKneeShin, { 0, 0, 0, 6, 5, 5, 5, 4, 4, 4});

	damloc ShinBone({
		{ 1, 1, 1, 1, 1, 2, 14}, { 1, 1, 1, 1, 1, 2, 8, 47}, { 2, 2, 4, 4, 7, 29, 2H}, { 4, 9, 9, 14, 60, 2H},
		{ 7, 14, 24, 1H, 2H}, { 11, 22, 35, 2H, 2H}, { 26, 50, 82, 2H, 2H}, { 45, 89, 1H, 2H}, { 1H, 2H, 2H, 2H}, { 2H, 2H, 2H, 2H}},
		{ 1H, 1H}, { 89, 93},
		"Shin - Bone", ShockKneeShin, { 5, 6, 6, 5, 4, 5, 5, 4, 4, 4});

	damloc AnkleFoot({
		{ 1, 1, 1, 1, 1, 1, 1}, { 1, 1, 2, 3, 3, 3, 3}, { 3, 4, 7, 9, 12, 12, 12}, { 6, 14, 20, 25, 25, 25},
		{ 9, 24, 42, 42, 42}, { 14, 36, 63, 63, 63}, { 33, 84, 95, 95, 95}, { 58, 95, 95, 95}, { 95, 95, 95, 95}, { 95, 95, 95, 95}},
		{ 1H, 1H}, { 94, 99},
		"Ankle - Foot", ShockAnkleFoot, { 6, 7, 7, 6, 5, 5, 5, 4, 4, 4});



	DamLocs.push_back(HeadGlance);				// 0
	DamLocs.push_back(HeadForehead);			// 1
	DamLocs.push_back(HeadEyeNose);				// 2
	DamLocs.push_back(HeadMouth);				// 3
	DamLocs.push_back(NeckFlesh);				// 4
	DamLocs.push_back(NeckSpine);				// 5
	DamLocs.push_back(ShoulderGlance);			// 6
	DamLocs.push_back(Shoulder);				// 7
	DamLocs.push_back(ArmGlance);				// 8
	DamLocs.push_back(ArmFlesh);				// 9
	DamLocs.push_back(ArmBone);					// 10
	DamLocs.push_back(ArmElbow);				// 11
	DamLocs.push_back(ForearmFlesh);			// 12
	DamLocs.push_back(ForearmBone);				// 13
	DamLocs.push_back(ArmHand);					// 14
	DamLocs.push_back(WeaponCrit);				// 15 SPECIAL
	DamLocs.push_back(TorsoGlance);				// 16
	DamLocs.push_back(NeckBase);				// 17
	DamLocs.push_back(LungRib);					// 18
	DamLocs.push_back(Lung);					// 19
	DamLocs.push_back(Heart);					// 20
	DamLocs.push_back(StomachRib);				// 21
	DamLocs.push_back(Stomach);					// 22
	DamLocs.push_back(StomachKidney);			// 23
	DamLocs.push_back(LiverKidney);				// 24
	DamLocs.push_back(LiverSpine);				// 25
	DamLocs.push_back(Intestines);				// 26
	DamLocs.push_back(Spine);					// 27
	DamLocs.push_back(Pelvis);					// 28
	DamLocs.push_back(LegGlance);				// 29
	DamLocs.push_back(ThighFlesh);				// 30
	DamLocs.push_back(ThighBone);				// 31
	DamLocs.push_back(Knee);					// 32
	DamLocs.push_back(ShinFlesh);				// 33
	DamLocs.push_back(ShinBone);				// 34
	DamLocs.push_back(AnkleFoot);				// 35



}