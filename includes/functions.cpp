#include <string>
#include <vector>
#include "functions.h"

double seriesResistorEquivalence(double R1, double R2) {
    return R1 + R2;
}

double seriesCapacitorEquivalence(double C1, double C2) {
    return 1.0/((1.0/C1) + (1.0/C2));
}

double seriesInductorEquivalence(double L1, double L2) {
    return L1 + L2;
}

double parallelResistorEquivalence(double R1, double R2) {
    return 1.0/((1.0/R1) + (1.0/R2));
}

double parallelCapacitorEquivalence(double C1, double C2) {
    return C1 + C2;
}

double parallelInductorEquivalence(double L1, double L2) {
    return 1.0/((1.0/L1) + (1.0/L2));
}

double equivalence(std::string type, std::string order, double num1, double num2) {
    if (order == "Series") {
        if (type == "Resistor") {
            return seriesResistorEquivalence(num1, num2);
        }
        else if (type == "Capacitor") {
            return seriesCapacitorEquivalence(num1, num2);
        }
        else if (type == "Inductor") {
            return seriesInductorEquivalence(num1, num2);
        }
        else {
            return 0;
        }
    }
    else if (order == "Parallel") {
        if (type == "Resistor") {
            return parallelResistorEquivalence(num1, num2);
        }
        else if (type == "Capacitor") {
            return parallelCapacitorEquivalence(num1, num2);
        }
        else if (type == "Inductor") {
            return parallelInductorEquivalence(num1, num2);
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}


//Voltage Source
//Finding Voltage Across from Voltage Source
std::vector<double> seriesVoltageFromVoltage(double voltage, double R1, double R2) {
    double Req = seriesResistorEquivalence(R1, R2);
    double current = voltage/Req;
    std::vector<double> voltageAcross = {current*R1, current*R2};
    return voltageAcross;
}

std::vector<double> parallelVoltageFromVoltage(double voltage) {
    std::vector<double> voltageAcross = {voltage, voltage};
    return voltageAcross;
}

std::vector<double> voltageArrayFromVoltage(std::string order, double voltage, double num1, double num2) {
    if (order == "Series") {
        return seriesVoltageFromVoltage(voltage, num1, num2);
    }
    else {
        return parallelVoltageFromVoltage(voltage);
    }
}

//Finding Current Through from Voltage Source
std::vector<double> parallelCurrentFromVoltage(double voltage, double R1, double R2) {
    std::vector<double> currentThrough = {voltage/R1, voltage/R2};
    return currentThrough;
}

std::vector<double> seriesCurrentFromVoltage(double voltage, double R1, double R2) {
    double Req = seriesResistorEquivalence(R1, R2);
    double current = voltage/Req;
    std::vector<double> currentThrough = {current, current};
    return currentThrough;
}

std::vector<double> currentArrayFromVoltage(std::string order, double voltage, double num1, double num2) {
    if (order == "Parallel") {
        return parallelCurrentFromVoltage(voltage, num1, num2);
    }
    else {
        return seriesCurrentFromVoltage(voltage, num1, num2);
    }
}


//Current Source
//Finding Voltage Across from Current Source
std::vector<double> seriesVoltageFromCurrent(double current, double R1, double R2) {
    std::vector<double> voltageAcross = {current*R1, current*R2};
    return voltageAcross;
}

std::vector<double> parallelVoltageFromCurrent(double current, double R1, double R2) {
    double Req = parallelResistorEquivalence(R1, R2);
    double voltage = current*Req;
    std::vector<double> voltageAcross = {voltage, voltage};
    return voltageAcross;
}

std::vector<double> voltageArrayFromCurrent(std::string order, double current, double num1, double num2) {
    if (order == "Series") {
        return seriesVoltageFromCurrent(current, num1, num2);
    }
    else {
        return parallelVoltageFromCurrent(current, num1, num2);
    }
}

//Finding Current Through from Current Source
std::vector<double> parallelCurrentFromCurrent(double current, double R1, double R2) {
    double Req = parallelResistorEquivalence(R1, R2);
    double voltage = current*Req;
    std::vector<double> currentThrough = {voltage/R1, voltage/R2};
    return currentThrough;
}

std::vector<double> seriesCurrentFromCurrent(double current) {
    std::vector<double> currentThrough = {current, current};
    return currentThrough;
}

std::vector<double> currentArrayFromCurrent(std::string order, double current, double num1, double num2) {
    if (order == "Parallel") {
        return parallelCurrentFromCurrent(current, num1, num2);
    }
    else {
        return seriesCurrentFromCurrent(current);
    }
}

//Voltage
std::vector<double> voltageArray(std::string source, std::string order, double value, double num1, double num2) {
    if (source == "Voltage") {
        return voltageArrayFromVoltage(order, value, num1, num2);
    }
    else {
        return voltageArrayFromCurrent(order, value, num1, num2);
    }
}

//Current
std::vector<double> currentArray(std::string source, std::string order, double value, double num1, double num2) {
    if (source == "Voltage") {
        return currentArrayFromVoltage(order, value, num1, num2);
    }
    else {
        return currentArrayFromCurrent(order, value, num1, num2);
    }
}
