#include <stdio.h>
#include <assert.h>

// Helper function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Helper function to handle alert logging
void logAlert(float celsius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", celsius);
}

// Function to send network alert
int sendNetworkAlert(float celsius) {
    logAlert(celsius);
    // Return 200 for ok, 500 for not-ok. Stub always succeeds and returns 200.
    return 200;
}

// Main alert function
int alertInCelsius(float fahrenheit) {
    float celsius = fahrenheitToCelsius(fahrenheit);
    int returnCode = sendNetworkAlert(celsius);
    return returnCode; // Return code to indicate success/failure
}

int main() {
    int alertFailures = 0;

    alertFailures += (alertInCelsius(400.5) != 200);
    alertFailures += (alertInCelsius(303.6) != 200);

    printf("%d alerts failed.\n", alertFailures);
    printf("All is well (maybe!)\n");
    return 0;
}
