#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_COURSES 10

// Data Structures

typedef struct {
    char name[50];
    int handicap;
} Player;

typedef struct {
    char courseName[50];
    char location[50];  // Location of the course
    char designer[50];  // Designer of the course
    int par[18];        // Assuming 18 holes per course
} GolfCourse;

typedef struct {
    int scores[18];  // Scores for each hole
    int putts[18];   // Putts for each hole
    char format[20]; // Golf format (e.g., "Stroke Play", "Match Play")
    int numHoles;    // Number of holes in the game
} Scorecard;

typedef struct {
    Player player;
    GolfCourse course;
    Scorecard scorecard;
} GameHistory;

typedef struct {
    GameHistory* games;
    GolfCourse* courses;
    int numGames;
    int numCourses;
    int maxGames;
    int maxCourses;
} GameTracker;

// Function Prototypes

float calculateAverageScore(int scores[], int numHoles);
float calculateHandicap(int scores[], int numHoles, int coursePar[], char format[]);
void displayScorecard(Scorecard* scorecard, int numHoles);
void displayPlayerStats(Player* player, float averageScore, float handicap);
void displayGameHistory(GameTracker* tracker);
void addNewCourse(GameTracker* tracker);
void recordGame(GameTracker* tracker);

// Console UI Function Prototypes
void displayMenu();

int main() {
    int choice;

    // Initialize Game Tracker
    GameTracker tracker;
    tracker.numGames = 0;
    tracker.maxGames = 10;  // Maximum number of games to track initially
    tracker.games = (GameHistory*)malloc(tracker.maxGames * sizeof(GameHistory));

    tracker.numCourses = 0;
    tracker.maxCourses = MAX_COURSES;
    tracker.courses = (GolfCourse*)malloc(tracker.maxCourses * sizeof(GolfCourse));

    if (tracker.games == NULL || tracker.courses == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordGame(&tracker);
                break;
            case 2:
                displayGameHistory(&tracker);
                break;
            case 3:
                displayPlayerStats(&tracker.games[tracker.numGames - 1].player,
                                    calculateAverageScore(tracker.games[tracker.numGames - 1].scorecard.scores, tracker.games[tracker.numGames - 1].scorecard.numHoles),
                                    calculateHandicap(tracker.games[tracker.numGames - 1].scorecard.scores, tracker.games[tracker.numGames - 1].scorecard.numHoles, tracker.games[tracker.numGames - 1].course.par, tracker.games[tracker.numGames - 1].scorecard.format));
                break;
            case 4:
                addNewCourse(&tracker);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    // Free allocated memory
    free(tracker.games);
    free(tracker.courses);

    return 0;
}

// Function Definitions

float calculateAverageScore(int scores[], int numHoles) {
    int totalScore = 0;
    for (int i = 0; i < numHoles; i++) {
        totalScore += scores[i];
    }
    return (float)totalScore / numHoles;
}

float calculateHandicap(int scores[], int numHoles, int coursePar[], char format[]) {
    float differential = 0.0;
    for (int i = 0; i < numHoles; i++) {
        differential += ((float)scores[i] - coursePar[i]) / 1.0; // Assuming a course rating of 1.0
    }

    // Custom handicap calculation based on scoring format
    if (strcmp(format, "Stroke Play") == 0) {
        // Custom logic for Stroke Play
    } else if (strcmp(format, "Match Play") == 0) {
        // Custom logic for Match Play
    }

    return differential / numHoles;
}

void displayScorecard(Scorecard* scorecard, int numHoles) {
    printf("Hole\tScore\tPutts\n");
    for (int i = 0; i < numHoles; i++) {
        printf("%d\t%d\t%d\n", i + 1, scorecard->scores[i], scorecard->putts[i]);
    }
}

void displayPlayerStats(Player* player, float averageScore, float handicap) {
    printf("\n----- Player Stats -----\n");
    printf("Player: %s\n", player->name);
    printf("Handicap: %d\n", player->handicap);
    printf("Average Score: %.2f\n", averageScore);
    printf("Calculated Handicap: %.2f\n", handicap);
}

void displayGameHistory(GameTracker* tracker) {
    printf("\n----- Game History -----\n");
    for (int i = 0; i < tracker->numGames; i++) {
        printf("Game %d:\n", i + 1);
        displayScorecard(&tracker->games[i].scorecard, tracker->games[i].scorecard.numHoles);
        printf("\n");
    }
}

void addNewCourse(GameTracker* tracker) {
    if (tracker->numCourses == tracker->maxCourses) {
        printf("Maximum number of courses reached.\n");
        return;
    }

    printf("Enter the name of the new course: ");
    scanf("%s", tracker->courses[tracker->numCourses].courseName);

    printf("Enter the location of the new course: ");
    scanf("%s", tracker->courses[tracker->numCourses].location);

    printf("Enter the designer of the new course: ");
    scanf("%s", tracker->courses[tracker->numCourses].designer);

    // Set par values for each hole in the course
    printf("Enter par values for each hole (18 holes):\n");
    for (int i = 0; i < 18; i++) {
        printf("Hole %d: ", i + 1);
        scanf("%d", &tracker->courses[tracker->numCourses].par[i]);
    }

    printf("New course added successfully!\n");

    tracker->numCourses++;
}

void recordGame(GameTracker* tracker) {
    if (tracker->numGames == tracker->maxGames) {
        // Increase the size of the array if needed
        tracker->maxGames = tracker->maxGames == 0 ? 2 : tracker->maxGames * 2;
        tracker->games = (GameHistory*)realloc(tracker->games, tracker->maxGames * sizeof(GameHistory));

        if (tracker->games == NULL) {
            printf("Memory allocation error.\n");
            return;
        }
    }

    printf("Enter player name: ");
    scanf("%s", tracker->games[tracker->numGames].player.name);

    // Additional input for course and scores can be added here

    // Assume a sample score for now
    tracker->games[tracker->numGames].scorecard.numHoles = 18;
    strcpy(tracker->games[tracker->numGames].scorecard.format, "Stroke Play");
    for (int i = 0; i < 18; i++) {
        printf("Enter score for Hole %d: ", i + 1);
        scanf("%d", &tracker->games[tracker->numGames].scorecard.scores[i]);
    }

    printf("Game recorded successfully!\n");

    // Increment the number of games
    tracker->numGames++;
}

// Console UI Function Definitions

void displayMenu() {
    printf("\n----- Golf Score Tracking System -----\n");
    printf("1. Record a Game\n");
    printf("2. Display Game History\n");
    printf("3. Display Current Player Stats\n");
    printf("4. Add New Course\n");
    printf("5. Exit\n");
}
