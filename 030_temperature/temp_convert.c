#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float convertToCelcius(float temperature, char* argv[])
{
    if (strcmp(argv[1], "°F") == 0 || strcmp(argv[1], "f") == 0 || strcmp(argv[1], "F") == 0 || strcmp(argv[1], "fahrenheit") == 0 || strcmp(argv[1], "Fahrenheit") == 0)
    {
        return 0.55555 * (temperature - 32);
    }
    else if (strcmp(argv[1], "k") == 0 || strcmp(argv[1], "K") == 0 || strcmp(argv[1], "kelvin") == 0 || strcmp(argv[1], "Kelvin") == 0)
    {
        return temperature - 273.15;
    }
    else if (strcmp(argv[1], "°C") == 0 || strcmp(argv[1], "c") == 0 || strcmp(argv[1], "C") == 0 || strcmp(argv[1], "celsius") == 0 || strcmp(argv[1], "Celsius") == 0)
    {
        return temperature;
    }
    else
    {
        fprintf(stderr, "temp_convert: error: Unrecognized temperature scale %s", argv[1]);
        abort();
        return EXIT_FAILURE;
    }
}

float convertToKelvin(float temperature, char* argv[])
{
    if (strcmp(argv[1], "°F") == 0 || strcmp(argv[1], "f") == 0 || strcmp(argv[1], "F") == 0 || strcmp(argv[1], "fahrenheit") == 0 || strcmp(argv[1], "Fahrenheit") == 0)
    {
        return (0.55555 * (temperature - 32)) + 273.15;
    }
    else if (strcmp(argv[1], "k") == 0 || strcmp(argv[1], "K") == 0 || strcmp(argv[1], "kelvin") == 0 || strcmp(argv[1], "Kelvin") == 0)
    { 
        return temperature;
    }
    else if (strcmp(argv[1], "°C") == 0 || strcmp(argv[1], "c") == 0 || strcmp(argv[1], "C") == 0 || strcmp(argv[1], "celsius") == 0 || strcmp(argv[1], "Celsius") == 0)
    {
        return temperature + 273.15;
    }
    else
    {
        fprintf(stderr, "temp_convert: error: Unrecognized temperature scale %s", argv[1]);
        abort();
        return EXIT_FAILURE;
    }
}

float convertToFahrenheit(float temperature, char* argv[])
{
    if (strcmp(argv[1], "°F") == 0 || strcmp(argv[1], "f") == 0 || strcmp(argv[1], "F") == 0 || strcmp(argv[1], "fahrenheit") == 0 || strcmp(argv[1], "Fahrenheit") == 0)
    {
        return temperature;
    }
    else if (strcmp(argv[1], "k") == 0 || strcmp(argv[1], "K") == 0 || strcmp(argv[1], "kelvin") == 0 || strcmp(argv[1], "Kelvin") == 0)
    {
        return 1.8 * (temperature - 273) + 32;
    }
    else if (strcmp(argv[1], "°C") == 0 || strcmp(argv[1], "c") == 0 || strcmp(argv[1], "C") == 0 || strcmp(argv[1], "celsius") == 0 || strcmp(argv[1], "Celsius") == 0)
    {
        return (temperature / 0.55555) + 32;
    }
    else
    {
        fprintf(stderr, "temp_convert: error: Unrecognized temperature scale %s", argv[1]);
        abort();
        return EXIT_FAILURE;
    }
}

int main(int argc, char* argv[])
{
    if (argv[1] == NULL)
    {
        fprintf(stderr, "temp_convert: error: Not enough arguments.\n");
        fprintf(stderr, "Usage: temp_convert INPUT_SCALE OUTPUT_SCALE [TEMPERATURE]...");
        abort();
        return EXIT_FAILURE;
    }
    for (int argumentIndex = 3; argumentIndex < argc; argumentIndex++)
    {
        if (strcmp(argv[2], "°C") == 0 || strcmp(argv[2], "c") == 0 || strcmp(argv[2], "C") == 0 || strcmp(argv[2], "celsius") == 0 || strcmp(argv[2], "Celsius") == 0)
        {
            float output = convertToCelcius(atof(argv[argumentIndex]), argv);
            printf("%f\n", output);
        }
        else if (strcmp(argv[2], "°F") == 0 || strcmp(argv[2], "f") == 0 || strcmp(argv[2], "F") == 0 || strcmp(argv[2], "fahrenheit") == 0 || strcmp(argv[2], "Fahrenheit") == 0)
        {
            float output = convertToFahrenheit(atof(argv[argumentIndex]), argv);
            printf("%f\n", output);
        }
        else if (strcmp(argv[2], "k") == 0 || strcmp(argv[2], "K") == 0 || strcmp(argv[2], "kelvin") == 0 || strcmp(argv[2], "Kelvin") == 0)
        {
            float output = convertToKelvin(atof(argv[argumentIndex]), argv);
            printf("%f\n", output);
        }
        else
        {
            fprintf(stderr, "temp_convert: error: Unrecognized temperature scale %s", argv[2]);
            abort();
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
