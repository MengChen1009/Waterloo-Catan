#ifndef _COLOR_H_
#define _COLOR_H_

enum Color { Blue, Red, Orange, Yellow };

std::string ToString(Color c)
{
    switch (c)
    {
        case Blue:   return "Blue";
        case Red:   return "Red";
        case Orange: return "Orange";
        default: return "Yellow";
    }
}

Color ToColor(std::string s) {
    if (s == "Blue") {
        return Blue;
    } else if (s == "Red") {
        return Red;
    } else if (s == "Orange") {
        return Orange;
    } else {
        return Yellow;
    }
}


#endif
