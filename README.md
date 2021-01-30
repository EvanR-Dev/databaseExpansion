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
