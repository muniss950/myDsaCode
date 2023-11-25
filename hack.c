#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data Structures

typedef struct Player {
    char name[50];
    int handicap;
    struct Player* next;
} Player;

typedef struct GolfCourse {
    char courseName[50];
    char location[50];
    char designer[50];
    int par[18];
    struct GolfCourse* next;
} GolfCourse;

typedef struct Scorecard {
    int scores[18];
    int putts[18];
    char format[20];
    int numHoles;
} Scorecard;

typedef struct GameHistory {
    Player player;
    GolfCourse course;
    Scorecard scorecard;
    struct GameHistory* next;
} GameHistory;

typedef struct {
    GameHistory* head;
    GolfCourse* courses;
    int numCourses;
} GameTracker;

// Function Prototypes

float calculateAverageScore(int scores[], int numHoles);
float calculateHandicap(int scores[], int numHoles, int coursePar[], char format[]);
void displayScorecard(Scorecard* scorecard, int numHoles);
void displayPlayerStats(Player* player, float averageScore, float handicap);
void displayGameHistory(GameTracker* tracker);
void recordGame(GameTracker* tracker);
void displayTrends(GameTracker* tracker);
void displayPersonalInsights(GameHistory* game);

// Console UI Function Prototypes
void displayMenu();

int main() {
    int choice;

    // Initialize Game Tracker
    GameTracker tracker;
    tracker.head = NULL;
    tracker.courses = NULL;
    tracker.numCourses = 0;

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
                // Display player stats for the last recorded game
                if (tracker.head != NULL) {
                    displayPlayerStats(&tracker.head->player,
                                        calculateAverageScore(tracker.head->scorecard.scores, tracker.head->scorecard.numHoles),
                                        calculateHandicap(tracker.head->scorecard.scores, tracker.head->scorecard.numHoles, tracker.head->course.par, tracker.head->scorecard.format));
                } else {
                    printf("No games recorded yet.\n");
                }
                break;
            case 4:
                displayTrends(&tracker);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    // Free allocated memory
    GameHistory* currentGame = tracker.head;
    while (currentGame != NULL) {
        GameHistory* nextGame = currentGame->next;
        free(currentGame);
        currentGame = nextGame;
    }

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
    GameHistory* current = tracker->head;
    while (current != NULL) {
        printf("Player: %s, Course: %s\n", current->player.name, current->course.courseName);
        displayScorecard(&current->scorecard, current->scorecard.numHoles);
        printf("\n");
        current = current->next;
    }
}

void recordGame(GameTracker* tracker) {
    // Implementation with linked list
    GameHistory* newGame = (GameHistory*)malloc(sizeof(GameHistory));
    if (newGame == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter player name: ");
    scanf("%s", newGame->player.name);

    // Additional input for course and scores can be added here
    printf("Enter number of holes in the game: ");
    newGame->scorecard.numHoles = getNumberOfHoles();

    printf("Enter scoring format (e.g., Stroke Play, Match Play): ");
    scanf("%s", newGame->scorecard.format);

    printf("Enter scores for each hole:\n");
    for (int i = 0; i < newGame->scorecard.numHoles; i++) {
        printf("Enter score for Hole %d: ", i + 1);
        scanf("%d", &newGame->scorecard.scores[i]);
    }

    // Initialize putts to zero for simplicity
    for (int i = 0; i < newGame->scorecard.numHoles; i++) {
        newGame->scorecard.putts[i] = 0;
    }

    // Insert the new game at the beginning of the linked list
    newGame->next = tracker->head;
    tracker->head = newGame;

    printf("Game recorded successfully!\n");
}

void displayTrends(GameTracker* tracker) {
    // Implement trend analysis here
    // You can analyze trends across multiple games and display insights

    printf("\n----- Trends Analysis -----\n");

    if (tracker->head == NULL) {
        printf("No games recorded yet.\n");
        return;
    }

    // Calculate the average score and handicap across all recorded games
    float totalAverageScore = 0.0;
    float totalHandicap = 0.0;
    int numGames = 0;

    GameHistory* current = tracker->head;
    while (current != NULL) {
        totalAverageScore += calculateAverageScore(current->scorecard.scores, current->scorecard.numHoles);
        totalHandicap += calculateHandicap(current->scorecard.scores, current->scorecard.numHoles, current->course.par, current->scorecard.format);
        numGames++;

        current = current->next;
    }

    float overallAverageScore = totalAverageScore / numGames;
    float overallHandicap = totalHandicap / numGames;

    printf("Overall Average Score: %.2f\n", overallAverageScore);
    printf("Overall Handicap: %.2f\n", overallHandicap);
}

void displayPersonalInsights(GameHistory* game) {
    // Implement personalized insights here
    // Analyze the player's performance in the context of their historical data

    printf("\n----- Personal Insights -----\n");

    if (game == NULL) {
        printf("No games recorded for this player.\n");
        return;
    }

    // Compare the player's latest game with their historical data
    float latestAverageScore = calculateAverageScore(game->scorecard.scores, game->scorecard.numHoles);
    float latestHandicap = calculateHandicap(game->scorecard.scores, game->scorecard.numHoles, game->course.par, game->scorecard.format);

    printf("Latest Average Score: %.2f\n", latestAverageScore);
    printf("Latest Handicap: %.2f\n", latestHandicap);

    // You can add more personalized insights based on your requirements
}

int getNumberOfHoles() {
    int numHoles;
    do {
        printf("Enter the number of holes (between 1 and 18): ");
        scanf("%d", &numHoles);
    } while (numHoles < 1 || numHoles > 18);
    return numHoles;
}

// Console UI Function Definitions

void displayMenu() {
    printf("\n----- Golf Score Tracking System -----\n");
    printf("1. Record a Game\n");
    printf("2. Display Game History\n");
    printf("3. Display Current Player Stats\n");
    printf("4. Trends Analysis\n");
    printf("5. Exit\n");
}
