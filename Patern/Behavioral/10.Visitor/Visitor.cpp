#include <iostream>
#include <string>
#include <vector>

// Предварительное объявление классов фигур
class Circle;
class Rectangle;

class IVisitor {
public:
    virtual void visit(Circle* circle) = 0;
    virtual void visit(Rectangle* rectangle) = 0;
    virtual ~IVisitor() = default;
};

class IShape {
public:
    virtual void accept(IVisitor* visitor) = 0;
    virtual ~IShape() = default;
};

class Circle : public IShape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
    void accept(IVisitor* visitor) override {
        visitor->visit(this);  // Вызываем visit для Circle
    }
};

class Rectangle : public IShape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    void accept(IVisitor* visitor) override {
        visitor->visit(this);  // Вызываем visit для Rectangle
    }
};

// Посетитель для вычисления площади
class AreaCalculator : public IVisitor {
public:
    void visit(Circle* circle) override {
        double area = 3.14 * circle->getRadius() * circle->getRadius();
        std::cout << "Площадь круга: " << area << std::endl;
    }
    void visit(Rectangle* rectangle) override {
        double area = rectangle->getWidth() * rectangle->getHeight();
        std::cout << "Площадь прямоугольника: " << area << std::endl;
    }
};

// Посетитель для рендеринга в SVG
class SVGRenderer : public IVisitor {
public:
    void visit(Circle* circle) override {
        std::cout << "Радиус круга = " << circle->getRadius() << std::endl;
    }
    void visit(Rectangle* rectangle) override {
        std::cout << "Ширина прямоугольника = " << rectangle->getWidth() << ", высота прямоугольника=" << rectangle->getHeight() << std::endl;
    }
};

// ===== 5. Клиентский код =====
int main() {
    std::vector<IShape*> shapes = {
        new Circle(5.0),
        new Rectangle(3.0, 4.0)
    };

    AreaCalculator areaCalc;
    SVGRenderer svgRenderer;

    for (IShape* shape : shapes) {
        shape->accept(&areaCalc);    // Вычисляем площадь
        shape->accept(&svgRenderer);
    }

    // Очистка памяти
    for (IShape* shape : shapes) {
        delete shape;
    }

    return 0;
}