/*
 * QUESTION 3 (DAA): Solve the Fractional Knapsack problem using a Greedy Method.
 *
 * Given n items, each having a value and weight, and a knapsack of fixed
 * capacity, find the maximum total value that can be obtained.
 *
 * Unlike 0/1 Knapsack, Fractional Knapsack allows us to take a fraction
 * of an item if the entire item cannot fit in the knapsack.
 *
 * GREEDY APPROACH:
 * 1. Calculate the value-to-weight ratio of each item.
 * 2. Sort all items in descending order of this ratio.
 * 3. Select items with the highest ratio first.
 * 4. If an item fits completely, take the whole item.
 * 5. Otherwise, take only the fraction that fits and stop.
 *
 * TIME COMPLEXITY: O(n log n) due to sorting.
 * SPACE COMPLEXITY: O(n) for storing the items.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Stores item details along with its original item number.
struct Item {
    int id;
    int value;
    int weight;
    double ratio;
};

// Sort items in descending order of value-to-weight ratio.
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Function to calculate the maximum value using the greedy method.
double fractionalKnapsack(vector<Item>& items, int capacity) {

    // Sort items according to their ratio.
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    // Select items starting from the highest ratio.
    for (int i = 0; i < items.size(); i++) {

        if (items[i].weight <= capacity) {

            // Take the complete item.
            maxValue += items[i].value;
            capacity -= items[i].weight;

            cout << "Item " << items[i].id << " : 100% selected" << endl;
        }
        else {

            // Take only the fraction that fits in the knapsack.
            double fraction = (double)capacity / items[i].weight;

            maxValue += items[i].value * fraction;

            cout << "Item " << items[i].id << " : "
                 << fraction * 100 << "% selected" << endl;

            break;  // Knapsack is now full.
        }
    }

    return maxValue;
}

int main() {

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of items!";
        cout << "Enter number of items: ";
        cin >> n;
    }

    vector<Item> items(n);

    // Read item details and calculate their ratios.
    for (int i = 0; i < n; i++) {

        items[i].id = i + 1;

        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;

        if (items[i].value < 0 || items[i].weight <= 0) {
            cout << "Invalid value or weight!";
            cout << "Enter value and weight of item " << i + 1 << ": ";
            cin >> items[i].value >> items[i].weight;
        }

        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    if (capacity < 0) {
        cout << "Invalid capacity!";
        cout << "Enter knapsack capacity: ";
        cin >> capacity;
    }

    double result = fractionalKnapsack(items, capacity);

    cout << "\nMaximum value in Knapsack = " << result << endl;

    return 0;
}