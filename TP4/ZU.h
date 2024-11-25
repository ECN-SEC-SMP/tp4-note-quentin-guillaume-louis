#ifndef ZU_H
#define ZU_H

#include "Constructible.h"

using std::string;

template<typename T>
class ZU : public Constructible<T> {
public:
	ZU() = default;
	ZU(T value);

	T surfaceConstructible() override;

	static string typeZone() override {
		return string("Zone Urbaine");
	}

protected:
	T surface_;
};

template<typename T>
ZU<T>::ZU(T value)
{

}

template<typename T>
T ZU<T>::surfaceConstructible() {
	//FINIR
}


#endif // ZU_H