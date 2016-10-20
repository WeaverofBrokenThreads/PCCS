#pragma once

#include "Character.h"

Character::Character(string text, string skilldesc)
{
	name = text;

	strength = roll(6, 2, 1) + 6;
	intelligence = roll(6, 2, 1) + 6;
	will = roll(6, 2, 1) + 6;
	health = roll(6, 2, 1) + 6;
	agility = roll(6, 2, 1) + 6;

	if (skilldesc == "Civ") skill_level = 0;
	else if (skilldesc == "Trained Civ") skill_level = roll(2, 1, 1);			// 1 - 2 SL
	else if (skilldesc == "Soldier") skill_level = roll(2, 1, 1) + 2;			// 3 - 4 SL
	else if (skilldesc == "Elite") skill_level = roll(4, 1, 1) + 4;			// 5 - 8 SL
	else if (skilldesc == "Special Forces") skill_level = roll(4, 1, 1) + 8;	// 9 - 12 SL
	else if (skilldesc == "Legendary") skill_level = roll(8, 1, 1) + 12;		// 13 - 20 SL

																			// Dumb if block to accomodate the writer's flawed logic where 0.5 x KV x 0 is equal to 5 at 10 Will
	if (skill_level == 0)
	{
		KV = will * 0.5 * 1;
	}
	else
	{
		KV = will * 0.5 * skill_level;
	}
	// End dumb if block.
	SAL = PCCS.skill_accuracy_table[skill_level];
	ISF = intelligence + SAL;
	find_base_speed();
	find_max_speed();
	find_CA();
	find_CAPI();

}

void Character::find_base_speed()
{
	int index = find_index(encumbrance, PCCS.BST_enc_index);
	base_speed = PCCS.base_speed_table[strength][index];
}

void Character::find_max_speed()
{
	int index = find_index(base_speed, PCCS.MST_base_index);
	max_speed = PCCS.max_speed_table[agility][index];

}

void Character::find_CA()
{
	int index = find_index(ISF, PCCS.CA_ISF_index);
	CA = PCCS.CA_table[max_speed][index];
}

void Character::find_CAPI()
{
	for (int i = 0; i < 5; i++)
	{
		CAPI[i] = PCCS.CAPI_table[CA][i];
	}
}

// Calculate Shot Accuracy (SAL + Weapon Aim Time Modifier)
void Character::calc_SA(Weapon Weapons)
{
	SA = Weapons.AimTimeMod;
	for (unsigned int i = 0; i < Weapons.AimTimeMod.size(); i++)
	{
		SA[i] = Weapons.AimTimeMod[i] + SAL;
		cout << "Aim Time " << i+1 << ": " << SA[i] << endl;
	}

}

void Character::get_Weapon(string name)
{
	if (name == "SIG P226")
	{
		Weapons.push_back(Weapon("P226"));
	}
	
}

void Character::FireWeapon(int ACAiming, vector<int> Shooter_Situations, vector<int> Target_Size, int Visibility, int TargetSpeed, int TargetRange, int FireMode, int AmmoType, int TargetSituation)
{
	int Accuracy_Level = SA[ACAiming-1];

	int TargetMovingMod;
	if (TargetSpeed == TARGET_STATIONARY)
		TargetMovingMod = 0;
	else
		TargetMovingMod = TARGET_MOVING(TargetSpeed, TargetRange);
	int TargetRangeMod = TARGET_RANGE_MODIFIER(TargetRange);
	int Initial_EAL = Accuracy_Level + Visibility + TargetMovingMod + TargetRangeMod;

	int EAL = Initial_EAL;
	for(auto x : Shooter_Situations)
		EAL += x;
	for(auto x : Target_Size)
		EAL += x;
	
	int Odds_Of_Hitting = 0;

	if (FireMode == FIREMODE_SINGLESHOT)
	{
		Odds_Of_Hitting = SINGLESHOT_HITCHANCE(EAL);
	}

	if (FireMode == FIREMODE_BURSTFIRE)
	{
		Odds_Of_Hitting = BURSTFIRE_HITCHANCE(EAL);
	}

	cout << "################################################################################" << endl;
	cout << "Using Weapon: " << Weapons[0].Name << endl;
	cout << "Shooter Accuracy Level: " << Accuracy_Level << endl;
	cout << "Effective Accuracy Level: " << EAL << endl;
	cout << "Odds of Hitting: " << Odds_Of_Hitting << endl;

	float Pen = 0;
	int DC = 0;
	string AmmoTypeString;

	if (AmmoType == FMJ_AMMO)
	{
		Pen = FIND_FMJ_PENETRATION(TargetRange);
		DC = FIND_FMJ_DC(TargetRange);
		AmmoTypeString = "FMJ";
	}
	if(AmmoType == JHP_AMMO)
	{
		Pen = FIND_JHP_PENETRATION(TargetRange);
		DC = FIND_JHP_DC(TargetRange);
	}
	if(AmmoType == AP_AMMO)
	{
		Pen = FIND_AP_PENETRATION(TargetRange);
		DC = FIND_AP_DC(TargetRange);
	}

	cout << endl << "Checking Hit using " << Weapons[0].Caliber << " " << AmmoTypeString << " Ammo" << endl;
	CheckHit(Odds_Of_Hitting, Pen, DC, TargetSituation, AmmoTypeString, TargetRange);

}

