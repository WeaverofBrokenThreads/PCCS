#include "Pistols.h"

Weapon::Weapon(string object)
{
	/*
	// SIG P226
	*/

	if (object == "P226")
	{
		Name = "SIG P226";
		WeaponType = "Semi-Automatic Pistol";
		WeaponOrigin = "Switzerland";
		Description = "Well balanced, large capacity version of the SIG P220 with ambidextrous magazine catch.";
		Caliber = "9x19mm";
		ThreeRoundBurst = true;
		SelfLoading = true;
		Length = 7;
		Weight = 3.2;
		ReloadTime = 4;
		RateOfFire = 1;
		Ammo_Capacity = 15;
		Ammo_Weight = 0.55;
		Feed_Device = "Magazine";
		Knockdown = 3;
		SustainedAutomaticBurst = 4;
		FMJPenetration = { 1.9, 1.8, 1.5, 1.1, 0.9, 0.4, 0.1, 0.1 };
		FMJDamageClass = { 3,   3,   2,   2,   1,   1,   1,   1 };
		JHPPenetration = { 1.9, 1.7, 1.4, 1.1, 0.8, 0.3, 0.1, 0.1 };
		JHPDamageClass = { 4,   4,   3,   2,   1,   1,   1,   1 };
		APPenetration = { 2.7, 2.5, 2.1, 1.6, 1.2, 0.5, 0.2, 0.1 };
		APDamageClass = { 3,   2,   2,   2,   1,   1,   1,   1 };
		BurstFire;

		EffectiveRange = 5;

		Minimum_Arc;
		Ballistic_Accuracy = { 45, 37, 28, 21, 16, 6, 1, -2 };
		TimeOfFlight = { 1, 1, 2, 4, 6, 15, 25, 36 };

		MaxAimTime = 6;
		AimTimeMod = { -17, -11, -10, -9, -8, -7 };
	}

}