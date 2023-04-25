#include <iostream>
#include "Reservior.h"

int main()
{
	setlocale(LC_ALL, "");
	Reservior reser1{ "baikal","lake",160.6,150.4,1667.5 };
	Reservior reser2{ "baikal","lfgee",160.6,150.4,1667.5 };
	Reservior* resers = new Reservior[3]{reser1,reser2,Reservior::Add()};

	for (int ii = 0; ii < 3; ii++) {
		resers[ii].ShowReserviors();
		std::cout << std::endl;
	}
	//Reservior::Save(resers, 0, 3);
}