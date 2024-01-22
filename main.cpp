#include <iostream>
#include <string>

class CookieClicker {
private:
    long long cookies;
    int cookiesPerClick;
    int cookiesPerSecond;
    long long totalSeconds;

public:
    CookieClicker() : cookies(0), cookiesPerClick(1), cookiesPerSecond(0), totalSeconds(0) {}

    void click() {
        cookies += cookiesPerClick;
    }

    void upgradeClick() {
        if (cookies >= 10) {
            cookies -= 10;
            cookiesPerClick++;
            std::cout << "Click power upgraded! You now make " << cookiesPerClick << " cookies per click." << std::endl;
        } else {
            std::cout << "Not enough cookies! You need 10 cookies to upgrade." << std::endl;
        }
    }

    void upgradeAutoClicker() {
        if (cookies >= 50) {
            cookies -= 50;
            cookiesPerSecond++;
            std::cout << "Auto clicker upgraded! You now make " << cookiesPerSecond << " cookies per second." << std::endl;
        } else {
            std::cout << "Not enough cookies! You need 50 cookies to upgrade." << std::endl;
        }
    }

    void addAutoCookies() {
        cookies += cookiesPerSecond * totalSeconds;
        totalSeconds = 0;
    }

    void simulateTimePassing() {
        totalSeconds++;
    }

    void displayStatus() {
        std::cout << "Cookies: " << cookies << ", Cookies per click: " << cookiesPerClick << ", Cookies per second: " << cookiesPerSecond << std::endl;
    }
};

int main() {
    CookieClicker game;
    std::string command;

    while (true) {
        game.simulateTimePassing();
        game.addAutoCookies();
        game.displayStatus();
        
        std::cout << "Enter command (click, upgrade click, upgrade auto): ";
        std::cin >> command;

        if (command == "click") {
            game.click();
        } else if (command == "upgrade") {
            game.upgradeClick();
        } else if (command == "auto") {
            game.upgradeAutoClicker();
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}

