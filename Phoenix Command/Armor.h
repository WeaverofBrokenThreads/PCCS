#pragma once
#include "Item.h"

class Armor : public Item
{
	int PF;                          // Protection Factor
	int BPF;                         // Blunt Protection Factor
	string wear_loc;                 // Visor, Head, Body
};