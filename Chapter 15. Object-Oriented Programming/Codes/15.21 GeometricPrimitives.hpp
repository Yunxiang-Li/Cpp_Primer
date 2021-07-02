#ifndef GEOMETRICPRIMITIVES_HPP
#define GEOMETRICPRIMITIVES_HPP

static const float PI = 3.1415f;

class Shape {
 public:
  virtual const char* shapeName() const = 0;
  virtual void resize_by_percentage(float percent) = 0;

  virtual ~Shape() {}
};

class Shape_2D : public Shape {
 public:
  Shape_2D() = default;
  Shape_2D(float x, float y) : mXSize(x), mYSize(y) {}

  virtual float area() const = 0;
  virtual float diameter() const = 0;
  virtual float circumference() const = 0;

  virtual ~Shape_2D() override {}

 protected:
  float mXSize{0.f};
  float mYSize{0.f};

};

class Shape_3D : public Shape {

 public:
  Shape_3D() = default;
  Shape_3D(float x, float y, float z) : mXSize(x), mYSize(y), mZSize(z) {}

  virtual float volume() const = 0;
  virtual ~Shape_3D() override {}

 private:
  float mXSize{0.f};
  float mYSize{0.f};
  float mZSize{0.f};
};

class Box : public Shape_3D {
 public:
  Box() = default;
  explicit Box(float width) : mHalf_len_x(width * 0.5f), mHalf_len_y(width * 0.5f), mHalf_len_z(width * 0.5f) {}
  Box(float center_x, float center_y, float center_z, float len_x, float len_y, float len_z) :
  Shape_3D(center_x, center_y, center_z), mHalf_len_x(len_x * 0.5f), mHalf_len_y(len_y * 0.5f),
  mHalf_len_z(len_z * 0.5f) {}

  inline virtual const char* shapeName() const override { return "Box"; }
  inline virtual void resize_by_percentage(float percent) override
  {
      mHalf_len_x *= percent;
      mHalf_len_y *= percent;
      mHalf_len_z *= percent;
  }

  inline float volume() const override
  {
      return mHalf_len_x * mHalf_len_y * mHalf_len_z * 8;
  }

  virtual ~Box() override {}

 protected:
  float mHalf_len_x = 0.5f;
  float mHalf_len_y = 0.5f;
  float mHalf_len_z = 0.5f;
};

class Circle : public Shape_2D {
 public:
  Circle() = default;
  explicit Circle(float radius) : mRadius(radius) {}

  Circle(float center_x, float center_y, float radius) : Shape_2D(center_x, center_y), mRadius(radius) {}

  inline virtual float area() const override
  {
      return PI * mRadius * mRadius;
  }

  inline virtual float diameter() const override
  {
      return 2 * mRadius;
  }

  inline virtual float circumference() const override
  {
      return 2 * PI * mRadius;
  }

  inline virtual const char* shapeName() const override
  {
      return "Circle";
  }

  inline virtual void resize_by_percentage(float pct) override
  {
      mRadius *= pct;
  }

  virtual ~Circle() override {}

 protected:
  float mRadius = 1.f;
};

class Sphere : public Shape_3D {
 public:
  Sphere() = default;
  explicit Sphere(float radius) : radius_(radius) {}
  Sphere(float center_x, float center_y, float center_z, float radius) : Shape_3D(center_x, center_y, center_z), radius_(radius) {}

  inline virtual const char* shapeName() const override { return "Sphere"; }
  inline virtual void resize_by_percentage(float pct) override { radius_ *= pct; }

  inline float volume() const override { return 4 * PI * radius_ * radius_ * radius_ / 3; }

  virtual ~Sphere() override {}

 protected:
  float radius_ = 1.f;
};

class Cone : public Shape_3D {
 public:
  Cone() = default;
  Cone(float radius, float height) : radius_(radius), height_(height) {}
  Cone(float center_x, float center_y, float center_z, float radius, float height) : Shape_3D(center_x, center_y, center_z), radius_(radius), height_(height) {}

  inline virtual const char* shapeName() const override { return "Cone"; }
  inline virtual void resize_by_percentage(float pct) override { radius_ *= pct; height_ *= pct; }

  inline float volume() const override { return PI * radius_ * radius_ * height_ / 3; }

  virtual ~Cone() override {}

 protected:
  float radius_ = 1.f;
  float height_ = 1.f;
};

#endif
