#include "Parcelle.h"

Parcelle::Parcelle(const Parcelle& parc)
{
}

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme)
{
}

int Parcelle::getNumero() const
{
	return 0;
}

std::string Parcelle::getProprietaire() const
{
	return std::string();
}

std::string Parcelle::getType() const
{
	return std::string();
}

float Parcelle::getSurface() const
{
	return 0.0f;
}

Polygone<float> Parcelle::getForme() const
{
	return Polygone<float>();
}

void Parcelle::setNumero(int n)
{
}

void Parcelle::setProprietaire(const std::string& prop)
{
}

void Parcelle::setForme(const Polygone<int>& form)
{
}

std::ostream& operator<<(std::ostream& os, const Parcelle& parcelle) {
	os << "Parcelle Information:\n";
	os << "Type: " << parcelle.getType() << "\n";
	os << "Numero: " << parcelle.getNumero() << "\n";
	os << "Proprietaire: " << parcelle.getProprietaire() << "\n";
	os << "Surface: " << parcelle.getSurface() << " m²\n";
	//os << "Pourcentage Constructible: " << parcelle.getPConstructible() << "%\n";
	//os << "Forme: " << parcelle.getForme() << "\n"; // Assuming Polygone has operator<< overloaded
	return os;
}