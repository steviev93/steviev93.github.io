//============================================================================
// Name        : LinkedList.cpp
// Author      : Stephen Valente
// Class       : CS-260-J1801
// Date		   : 9-19-2020
// Version     : 1.0
// Copyright   : Copyright Â© 2017 SNHU COCE
// Description : Lab 3-3 Lists and Searching
//============================================================================

#include <algorithm>
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

private:
    // FIXME (1): Internal structure for list entries, housekeeping variables
	struct Node {
		Bid bid;
		Node* next;

		// Default Constructor
		Node() {
			next = nullptr;
		}

		//initialize a node with a bid
		Node(Bid aBid) {
			bid = aBid;
			// Make sure bid doesn't point to any other memory it shouldn't
			next = nullptr;
		}
	};

	Node* head;
	Node* tail;
	//initialize size variable
	int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList();
    void Remove(string bidId);
    void InsertAfter(string bidId, Bid bid);
    Bid Search(string bidId);
    int Size();
};

/**
 * Default constructor
 */
LinkedList::LinkedList() {
    // FIXME (2): Initialize housekeeping variables
	head = tail = nullptr;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
}

/**
 * Append a new bid to the end of the list
 */
void LinkedList::Append(Bid bid) {
    // FIXME (3): Implement append logic
	Node* node = new Node(bid);

	if (head == nullptr) {
		head = node;
	}else {
		if (tail != nullptr) {
			tail->next = node;
		}

	}

	//new node is always the tail with Append()
	tail = node;

	size++;
}

/**
 * Prepend a new bid to the start of the list
 */
void LinkedList::Prepend(Bid bid) {
    // FIXME (4): Implement prepend logic
	// initialize a bid node
	Node* node = new Node(bid);

	//check whether head node is empty
	if (head != nullptr) {
		// adjust node pointer to the current head
		node->next = head;
	}
	// make arg node the head node
	head = node;
	// increment the size
	size++;
}

/**
 * Simple output of all bids in the list
 */
void LinkedList::PrintList() {
    // FIXME (5): Implement print logic
	Node* current = head;

	// use while loop until nullptr(end of list) is reached, print values
	while (current != nullptr) {
		cout << current->bid.bidId << ": " << current->bid.title << " | "
			 << current->bid.amount << " | " << current->bid.fund << endl;
		current = current->next;
	}
}

/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 */
void LinkedList::Remove(string bidId) {
    // FIXME (6): Implement remove logic
	// Check for instance of Id being the head
	if (head != nullptr) {
		if (head->bid.bidId.compare(bidId) == 0){
			//Set tempNode equal to whatever is beyond head node (null or other)
			Node* tempNode = head->next;
			delete head;
			head = tempNode;
		}
	}
	Node* current = head;

	while (current->next != nullptr) {
		//checking the next node instead of current so we can still redirect the pointer
		if (current->next->bid.bidId.compare(bidId) == 0) {
			//save the next node in a separate variable before deleting to call pointer
			Node* tempNode = current->next;

			//redirect the current pointer two nodes to the right (around temp node to be removed)
			current->next = tempNode->next;

			//now that pointers are set, safely delete the tempNode
			delete tempNode;

			//account for size decrement
			size--;

			return;


			}
			current = current->next;

		}
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid LinkedList::Search(string bidId) {
    // FIXME (7): Implement search logic
	Node* current = head;
	Bid rBid;
    //loop through nodes
	while (current != nullptr) {
        //if node matches, set node data = bid to be returned, rBid
		if (current->bid.bidId.compare(bidId) == 0) {
			rBid =  current->bid;
			break;
		}
		current = current->next;

	}
	return rBid;
}

void LinkedList::InsertAfter(string bidId, Bid bid) {
    // FIXME : Implement insert after logic (specified in d2l)
	Node* current = head;
	Node* tempNode;
	// create new instance of a node with new information
	Node* node = new Node(bid);

	while (current != nullptr) {
		if (current->bid.bidId.compare(bidId) == 0) {
            //set tempNode for redirected pointers later
			tempNode = current->next;
            //redirect the current node's pointer to the new node
			current->next = node;
            //redirect the new node's pointer to tempNode
			node->next = tempNode;
			cout << bid.bidId << " successfully inserted after " << current->bid.bidId << endl;
			break;
		}
		current = current->next;

	}
	return;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount
         << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string csvPath, LinkedList *list) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << bid.bidId << ": " << bid.title << " | " << bid.fund << " | " << bid.amount << endl;

            // add this bid to the end
            list->Append(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 *
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales_Dec_2016.csv";
        bidKey = "98109";
    }

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  6. Prepend a Bid" << endl;
        cout << "  7. Insert After a Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        //Enter a bid
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;
        //Load
        case 2:
            ticks = clock();

            loadBids(csvPath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;
        //Display
        case 3:
            bidList.PrintList();

            break;
        //Search
        case 4:


			ticks = clock();

			bid = bidList.Search(bidKey);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			if (!bid.bidId.empty()) {
				displayBid(bid);
			} else {
				cout << "Bid Id " << bidKey << " not found." << endl;
			}

			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

			break;


		//Remove
        case 5:

            bidList.Remove(bidKey);

            break;
        //Prepend
        case 6:
        	bid = getBid();
        	bidList.Prepend(bid);
        	displayBid(bid);
        	break;

        //Insert After
        case 7:
        	bid = getBid();
        	ticks = clock();
        	bidList.InsertAfter(bidKey, bid);
        	displayBid(bid);
        	ticks = clock() - ticks;
        	cout << "time: " << ticks << " milliseconds" << endl;
        	cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;


        }
    }

    cout << "Good bye." << endl;

    return 0;
}
