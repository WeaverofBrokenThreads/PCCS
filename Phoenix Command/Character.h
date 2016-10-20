#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "main.h"
#include "Weapon.h"

#include "PCCS.h"
#include "APCCS.h"


#define FIND_FMJ_PENETRATION(x)				Weapons[0].FMJPenetration[find_index(x, APCCS.table4DRangeIndex)]
#define FIND_FMJ_DC(x)						Weapons[0].FMJDamageClass[find_index(x, APCCS.table4DRangeIndex)]
#define FIND_JHP_PENETRATION(x)				Weapons[0].JHPPenetration[find_index(x, APCCS.table4DRangeIndex)]
#define FIND_JHP_DC(x)						Weapons[0].JHPDamageClass[find_index(x, APCCS.table4DRangeIndex)]
#define FIND_AP_PENETRATION(x)				Weapons[0].APPenetration[find_index(x, APCCS.table4DRangeIndex)]
#define FIND_AP_DC(x)						Weapons[0].APDamageClass[find_index(x, APCCS.table4DRangeIndex)]

#define FMJ_AMMO							0
#define JHP_AMMO							1
#define AP_AMMO								2

class Character
{
public:

	string name;
	int strength;
	int intelligence;
	int will;
	int health;
	int agility;

	int encumbrance;

	double base_speed;
	int max_speed;

	int SAL; // Skill Accuracy Level
	int ISF; // Intelligence Skill Factor

	int CA; // Combat Actions
	int CAPI[5];      // Combat Actions Per Impulse

	int KV; // Knockout Value

	int skill_level;

	vector<int> SA; // Shot Accuracy
	vector<Weapon> Weapons;

	Character(string, string);
	void find_base_speed();
	void find_max_speed();
	void find_CA();
	void find_CAPI();
	// Calculate Shot Accuracy (SAL + Weapon Aim Time Modifier)
	void calc_SA(Weapon Weapon);
	void get_Weapon(string name);
	void FireWeapon(int ACAiming, vector<int> Shooter_Situations, vector<int> Target_Size, int Visibility, int TargetSpeed, int TargetRange, int FireMode, int AmmoType, int TargetSituation);
	void Character::CheckHit(int Odds, float Pen, int DC, int TargetSituation, string AmmoTypeString, int Range);
	void CheckKnockout(int PD, int SP, int KV, int Health);
	void CheckRecovery(int Damage, int Health);
};

#endif //CHARACTER_H