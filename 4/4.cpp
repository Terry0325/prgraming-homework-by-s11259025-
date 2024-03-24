#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int reviewer[4][6] = {
        {3, 1, 5, 2, 1, 6},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
    };
    int input_movie[3];
    int input_rating[3];
    double distance[4] = { 0 };
    double distance_min = 1000;
    int closest_reviewer = 0;

    // Prompt user to input ratings for three movies
    cout << "Choose three movies that you want to rate\n(eg: 101,1,102,3,103,5)\n";
    for (int input_index = 0; input_index <= 2; input_index++) {
        cout << "The movie:";
        cin >> input_movie[input_index];
        cout << "The rating:";
        cin >> input_rating[input_index];
    }

    // Calculate distance from each reviewer to the input ratings
    for (int reviewer_index = 0; reviewer_index <= 3; reviewer_index++) {
        for (int input_index = 0; input_index <= 2; input_index++) {
            for (int reviewer_movie_index = 0; reviewer_movie_index <= 5; reviewer_movie_index++) {
                // If the movie is found, calculate the distance
                if (input_movie[input_index] == (reviewer_movie_index + 100)) {
                    distance[reviewer_index] += pow((reviewer[reviewer_index][reviewer_movie_index] - input_rating[input_index]), 2);

                    // Mark the movie as rated to avoid re-rating
                    reviewer[reviewer_index][reviewer_movie_index] = -1;
                }
            }
        }
        distance[reviewer_index] = sqrt(distance[reviewer_index]); // Calculate the final distance
    }

    // Find the closest reviewer
    for (int reviewer_index = 0; reviewer_index < 4; reviewer_index++) {
        if (distance[reviewer_index] <= distance_min) {
            distance_min = distance[reviewer_index];
            closest_reviewer = reviewer_index;
        }
    }

    // Predict and display ratings for other movies
    cout << "\nOther movies ratings we predict:\n";
    for (int reviewer_movie_index = 0; reviewer_movie_index <= 5; reviewer_movie_index++) {
        // If the movie hasn't been rated yet, display the predicted rating
        if (reviewer[closest_reviewer][reviewer_movie_index] > 0) {
            cout << '\n' << reviewer_movie_index + 100 << ":" << reviewer[closest_reviewer][reviewer_movie_index];
        }
    }

    return 0;
}
