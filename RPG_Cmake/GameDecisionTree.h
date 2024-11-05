#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"
#include <queue>

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    GameDecisionTree() : root(nullptr) {}

    // get private root Node
    Node<T>* getRoot() {
        return this->root;
    }

    // set private root Node
    void setRoot(Node<T>* someNode) {
        this->root = someNode;
    }

    // add new Node based on next available child
    void addNode(Node<T>* someNode, Node<T>* parent) {
        queue<Node<T>*> storyQueue;
        // this really only occurs once
        do {
            if (getRoot() == nullptr) {
                setRoot(someNode);
            }

            else if (parent->getLeft() == nullptr && (parent->getLeftEvent() == someNode->getEventNumber())) {
                parent->setLeft(someNode);
            }
            else if (parent->getRight() == nullptr && (parent->getRightEvent() == someNode->getEventNumber())) {
                parent->setRight(someNode);
            }
            else {
                // if current node has all children filled up, create a queue and store their left and right childrens; left first

                if (parent->getLeft() != nullptr) {
                    storyQueue.push(parent->getLeft());
                }
                if (parent->getRight() != nullptr) {
                    storyQueue.push(parent->getRight());
                }
                // update parent node to first node in queue
                if (!storyQueue.empty()) {
                    parent = storyQueue.front();
                    // remove queue
                    storyQueue.pop();
                    // recursively add node with updated parent
                    addNode(someNode, parent);
                }
            }
        } while (!storyQueue.empty());
    }
    // Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        string line, description;
        int eventNumber;
        int leftEventNumber;
        int rightEventNumber;
        
        cout << "Loading Story From File" << endl;
        
        // open file
        ifstream file(filename);

        if (!file.is_open())
        {
            cout << "File " << filename << " is not open! Cannot read from file.";
            return;
        }

        // Story.txt file sets up each line using the following format:
        // Event Number | Description | Left Event | Right Event
        while (getline(file, line)) {
            cout << line << endl;
            string token; // separated string
            size_t pos = 0; // position of delimiter
            int data = 0; // data keeps track of delimited stuff embedded in each line in Story.txt

            while ( (pos = line.find(delimiter)) != string::npos && data < 4) {
                token = line.substr(0, pos);
                switch (data)
                {
                    case 0:
                        eventNumber = stoi(token);
                        break;
                    case 1:
                        description = token;
                        break;
                    case 2:
                        leftEventNumber = stoi(token);
                        break;
                    case 3:
                        rightEventNumber = stoi(token);
                        break;
                }
                data++;
                line.erase(0, pos + 1);
            }

            // all data in line has been parsed
            Story newStory = Story(description, eventNumber, leftEventNumber, rightEventNumber);
            Node<Story>* newNode = new Node(newStory);

            addNode(newNode,root);
            
        }

        // close file
        file.close();


    }

    // Function to start the game and traverse the tree based on user input
    void playGame() {

    }
};

#endif // GAMEDECISIONTREE_H