void Character::CheckHit(int Odds, float Pen, int DC, int TargetSituation, string AmmoTypeString, int Range)
{

	int HitRoll = roll(100, 1);
	cout << "Rolled: " << HitRoll << " vs " << Odds << endl;
	cout << endl;
	
	if (HitRoll <= Odds)
	{
		int HitLocRoll = roll(100, 1);
		if (TargetSituation == TARGET_EXPOSED)
		{
			for (auto x : APCCS.DamLocs)
			{
				if (x.Open[0] <= HitLocRoll && x.Open[1] >= HitLocRoll)
				{
					int DamageDone = x.DC[DC][find_index(Pen, x.EPENindex[DC])];
					int ShockPoints = 0;
					cout << "Target hit!" << endl << endl;
					cout << "Hit location: " << x.hitloc << endl;

					cout << endl << Weapons[0].Caliber << " " << AmmoTypeString << " Penetration at " << Range << " meters: " << Pen << endl;
					cout << "Weapon Damage Class at " << Range << " meters: " << DC << endl << endl;
					cout << "Damage Inflicted: " << DamageDone << endl;

					CheckKnockout(DamageDone, ShockPoints, KV, health);
				}
			}
		}
	}
	else
	{
		cout << "Target missed." << endl;
		return;
	}

}

void Character::CheckKnockout(int PD, int SP, int KV, int Health)
{
	cout << endl;
	cout << "Checking for Knockout" << endl;
	cout << "Target KV: " << KV << endl;
	int Damage = PD + SP;
	int chance = 0;
	if(Damage <= KV / 10)
		chance = -1;							// NA
	if(Damage >= KV / 10 && Damage <= KV)
		chance = 10;
	if(Damage >= KV && Damage <= KV * 2)
		chance = 25;
	if(Damage >= KV * 2 && Damage <= KV * 3)
		chance = 75;
	if(Damage >= KV * 3)
		chance = 98;

	int Roll = roll(100, 1);
	if (Roll <= chance)
	{
		cout << "Target knocked out!" << endl;
		CheckRecovery(PD, Health);
	}
	else
		cout << "Target remains conscious." << endl;
}

void Character::CheckRecovery(int Damage, int Health)
{
	int DT = Damage * 10 / Health;
	int CTP = FIND_RECOVERY_CTP(DT);
	int RR = FIND_RECOVERY_RR(DT);
	int RRroll = roll(100, 1);
	if (CTP <= 200)
	{
		cout << "Target is critical";
		
		if (RRroll <= RR)
		{
			cout << " but will survive." << endl;
		}
		else
			cout << " and will bleed out in " << CTP << " seconds." << endl;
	}
	else if (CTP <= 2 * 3600)
	{
		cout << "Target is heavily wounded." << endl;
		if (RRroll <= RR)
		{
			cout << "Target will survive." << endl;
		}
		else
			cout << "Target must find aid in " << CTP / 60 << " minutes, or will die." << endl;
	}
	else if (CTP <= 48 * 3600)
	{
		cout << "Target is wounded." << endl;
		if (RRroll <= RR)
		{
			cout << "Target will survive." << endl;
		}
		else
			cout << "Target must find aid in " << CTP / 3600 << " hours, or will die." << endl;
	}

	else
	{
		cout << "Target is wounded, and should seek medical aid within " << CTP / 3600 << " hours or complications may arise." << endl;
	}
}