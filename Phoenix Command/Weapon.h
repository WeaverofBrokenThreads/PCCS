#pragma once
#include "Item.h"

class Weapon : public Item
{
public:

	string Name;
	string WeaponType;
	string WeaponOrigin;
	string Description;
	string Caliber;
	bool ThreeRoundBurst;
	bool SelfLoading;
	int Length;
	double Weight;
	int ReloadTime;
	int RateOfFire;
	int Ammo_Capacity;
	double Ammo_Weight;
	string Feed_Device;
	int Knockdown;
	int SustainedAutomaticBurst;
	vector<double> FMJPenetration;
	vector<int> FMJDamageClass;
	vector<double> JHPPenetration;
	vector<int> JHPDamageClass;
	vector<double> APPenetration;
	vector<int> APDamageClass;
	vector<int> BurstFire;

	int EffectiveRange;

	vector<double> Minimum_Arc;
	vector<int> Ballistic_Accuracy;
	vector<int> TimeOfFlight;

	int MaxAimTime;
	vector<int> AimTimeMod;

	Weapon::Weapon();
	Weapon::Weapon(int Len, int Wei, int Ammo_Cap, double Ammo_Wei, int KD, vector<double>FMJPen, vector<double>JHPPen, vector<double>APPen, vector<int> FMJDC, vector<int> JHPDC, vector<int> APDC, vector<double> MA, vector<int> BA, vector<int> TOF, int ER, int MAT, int RT, int SAB, int ROF, bool TRB, bool SL, string name, string desc, string type, string origin, string FD, vector<int> ATM, string Cal);
	Weapon::Weapon(string object);
};