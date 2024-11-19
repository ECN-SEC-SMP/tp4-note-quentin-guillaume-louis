#pragma once
#include "Polygone.h"
#include <string>

class Parcelle
{
public:
	Parcelle(const Parcelle& parc);
	Parcelle(int num, std::string prop, Polygone<int> forme);
	Parcelle(int num, std::string prop, Polygone<float> forme);

	int getNumero() const;
	std::string getPropriétaire() const;
	std::string getType() const;
	float getSurface() const;
	Polygone<float> getForme() const;

	void setNumero(int n);
	void setPropriétaire(std::string prop);
	void setForme(Polygone<int> form);
	void setType(std::string type);

	~Parcelle();

private:

};
