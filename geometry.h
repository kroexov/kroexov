#ifndef C___LAB_2_SEMESTER_GEOMETRY_H
#define C___LAB_2_SEMESTER_GEOMETRY_H
#include <vector>
#define vec std::vector<Point>

class Point
{
private:
    double x;
    double y;
public:
    Point();
    Point(double x, double y);
    Point(const Point &point1);
    Point& operator=(const Point &point);
    void get();
    double getX() const;
    double getY() const;
    void set(double x, double y);

};

class PolygonalChain{
private:
    int number_of_points;
    vec points;
public:
    PolygonalChain(int n,Point* fig);

    PolygonalChain& operator=(const PolygonalChain &chain);

    PolygonalChain(const PolygonalChain &chain);

    void get();
    int getN() const;
    Point getPoint(int n) const;

    virtual float perimeter() const;
};

class ClosedPolygonalChain:public PolygonalChain{
private:
    int number_of_points;
    vec points;
public:
    ClosedPolygonalChain(int n,Point* fig);

    ClosedPolygonalChain& operator=(const ClosedPolygonalChain &chain);

    ClosedPolygonalChain(const ClosedPolygonalChain &chain);

    float perimeter() const;
};

class Polygon{
private:
    int number_of_points;
    vec points;
public:
    Polygon(int n,Point* fig);

    Polygon(const Polygon &fig);

    Polygon& operator=(const Polygon &fig);

    void get();

    Point getPoint(int n);

    virtual float perimeter();

    virtual float area() const;
};

class RegularPolygon:public Polygon{
private:
    int number_of_points;
    vec points;
public:
    RegularPolygon(int n,Point* fig);

    RegularPolygon(const RegularPolygon &fig);

    RegularPolygon& operator=(const RegularPolygon &fig);

    bool regular();

};

class Triangle:public Polygon{
private:
    int number_of_points=3;
    vec points;
public:
    Triangle(int n,Point* fig);

    Triangle(const Triangle &fig);

    Triangle& operator=(const Triangle &fig);

    float height();

    float area();

    bool hasRightAngle() const;

};

class Trapezoid:public Polygon{
private:
    int number_of_points=4;
    vec points;
public:
    Trapezoid (int n,Point* fig);
    Trapezoid (const Trapezoid &fig);
    Trapezoid& operator=(const Trapezoid &fig);
    float height() const;
    float area() const;
};






#endif //C___LAB_2_SEMESTER_GEOMETRY_H
