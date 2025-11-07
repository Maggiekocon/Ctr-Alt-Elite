    // This is the file that generates the questions for the math quiz.
    // A random function and values are picked, then so are random answers.
    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <fstream>
    #include <sstream>
    
    using namespace std;
    
    const int NUM_QUESTIONS = 5;
    // Each question will have two values between these numbers.
    const int MIN_VALUE = -10;
    const int MAX_VALUE = 10;
    
    int main()
    {
        ofstream outputFile;
        outputFile.open("output.txt");
        int questionType;
        int val1, val2;
        int i;
        ostringstream question;
        double answer;
        double options[4];
        int correctIndex;
        // Make random number generator seed off of current time.
        srand(static_cast<unsigned>(time(0)));
    
        if (outputFile.is_open())
        {
            // Generate the questions.
            for (i = 0; i < NUM_QUESTIONS; i++)
            {
                questionType = rand() % 4; // 0, 1, 2, 3 are add, sub, mult, div.
                correctIndex = rand() % 4; // Make correct answer A, B, C, or D.
                val1 = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE + 1));
                val2 = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE + 1));
                switch(questionType)
                {
                    case 0:
                        question << "Question " << i << ": " << val1 " + " << val2 << " = ?";
                        answer = val1 + val2;
                        break;
                    case 1:
                        question << "Question " << i << ": " << val1 " - " << val2 << " = ?";
                        answer = val1 - val2;
                        break;
                    case 2:
                        question << "Question " << i << ": " << val1 " * " << val2 << " = ?";
                        answer = val1 * val2;
                        break;
                    case 3:
                        question << "Question " << i << ": " << val1 " / " << val2 << " = ?";
                        answer = val1 / val2;
                        break;
                }
                outputFile << question << endl;
                for (int n = 0; n < 4; n++)
                {
                    if (correctIndex == n)
                        options[n] = answer;
                    else // Make wrong answers random numbers.
                        options[n] = MIN_VALUE + (rand() % (MAX_VALUE - MIN_VALUE + 1));
                }
                outputFile << "A: " << options[0] << endl;
                outputFile << "B: " << options[1] << endl;
                outputFile << "C: " << options[2] << endl;
                outputFile << "D: " << options[3] << endl;
                switch(correctIndex)
                {
                    case 0:
                        outputFile << "The correct answer is A." << endl;
                        break;
                    case 1:
                        outputFile << "The correct answer is B." << endl;
                        break;
                    case 2:
                        outputFile << "The correct answer is C." << endl;
                        break;
                    case 3:
                        outputFile << "The correct answer is D." << endl;
                        break;
                }
            }
        }
    
        return 0;
    }