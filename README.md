# SCHIRA_MEZICH_CSCI2270_FinalProject
Final Project 

Summary

-This program will be an electronic score keeping program for a baseball game. Its function is to allow the user to manually input the lineup, keep track of the results of each at bat, and calculate the final score of the game as well as each batters individual averages. There will also be an option to simulate a full 9 inning game and display the results.

How to Run

-Download main.cpp, Baseball.cpp, and Baseball.h and add to a project in codeblocks

-run main 

-it will prompt user to either start a manual scorecard or to simulate a game

-if simulate game: 

                       -> user will be prompted to create the lineups for both teams by entering the players numbers when prompted
                       ->random batting averages will be assigned by generating a random number of hits between 20 and 60 for each player, and assuming 100 at bats (this allows for averages between .2 and .6)
                       -> hits will be randomly generated based on the batters average, and the average will be updated after each at bat
                       -> full 9 inning game will be simulated and results displayed
                       -> if score is tied at the end of the game game will continue simulating innings until one team wins
                       -> after 1 game user can simulate another while keeping the same lineup (stats are updated and reused) or starting a new lineup

-if start new scorecard: 

                       -> user will be prompted to create the lineups for both teams by entering the players numbers when prompted
                        
                       -> then user will be prompted to enter what each batter did in their atbat as they come up to bat
                       
                       -> this will continue until 9 innings (or one team wins in result of tie at end of 9 innings) have been played and then final scores for each team will be displayed and averages for each player will be displayed
                       
Dependencies

-none

System Requirements

-none

Group Members
Andrew Mezich
Zack Schira

Contributors
none

Open issues/bugs
FIXED Averages are not calculating properly

Phase 2 collaboration recommendation
implement option to simulate many games at once
implement different output options (eg. score by inning, print stats...)
check that at bat result input is only an int between 0 and 4/general robustness of code
