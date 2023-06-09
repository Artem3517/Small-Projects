#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "figure.hpp"

class O : public Figure{
public:
    O() = default;
    void setPositionOne(int row, int col);
};