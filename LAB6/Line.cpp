#include "Line.h"

Line::Line(double length, double width) : length__(length), width__(width) {}

double Line::getWidth() const {return this->width__;}

double Line::getLength() const {return this->length__;}

double Line::getArea() const
{
    return length__ * width__;
}

bool Line::operator < (const Line &obj)
{
    return this->getArea() < obj.getArea();
}

bool Line::operator ==(const Line &obj)
{
    return this->getArea() == obj.getArea();
}

Line& Line::operator =(const Line &obj)
{
    this->length__ = obj.getLength();
    this->width__ = obj.getWidth();
    return *this;
}