#include <iostream>
#include "Queue.h"
#include <string>
#include <vector>

using namespace std;

// Rescursive linear search function for the last occurence of a target in a vector
int recursiveSearch(const vector<int>& vec, int target, int index) {
    if (index < 0) return -1; // Base case:not found
    if (vec[index] == target) return index;
    return recursiveSearch(vec, target, index -1); // Recursive step
}

int main() {
    Queue<int> q;

    //Push values into the queue
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // Displat the queue
    cout << "Queue elements: ";
    q.display();

    // Move the front element to the rrar and display again
    q.move_to_rear();
    cout << "After moving to rear: ";
    q.display();

    // Step 3: Test the recursive search function
    int target = 5;
    vector<int> vec = {1, 3, 5, 5, 7, 9};
    int lastIndex = recursiveSearch(vec, target, vec.size() - 1);
    cout << "Last occurence of " << target << " is at index: " << lastIndex << endl;

    return 0;


}