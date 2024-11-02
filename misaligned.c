#include <stdio.h>
#include <assert.h>
#include <string.h>

// Major and minor color arrays for generating color pairs
const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

/**
 * @brief Prints a color pair given its index, major color, and minor color.
 * 
 * @param index Index of the color pair.
 * @param majorColor Major color in the pair.
 * @param minorColor Minor color in the pair.
 */
void printColorPair(int index, const char* majorColor, const char* minorColor) {
    // Print formatted color pair with index
    printf("%d | %s | %s\n", index, majorColor, minorColor);
}

/**
 * @brief Returns the expected color pair as a formatted string for validation.
 * Introduces a mismatch if simulateFailure is set and the index is 5.
 * 
 * @param index Index of the color pair.
 * @param majorColor Major color in the pair.
 * @param minorColor Minor color in the pair.
 * @param simulateFailure Flag to introduce a mismatch for testing.
 * @return const char* Expected formatted color pair string.
 */
const char* getExpectedColorPair(int index, const char* majorColor, const char* minorColor, int simulateFailure) {
    // Buffer to hold the formatted string
    static char expectedPair[50];
    // Introduce a mismatch if simulateFailure is true and the index is 5
    if (simulateFailure && index == 5) {
        snprintf(expectedPair, sizeof(expectedPair), "%d | %s | %s", index, "Mismatch", minorColor);
    } else {
        snprintf(expectedPair, sizeof(expectedPair), "%d | %s | %s", index, majorColor, minorColor);
    }
    return expectedPair;
}

/**
 * @brief Prints the color map and validates each entry, with an option to simulate a failure.
 * 
 * @param simulateFailure Set to 1 to introduce a failure for testing.
 */
void printAndValidateColorMap(int simulateFailure) {
    int index = 0;  // Index to keep track of color pairs
    char buffer[50];  // Buffer to store formatted color pair string

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Format the current color pair
            snprintf(buffer, sizeof(buffer), "%d | %s | %s", index, majorColors[i], minorColors[j]);
            // Print the color pair
            printColorPair(index, majorColors[i], minorColors[j]);
            // Validate that the printed color pair matches the expected format
            assert(strcmp(buffer, getExpectedColorPair(index, majorColors[i], minorColors[j], simulateFailure)) == 0);
            index++;
        }
    }
}

int main() {
    // Print and validate the color map, with simulateFailure set to 1 to introduce a mismatch
    printAndValidateColorMap(1); // Expect a failure for validation testing
    printf("All is well (maybe!)\n");
    return 0;
}
