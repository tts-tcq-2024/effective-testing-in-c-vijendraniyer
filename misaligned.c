#include <stdio.h>
#include <assert.h>

const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

// Helper function to print a color pair
void printColorPair(int index, const char* majorColor, const char* minorColor) {
    printf("%d | %s | %s\n", index, majorColor, minorColor);
}

// Function to print the color map
void printColorMap() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printColorPair(i * 5 + j, majorColors[i], minorColors[j]);
        }
    }
}

int main() {
    printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
