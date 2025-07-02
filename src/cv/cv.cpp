#include <iostream>
#include "cv.h"

namespace AZc{
namespace cv{

    float clacIOU(const Rect& rect1, const Rect& rect2){

        int intersection_x1 = std::max(rect1._x, rect2._x);
        int intersection_y1 = std::max(rect1._y, rect2._y);
        int intersection_x2 = std::min(rect1._x + rect1._w - 1, rect2._x + rect2._w - 1);
        int intersection_y2 = std::min(rect1._y + rect1._h - 1, rect2._y + rect2._h - 1);

        if(intersection_x1 >= intersection_x2 || intersection_y1 >= intersection_y2) return 0;

        int intersection_area = (intersection_x2 - intersection_x1 + 1) * (intersection_y2 - intersection_y1 + 1);
        int union_area = rect1.area() + rect2.area() - intersection_area;

        if(union_area == 0) return 0;

        return static_cast<float>(intersection_area) / static_cast<float>(union_area);
    }


} // namespace cv
} // namespace AZc
