#include<iostream>

//Liscov substitution principle

//drawchape must know each and every shape type
void drawShape (const Shape &shape) {
    
    if (typeid(shape) == typeid(Square) ) {
       Square &s = static_cast<Square &>(shape);
       drawSquare(s);
    } else if (typeid(shape) == typeid(Circle)) {
       Circle &c = static_cast<Circle &>(shape);
       drawCircle(c);
    } 

}


