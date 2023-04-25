#include <iostream>
#include "Reservior.h"
#include <fstream>


Reservior::Reservior(const char* n, const char* t, const double w, const double l, const double md) :
	name{(n)? new char[strlen(n)+1]: nullptr},
	type{(t)? new char[strlen(n)+1]: nullptr},
	width{w},len{l},max_depth{md}
{
	SetName(n);
	SetType(t);
}

Reservior::Reservior():
	Reservior(nullptr,nullptr,0,0,0)
{}

Reservior::Reservior(const Reservior& reser)
{
	if (type) delete[]type;
	type = new char[strlen(reser.type) + 1];
	strcpy_s(type, strlen(reser.type) + 1, reser.type);

	if (name) delete[]name;
	name = new char[strlen(reser.name) + 1];
	strcpy_s(name, strlen(reser.name) + 1, reser.name);

	width = reser.width;
	len = reser.len;
	max_depth = reser.max_depth;
	
}

Reservior::~Reservior() {
	delete[] type;
	delete[] name;
}



void Reservior::SetType(const char* t) {
	if (t) {
		if (type) delete[]type;
		type = new char[strlen(t) + 1];
		strcpy_s(type, strlen(t) + 1, t);
	}
}

void Reservior::SetName(const char* n) {
	if (n) {
		if (name) delete[]name;
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
}


double Reservior::ReserviorV() const
{
	return (width * len  * max_depth);

}

double Reservior::ReserviorSquare() const
{
	return (width * len);
}


Reservior Reservior::Add() {
	char* n = new char[150];
	char* t = new char[150];
	double w = 0;
	double l = 0;
	double md = 0;
	std::cout << "Введите имя водоема: "; gets_s(n, 100); std::cout << "\n";
	std::cout << "Введите тип водоема: "; gets_s(t, 100); std::cout << "\n";
	std::cout << "Введите ширину: "; std::cin >> w; std::cout << "\n";
	std::cout << "Введите длину: "; std::cin>>l; std::cout << "\n";
	std::cout << "Введите макс глубину: "; std::cin>>md; std::cout << "\n";
	return Reservior(n, t, w, l, md);
}

void Reservior::Del(Reservior* resers, int index, int size) {
	for (int ii = index; ii < size - 1; ii++) {
		strcpy_s(resers[ii].name, strlen(resers[ii].name) + 1, resers[ii + 1].name);
		strcpy_s(resers[ii].type, strlen(resers[ii].type) + 1, resers[ii + 1].type);
		resers[ii].width = resers[ii + 1].width;
		resers[ii].len = resers[ii + 1].len;
		resers[ii].max_depth = resers[ii + 1].max_depth;
	}
	delete[]resers[size - 1].name;
	delete[]resers[size - 1].type;
	delete &resers[size - 1].len;
	delete &resers[size - 1].width;
	delete &resers[size - 1].max_depth;
}

void Reservior::ShowReserviors() {
	if (name) { std::cout << "название водоема: "; puts(name); } //std::cout << "\n"; }
	if (type) { std::cout << "тип водоема: "; puts(type); }//std::cout << "\n"; }
	if(len){ std::cout << "длина водоема: "<< len; std::cout << "\n"; }
	if(width){ std::cout << "ширина водоема: "<< width; std::cout << "\n"; }
	if(max_depth){ std::cout << "макс глубина водоема: "<< max_depth; std::cout << "\n"; }
}

void Reservior::Load(Reservior* resers, int begin, int end) {
	std::ifstream inf("Reserviors.txt");
	if ("Reserviors.txt") {
		for (int reservior = begin; reservior < end; reservior++) {
			inf >> resers[reservior].name;
			inf >> resers[reservior].type;
			inf >> resers[reservior].len;
			inf >> resers[reservior].width;
			inf >> resers[reservior].max_depth;
		}
		inf.close();
	}
}

void Reservior::Save(Reservior* resers, int begin, int end) {
	std::ofstream outf("Reserviors.txt");
	if ("Reserviors.txt") {
		for (int reservior = begin; reservior < end; reservior++) {
			outf << resers[reservior].name << "\n";
			outf << resers[reservior].type << "\n";
			outf << resers[reservior].len << "\n";
			outf << resers[reservior].width << "\n";
			outf << resers[reservior].max_depth << "\n";
			outf << std::endl;
		}
		outf.close();
	}
}


Reservior& Reservior::operator=(const Reservior& reser) {
	if (this == &reser) { return *this; }

	delete[] name;
	name = new char[strlen(reser.name) + 1];
	strcpy_s(name, strlen(reser.name) + 1, reser.name);

	delete[] type;
	type = new char[strlen(reser.type) + 1];
	strcpy_s(type, strlen(reser.type) + 1, reser.type);
	width = reser.width;
	len = reser.len;
	max_depth = reser.max_depth;

	return *this;
}





