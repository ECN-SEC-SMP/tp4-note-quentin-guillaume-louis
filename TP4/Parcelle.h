#pragma once
#include <string>
#include "Polygone.h"
#include <iostream>

class Parcelle
{
public:
	Parcelle(const Parcelle& parc);
	Parcelle(int num, std::string prop, Polygone<int> forme);
	Parcelle(int num, std::string prop, Polygone<float> forme);

	int getNumero() const;
	std::string getProprietaire() const;
	std::string getType() const;
	float getSurface() const;
	Polygone<float> getForme() const;

	void setNumero(int n);
	void setProprietaire(const std::string& prop);
	void setForme(const Polygone<int>& form);
	virtual void setType(const std::string& type) = 0;

	friend std::ostream& operator<<(std::ostream& os, const Parcelle& parcelle);


private:
	std::string _type;
	int			_numero;
	std::string _propriétaire;
	float		_surface;
	int			_forme;
	int			_pConstructible;
};

