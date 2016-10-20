#pragma once
#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::Weapon(int Len, int Wei, int Ammo_Cap, double Ammo_Wei, int KD, vector<double> FMJPen, vector<double> JHPPen, vector<double> APPen, vector<int> FMJDC, vector<int> JHPDC, vector<int> APDC, vector<double> MA, vector<int> BA, vector<int> TOF, int ER, int MAT, int RT, int SAB, int ROF, bool TRB, bool SL, string name, string desc, string type, string origin, string FD, vector<int> ATM, string Cal)
{
	Name = name;
	Length = Len;
	Weight = Wei;
	Ammo_Capacity = Ammo_Cap;
	Ammo_Weight = Ammo_Wei;
	Knockdown = KD;
	FMJPenetration = FMJPen;
	JHPPenetration = JHPPen;
	APPenetration = APPen;
	FMJDamageClass = FMJDC;
	JHPDamageClass = JHPDC;
	APDamageClass = APDC;
	Minimum_Arc = MA;
	Ballistic_Accuracy = BA;
	TimeOfFlight = TOF;
	ReloadTime = RT;
	SustainedAutomaticBurst = SAB;
	AimTimeMod = ATM;
	Description = desc;
	WeaponType = type;
	WeaponOrigin = origin;
	Feed_Device = FD;
	Caliber = Cal;
	RateOfFire = ROF;
	ThreeRoundBurst = TRB;
	SelfLoading = SL;
	EffectiveRange = ER;
	MaxAimTime = MAT;
}