#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Helper function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Helper function to handle alert logging
void logAlert(float celsius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", celsius);
}

// Function to send network alert, with simulated failures for testing
int sendNetworkAlert(float celsius) {
    logAlert(celsius);
    // Simulate failure if temperature exceeds 200 Celsius
    return (celsius > 200.0) ? 500 : 200;
}

// Main alert function
void alertInCelsius(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    int returnCode = sendNetworkAlert(celsius);
    if (returnCode != 200) {
        // Increment the count to track actual failures.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelsius(400.5);  // This should trigger a failure
    alertInCelsius(303.6);  // This should trigger a failure
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 2);  // Expecting 2 failures
    printf("All is well (maybe!)\n");
    return 0;
}
