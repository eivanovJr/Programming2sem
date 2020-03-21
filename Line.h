#ifndef LAB6_LINE_H
#define LAB6_LINE_H

class Line
{
public:
    explicit Line(double = 0, double = 0);
    [[nodiscard]] double getArea() const;
    [[nodiscard]] double getLength() const;
    [[nodiscard]] double getWidth() const;
    bool operator < (const Line &);
    bool operator ==(const Line &);
    Line& operator =(const Line &);
private:
    double length__;
    double width__;
};

#endif //LAB6_LINE_H
