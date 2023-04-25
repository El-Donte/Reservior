#pragma once
class Reservior
{
	char* name;
	char* type;
	double width;
	double len;
	double max_depth;
public: 
	Reservior();
	Reservior(const char* n, const char* t,const double w, const double l,const  double md );
	Reservior(const Reservior& reser);
	~Reservior();

	Reservior& operator=(const Reservior& reser);
	friend bool operator==(const Reservior& reser1, const Reservior& reser2) {
		return reser1.ReserviorSquare() == reser2.ReserviorSquare();
	}

	void SetName(const char* n);
	void SetType(const char* t);
	char* GetName() { return this->name; };
	char* GetType() { return this->type; };
	double GetWidth() { return this->max_depth; };
	double GetLen() { return this->max_depth; };
	double GetMaxDepth() { return this->max_depth; };

	double ReserviorV() const;
	double ReserviorSquare() const;
	static Reservior Add();
	static void Del(Reservior* resers, int index, int size);
	void ShowReserviors();
	static void Save(Reservior* resers, int begin, int end);
	static void Load(Reservior* resers, int begin, int end);

};

