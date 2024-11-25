#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H

#include <string.h>
#include <iostream>


template<typename T>
class Constructible {
public:
	Constructible() = default;
	
	virtual T surfaceConstructible() = 0;
	static virtual std::string typeZone() const = 0;
};

#endif // CONSTRUCTIBLE_H
