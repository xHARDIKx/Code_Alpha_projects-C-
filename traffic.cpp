#include <iostream>
#include <chrono>
#include <thread>

enum TrafficLightColor {
    RED,
    YELLOW,
    GREEN
};

class TrafficLight {
private:
    TrafficLightColor color;

public:
    TrafficLight() : color(RED) {}

    void switchToGreen() {
        color = GREEN;
        std::cout << "Traffic light switched to GREEN.\n";
    }

    void switchToYellow() {
        color = YELLOW;
        std::cout << "Traffic light switched to YELLOW.\n";
    }

    void switchToRed() {
        color = RED;
        std::cout << "Traffic light switched to RED.\n";
    }

    TrafficLightColor getColor() {
        return color;
    }
};

int main() {
    TrafficLight trafficLight;

    while (true) {
        switch (trafficLight.getColor()) {
            case RED:
                trafficLight.switchToGreen();
                std::this_thread::sleep_for(std::chrono::seconds(5));
                break;
            case GREEN:
                trafficLight.switchToYellow();
                std::this_thread::sleep_for(std::chrono::seconds(2));
                break;
            case YELLOW:
                trafficLight.switchToRed();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                break;
        }
    }

    return 0;
}
