#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;  // Global variable to track the number of failed alerts

/**
 * @brief Converts a temperature from Fahrenheit to Celsius.
 * 
 * @param fahrenheit Temperature in Fahrenheit.
 * @return float Temperature in Celsius.
 */
float fahrenheitToCelsius(float fahrenheit) {
    // Conversion formula from Fahrenheit to Celsius
    return (fahrenheit - 32) * 5 / 9;
}

/**
 * @brief Logs an alert message with the given Celsius temperature.
 * 
 * @param celsius Temperature in Celsius to be logged.
 */
void logAlert(float celsius) {
    // Print the alert message with formatted temperature
    printf("ALERT: Temperature is %.1f Celsius.\n", celsius);
}

/**
 * @brief Simulates sending a network alert with the given Celsius temperature.
 * Returns a failure if temperature exceeds 200°C.
 * 
 * @param celsius Temperature in Celsius.
 * @return int 200 if alert is successful, 500 if alert fails.
 */
int sendNetworkAlert(float celsius) {
    // Log the alert message before sending
    logAlert(celsius);
    // Simulate a failure (500) if the temperature exceeds 200°C; otherwise, return 200
    return (celsius > 200.0) ? 500 : 200;
}

/**
 * @brief Converts Fahrenheit to Celsius and sends an alert. Increments failure
 * count if the alert fails.
 * 
 * @param fahrenheit Temperature in Fahrenheit to be alerted.
 */
void alertInCelsius(float fahrenheit) {
    // Convert Fahrenheit temperature to Celsius
    float celsius = fahrenheitToCelsius(fahrenheit);
    // Send alert with the converted Celsius temperature
    int returnCode = sendNetworkAlert(celsius);
    // Increment failure count if alert response is not 200 (indicating a failure)
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

int main() {
    // Test cases to simulate alerts
    alertInCelsius(400.5);  // Expect this alert to fail
    alertInCelsius(303.6);  // Expect this alert to fail
    // Display the total count of failed alerts
    printf("%d alerts failed.\n", alertFailureCount);
    // Assert that we have two failures as expected
    assert(alertFailureCount == 2);
    printf("All is well (maybe!)\n");
    return 0;
}
