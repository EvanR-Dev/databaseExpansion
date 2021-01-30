#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string initialDomain = ""; // Allow name of user's domain to be used across whole program
string domain = "";

// Define the struct for general purposes
struct domainNode {
    string guess;
    string question;
    domainNode* yesAnswer = NULL;
    domainNode* noAnswer = NULL;
};

// New element node for whole domain "DB"
domainNode* newNode(string initGuess) {
    domainNode* newNode = new domainNode(); // Declare pointer as new node
    newNode->yesAnswer = NULL;
    newNode->noAnswer = NULL;
    newNode->question = "";
    newNode->guess = initGuess; // Access variable's pointer and initialize it for later element
    return newNode;
}

// Insert info about element in domain
void enterNewDomain(domainNode* currNode, string& tempGuess) {
    cout << "\nEnter the name of the " << domain + '\b' << " you are thinking of:\n";
    cin >> tempGuess; // Add element to "DB" by user's guess
}

void getNewQ(domainNode* currNode, string& tempGuess, string& tempQuestion) {
    cin.ignore(); // Needed to not skip prev prompt
    cout << "\nGive a Yes or No question that distinguishes a " << tempGuess
        << " from a " << currNode->guess << ":\n";
    //currNode->domainNode*;
    //currNode->tempGuess;
    getline(cin, tempQuestion); // Get question to be stored about guess for "DB"
}

// User enters binary answer, verify it
void verifyYOrNAnswer(char& userAnswer) {
    cin >> userAnswer;
    userAnswer = tolower(userAnswer);

    // Validate input
    while (userAnswer != 'y' && userAnswer != 'n') {
        cout << "Invalid Entry. Please input y or n: ";
        cin >> userAnswer;
        userAnswer = tolower(userAnswer);
    }
}

void ansQ(char& yesOrNoAnsToQ) {
    cout << "\nWhat is the answer to your question for this " << domain + '\b' << "?\n";
    verifyYOrNAnswer(yesOrNoAnsToQ);

    /*  cin >> yesOrNoAnsToQ; // (Binary) choice for question so guess can be learned about by program
        yesOrNoAnsToQ = tolower(yesOrNoAnsToQ);
    */

    /*   for (int i : yesOrNoAns) // range-based for loop
             cout << "FIX";
    */
}

void startGame(domainNode* currNode) {
    char userAnsQ = ' '; // User gives answer to their question for program
    char userAnswerGuess = ' '; // User gives answer to program's guess
    string tempGuess = "";  // User's guess
    string tempQ = ""; // User's Q to differentiate between two different elements belonging to the domain

    if (currNode->question.size() == 0) { // No memory address, null, no question (hasn't been accessed yet)
        cout << "\nIs it a(n) " << currNode->guess << "?\n"; // Retrieve guess
        verifyYOrNAnswer(userAnswerGuess);

        if (userAnswerGuess == 'y') { // User's guess is the guess
            cout << "Good! I guessed your " << domain + '\b' << ".\n"; // End of guessing
        }
        else { // Program guess was wrong
            enterNewDomain(currNode, tempGuess);
            getNewQ(currNode, tempGuess, tempQ); // User distinguishes
            ansQ(userAnsQ);

            /*
            domainNode* yesNode = nullptr;
            domainNode* noNode = nullptr;
            newNode->guess = initGuess; // (Change var lat)
            */
            domainNode* yesNode = NULL; // nullptr reset
            domainNode* noNode = NULL;

            if (userAnsQ == 'y') { // User's question is answered as yes
                noNode = newNode(currNode->guess); // Take program's guess currently and update DB
                yesNode = newNode(tempGuess); // User's guess is passed on to update DB
            }
            else { // User's question is answered as no
                noNode = newNode(tempGuess); // User's guess is a no, update
                yesNode = newNode(currNode->guess); // Take current guess to update
            }
            // Once the user's guess and their answer is processed, point to struct variables and (update/reset)
            currNode->guess = "";
            currNode->noAnswer = noNode;
            currNode->yesAnswer = yesNode;
            currNode->question = tempQ;
        }
    }
    else { // There is a question that is being pointed to, and we need to process the info from the DB
        cout << currNode->question << '\n'; // Retrieve & Display the Q in the address
        verifyYOrNAnswer(userAnswerGuess); // User gives answer to the program's guess

        if (userAnswerGuess == 'n') // User answers no
            startGame(currNode->noAnswer); // Use recursion and point to noAnswer
        else
            startGame(currNode->yesAnswer); // Use recursion and point to yesAnswer
        /*
            currNode->guess;
            currNode->noAnswer;
            currNode->yesAnswer;
            currNode->question;
        */
    }
}

int main() {
    char userChoice = ' ';

    // Initialize user preference for game
    cout << "Let's play a Guessing Game:\nEnter y or Y for Yes and n or N for No.\n\n";
    cout << "First, enter a domain/group of things that the guessing will be centered around (in plural form): ";
    cin >> domain;
    cout << "Enter the starting element (head) for the guessing to begin: ";
    cin >> initialDomain;
    //getline(cin, initialDomain);
    //cin.ignore();
  //string domainName = domain + '\b';

    domainNode* head = newNode(initialDomain); // Initialize (animal) node as starting point node

    // Initiate game
    cout << "\nYou can now enter the game.\nType y to continue or any other letter to exit now: ";
    cin >> userChoice; // Get user's choice
    userChoice = tolower(userChoice); // Checking if "Y"

    // Verify choice
    while (userChoice == 'y') { // Start game
        startGame(head); // Start at head pointer
        cout << "If you want to play again, type y. Otherwise, type any other letter to exit: "; // Retry
        cin >> userChoice; // Play game again if yes (build DB), otherwise exit program
        userChoice = tolower(userChoice);
    }
}