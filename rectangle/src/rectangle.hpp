#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle{
public:
    Rectangle(double width, double height);

    double Area() const {return width_ * height_;}
    void Width(double w);
    void Height(double h);
    double Width() const {return width_;}
    double Height() const {return height_;}
private:
    double width_;
    double height_;
};


#endif //RECTANGLE_HPP