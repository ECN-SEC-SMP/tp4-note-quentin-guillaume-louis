#ifndef POINT2D_H
#define POINT2D_H

#include<ostream>

template<typename T>
class Point2D {
public:
  Point2D() = default;
  explicit Point2D(T x, T y);
  Point2D(Point2D<T> const& autre);

  T getX() const;
  T getY() const;

  void setX(const T x);
  void setY(const T y);

  void translate(T x, T y);

protected:
  T x_;
  T y_;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point2D<T>& dt) {
  
    os << "X : " << dt.getX() << std::endl << "Y : " << dt.getY();
    return os;
}

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

#endif // POINT2D_H