/*  Write a program similar to the Animal Guessing game. Use a binary tree of structs implemented with pointers.
    In this binary tree we will store a database of animals and questions that can be used to guess an animal.
    The questions will be arbitrary yes/no questions, and names of animals will usually be one word but can be more.

    Guesses will be either correct or incorrect, again as demonstrated in class. Every time the
    program incorrectly guesses an animal type, the program will ask the user to help it learn the
    new animal type and ask how that animal type can be differentiated from the other animal
    types. The program will then be just a little bit smarter. The longer the user plays the game, the
    larger and more sophisticated the binary tree database will become.

    The game ends when the program has learned about a new animal and stored the new knowledge or when it correctly
    guesses the user’s animal. The program then asks the user to play the game again, and if the user agrees, the program
    starts all over but this time with a possibly augmented DB.

    1. Define a struct (animalNode)
    2. All animal nodes used by the program must be created dynamically (using the new command)
    3. Each animal node will contain either a question for the user or the name of an animal to
    guess – never both! If the node contains a question, the guess member will be blank,
    and both the yesAnswer and the noAnswer will point to child animal nodes. If the
    animal node contains a guess however, the question member will be blank, and both
    child pointers will be nullptrs
    4. When the program starts, initialize the database by creating an empty rootNode and setting
    the guess member to “lizard.” Set both the yesAnswer and noAnswer to nullptrs and the question
    to the empty string. You will now have your first node, and you can begin playing the game
    5. The game will first ask the user to think of an animal and wait for the user to hit the
    Enter key. It will then ask the user if the animal the user is thinking of is a lizard. If the
    user enters “yes,” the program “wins,” and the game starts all over
    6. If the user enters “no,” then the program will ask the user to teach it about the new
    animal the user is thinking of. It will do this by asking the user 1) what animal was being
    thought of and 2) a question that can be used to differentiate that animal from the one
    the program guessed
    7. At this point, you will need to grow the tree a bit and rearrange some of the information
    in it
    8. Then ask the user to enter a question that can be used to differentiate the current
    animal from the new animal. Read that question in and store it in the current node’s
    question member, clear the current node’s guess member
    9. Ask the user whether the answer to the question for the new animal is “yes” or “no,”,
    and depending on the answer, store the new animal’s name in either the yesAns node
    or the noAns node
    10. Finally, move the previously guessed animal’s name (the one that was in curNode) to
    the other animalNode’s guess member

    Changelog:
    Improved user input validation efficiency (4/16/20)
    Altered pointer variables and logic (4/16/20)
    Created user validation input (4/16/20)
    Generalized case of letters when inputting for yes or no (c-string function usage) (4/17/20)
    Fixed use of recursion of startGame function (4/17/20)
    Made code more editable by using variables and arbitrary names (4/17/20)
    Made code more efficient and organized (4/19/20)
    Updated input validation (4/20/20)
    Improved visuals by adding more spaces between lines (4/20/20)

    Notes:
    The sample output is a little inaccurate. The program must learn of the questions that the user inputs,
    thus increasing the "augmented DB"

    I was trying to allow spaces, but with all the prompts, it is rather inefficient and/or difficult
    to enable this. For now, underscores can always be used. It does not improve the program's methodology
    and logic for building the DB

    We just start from the head and ensure the directions are followed carefully
    The directions give a great outline about the pointer logic. We must start from the head
    and then point to where the database is built from asking questions

    This was one of the more difficult HWs. I will now try to do as much practice as I can
    with pointers in the textbook

    I have commented almost everything in this program. This is crucial as the logic may somewhat be difficult
    to follow as there are lots of new nodes and variables

    **SPECIAL FEATURES:**
    The program has been generalized to the user can enter group/domain of things to guess and
    also choose the head of the tree

    A simple yet important addition: added user input validation to see if their choice is valid or not
*/

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