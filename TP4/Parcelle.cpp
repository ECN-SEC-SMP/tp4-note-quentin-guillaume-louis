#include "Parcelle.h"
#include "utility.h"
Parcelle::Parcelle(const Parcelle& parc)
{
	this->_surface			= parc.getSurface();
	this->_type				= parc.getType();
	this->_numero			= parc.getNumero();
	this->_forme			= parc.getForme();
	this->_proprietaire		= parc.getProprietaire();
	this->_pConstructible	= 0;
}

Parcelle::Parcelle(int num, std::string prop, Polygone<int> forme) : _forme(forme), _proprietaire(prop), _numero(num)
{

	this->_surface = 0.0f;
	this->_forme = {};
	this->_pConstructible = 0;
}

int Parcelle::getNumero() const
{
	return this->_numero;
}

std::string Parcelle::getProprietaire() const
{
	return this->_proprietaire;
}

std::string Parcelle::getType() const
{
	return this->_type;
}

float Parcelle::getSurface() const
{
	return this->_surface;
}

Polygone<int> Parcelle::getForme() const
{
	return this->_forme;
}

void Parcelle::setNumero(int n)
{
	this->_numero = n;
}

void Parcelle::setProprietaire(const std::string& prop)
{
	this->_proprietaire = prop;
}

void Parcelle::setForme(const Polygone<int>& form)
{
	this->_forme = form;
	this->_surface = Calcul_surface(form); //met à jour la surface
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
