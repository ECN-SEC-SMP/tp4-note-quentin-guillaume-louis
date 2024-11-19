#ifndef POINT2D_H
#define POINT2D_H

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

#endif // POINT2D_H