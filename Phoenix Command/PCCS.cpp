#pragma once
#include "PCCS.h"

/*

########################################################################
########################################################################
                           THIS IS OBSOLETE
########################################################################
########################################################################

*/

hitroll::hitroll(int min, int max, string limbname, string hitloc, int LVDamage, string LVDesc, int OPDC1, int OPDC2, int OPDC3, string OPDesc1, string OPDesc2, string OPDesc3)
{
	minrange = min;
	maxrange = max;
	limb = limbname;
	locname = hitloc;
	LVD = LVDamage;
	desc = LVDesc;
	OPDC[0] = OPDC1;
	OPDC[1] = OPDC2;
	OPDC[2] = OPDC3;
	OPDesc[0] = OPDesc1;
	OPDesc[1] = OPDesc2;
	OPDesc[2] = OPDesc3;
}

PCCS::PCCS()
{
	ConstructFACtable();
	ConstructITOtable();
}

struct PCCS PCCS;

void PCCS::ConstructFACtable()
{
	hitroll Head_Glance(0, 2, "Head", "Glance", 7, "Light Injury", 200, 1000, 80000, "Critical Injury", "Critical Injury", "Critical Injury");
	hitroll Head_Forehead(3, 17, "Head", "Forehead", 2000, "Critical Injury", 60000, 0, 0, "Critical Injury", "Fatal Injury", "Fatal Injury");
	hitroll Head_Eye_Nose(18, 22, "Head", "Eye - Nose", 3000, "Critical Injury", 80000, 0, 0, "Critical Injury", "Fatal Injury", "Fatal Injury");
	hitroll Head_Mouth(23, 38, "Head", "Mouth", 300, "Critical Injury", 6000, 30000, 0, "Critical Injury", "Critical Injury", "Fatal Injury");
	hitroll Arm_Glance(39, 56, "Arm", "Glance", 1, "Superficial Injury", 5, 11, 32, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Shoulder(57, 69, "Arm", "Shoulder", 21, "Disabling Injury", 500, 1000, 1000, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Upper_Flesh(70, 76, "Arm", "Upper Arm - Flesh", 3, "Superficial Injury", 12, 100, 100, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Upper_Bone(77, 80, "Arm", "Upper Arm - Bone", 7, "Disabling Injury", 60, 100, 100, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Fore_Flesh(81, 83, "Arm", "Forearm - Flesh", 3, "Superficial Injury", 12, 50, 50, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Fore_Bone(84, 92, "Arm", "Forearm - Bone", 6, "Disabling Injury", 60, 60, 60, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Hand(93, 95, "Arm", "Hand", 3, "Superficial Injury", 8, 15, 15, "Disabling Injury", "Disabling Injury", "Disabling Injury");
	hitroll Arm_Weapon(96, 99, "Arm", "Weapon", 0, "Weapon Critical", 0, 0, 0, "Weapon Critical", "Weapon Critical", "Weapon Critical");

	FAChitloc.push_back(Head_Glance);
	FAChitloc.push_back(Head_Forehead);
	FAChitloc.push_back(Head_Eye_Nose);
	FAChitloc.push_back(Head_Mouth);
	FAChitloc.push_back(Arm_Glance);
	FAChitloc.push_back(Arm_Shoulder);
	FAChitloc.push_back(Arm_Upper_Flesh);
	FAChitloc.push_back(Arm_Upper_Bone);
	FAChitloc.push_back(Arm_Hand);
	FAChitloc.push_back(Arm_Weapon);

}

void PCCS::ConstructITOtable()
{
	hitroll Head_Glance(0, 0, "Head", "Glance", 7, "Light Injury", 200, 1000, 80000, "Critical Injury", "Critical Injury", "Critical Injury");
	hitroll Head_Forehead(1, 2, "Head", "Forehead", 2000, "Critical Injury", 60000, 0, 0, "Critical Injury", "Fatal Injury", "Fatal Injury");
	hitroll Head_Eye_Nose(3, 3, "Head", "Eye - Nose", 3000, "Critical Injury", 80000, 0, 0, "Critical Injury", "Fatal Injury", "Fatal Injury");
	hitroll Head_Mouth(4, 5, "Head", "Mouth", 300, "Critical Injury", 6000, 30000, 0, "Critical Injury", "Critical Injury", "Fatal Injury");
	hitroll Arm_Glance(6, 8, "Arm", "Glance", 1, "Superficial Injury", 5, 11, 32, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Shoulder(9, 10, "Arm", "Shoulder", 21, "Disabling", 500, 1000, 1000, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Upper_Flesh(11, 11, "Arm", "Upper Arm - Flesh", 3, "Superficial Injury", 12, 100, 100, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Upper_Bone(12, 12, "Arm", "Upper Arm - Bone", 7, "Disabling", 60, 100, 100, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Fore_Flesh(13, 13, "Arm", "Forearm - Flesh", 3, "Superficial Injury", 12, 50, 50, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Fore_Bone(14, 14, "Arm", "Forearm - Bone", 6, "Disabling", 60, 60, 60, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Hand(15, 15, "Arm", "Hand", 3, "Superficial Injury", 8, 15, 15, "Disabling", "Disabling", "Disabling");
	hitroll Arm_Weapon(16, 16, "Arm", "Weapon", 0, "Weapon Critical", 0, 0, 0, "Weapon Critical", "Weapon Critical", "Weapon Critical");
	hitroll Body_Glance(17, 19, "Body", "Glance", 1, "Superficial Injury", 7, 16, 47, "Light Injury", "Medium Injury", "Heavy Injury");
	hitroll Body_Chest(20, 23, "Body", "Chest", 51, "Heavy Injury", 100, 300, 2000, "Critical Injury", "Critical Injury", "Critical Injury");
	hitroll Body_Base_Neck(24, 24, "Body", "Base of Neck", 300, "Critical Injury", 6000, 40000, 0, "Critical Injury", "Critical Injury", "Fatal Injury");
	hitroll Body_Heart(25, 25, "Body", "Heart", 4000, "Critical Injury", 100000, 0, 0, "Critical Injury", "Fatal Injury", "Fatal Injury");
	hitroll Body_Spine(26, 30, "Body", "Spine", 300, "Critical Injury", 5000, 30000, 0, "Critical Injury", "Critical Injury", "Fatal Injury");
	hitroll Body_Abdomen(31, 42, "Body", "Abdomen", 35, "Heavy Injury", 900, 5000, 3000, "Critical Injury", "Critical Injury", "Critical Injury");
	hitroll Body_Pelvis(43, 56, "Body", "Pelvis", 21, "Medium Injury", 100, 500, 4000, "Critical Injury", "Critical Injury", "Critical Injury");
	hitroll Leg_Glance(57, 60, "Leg", "Glance", 1, "Superficial Injury", 7, 16, 47, "Disabling", "Disabling", "Disabling");
	hitroll Leg_Thigh_Flesh(61, 77, "Leg", "Thigh - Flesh", 3, "Superficial Injury", 88, 500, 600, "Disabling", "Disabling", "Disabling");
	hitroll Leg_Thigh_Bone(78, 82, "Leg", "Thigh - Bone", 16, "Disabling", 400, 700, 700, "Disabling", "Disabling", "Disabling");
	hitroll Leg_Shin_Foot(83, 99, "Leg", "Shin - Foot", 14, "Disabling", 200, 200, 200, "Disabling", "Disabling", "Disabling");

	ITOhitloc.push_back(Head_Glance);
	ITOhitloc.push_back(Head_Forehead);
	ITOhitloc.push_back(Head_Eye_Nose);
	ITOhitloc.push_back(Head_Mouth);
	ITOhitloc.push_back(Arm_Glance);
	ITOhitloc.push_back(Arm_Shoulder);
	ITOhitloc.push_back(Arm_Upper_Flesh);
	ITOhitloc.push_back(Arm_Upper_Bone);
	ITOhitloc.push_back(Arm_Hand);
	ITOhitloc.push_back(Body_Glance);
	ITOhitloc.push_back(Body_Chest);
	ITOhitloc.push_back(Body_Base_Neck);
	ITOhitloc.push_back(Body_Heart);
	ITOhitloc.push_back(Body_Spine);
	ITOhitloc.push_back(Body_Abdomen);
	ITOhitloc.push_back(Body_Pelvis);
	ITOhitloc.push_back(Leg_Glance);
	ITOhitloc.push_back(Leg_Thigh_Flesh);
	ITOhitloc.push_back(Leg_Thigh_Bone);
	ITOhitloc.push_back(Leg_Shin_Foot);

}

