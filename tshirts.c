#include <stdio.h>
#include <assert.h>

/**
 * @brief Determines the size of a T-shirt based on chest measurement in centimeters.
 * 
 * @param cms Chest measurement in centimeters.
 * @return char Size: 'S' for Small, 'M' for Medium, and 'L' for Large.
 */
char size(int cms) {
    // Determine T-shirt size based on given cms
    if (cms < 38) {
        return 'S';  // Small for chest size < 38
    } else if (cms <= 42) {  // Adjusted to include 42 in Medium
        return 'M';  // Medium for chest size between 38 and 42 (inclusive)
    } else {
        return 'L';  // Large for chest size > 42
    }
}

int main() {
    // Assert statements to verify that the function behaves as expected
    assert(size(37) == 'S');  // Boundary test for Small
    assert(size(38) == 'S');  // Boundary test for Small
    assert(size(40) == 'M');  // Test for Medium
    assert(size(42) == 'M');  // Boundary test for Medium
    assert(size(43) == 'L');  // Test for Large
    printf("All is well (maybe!)\n");
    return 0;
}
