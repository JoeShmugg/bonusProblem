#pragma once

#include <string>
#include <vector>


double seriesResistorEquivalence(double R1, double R2);
double seriesCapacitorEquivalence(double C1, double C2);
double seriesInductorEquivalence(double L1, double L2);
double parallelResistorEquivalence(double R1, double R2);
double parallelCapacitorEquivalence(double C1, double C2);
double parallelInductorEquivalence(double L1, double L2);

double equivalence(std::string type, std::string order, double num1, double num2);


//Voltage Source
//Finding Voltage Across from Voltage Source
std::vector<double> seriesVoltageFromVoltage(double voltage, double R1, double R2);

std::vector<double> parallelVoltageFromVoltage(double voltage);

std::vector<double> voltageArrayFromVoltage(std::string order, double voltage, double num1, double num2);

//Finding Current Through from Voltage Source
std::vector<double> parallelCurrentFromVoltage(double voltage, double R1, double R2);

std::vector<double> seriesCurrentFromVoltage(double voltage, double R1, double R2);

std::vector<double> currentArrayFromVoltage(std::string order, double voltage, double num1, double num2);


//Current Source
//Finding Voltage Across from Current Source
std::vector<double> seriesVoltageFromCurrent(double current, double R1, double R2);

std::vector<double> parallelVoltageFromCurrent(double current, double R1, double R2);

std::vector<double> voltageArrayFromCurrent(std::string order, double current, double num1, double num2);

//Finding Current Through from Current Source
std::vector<double> parallelCurrentFromCurrent(double current, double R1, double R2);

std::vector<double> seriesCurrentFromCurrent(double current);

std::vector<double> currentArrayFromCurrent(std::string order, double current, double num1, double num2);

//Voltage
std::vector<double> voltageArray(std::string source, std::string order, double value, double num1, double num2);

//Current
std::vector<double> currentArray(std::string source, std::string order, double value, double num1, double num2);
