#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_COURSES 10
#define MAX_GAMES 100

// Data Structures

typedef struct {
    char name[50];
    int handicap;
} Player;

typedef struct {
    char courseName[50];
    int par[18];
} GolfCourse;


// Modify the Scorecard structure to include the number of holes
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
    Player players[MAX_PLAYERS];
    int numPlayers;

    GolfCourse courses[MAX_COURSES];
    int numCourses;

    GameHistory games[MAX_GAMES];
    int numGames;
} GameTracker;

// Function Prototypes

float calculateAverageScore(int scores[], int numHoles);
float calculateHandicap(int scores[], int numHoles, int coursePar[]);
void displayScorecard(Scorecard* scorecard, int numHoles);

void displayPlayerStats(GameTracker* tracker, int gameIndex);
void displayGameHistory(GameTracker* tracker);

// Console UI Function Prototypes
void displayMenu();
void recordGame(GameTracker* tracker);
void displayPlayerStatsUI(Player* player, float averageScore, float handicap);
void displayScorecardUI(Scorecard* scorecard, int numHoles);

void displayScoreTrends(GameTracker* tracker) ;

// Function Prototypes
void addNewPlayer(GameTracker* tracker);

void addNewCourse(GameTracker* tracker);

void providePersonalizedInsights(GameTracker* tracker) ;
int main() {
    int choice;

    // Initialize Game Tracker
    GameTracker tracker;
    tracker.numPlayers = 0;
    tracker.numCourses = 0;
    tracker.numGames = 0;

 // Add players
    strcpy(tracker.players[tracker.numPlayers].name, "Player1");
    tracker.players[tracker.numPlayers].handicap = 10;
    tracker.numPlayers++;

    // Add courses
    strcpy(tracker.courses[tracker.numCourses].courseName, "Course1");
    // Set par values for each hole in the course
    for (int i = 0; i < 18; i++) {
        tracker.courses[tracker.numCourses].par[i] = 4; // You can set the par values accordingly
    }
    tracker.numCourses++;
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
                if (tracker.numGames > 0) {
                  int selectedGame;
                  printf("Enter the game number to display stats: ");
                  scanf("%d", &selectedGame);

                  if (selectedGame >= 1 && selectedGame <= tracker.numGames) {
                    displayPlayerStats(&tracker, selectedGame - 1);
                  } else {
                      printf("Invalid game number.\n");
                  }
                } else {
                    printf("No games recorded yet.\n");
                }
                break;
            case 4:
                addNewPlayer(&tracker);
                break;
            case 5:
                addNewCourse(&tracker);
                break;
            case 6:
                displayScoreTrends(&tracker);
                break;
            case 7:
                providePersonalizedInsights(&tracker);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}

