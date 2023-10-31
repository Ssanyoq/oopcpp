#ifndef OOPCPP_SPRITE_H
#define OOPCPP_SPRITE_H

#include <utility>

#define long long ll

using std::pair;

class Sprite {
protected:
    pair<ll, ll> position;
    short rotation;
public:
    Sprite(x, y, position=0);
    Sprite();

    std::pair<ll , ll> getPos() {return position};

    void delete();

    void move();

    void rotate(short newDirection);
};

#endif
