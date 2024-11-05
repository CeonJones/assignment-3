#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// template class for a queue of any data type

template <typename T>
class Queue{
    private:
        //Node struct to show each element in the queue
        struct Node {
            T data;         // Value of the node
            Node* next;     // Pointer to the next node
            Node(T val) : data(val), next(nullptr) {}
        };
        
        Node* frontNode;    // Pointer to the front of the queue
        Node* rearNode;     // Pointer to the rear of the queue
        int count;          // Number of elements in the queue

    public:
        // Constructor
        Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}
        
        // Destructor
        ~Queue() {
            while (!empty()) {
                pop();      // Remove all elements from the queue
            }
        }

        // Adds element to the rear of the queue
        void push(const T& value) {
            Node* newnode = new Node(value);    // Create a new node
            if (empty()) {
                frontNode = rearNode = newnode; // First node in the queue
            } else {
                rearNode->next = newnode;       // Add the new node to the rear
                rearNode = newnode;             // Update the rear pointer
            }
            ++count;                            // Increase the count
        }

        // Removes the element at the front of the queue
        void pop() {
            if (!empty()) {
                Node* temp = frontNode;     // Save the front node
                frontNode = frontNode->next;    // Move the front pointer to the next node
                delete temp;                // Delete the front node
                --count;                    // Decrease the count
                if (empty()) {
                    rearNode = nullptr;     // If the queue is empty, set the rear to nullptr
                }
            }
        }
        
        // Returns the element at the front of the queue
        T front() const {
            if (!empty()) {
                return frontNode->data;    // Return the value of the front node
            }
            throw std::out_of_range("Queue is empty");  // Throw an exception if the queue is empty
        }

        // Returns the number of elements in the queue
        int size() const {
            return count;
        }
        
        // Returns true if the queue is empty
        bool empty() const {
            return count == 0;
        }
        
        // Moves the front element to the rear of the queue
        void move_to_rear() {
            if (size() > 1) {           // If the queue has more than one element
                T frontValue = front(); // Save the value of the front element
                pop();              // Remove the front element
                push(frontValue);   // Push the value to the rear
            }
        }

        // Display the elements in the queue
        void display() const {
            Node* current = frontNode;  // Start from the front node
            while (current) {           // Traverse the queue
                std::cout << current->data << " ";  // Display the value of the current node
                current = current->next;        // Move to the next node
            }
            std::cout << std::endl;     // Move to the next line
        }
};

#endif