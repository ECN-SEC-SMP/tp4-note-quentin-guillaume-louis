#ifndef ZU_H
#define ZU_H

#include "Constructible.h"

using std::string;

template<typename T>
class ZU : public Constructible<T> {
public:
	ZU() = delete;
	ZU(const Parcelle& p, T surfaceConstruite = 0);
	~ZU();

	T surfaceConstructible() override;
	void setSurfaceConstruite(const T& surfaceConstructible) const;

	static string typeZone() override {
		return string("Zone Urbaine");
	}

protected:
	Parcelle* parcelle_;
	T surfaceConstruite_;
};

template<typename T>
ZU<T>::ZU(const Parcelle& p, T surfaceConstruite)
{
	parcelle_ = &p;
	surfaceConstruite_ = surfaceConstruite;
}

template<typename T>
ZU<T>::~ZU() {
	parcelle_ = nullptr;
}

template<typename T>
T ZU<T>::surfaceConstructible() {
	return parcelle_->getSurface() - surfaceConstruite_;
}

template<typename T>
void ZU<T>::setSurfaceConstruite(const T& surfaceConstructible) const {
	surfaceConstruite_ = surfaceConstructible;
}

#endif // ZU_H