// Function Definitions
//
void addNewPlayer(GameTracker* tracker) {
    if (tracker->numPlayers == MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    printf("Enter the name of the new player: ");
    scanf("%s", tracker->players[tracker->numPlayers].name);
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the handicap of the new player: ");
    scanf("%d", &tracker->players[tracker->numPlayers].handicap);

    printf("New player added successfully!\n");


    tracker->numPlayers++;
}

void addNewCourse(GameTracker* tracker) {
    if (tracker->numCourses == MAX_COURSES) {
        printf("Maximum number of courses reached.\n");
        return;
    }

    printf("Enter the name of the new course: ");
    scanf("%s", tracker->courses[tracker->numCourses].courseName);

    // Set par values for each hole in the course
    printf("Enter par values for each hole (18 holes):\n");
    for (int i = 0; i < 18; i++) {
        printf("Hole %d: ", i + 1);
        scanf("%d", &tracker->courses[tracker->numCourses].par[i]);
    }

    printf("New course added successfully!\n");

    tracker->numCourses++;
}

void providePersonalizedInsights(GameTracker* tracker) {
    if (tracker->numGames < 2) {
        printf("Not enough data to provide insights. Record more games.\n");
        return;
    }

    // Compare the average scores of the last two games
    float averageScore1 = calculateAverageScore(tracker->games[tracker->numGames - 2].scorecard.scores, 18);
    float averageScore2 = calculateAverageScore(tracker->games[tracker->numGames - 1].scorecard.scores, 18);

    printf("\n----- Personalized Insights -----\n");
    printf("Your average score has ");
    if (averageScore2 < averageScore1) {
        printf("improved");
    } else if (averageScore2 > averageScore1) {
        printf("increased");
    } else {
        printf("remained the same");
    }
    printf(" since your last game.\n");
}
float calculateAverageScore(int scores[], int numHoles) {
    int totalScore = 0;
    for (int i = 0; i < numHoles; i++) {
        totalScore += scores[i];
    }
    return (float)totalScore / numHoles;
}

float calculateHandicap(int scores[], int numHoles, int coursePar[]) {
    float differential = 0.0;
    for (int i = 0; i < numHoles; i++) {
        differential += ((float)scores[i] - coursePar[i]) / 1.0; // Assuming a course rating of 1.0
    }
    return differential / numHoles;
}

void displayScorecard(Scorecard* scorecard, int numHoles) {
    printf("Hole\tScore\tPutts\n");
    for (int i = 0; i < numHoles; i++) {
        printf("%d\t%d\t%d\n", i + 1, scorecard->scores[i], scorecard->putts[i]);
    }
}

void displayPlayerStats(GameTracker* tracker, int gameIndex) {
    if (gameIndex < 0 || gameIndex >= tracker->numGames) {
        printf("Invalid game index.\n");
        return;
    }

    Player* currentPlayer = &tracker->games[gameIndex].player;
    float averageScore = calculateAverageScore(tracker->games[gameIndex].scorecard.scores, 18);
    float handicap = calculateHandicap(tracker->games[gameIndex].scorecard.scores, 18,
                                        tracker->games[gameIndex].course.par);

    printf("\n----- Player Stats -----\n");
    printf("Player: %s\n", currentPlayer->name);
    printf("Handicap: %d\n", currentPlayer->handicap);
    printf("Average Score: %.2f\n", averageScore);
    printf("Calculated Handicap: %.2f\n", handicap);
}
void displayGameHistory(GameTracker* tracker) {
    printf("\n----- Game History -----\n");
    for (int i = 0; i < tracker->numGames; i++) {
        printf("Game %d:\n", i + 1);
        displayScorecardUI(&tracker->games[i].scorecard, 18);
        printf("\n");
    }
}

// Console UI Function Definitions

void displayMenu() {
    printf("\n----- Golf Score Tracking System -----\n");
    printf("1. Record a Game\n");
    printf("2. Display Game History\n");
    printf("3. Display Current Player Stats\n");
    printf("4. Enter new player\n");
    printf("5. Enter new course\n");
    printf("6. Show score trends\n");
    printf("7. Personalized Insights\n");
    printf("8. Exit\n");
}

void displayScoreTrends(GameTracker* tracker) {
    printf("\n----- Score Trends Over Time -----\n");
    for (int i = 0; i < tracker->numGames; i++) {
        float averageScore = calculateAverageScore(tracker->games[i].scorecard.scores, 18);
        printf(" Average score in Game %d: %.2f\n", i + 1, averageScore);
    }
}
// Modify the recordGame function to include the number of holes input
void recordGame(GameTracker* tracker) {
    // Increase the size of the array
    GameHistory* temp = (GameHistory*)realloc(tracker->games, (tracker->numGames + 1) * sizeof(GameHistory));

    if (temp == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    // Update the tracker's games pointer
    tracker->games = temp;
    printf("Enter player name: ");
    scanf("%s", tracker->games[tracker->numGames].player.name);

    printf("Enter the golf format (e.g., Stroke Play, Match Play): ");
    scanf("%s", tracker->games[tracker->numGames].scorecard.format);

    printf("Enter the number of holes in the game: ");
    scanf("%d", &tracker->games[tracker->numGames].scorecard.numHoles);

    // Validate the number of holes (assuming a reasonable range)
    if (tracker->games[tracker->numGames].scorecard.numHoles < 1 || tracker->games[tracker->numGames].scorecard.numHoles > 18) {
        printf("Invalid number of holes. Please enter a number between 1 and 18.\n");
        return;
    }

    // Additional input for course and scores can be added here

    // Assume a sample score for now
    for (int i = 0; i < tracker->games[tracker->numGames].scorecard.numHoles; i++) {
        printf("Enter score for Hole %d: ", i + 1);
        scanf("%d", &tracker->games[tracker->numGames].scorecard.scores[i]);
    }

    printf("Game recorded successfully!\n");

    // Increment the number of games
    tracker->numGames++;
}
void displayScorecardUI(Scorecard* scorecard, int numHoles) {
    printf("Hole\tScore\tPutts\n");
    for (int i = 0; i < numHoles; i++) {
        printf("%d\t%d\t%d\n", i + 1, scorecard->scores[i], scorecard->putts[i]);
    }
}
