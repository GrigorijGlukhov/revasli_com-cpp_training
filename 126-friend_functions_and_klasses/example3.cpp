// using friend function with two classes

#include <iostream>
#include <string>

class Humidity; // declarign class before use in class friend function declaration

class Temperature
{
    int m_temperature;
public:
    Temperature(int value) : m_temperature(value) {}
    friend void printWeather(Temperature & temperature, Humidity & humidity);
};

class Humidity
{
    int m_humidity;
public:
    Humidity(int value) : m_humidity(value) {}
    friend void printWeather(Temperature & temperature, Humidity & humidity);
};

void printWeather(Temperature & temperature, Humidity & humidity)
{
    std::cout << "Temperature: " << temperature.m_temperature << " Humidity: " << humidity.m_humidity << '\n';
}


int main()
{
    Temperature temp(10);
    Humidity humidity(24);
    printWeather(temp, humidity);

    return EXIT_SUCCESS;
}
