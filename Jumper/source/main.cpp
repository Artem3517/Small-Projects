#include "../header/window.hpp"
#include "../header/field.hpp"

#include <ctime>

int main() {
    srand(time(NULL));
    Window screen(500, 600);
    screen.drawWindow();
    return 0;
}