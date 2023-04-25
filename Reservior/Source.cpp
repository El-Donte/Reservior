#include <iostream>
#include "Reservior.h"

int main()
{
	setlocale(LC_ALL, "");

	Reservior* resers = new Reservior[4];
	resers[0] = { "baikal","lake",160.6,150.4,1667.5 };
	resers[1] = { "","",0,0,0 };
	resers[2] = { "gww","lake",160.6,150.4,1667.5 };
	
	

	

	for (int ii = 0; ii < 4; ii++) {
		resers[ii].ShowReserviors();
		std::cout << std::endl;
	}


	

	//Reservior::Save(resers, 0, 3);
}