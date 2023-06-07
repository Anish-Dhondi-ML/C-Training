#include <iostream>

using namespace std;

// Function prototypes
int getGolfScores(int scores[]);
void displayGolfScores(int scores[], int count);
double calculateAverageScore(int scores[], int count);

// Main function
int main()
{
    // Declare an array to store golf scores
    const int MAX_SCORES = 10;
    int scores[MAX_SCORES];

    // Get the number of golf scores from the user
    int count = getGolfScores(scores);

    // Display the golf scores on one line
    displayGolfScores(scores, count);

    // Calculate and display the average golf score
    double averageScore = calculateAverageScore(scores, count);
    cout << "Average Score: " << averageScore << endl;

    return 0;
}

// Function to get golf scores from the user
int getGolfScores(int scores[])
{
    int count = 0;

    cout << "Enter up to 10 golf scores (enter a negative number to stop): ";

    // Loop to get golf scores from the user
    while (count < 10)
    {
        int score;
        cin >> score;

        if (score < 0)
        {
            break;
        }

        scores[count] = score;
        count++;
    }

    return count;
}

// Function to display golf scores
void displayGolfScores(int scores[], int count)
{
    cout << "Golf Scores: ";
    for (int i = 0; i < count; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;
}

// Function to calculate the average golf score
double calculateAverageScore(int scores[], int count)
{
    double sum = 0.0;

    for (int i = 0; i < count; i++)
    {
        sum += scores[i];
    }

    return sum / count;
}
