#ifndef CONSTRUCTIBLE_H
#define CONSTRUCTIBLE_H



template<typename T>
class Constructible {
public:
	Constructible() = default;
	
	virtual T surfaceConstructible() = 0;
	
};

#endif // CONSTRUCTIBLE_H
