#include "../header/window.hpp"
#include "../header/button.hpp"
#include "../header/calendar.hpp"

int main() {
    Window mainScreen(800, 500);
    mainScreen.setup();
    mainScreen.draw();
    return 0;
}