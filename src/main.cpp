#include <iostream>
#include <string>
#include <vector>

#include "../includes/functions.h"


int main(int argc, char* argv[]) {
    int RLC1, RLC2;
    int sourceValue;
    std::string type;
    std::string order;
    std::string source;

    std::cout << "Choose either Resistor, Capacitor, or Inductor: ";
    std::cin >> type;

    std::cout << "Choose between Series or Parallel: ";
    std::cin >> order;

    std::cout << "Choose the source between Voltage or Current: ";
    std::cin >> source;

    if (type == "Resistor") {
        std::cout << "Enter the values of the Resistors ex:(5 10): ";
        std::cin >> RLC1 >> RLC2;
    }
    else if (type == "Capacitor") {
        std::cout << "Enter the values of the Capacitors ex:(5 10): ";
        std::cin >> RLC1 >> RLC2;
    }
    else if (type == "Inductor") {
        std::cout << "Enter the values of the Inductors ex:(5 10): ";
        std::cin >> RLC1 >> RLC2;
    }

    if (source == "Voltage") {
        std::cout << "Enter Voltage: ";
        std::cin >> sourceValue;
    }
    else if (source == "Current") {
        std::cout << "Enter Current: ";
        std::cin >> sourceValue;
    }

    std::cout << "==================================================" << '\n';
    std::cout << "Total Equivilance: " << equivalence(type, order, RLC1, RLC2) << '\n';
    std::cout << "==================================================" << '\n';

    if (type == "Resistor") {
        std::vector<double> voltage = voltageArray(source, order, sourceValue, RLC1, RLC2);
        std::cout << "Voltage Across Resistor 1: " << voltage[0] << '\n';
        std::cout << "Voltage Across Resistor 2: " << voltage[1] << '\n';
        std::cout << "==================================================" << '\n';

        std::vector<double> current = currentArray(source, order, sourceValue, RLC1, RLC2);
        std::cout << "Current Across Resistor 1: " << current[0] << '\n';
        std::cout << "Current Across Resistor 2: " << current[1] << '\n';
        std::cout << "==================================================" << '\n';
    }

    return 0;
}