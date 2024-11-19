#include "Point2D.h"

template<typename T>
Point2D<T>::Point2D(T x, T y) : x_(x), y_(y) {

}

template<typename T>
Point2D<T>::Point2D(Point2D<T> const& autre) : x_(autre.x_), y_(autre.y_) {
  
}

template<typename T>
T Point2D<T>::getX() const {
  return this->x_;
}

template<typename T>
T Point2D<T>::getY() const {
  return this->y_;
}

template<typename T>
void Point2D<T>::setX(const T x) {
  this->x_ = x;
}

template<typename T>
void Point2D<T>::setY(const T y) {
  this->y_ = y;
}
