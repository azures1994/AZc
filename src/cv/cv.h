#pragma once

namespace AZc{
namespace cv{

struct Rect{
    int _x;
    int _y;
    int _w;
    int _h;

    Rect(){
        _x = 0;
        _y = 0;
        _w = 0;
        _h = 0;
    }

    Rect(int x_, int y_, int w_, int h_){
        _x = x_;
        _y = y_;
        _w = w_;
        _h = h_;
    }

    int area() const{
        return _w * _h;
    }
};

float clacIOU(const Rect& rect1, const Rect& rect2);

} // namespcae cv
} // namespace AZc