#ifndef ZU_H
#define ZU_H

#include "Constructible.h"

using std::string;

template<typename T>
class ZU : public Constructible<T>
{
public:
	ZU() = delete;
	explicit ZU(int num, std::string prop, Polygone<T> forme);

	T surfaceConstructible() override;
	void setSurfaceConstruite(const T& surfaceConstructible);
	T constructible() const;

	virtual void affiche(std::ostream& os) override {
		os << "Parcelle Numero: " << this->getNumero() << "\n";
		os << "Type: " << this->getType() << "\n";
		os << "Polygone: " << "\n";
		os << "Proprietaire: " << this->getProprietaire() << "\n";
		os << "Surface: " << this->getSurface() << " m²\n";
		os << "% constructible: " << this->constructible() << " m²\n";
		os << "Surface construite: " << this->surfaceConstruite_ << "\n";
		os << "Surface a construire restante: " << this->surfaceConstructible() << "\n";
	}

protected:
	T surfaceConstruite_;
};

template<typename T>
ZU<T>::ZU(int num, std::string prop, Polygone<T> forme) : Constructible<T>(num, prop, forme)
{
	surfaceConstruite_ = 0;
	this->setType("ZU");
}

template<typename T>
T ZU<T>::surfaceConstructible() {
	return this->getSurface() - surfaceConstruite_;
}

template<typename T>
void ZU<T>::setSurfaceConstruite(const T& surfaceConstructible) {
	surfaceConstruite_ = surfaceConstructible;
}

template<typename T>
T ZU<T>::constructible() const {
	return (1 - (surfaceConstruite_ / this->getSurface()));
}

#endif // ZU_H