/*********NOTE: THIS PROGRAM IS UNFINISHED. It can run properly,
but the outputs still need to be adjusted.*********************/

/* Created by Dailuaine Esguerra 2021
 This program is a typing test used to test the user's
 typing accuracy and words per minute. It wil read in a file
 and output the text to user, prompt the user to type in each
 sentence, time the user's typing, and output their words
 per minute/amount of errors/accuracy.
 Thank you for trying the program out! If there are
 any questions you have about my about my code please
 reach me at dailuaine.esguerra@gmail.com.
*/

//Including libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

const int MAX_WORDS = 40;

int main()
{
    //Welcome Message
    std::cout << "*************************************" << std::endl;
    std::cout << "Welcome to the C++ Type Test Simulator" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << std::endl;

    char yesOrNo; //Declaring variable for input

    do
    {
        //Prompt user to start test
        std::string startTest;
        std::cout << "Enter \"start\" to start the test: ";
        std::cin >> startTest;

        //Running the test
        while (startTest == "start")
        {
            //Importing text file
            std::ifstream infile;
            infile.open("testtext.txt"); //Opens txt file

            //Storing words from file into array
            if(infile.good())
            {
                std::string wordArray[MAX_WORDS];

                //Starting the clock timer
                clock_t startTimer, endTimer;
                startTimer = clock(); //Starts test

                std::cout << std::endl;
                std::cout << "Enter the following sentences: ";

                int wordCount;
                for (int i = 0; i < MAX_WORDS; i++)
                {
                    infile >> wordArray[i];
                    std::cout << wordArray[i] << " ";
                    wordCount++;
                }

                //Obtaining user input
                std::string input;
                std::string inputArray[MAX_WORDS];
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Your input: ";

                for (int i = 0; i < MAX_WORDS; i++)
                {
                    std::cin >> input;
                    inputArray[i] = input;
                }
                
                //Calculating amount of errors from input
                int errors = 0;
                for (int i = 0; i < MAX_WORDS; i++)
                {
                    infile >> wordArray[i];
                    if (inputArray[i] != wordArray[i])
                    {
                        errors++;
                    }
                }

                //Ending test
                infile.close();
                endTimer = clock(); //Stops timer

                //Calculating time
                double seconds = 0.0;
                seconds = (double)(endTimer - startTimer) / CLOCKS_PER_SEC;

                //Calculating words per minute
                int WPM = 0;
                WPM = (seconds/6)*60;

                //Calculating accuracy
                double accuracy = 0.0;
                accuracy = ((wordCount - errors)/wordCount) *100;
        
                //Outputting results to user
                std::cout << std::endl;
                std::cout << "Time: " << seconds << " seconds" << std::endl;
                std::cout << "Number of errors: " << errors << std::endl;
                std::cout << "Words per minute: " << WPM << std::endl;
                std::cout << "Accuracy: " << accuracy << " %" << std::endl;
                
                break; //Breaks out of test

            }
            else
            {
                //Displays error message if the txt file could not be opened
                std::cout << "Error. Could not open file." << std::endl;
                break; //breaks out of while loop
            }
            
        }

        yesOrNo = toupper(yesOrNo); //Uppercasing input

        //Asking user if they would like to continue test
        std::cout << std::endl;
        std::cout << "Would you like to run another test? (Y/N): ";
        std::cin >> yesOrNo;
        std::cout << std::endl;

    } while (yesOrNo == 'Y' || yesOrNo =='y');


    std::cout << "Goodbye!" << std::endl;

    //End of Program

}
