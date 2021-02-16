#include "geometry.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>
#define vec std::vector<Point>

    Point::Point() //конструктор со значениями по умолчанию
    {
        x=0;
        y=0;
    }

    Point::Point(double x, double y) //конструктор с заданными значениями
    {
        this->x=x;
        this->y=y;
    }

    Point::Point(const Point &point1) //конструктор копирования
    {
        x=point1.x;
        y=point1.y;
    }
    Point& Point::operator=(const Point &point){ //оператор присваивания
        x = point.x;
        y = point.y;
    }
    void Point::get()
    {
        std::cout<<"x: "<<x<<"\ny: "<<y<<std::endl;
    }
    double Point::getX() const {
        return x;
    }
    double Point::getY() const {
        return y;
    }
    void Point::set(double x, double y)
    {
        this->x=x;
        this->y=y;
    }



PolygonalChain::PolygonalChain(int n,Point* fig) //конструктор
    {
        number_of_points=n;
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

PolygonalChain&PolygonalChain:: operator=(const PolygonalChain &chain){ //оператор присваивания
        points.clear();
        number_of_points=chain.number_of_points;
        for (int i=0;i<chain.number_of_points;i++){
            points.push_back(chain.points[i]);
        }
    }

PolygonalChain::PolygonalChain(const PolygonalChain &chain) //конструктор копирования
    {
        points.clear();
        number_of_points=chain.number_of_points;
        for (int i=0;i<chain.number_of_points;i++){
            points.push_back(chain.points[i]);
        }
    }

    void PolygonalChain::get()
    {
        std::cout<<"number: "<<number_of_points<<std::endl;
        for (int i=0;i<number_of_points;i++){
            std::cout<<"point "<<i<<": "<<points[i].getX()<<" "<<points[i].getY()<<std::endl;
        }
    }

    Point PolygonalChain::getPoint(int n) const { //возвращает точку по номеру
        return points[n];
    }

    int PolygonalChain::getN() const {
    return number_of_points;
    }

    float PolygonalChain::perimeter() const {
        float per=0;
        for (int i=1;i<number_of_points;i++){
            per=per+sqrt(pow((points[i-1].getX()-points[i].getX()),2)+pow((points[i-1].getY()-points[i].getY()),2));
        }
        return per;
    }


ClosedPolygonalChain::ClosedPolygonalChain(int n,Point* fig):PolygonalChain(n,fig) //конструктор
    {
        number_of_points=n;
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

ClosedPolygonalChain&ClosedPolygonalChain:: operator=(const ClosedPolygonalChain &chain){ //оператор присваивания
        points.clear();
        number_of_points=chain.number_of_points;
        for (int i=0;i<chain.number_of_points;i++){
            points.push_back(chain.points[i]);
        }
    }

ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &chain):PolygonalChain(chain) //конструктор копирования
    {
        points.clear();
        number_of_points=chain.number_of_points;
        for (int i=0;i<chain.number_of_points;i++){
            points.push_back(chain.points[i]);
        }
    }


    float ClosedPolygonalChain::perimeter() const {
        float per=0;
        for (int i=1;i<number_of_points;i++){
            per=per+sqrt(pow((points[i-1].getX()-points[i].getX()),2)+pow((points[i-1].getY()-points[i].getY()),2));
        }
        per=per+sqrt(pow((points[0].getX()-points[number_of_points-1].getX()),2)+pow((points[0].getY()-points[number_of_points-1].getY()),2));
        return per;
    }


Polygon::Polygon(int n,Point* fig){
        number_of_points=n;
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

Polygon::Polygon(const Polygon &fig){ //копирование
        points.clear();
        number_of_points=fig.number_of_points;
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

Polygon&Polygon:: operator=(const Polygon &fig){ //присваивание
        points.clear();
        number_of_points=fig.number_of_points;
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

    void Polygon::get()
    {
        std::cout<<"number: "<<number_of_points<<std::endl;
        for (int i=0;i<number_of_points;i++){
            std::cout<<"point "<<i<<": "<<points[i].getX()<<" "<<points[i].getY()<<std::endl;
        }
    }

    Point Polygon::getPoint(int n){ //возвращает точку по номеру
        return points[n];
    }

    float Polygon::perimeter(){
        float per=0;
        for (int i=1;i<number_of_points;i++){
            per=per+abs(sqrt(pow((points[i-1].getX()-points[i].getX()),2)+pow((points[i-1].getY()-points[i].getY()),2)));
        }
        per=per+sqrt(pow((points[0].getX()-points[number_of_points-1].getX()),2)+pow((points[0].getY()-points[number_of_points-1].getY()),2));
        return per;
    }

    float Polygon::area() const {
        float sq=0;
        for (int i=0;i<number_of_points-1;i++){
            sq+=points[i].getX()*points[i+1].getY()-points[i].getY()*points[i+1].getX();
        }
        sq+=points[number_of_points-1].getX()*points[0].getY()-points[number_of_points-1].getY()*points[0].getX();
        return abs(sq/2);
    }


RegularPolygon::RegularPolygon(int n,Point* fig):Polygon(n,fig){
        number_of_points=n;
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

RegularPolygon::RegularPolygon(const RegularPolygon &fig):Polygon(fig){ //копирование
        points.clear();
        number_of_points=fig.number_of_points;
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

RegularPolygon&RegularPolygon:: operator=(const RegularPolygon &fig){ //присваивание
        points.clear();
        number_of_points=fig.number_of_points;
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }


    bool RegularPolygon::regular(){
        float first=abs(sqrt(pow((points[0].getX()-points[1].getX()),2)+pow((points[0].getY()-points[1].getY()),2)));
        for (int i=2;i<number_of_points;i++) {
            if (abs(sqrt(pow((points[i-1].getX()-points[i].getX()),2)+pow((points[i-1].getY()-points[i].getY()),2)))!=first)
                return false;
        }
        if (abs(sqrt(pow((points[0].getX()-points[number_of_points-1].getX()),2)+pow((points[0].getY()-points[number_of_points-1].getY()),2)))!=first)
            return false;
        return true;
    }



Triangle::Triangle(int n,Point* fig):Polygon(n,fig){
        assert(n==3);
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

Triangle::Triangle(const Triangle &fig):Polygon(fig){ //копирование
        points.clear();
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

Triangle&Triangle:: operator=(const Triangle &fig){ //присваивание
        points.clear();
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }



    float Triangle::height()
    {
        float a=abs(sqrt(pow((points[1].getX()-points[2].getX()),2)+pow((points[1].getY()-points[2].getY()),2)));
        float b=abs(sqrt(pow((points[0].getX()-points[1].getX()),2)+pow((points[0].getY()-points[1].getY()),2)));
        float c=abs(sqrt(pow((points[0].getX()-points[2].getX()),2)+pow((points[0].getY()-points[2].getY()),2)));
        float p=(a+b+c)/2;
        float h=(2/a)*sqrt(p*(p-a)*(p-b)*(p-c));
        return h;
    }

    float Triangle::area()
    {
        float a=abs(sqrt(pow((points[1].getX()-points[2].getX()),2)+pow((points[1].getY()-points[2].getY()),2)));
        float b=abs(sqrt(pow((points[0].getX()-points[1].getX()),2)+pow((points[0].getY()-points[1].getY()),2)));
        float c=abs(sqrt(pow((points[0].getX()-points[2].getX()),2)+pow((points[0].getY()-points[2].getY()),2)));
        float p=(a+b+c)/2;
        float area=sqrt(p*(p-a)*(p-b)*(p-c));
        return area;
    }

    bool Triangle::hasRightAngle() const {
        float a=abs(sqrt(pow((points[1].getX()-points[2].getX()),2)+pow((points[1].getY()-points[2].getY()),2)));
        float b=abs(sqrt(pow((points[0].getX()-points[1].getX()),2)+pow((points[0].getY()-points[1].getY()),2)));
        float c=abs(sqrt(pow((points[0].getX()-points[2].getX()),2)+pow((points[0].getY()-points[2].getY()),2)));
        float gip=0;
        float kat1,kat2=0;
        if (c>=a) {
            if (c >= b) {
                gip = c;
                kat1 = a;
                kat2 = b;
            } else {
                gip = b;
                kat1 = a;
                kat2 = c;
            }
        }
        else {
            if (a >= b) {
                gip = a;
                kat1 = b;
                kat2 = c;
            } else {
                gip = b;
                kat1 = a;
                kat2 = c;
            }
        }
        if ((gip*gip)==(kat1*kat1+kat2*kat2)) //по формуле Пифагора
            return true;
        else
            return false;
    }


Trapezoid::Trapezoid (int n,Point* fig):Polygon(n,fig){
        assert(n==4);
        for (int i=0;i<n;i++){
            points.push_back(fig[i]);
        }
    }

Trapezoid::Trapezoid (const Trapezoid &fig):Polygon(fig){ //копирование
        points.clear();
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

Trapezoid&Trapezoid:: operator=(const Trapezoid &fig){ //присваивание
        points.clear();
        for (int i=0;i<fig.number_of_points;i++){
            points.push_back(fig.points[i]);
        }
    }

    float Trapezoid::height() const {
        float higher=abs(sqrt(pow((points[1].getX()-points[2].getX()),2)+pow((points[1].getY()-points[2].getY()),2)));
        float lower=abs(sqrt(pow((points[0].getX()-points[3].getX()),2)+pow((points[0].getY()-points[3].getY()),2)));
        float h=area()/(0.5*higher+0.5*lower);
        return h;
    }

    float Trapezoid::area() const {
        float sq=0;
        for (int i=0;i<number_of_points-1;i++){
            sq+=points[i].getX()*points[i+1].getY()-points[i].getY()*points[i+1].getX();
        }
        sq+=points[number_of_points-1].getX()*points[0].getY()-points[number_of_points-1].getY()*points[0].getX();
        return abs(sq/2);
    }

