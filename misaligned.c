#include <stdio.h>
#include <assert.h>
#include <string.h>

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Helper function to print a color pair
void printColorPair(int index, const char* majorColor, const char* minorColor) {
    printf("%d | %s | %s\n", index, majorColor, minorColor);
}

// Helper function to retrieve color pair for validation
const char* getExpectedColorPair(int index, const char* majorColor, const char* minorColor, int simulateFailure) {
    static char expectedPair[50];
    // Introduce a forced mismatch to trigger assertion failure
    if (simulateFailure && index == 5) {
        snprintf(expectedPair, sizeof(expectedPair), "%d | %s | %s", index, "Mismatch", minorColor);
    } else {
        snprintf(expectedPair, sizeof(expectedPair), "%d | %s | %s", index, majorColor, minorColor);
    }
    return expectedPair;
}

// Function to print and validate the color map
void printAndValidateColorMap(int simulateFailure) {
    int index = 0;
    char buffer[50];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            snprintf(buffer, sizeof(buffer), "%d | %s | %s", index, majorColors[i], minorColors[j]);
            printColorPair(index, majorColors[i], minorColors[j]);
            // Validate each pair matches expected format, with a forced failure at index 5
            assert(strcmp(buffer, getExpectedColorPair(index, majorColors[i], minorColors[j], simulateFailure)) == 0);
            index++;
        }
    }
}

int main() {
    printAndValidateColorMap(1); // Pass 1 to simulate failure
    printf("All is well (maybe!)\n");
    return 0;
}
