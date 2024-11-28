#pragma once

#ifndef ZN_H
#define ZN_H

#include "Constructible.h"

using std::string;

template<typename T>
class ZN : public Constructible<T> {
public:
	ZN() = delete;
	explicit ZN(const Parcelle& p, T surfaceConstruite = 0);
	~ZN();

	T surfaceConstructible() override;
	void setSurfaceConstruite(const T& surfaceConstructible);

	static string typeZone() override {
		return string("Zone Naturelle");
	}

protected:
	Parcelle* parcelle_;
	T surfaceConstruite_;
};

template<typename T>
ZN<T>::ZN(const Parcelle& p, T surfaceConstruite)
{
	parcelle_ = &p;
	surfaceConstruite_ = surfaceConstruite;
}

template<typename T>
ZN<T>::~ZN() {
	parcelle_ = nullptr;
}

template<typename T>
T ZN<T>::surfaceConstructible() {
	return (T) 0;
}

template<typename T>
void ZN<T>::setSurfaceConstruite(const T& surfaceConstructible) {
}

#endif // ZN_H