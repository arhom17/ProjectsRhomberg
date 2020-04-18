//Soccer Statistical Program
//by Alex Rhomberg

#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "Team.h" //Team class for the stat tracker

using namespace std;

struct ListNode { //Structure that declares the List Node

	Team dataVal; //The data val is a Process instead of a int
	ListNode* nextNodePtr;

};

//Function prototypes
void listAppend(ListNode*&, ListNode*&, Team); //Adds the player in the Team class to the list

void loadMenuLogo(); //Function the load the menu
void printOutStat(ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, Team); // function that prints out the stats for the stat tracker
void printOutAnalysis(ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, ListNode*&, Team); // function that prints out the stats for the Analysis tracker

int main() {
	//These are the list nodes head and tails for each stat for the stat tracker
	ListNode* teamHead = nullptr, * teamTail = nullptr;
	ListNode* passHead = nullptr, * passTail = nullptr;
	ListNode* shotHead = nullptr, * shotTail = nullptr;
	ListNode* goalHead = nullptr, * goalTail = nullptr;
	ListNode* tackleHead = nullptr, * tackleTail = nullptr;
	ListNode* stealHead = nullptr, * stealTail = nullptr;
	ListNode* foulHead = nullptr, * foulTail = nullptr;
	ListNode* offSidesHead = nullptr, * offSidesTail = nullptr;
	ListNode* gkSaveHead = nullptr, * gkSaveTail = nullptr;
	ListNode* awayGoalHead = nullptr, * awayGoalTail = nullptr;

	ListNode* practiceHead = nullptr, * practiceTail = nullptr;

	ListNode* longBallHead = nullptr, * longBallTail = nullptr;
	ListNode* keyPassHead = nullptr, * keyPassTail = nullptr;
	ListNode* takeOnHead = nullptr, * takeOnTail = nullptr;
	ListNode* goalAnalysisHead = nullptr, * goalAnalysisTail = nullptr;
	ListNode* shotAnalysisHead = nullptr, * shotAnalysisTail = nullptr;
	ListNode* stealAnalysisHead = nullptr, * stealAnalysisTail = nullptr;
	ListNode* tackleAnalysisHead = nullptr, * tackleAnalysisTail = nullptr;
	ListNode* turnoverAnalysisHead = nullptr, * turnoverAnalysisTail = nullptr;
	ListNode* pressureHead = nullptr, * pressureTail = nullptr;
	ListNode* allowedShotHead = nullptr, * allowedShotTail = nullptr;

	ListNode* temp, * toDelete;

	//----------------
	fstream in;
	ofstream out;
	string fileName;
	int playerNum;     //These are the main calls
	string playerName;
	int userChoice;
	int userMenuChoice;
	//----------------

	//Below are the variables for the stat tracker
	//----------------
	int passDistance;
	int passSuccess;
	double passTimeStamp;

	int shotHow;
	int shotWhere;
	int shotWhich;
	int onGoal = 1;
	double shotTimeStamp;

	string outFileName;
	Team player;

	double startTimeFirstHalf = 0;
	double endTimeFirstHalf = 0;
	double firstHalfTime = 0;
	double startHalfTime = 0;
	double endHalfTime = 0;
	double halfTime = 0;

	int goalHow;
	int goalWhere;
	int goalWhich;
	double goalTimeStamp;
	double assistNum = 0;
	int assistWhich = 0;
	double assistTimeStamp = 0;
	int getAssist;

	int tackleHow;
	double tackleTimeStamp;

	int stealHow;
	int stealWhich;
	double stealTimeStamp;

	int foulWhere;
	int foulCard;
	double foulTimeStamp;

	double offSidesTimeStamp;

	int gkSaveHow;
	int gkSaveWhich;
	double gkSaveTimeStamp;

	double awayGoalTimeStamp;

	int userAssignedPoints;

	//----------------
	int longBallSuccess;
	int longBallWhere;
	double	longBallTimeStamp;
	int longBallPlayerPoints;
	int longBallGamePoints;

	int keyPassWhere;
	double keyPassTimeStamp;
	int keyPassPlayerPoints;
	int keyPassGamePoints;

	int takeOnSuccess;
	int takeOnWhere;
	double takeOnTimeStamp;
	int takeOnPlayerPoints;
	int takeOnGamePoints;

	int goalAnalysisHow;
	int goalAnalysisWhere;
	int goalAnalysisWhich;
	double goalAnalysisTimeStamp;
	int goalAnalysisPlayerPoints;
	int goalAnalysisGamePoints;
	int assistAnalysisWhich = 0;
	double assistAnalysisTimeStamp = 0;
	int assistAnalysisPlayerPoints = 0;

	int shotAnalysisHow;
	int shotAnalysisWhere;
	int shotAnalysisFrame;
	double shotAnalysisTimeStamp;
	int shotAnalysisPlayerPoints;
	int shotAnalysisGamePoints;

	int stealAnalysisHow;
	int stealAnalysisWhich;
	double stealAnalysisTimeStamp;
	int stealAnalysisPlayerPoints;
	int stealAnalysisGamePoints;

	int tackleAnalysisHow;
	double tackleAnalysisTimeStamp;
	int tackleAnalysisPlayerPoints;
	int tackleAnalysisGamePoints;

	int turnoverAnalysisWhich;
	int turnoverAnalysisWhere;
	int turnoverAnalysisHow;
	double turnoverAnalysisTimeStamp;
	int turnoverAnalysisPlayerPoints;
	int turnoverAnalysisGamePoints;

	int pressureSuccess;
	int pressureWhere;
	double pressureTimeStamp;
	int pressurePlayerPoints;
	int pressureGamePoints;

	int allowedShotHow;
	int allowedShotWhere;
	double allowedShotTimeStamp;
	int allowedShotGamePoints;

	//----------------

	loadMenuLogo(); //Loads the main menu logo

	//MAIN MENU
	cout << "Welcome to the Statistical Soccer Program." << endl;
	cout << endl;
	cout << "1 : Practice Tracker" << endl;
	cout << "2 : Stat Tracker" << endl;
	cout << "3 : Game Analysis" << endl;
	cout << endl;
	cout << "0 : Quit" << endl;

	cout << endl;
	cin >> userMenuChoice;

	if (userMenuChoice < 0 || userMenuChoice > 3) { //Data validation for the mani menu
		do {
			cout << "Please enter a valid number" << endl;
			cin >> userMenuChoice;
		} while (userMenuChoice < 0 || userMenuChoice > 3);
	}

		switch (userMenuChoice) { //Switch for the main menu
		case 1:
		{

			do{

				system("CLS");

				cout << "Please enter what you would like to track" << endl;
				cout << endl;
				cout << "1 : Offense" << endl;
				cout << "2 : Midfield" << endl;
				cout << "3 : Defense" << endl;
				cout << endl;
				cout << "4 : Reflex" << endl;
				cout << "5 : Kicking" << endl;
				cout << "6 : Diving" << endl;
				cout << endl;
				cout << "7 : Leadership" << endl;
				cout << "8 : Fitness" << endl;
				cout << "9 : Hustle" << endl;
				cout << endl;
				cout << "0 : Quit" << endl;

			cin >> userMenuChoice;
			cout << endl;

			
				switch (userMenuChoice) {
				case 1: //Offense
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 1, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);

					break;
				}
				case 2: //Midfield
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 2, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 3: //Defense
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 3, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 4: //Reflex
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 4, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 5: //Kicking
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 5, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 6: //Diving
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 6, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 7: //Leadership
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 7, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 8: //Fitness
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 8, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				case 9: //Hustle
				{
					cout << "Enter player num" << endl;
					cin >> playerNum;
					cout << "Enter number of points" << endl;
					cin >> userAssignedPoints;

					player.initializePractice(playerNum, 9, userAssignedPoints);

					listAppend(practiceHead, practiceTail, player);
					break;
				}
				default:
				{
					cout << "Please enter a valid input" << endl;
					break;
				}
				}
			}while (userMenuChoice != 0);

			cout << endl;
			cout << "Enter file name of file to output: ";
			cin >> outFileName;

			out.open(outFileName);

			out << "NUM\tTYPE\tPOINTS\t" << endl;
			temp = practiceHead;
			if (temp == nullptr) {
				out << "\t\t\t" << endl;
			}
			else {
				do {
					player = temp->dataVal;
					out << player.getPlayerNum() << "\t" << player.getPracticeType() << "\t" << player.getPracticePoints() << endl;
					temp = temp->nextNodePtr;
				} while (temp != practiceHead);
			}
			out << endl;

			break;
		}

		case 2: //STAT TRACKER
		{
			system("CLS"); //CLEAR SCREAN
			cout << endl;
			cout << "Stat Tracker" << endl;
			cout << endl;
			cout << endl;
			cout << "Enter file name followed by \".txt\": ";
			cin >> fileName;

			in.open(fileName);
			while (!in.is_open()) { //Data validation for file name

				cout << endl;
				cout << "Please enter a valid name: ";
				cin >> fileName;
				in.open(fileName);

			}

			cout << endl;
			cout << "File successfully opened. \n"; //Will let you know if the file opened
			cout << endl;

			//Read in the player numbers and names
			while (!in.eof()) {
				in >> playerNum;
				getline(in, playerName);

				player.initializePlayer(playerNum, playerName); //initializes the players names and numbers

				listAppend(teamHead, teamTail, player); //adds the players to the list to print out in the menu
			}

			in.close();

			system("CLS"); //CLEAR SCREAN

			cout << endl;
			cout << endl;

			cout << "Players: " << endl;
			cout << endl;

			temp = teamHead; //Prints out the list of players
			do {
				player = temp->dataVal;
				cout << player.getPlayerNum() << " -" << player.getPlayerName() << endl;
				temp = temp->nextNodePtr;
			} while (temp != teamHead);
			cout << endl;

			do {
				cout << "Please enter what you would like to do: " << endl;
				cout << "90 : Start First Half Clock" << endl;
				cout << endl;
				cin >> userChoice;

				switch (userChoice) { //Starts the clock at the beginning of the game
				case 90:
				{
					startTimeFirstHalf = clock();
					break;
				}
				}
			} while (userChoice != 90);

			system("CLS"); //CLEAR SCREAN

			do {

				cout << endl;
				cout << endl;

				cout << "Players: " << endl;
				cout << endl;

				temp = teamHead; //Prints out the list of players again
				do {
					player = temp->dataVal;
					cout << player.getPlayerNum() << " -" << player.getPlayerName() << endl;
					temp = temp->nextNodePtr;
				} while (temp != teamHead);
				cout << endl;

				//Menu for the stat taker
				cout << "Please enter what you would like to do: " << endl;
				cout << "1 : Pass" << endl;
				cout << "2 : Shot" << endl;
				cout << "3 : Goal" << endl;
				cout << "4 : Tackle" << endl;
				cout << "5 : Steal" << endl;
				cout << "6 : Foul" << endl;
				cout << "7 : Offsides" << endl;
				cout << "8 : GK Save" << endl;
				cout << "9 : Away Goal" << endl;
				cout << endl;
				cout << "89 : Start Halftime" << endl;
				cout << "90 : End Halftime" << endl;
				cout << endl;
				cout << "91 : Print Now" << endl;
				cout << endl;
				cout << "0 : Quit" << endl;
				cout << endl;
				cin >> userChoice;

				switch (userChoice) {
				case 1: //PASS STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Short - 1  Long - 2:";
					cin >> passDistance;
					while (passDistance < 1 || passDistance > 2) {
						cout << "Invalid, re-enter: ";
						cin >> passDistance;
					}
					cout << "Successful - 1  Not Successful - 2: ";
					cin >> passSuccess;
					while (passSuccess < 1 || passSuccess > 2) {
						cout << "Invalid, re-enter: ";
						cin >> passSuccess;
					}
					endTimeFirstHalf = clock();
					passTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializePass(playerNum, passDistance, passSuccess, passTimeStamp);

					listAppend(passHead, passTail, player);

					break;
				}
				case 2: //SHOT STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2: ";
					cin >> shotHow;
					while (shotHow < 1 || shotHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> shotHow;
					}
					cout << "Inside Box - 1  Outside Box - 2: ";
					cin >> shotWhere;
					while (shotWhere < 1 || shotWhere > 2) {
						cout << "Invalid, re-enter: ";
						cin >> shotWhere;
					}
					cout << "Pass - 1  Solo - 2  Corner - 3  Free Kick - 4  Penalty - 5  Team Play - 6: ";
					cin >> shotWhich;
					while (shotWhich < 1 || shotWhich > 6) {
						cout << "Invalid, re-enter: ";
						cin >> shotWhich;
					}
					cout << "On Goal - 1  Not - 2: ";
					cin >> onGoal;
					while (onGoal < 1 || onGoal > 2) {
						cout << "Invalid, re-enter: ";
						cin >> onGoal;
					}
					endTimeFirstHalf = clock();
					shotTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeShot(playerNum, shotHow, shotWhere, shotWhich, onGoal, shotTimeStamp);

					listAppend(shotHead, shotTail, player);

					break;
				}
				case 3: //GOAL STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2: ";
					cin >> goalHow;
					while (goalHow < 1 || goalHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> goalHow;
					}
					cout << "Inside Box - 1  Outside Box - 2: ";
					cin >> goalWhere;
					while (goalWhere < 1 || goalWhere > 2) {
						cout << "Invalid, re-enter: ";
						cin >> goalWhere;
					}
					cout << "Pass - 1  Solo - 2  Corner - 3  Free Kick - 4  Penalty - 5  Team Play - 6: ";
					cin >> goalWhich;
					while (goalWhich < 1 || goalWhich > 6) {
						cout << "Invalid, re-enter: ";
						cin >> goalWhich;
					}

					endTimeFirstHalf = clock();
					goalTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					cout << "Assist - 1  None - 2: ";
					cin >> getAssist;
					if (getAssist < 1 || getAssist > 2) {
						cout << "Invalid, re-enter: ";
						cin >> getAssist;
					}
					else if (getAssist == 1) {
						cout << "Player Num: ";
						cin >> assistNum;
						while (assistNum < 1 || assistNum > 99) {
							cout << "Invalid, re-enter: ";
							cin >> assistNum;
						}
						cout << "Pass - 1  Solo - 2  Corner - 3  Free Kick - 4  Penalty - 5  Team Play - 6: ";
						cin >> assistWhich;
						while (assistWhich < 1 || assistWhich > 6) {
							cout << "Invalid, re-enter: ";
							cin >> assistWhich;

							assistTimeStamp = goalTimeStamp;
						}
					}
					else {
						assistNum = 0;
						assistWhich = 0;
						assistTimeStamp = 0;
					}

					player.initializeShot(playerNum, goalHow, goalWhere, goalWhich, onGoal, goalTimeStamp);

					listAppend(shotHead, shotTail, player);

					player.initializeGoal(playerNum, goalHow, goalWhere, goalWhich, goalTimeStamp, assistNum, assistWhich, assistTimeStamp);

					listAppend(goalHead, goalTail, player);
					break;
				}
				case 4: //TACKLE STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Standing - 1  Sliding - 2:";
					cin >> tackleHow;
					while (tackleHow < 1 || tackleHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> tackleHow;
					}
					endTimeFirstHalf = clock();
					tackleTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeTackle(playerNum, tackleHow, tackleTimeStamp);

					listAppend(tackleHead, tackleTail, player);
					break;
				}
				case 5: //STEAL STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2 :";
					cin >> stealHow;
					while (stealHow < 1 || stealHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> stealHow;
					}
					cout << "Standing - 1  Sliding - 2 :";
					cin >> stealWhich;
					while (stealWhich < 1 || stealWhich > 2) {
						cout << "Invalid, re-enter: ";
						cin >> stealWhich;
					}
					endTimeFirstHalf = clock();
					stealTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeSteal(playerNum, stealHow, stealWhich, stealTimeStamp);

					listAppend(stealHead, stealTail, player);
					break;
				}
				case 6: //FOUL STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Attacking 3rd - 1  Defending 3rd - 2  Attacking half - 3  Defending half - 4:";
					cin >> foulWhere;
					while (foulWhere < 1 || foulWhere > 4) {
						cout << "Invalid, re-enter: ";
						cin >> foulWhere;
					}
					cout << "Yellow - 1  Red - 2  None - 3 :";
					cin >> foulCard;
					while (foulCard < 1 || foulCard > 3) {
						cout << "Invalid, re-enter: ";
						cin >> foulCard;
					}
					endTimeFirstHalf = clock();
					foulTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeFoul(playerNum, foulWhere, foulCard, foulTimeStamp);

					listAppend(foulHead, foulTail, player);

					break;
				}
				case 7: //OFFSIDES STAT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					endTimeFirstHalf = clock();
					offSidesTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeOffSides(playerNum, offSidesTimeStamp);

					listAppend(offSidesHead, offSidesTail, player);

					break;
				}
				case 8: //GK SAVE STAT
				{
					cout << "GK Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Hands - 2: ";
					cin >> gkSaveHow;
					while (gkSaveHow < 1 || gkSaveHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> gkSaveHow;
					}
					cout << "Solo Shot - 1  Cross - 2  Corner - 3  Free Kick - 4  Penalty - 5  Teamplay - 6: ";
					cin >> gkSaveWhich;
					while (gkSaveWhich < 1 || gkSaveWhich > 6) {
						cout << "Invalid, re-enter: ";
						cin >> gkSaveWhich;
					}
					endTimeFirstHalf = clock();
					gkSaveTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeGKSave(playerNum, gkSaveHow, gkSaveWhich, gkSaveTimeStamp);

					listAppend(gkSaveHead, gkSaveTail, player);
					break;
				}
				case 9: //AWAY GOAL STAT
				{
					cout << "GK Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter : ";
						cin >> playerNum;
					}
					endTimeFirstHalf = clock();
					awayGoalTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeAwayGoal(playerNum, awayGoalTimeStamp);

					listAppend(awayGoalHead, awayGoalTail, player);

					break;
				}
				case 89: //START HALF TIME CLOCK
				{
					endTimeFirstHalf = clock();
					firstHalfTime = ((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0;
					startHalfTime = clock();
					break;
				}
				case 90: //END HALF TIME AND START SECOND HALF
				{
					endHalfTime = clock();
					halfTime = ((endHalfTime - startHalfTime) / CLOCKS_PER_SEC) / 60.0;
					break;
				}
				case 91: //PRINT STATS MID GAME
				{
					printOutStat(passHead, shotHead, goalHead, tackleHead, stealHead, foulHead, offSidesHead, gkSaveHead, awayGoalHead, temp, player);
				}
				default:
				{
					cout << "Please enter a valid input" << endl;
					break;
				}
				}

				system("CLS"); //CLEAR SCREAN

			} while (userChoice != 0);

			//Function print stats after the user quits
			printOutStat(passHead, shotHead, goalHead, tackleHead, stealHead, foulHead, offSidesHead, gkSaveHead, awayGoalHead, temp, player);
			break;
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		case 3:
		{
			system("CLS"); //CLEAR SCREAN

			system("CLS"); //CLEAR SCREAN
			cout << endl;
			cout << "Game Analysis" << endl;
			cout << endl;
			cout << endl;
			cout << "Enter file name followed by \".txt\": ";
			cin >> fileName;

			in.open(fileName);
			while (!in.is_open()) { //Data validation for file name

				cout << endl;
				cout << "Please enter a valid name: ";
				cin >> fileName;
				in.open(fileName);

			}

			cout << endl;
			cout << "File successfully opened. \n"; //Will let you know if the file opened
			cout << endl;

			//Read in the player numbers and names
			while (!in.eof()) {
				in >> playerNum;
				getline(in, playerName);

				player.initializePlayer(playerNum, playerName); //initializes the players names and numbers

				listAppend(teamHead, teamTail, player); //adds the players to the list to print out in the menu
			}

			in.close();

			system("CLS"); //CLEAR SCREAN

			cout << endl;
			cout << endl;

			cout << "Players: " << endl;
			cout << endl;

			temp = teamHead; //Prints out the list of players
			do {
				player = temp->dataVal;
				cout << player.getPlayerNum() << " -" << player.getPlayerName() << endl;
				temp = temp->nextNodePtr;
			} while (temp != teamHead);
			cout << endl;

			do {
				cout << "Please enter what you would like to do: " << endl;
				cout << "90 : Start First Half Clock" << endl;
				cout << endl;
				cin >> userChoice;

				switch (userChoice) { //Starts the clock at the beginning of the game
				case 90:
				{
					startTimeFirstHalf = clock();
					break;
				}
				}
			} while (userChoice != 90);

			system("CLS"); //CLEAR SCREAN

			do {

				cout << endl;
				cout << endl;

				cout << "Players: " << endl;
				cout << endl;

				temp = teamHead; //Prints out the list of players again
				do {
					player = temp->dataVal;
					cout << player.getPlayerNum() << " -" << player.getPlayerName() << endl;
					temp = temp->nextNodePtr;
				} while (temp != teamHead);
				cout << endl;

				//Menu for the stat taker
				cout << "Please enter what you would like to do: " << endl;
				cout << "1 : Long Ball" << endl;
				cout << "2 : Key Pass" << endl;
				cout << "3 : Take On" << endl;
				cout << "4 : Goal" << endl;
				cout << "5 : Shot" << endl;
				cout << "6 : Steal" << endl;
				cout << "7 : Tackle" << endl;
				cout << "8 : Turnover" << endl;
				cout << "9 : Pressure" << endl;
				cout << "0 : Allowed Shot" << endl;
				cout << endl;
				cout << "89 : Start Halftime" << endl;
				cout << "90 : End Halftime" << endl;
				cout << endl;
				cout << "91 : Print Now" << endl;
				cout << endl;
				cout << "99 : Quit" << endl;
				cout << endl;
				cin >> userChoice;

				switch (userChoice) {
				case 1: //LONG BALL
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Successful - 1  Not Successful - 2:";
					cin >> longBallSuccess;
					while (longBallSuccess < 1 || longBallSuccess > 2) {
						cout << "Invalid, re-enter: ";
						cin >> longBallSuccess;
					}
					cout << "Def Left - 1  Def Center - 2  Def Right - 3  Mid Left - 4  Mid Center - 5  Mid Right - 6  Att Left - 7  Att Center - 8  Att Right - 9: ";
					cin >> longBallWhere;
					while (longBallWhere < 1 || longBallWhere > 9) {
						cout << "Invalid, re-enter: ";
						cin >> longBallWhere;
					}
					endTimeFirstHalf = clock();
					longBallTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					if (longBallSuccess == 1) {
						longBallPlayerPoints = 2;
						longBallGamePoints = 2;
					}
					else if (longBallSuccess == 2) {
						longBallPlayerPoints = 1;
						longBallGamePoints = -1;
					}
					else {
						longBallPlayerPoints = 0;
						longBallGamePoints = 0;
					}

					player.initializeLongBall(playerNum, longBallSuccess, longBallWhere, longBallTimeStamp, longBallPlayerPoints, longBallGamePoints);

					listAppend(longBallHead, longBallTail, player);

					break;
				}
				case 2: //KEY PASS
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Att Left - 1  Att Center - 2  Att Right - 3: ";
					cin >> keyPassWhere;
					while (keyPassWhere < 1 || keyPassWhere > 3) {
						cout << "Invalid, re-enter: ";
						cin >> keyPassWhere;
					}

					keyPassPlayerPoints = 1;
					keyPassGamePoints = 1;

					endTimeFirstHalf = clock();
					keyPassTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					player.initializeKeyPass(playerNum, keyPassWhere, keyPassTimeStamp, keyPassPlayerPoints, keyPassGamePoints);

					listAppend(keyPassHead, keyPassTail, player);

					break;
				}
				case 3: //TAKE ON
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Successful - 1  Not Successful - 2: ";
					cin >> takeOnSuccess;
					while (takeOnSuccess < 1 || takeOnSuccess > 2) {
						cout << "Invalid, re-enter: ";
						cin >> takeOnSuccess;
					}
					cout << "Att Left - 1  Att Center - 2  Att Right - 3: ";
					cin >> takeOnWhere;
					while (takeOnWhere < 1 || takeOnWhere > 3) {
						cout << "Invalid, re-enter: ";
						cin >> takeOnWhere;
					}

					endTimeFirstHalf = clock();
					takeOnTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					if (takeOnSuccess == 1) {
						takeOnPlayerPoints = 1;
						takeOnGamePoints = 2;
					}
					else if (takeOnSuccess == 2) {
						takeOnPlayerPoints = 0;
						takeOnGamePoints = 1;
					}
					else {
						takeOnPlayerPoints = 0;
						takeOnGamePoints = 0;
					}

					player.initializeTakeOn(playerNum, takeOnSuccess, takeOnWhere, takeOnTimeStamp, takeOnPlayerPoints, takeOnGamePoints);

					listAppend(takeOnHead, takeOnTail, player);

					break;
				}
				case 4: //GOAL
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2:";
					cin >> goalAnalysisHow;
					while (goalAnalysisHow < 1 || goalAnalysisHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> goalAnalysisHow;
					}
					cout << "Inside Box - 1  Outside Box - 2:";
					cin >> goalAnalysisWhere;
					while (goalAnalysisWhere < 1 || goalAnalysisWhere > 2) {
						cout << "Invalid, re-enter: ";
						cin >> goalAnalysisWhere;
					}
					cout << "Pass - 1  Solo - 2  Corner - 3  Free Kick - 4  Penalty - 5  Team Play - 6:";
					cin >> goalAnalysisWhich;
					while (goalAnalysisWhich < 1 || goalAnalysisWhich > 6) {
						cout << "Invalid, re-enter: ";
						cin >> goalAnalysisWhich;
					}

					endTimeFirstHalf = clock();
					goalAnalysisTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					goalAnalysisPlayerPoints = 4;
					goalAnalysisGamePoints = 6;

					cout << "Assist - 1  None - 2: ";
					cin >> getAssist;
					if (getAssist < 1 || getAssist > 2) {
						cout << "Invalid, re-enter: ";
						cin >> getAssist;
					}
					else if (getAssist == 1) {
						cout << "Player Num: ";
						cin >> assistNum;
						while (assistNum < 1 || assistNum > 99) {
							cout << "Invalid, re-enter: ";
							cin >> assistNum;
						}

						assistAnalysisWhich = goalAnalysisWhich;

						assistAnalysisTimeStamp = goalAnalysisTimeStamp;
							
						assistAnalysisPlayerPoints = 2;
						
					}
					else {
						assistNum = 0;
						assistAnalysisWhich = 0;
						assistAnalysisTimeStamp = 0;
						assistAnalysisPlayerPoints = 0;
					}


					player.initializeGoalAnalysis(playerNum, goalAnalysisHow, goalAnalysisWhere, goalAnalysisWhich, goalAnalysisTimeStamp, goalAnalysisPlayerPoints, goalAnalysisGamePoints, assistNum, assistAnalysisWhich, assistAnalysisTimeStamp, assistAnalysisPlayerPoints);

					listAppend(goalAnalysisHead, goalAnalysisTail, player);

					break;
				}
				case 5: //SHOT
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2 :";
					cin >> shotAnalysisHow;
					while (shotAnalysisHow < 1 || shotAnalysisHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> shotAnalysisHow;
					}
					cout << "Inside Box - 1  Outside Box - 2 :";
					cin >> shotAnalysisWhere;
					while (shotAnalysisWhere < 1 || shotAnalysisWhere > 2) {
						cout << "Invalid, re-enter: ";
						cin >> shotAnalysisWhere;
					}
					cout << "On Frame - 1  Off Frame - 2 :";
					cin >> shotAnalysisFrame;
					while (shotAnalysisFrame < 1 || shotAnalysisFrame > 2) {
						cout << "Invalid, re-enter: ";
						cin >> shotAnalysisFrame;
					}
					endTimeFirstHalf = clock();
					shotAnalysisTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					if (shotAnalysisFrame == 1) {
						shotAnalysisPlayerPoints = 2;
						shotAnalysisGamePoints = 2;
					}
					else if (shotAnalysisFrame == 2) {
						shotAnalysisPlayerPoints = 1;
						shotAnalysisGamePoints = 2;
					}
					else {
						shotAnalysisPlayerPoints = 0;
						shotAnalysisGamePoints = 0;
					}

					player.initializeShotAnalysis(playerNum, shotAnalysisHow, shotAnalysisWhere, shotAnalysisFrame, shotAnalysisTimeStamp, shotAnalysisPlayerPoints, shotAnalysisGamePoints);

					listAppend(shotAnalysisHead, shotAnalysisTail, player);
					break;
				}
				case 6: //STEAL
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2: ";
					cin >> stealAnalysisHow;
					while (stealAnalysisHow < 1 || stealAnalysisHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> stealAnalysisHow;
					}
					cout << "Standing - 1  Sliding - 2:";
					cin >> stealAnalysisWhich;
					while (stealAnalysisWhich < 1 || stealAnalysisWhich > 2) {
						cout << "Invalid, re-enter: ";
						cin >> stealAnalysisWhich;
					}
					endTimeFirstHalf = clock();
					stealAnalysisTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					stealAnalysisPlayerPoints = 1;
					stealAnalysisGamePoints = -1;

					player.initializeStealAnalysis(playerNum, stealAnalysisHow, stealAnalysisWhich, stealAnalysisTimeStamp, stealAnalysisPlayerPoints, stealAnalysisGamePoints);

					listAppend(stealAnalysisHead, stealAnalysisTail, player);

					break;
				}
				case 7: //TACKLE
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Standing - 1  Sliding - 2:";
					cin >> tackleAnalysisHow;
					while (tackleAnalysisHow < 1 || tackleAnalysisHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> tackleAnalysisHow;
					}
					endTimeFirstHalf = clock();
					tackleAnalysisTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					tackleAnalysisPlayerPoints = 1;
					tackleAnalysisGamePoints = -2;

					player.initializeTackleAnalysis(playerNum, tackleAnalysisHow, tackleAnalysisTimeStamp, tackleAnalysisPlayerPoints, tackleAnalysisGamePoints);

					listAppend(tackleAnalysisHead, tackleAnalysisTail, player);

					break;
				}
				case 8: //TURNOVER
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter: ";
						cin >> playerNum;
					}
					cout << "Offensive Breakdown - 1  Defensive Breakdown - 2: ";
					cin >> turnoverAnalysisWhich;
					while (turnoverAnalysisWhich < 1 || turnoverAnalysisWhich > 2) {
						cout << "Invalid, re-enter: ";
						cin >> turnoverAnalysisWhich;
					}
					cout << "Def Left - 1  Def Center - 2  Def Right - 3  Mid Left - 4  Mid Center - 5  Mid Right - 6  Att Left - 7  Att Center - 8  Att Right - 9: ";
					cin >> turnoverAnalysisWhere;
					while (turnoverAnalysisWhere < 1 || turnoverAnalysisWhere > 9) {
						cout << "Invalid, re-enter: ";
						cin >> turnoverAnalysisWhere;
					}
					cout << "Pass - 1  Standing - 2: ";
					cin >> turnoverAnalysisHow;
					while (turnoverAnalysisHow < 1 || turnoverAnalysisHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> turnoverAnalysisHow;
					}
					endTimeFirstHalf = clock();
					turnoverAnalysisTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					turnoverAnalysisPlayerPoints = -2;
					turnoverAnalysisGamePoints = -1;

					player.initializeTurnoverAnalysis(playerNum, turnoverAnalysisWhich, turnoverAnalysisWhere, turnoverAnalysisHow, turnoverAnalysisTimeStamp, turnoverAnalysisPlayerPoints, turnoverAnalysisGamePoints);

					listAppend(turnoverAnalysisHead, turnoverAnalysisTail, player);
					break;
				}
				case 9: //PRESSURE
				{
					cout << "Player Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter : ";
						cin >> playerNum;
					}
					cout << "Successful - 1  Not Successful - 2: ";
					cin >> pressureSuccess;
					while (pressureSuccess < 1 || pressureSuccess > 2) {
						cout << "Invalid, re-enter: ";
						cin >> pressureSuccess;
					}
					cout << "Att Left - 1  Att Center - 2  Att Right - 3: ";
					cin >> pressureWhere;
					while (pressureWhere < 1 || pressureWhere > 3) {
					cout << "Invalid, re-enter: ";
					cin >> pressureWhere;
					}
					endTimeFirstHalf = clock();
					pressureTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					if (pressureSuccess == 1) {
						pressurePlayerPoints = 1;
						pressureGamePoints = 3;
					}
					else if (pressureSuccess == 2) {
						pressurePlayerPoints = 0;
						pressureGamePoints = 2;
					}
					else {
						pressurePlayerPoints = 0;
						pressureGamePoints = 0;
					}

					player.initializePressure(playerNum, pressureSuccess, pressureWhere, pressureTimeStamp, pressurePlayerPoints, pressureGamePoints);

					listAppend(pressureHead, pressureTail, player);

					break;
				}
				case 0: //AWAY GOAL STAT
				{
					cout << "GK Num: ";
					cin >> playerNum;
					while (playerNum < 1 || playerNum > 99) {
						cout << "Invalid, re-enter : ";
						cin >> playerNum;
					}
					cout << "Foot - 1  Head - 2: ";
					cin >> allowedShotHow;
					while (allowedShotHow < 1 || allowedShotHow > 2) {
						cout << "Invalid, re-enter: ";
						cin >> allowedShotHow;
					}
					cout << "Inside Box - 1  Outside Box - 2: ";
					cin >> allowedShotWhere;
					while (allowedShotWhere < 1 || allowedShotWhere > 2) {
						cout << "Invalid, re-enter: ";
						cin >> allowedShotWhere;
					}
					endTimeFirstHalf = clock();
					allowedShotTimeStamp = (((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0) - halfTime;

					allowedShotGamePoints = -4;

					player.initializeAllowedShot(playerNum, allowedShotHow, allowedShotWhere, allowedShotTimeStamp, allowedShotGamePoints);

					listAppend(allowedShotHead, allowedShotTail, player);

					break;
				}
				case 89: //START HALF TIME CLOCK
				{
					endTimeFirstHalf = clock();
					firstHalfTime = ((endTimeFirstHalf - startTimeFirstHalf) / CLOCKS_PER_SEC) / 60.0;
					startHalfTime = clock();
					break;
				}
				case 90: //END HALF TIME AND START SECOND HALF
				{
					endHalfTime = clock();
					halfTime = ((endHalfTime - startHalfTime) / CLOCKS_PER_SEC) / 60.0;
					break;
				}
				case 91: //PRINT STATS MID GAME
				{
					printOutAnalysis(longBallHead, keyPassHead, takeOnHead, goalAnalysisHead, shotAnalysisHead, stealAnalysisHead, tackleAnalysisHead, turnoverAnalysisHead, pressureHead, allowedShotHead, temp, player);
				}
				default:
				{
					cout << "Please enter a valid input" << endl;
					break;
				}
				}

				system("CLS"); //CLEAR SCREAN

			} while (userChoice != 99);

			//Function print stats after the user quits
			printOutAnalysis(longBallHead, keyPassHead, takeOnHead, goalAnalysisHead, shotAnalysisHead, stealAnalysisHead, tackleAnalysisHead, turnoverAnalysisHead, pressureHead, allowedShotHead, temp, player);

			break;
		}
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		default:
		{
			system("CLS"); //CLEAR SCREAN

			cout << "Thank you for using the program" << endl;
			break;
		}
		}

	//system("pause");
	return 0;
}

//------------------------------------------------------------------------------------------------------------------
//FUNCTIONS are below

//List append function
void listAppend(ListNode*& h, ListNode*& t, Team p) {
	ListNode* n;
	n = new ListNode;
	n->dataVal = p;
	n->nextNodePtr = nullptr;

	if (h == nullptr) {
		h = n;
		t = n;
	}
	else {
		t->nextNodePtr = n;
		t = n;
	}
	t->nextNodePtr = h; //makes it circular
}

void loadMenuLogo() { // This is the menu logo that is displayed at the beginning of the program
	cout << endl;
	cout << "     *********************************************************************************     " << endl;
	cout << "     *********************************************************************************     " << endl;
	cout << "     **                                                                             **     " << endl;
	cout << "     **                                                                             **     " << endl;
	cout << "     **              *********           *********          ********                **     " << endl;
	cout << "     **             ***********         ***********         *********               **     " << endl;
	cout << "     **            ***                 ***                  ***     ***             **     " << endl;
	cout << "     **            ***                 ***                  ***      ***            **     " << endl;
	cout << "     **            ***                 ***                  ***      ***            **     " << endl;
	cout << "     **            ***                 ***                  ***      ***            **     " << endl;
	cout << "     **             **********          **********          ***    ***              **     " << endl;
	cout << "     **              **********          **********         *********               **     " << endl;
	cout << "     **                      ***                 ***        ******                  **     " << endl;
	cout << "     **                      ***                 ***        ***                     **     " << endl;
	cout << "     **                      ***                 ***        ***                     **     " << endl;
	cout << "     **                      ***                 ***        ***                     **     " << endl;
	cout << "     **             ***********         ***********         ***                     **     " << endl;
	cout << "     **              *********           *********          ***                     **     " << endl;
	cout << "     **                                                                             **     " << endl;
	cout << "     **                                                                             **     " << endl;
	cout << "     *********************************************************************************     " << endl;
	cout << "     *********************************************************************************     " << endl;
	cout << "                                                                                           " << endl;
	cout << "                                     By Alex Rhomberg                                      " << endl;
	cout << "                                      version  1.0                                         " << endl;
	cout << endl;
}

//Function goes through each list and prints out to the text file
void printOutStat(ListNode*& pass, ListNode*& shot, ListNode*& goal, ListNode*& tackle, ListNode*& steal, ListNode*& foul, ListNode*& offsides, ListNode*& gksave, ListNode*& awaygoal, ListNode*& tem, Team play) {
	ofstream out;
	string outFileName;
	
	cout << endl;
	cout << "Enter file name of file to output: ";
	cin >> outFileName;

	out.open(outFileName);

	out << "Pass\tPassDistance\tPassSuccess\tPassTimeStamp\t" << endl;
	tem = pass;
	if (tem == nullptr) {
		out << "\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getPassNum() << "\t" << play.getPassDistance() << "\t" << play.getPassSuccess() << "\t" << play.getPassTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != pass);
	}
	out << endl;

	out << "Shot\tShowHow\tShowWhere\tShotWhich\tOnGoal\tPassTimeStamp\t" << endl;
	tem = shot;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getShotNum() << "\t" << play.getShotHow() << "\t" << play.getShotWhere() << "\t" << play.getShotWhich() << "\t" << play.getOnGoal() << "\t" << play.getShotTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != shot);
	}
	out << endl;

	out << "Goal\tGoalHow\tGoalWhere\tGoalWhich\tGoalTimeStamp\tAssist\tAssistWhich\tAssistTimeStamp\t" << endl;
	tem = goal;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getGoalNum() << "\t" << play.getGoalHow() << "\t" << play.getGoalWhere() << "\t" << play.getGoalWhich() << "\t" << play.getGoalTimeStamp() << "\t" << play.getAssistNum() << "\t" << play.getAssistWhich() << "\t" << play.getAssistTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != goal);
	}
	out << endl;

	out << "Tackle\tTackleHow\tTackleTimeStamp\t" << endl;
	tem = tackle;
	if (tem == nullptr) {
		out << "\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTackleNum() << "\t" << play.getTackleHow() << "\t" << play.getTackleTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != tackle);
	}
	out << endl;

	out << "Steal\tStealHow\tStealWhich\tStealTimeStamp\t" << endl;
	tem = steal;
	if (tem == nullptr) {
		out << "\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getStealNum() << "\t" << play.getStealHow() << "\t" << play.getStealWhich() << "\t" << play.getStealTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != steal);
	}
	out << endl;

	out << "Foul\tFoulWhere\tCard\tFoulTimeStamp\t" << endl;
	tem = foul;
	if (tem == nullptr) {
		out << "\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getFoulNum() << "\t" << play.getFoulWhere() << "\t" << play.getFoulCard() << "\t" << play.getFoulTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != foul);
	}
	out << endl;

	out << "OffSides\toffSidesTimeStamp\t" << endl;
	tem = offsides;
	if (tem == nullptr) {
		out << "\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getOffSidesNum() << "\t" << play.getOffSidesTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != offsides);
	}
	out << endl;

	out << "GKSave\tGKSaveHow\tGKSaveWhich\tGKSaveTimeStamp\t" << endl;
	tem = gksave;
	if (tem == nullptr) {
		out << "\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getGKSaveNum() << "\t" << play.getGKSaveHow() << "\t" << play.getGKSaveWhich() << "\t" << play.getGKSaveTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != gksave);
	}
	out << endl;

	out << "AwayGoal\tAwayGoalTimeStamp\t" << endl;
	tem = awaygoal;
	if (tem == nullptr) {
		out << "\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getAwayGoalNum() << "\t" << play.getAwayGoalTimeStamp() << endl;
			tem = tem->nextNodePtr;
		} while (tem != awaygoal);
	}
	out << endl;

	out.close();
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//Function goes through each list and prints out to the text file
void printOutAnalysis(ListNode*& longBall, ListNode*& keyPass, ListNode*& takeOn, ListNode*& goalAnalysis, ListNode*& shotAnalysis, ListNode*& stealAnalysis, ListNode*& tackleAnalysis, ListNode*& turnoverAnalysis, ListNode*& pressure, ListNode*& allowedShot, ListNode*& tem, Team play) {
	ofstream out;
	string outFileName;

	cout << endl;
	cout << "Enter file name of file to output: ";
	cin >> outFileName;

	out.open(outFileName);

	out << "LongBall\tLongBallSuccess\tLongBallWhere\tLongBallTimeStamp\tLongBallPlayerPoints\tLongBallGamePoints\t" << endl;
	tem = longBall;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getLongBallNum() << "\t" << play.getLongBallSuccess() << "\t" << play.getLongBallWhere() << "\t" << play.getLongBallTimeStamp() << "\t" << play.getLongBallPlayerPoints() << "\t" << play.getLongBallGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != longBall);
	}
	out << endl;

	out << "KeyPass\tKeyPassWhere\tKeyPassTimeStamp\tKeyPassPlayerPoints\tKeyPassGamePoints\t" << endl;
	tem = keyPass;
	if (tem == nullptr) {
		out << "\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getKeyPassNum() << "\t" << play.getKeyPassWhere() << "\t" << play.getKeyPassTimeStamp() << "\t" << play.getKeyPassPlayerPoints() << "\t" << play.getKeyPassGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != keyPass);
	}
	out << endl;

	out << "TakeOn\tTakeOnSuccess\tTakeOnWhere\tTakeOnTimeStamp\tTakeOnPlayerPoints\tTakeOnGamePoints\t" << endl;
	tem = takeOn;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTakeOnNum() << "\t" << play.getTakeOnSuccess() << "\t" << play.getTakeOnWhere() << "\t" << play.getTakeOnTimeStamp() << "\t" << play.getTakeOnPlayerPoints() << "\t" << play.getTakeOnGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != takeOn);
	}
	out << endl;

	out << "Goal\tGoalHow\tGoalWhere\tGoalWhich\tGoalTimeStamp\tGoalPlayerPoints\tGoalGamePoints\tAssist\tAssistWhich\tAssistTimeStamp\tAssistPlayerPoints\t" << endl;
	tem = goalAnalysis;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getGoalAnalysisNum() << "\t" << play.getGoalAnalysisHow() << "\t" << play.getGoalAnalysisWhere() << "\t" << play.getGoalAnalysisWhich() << "\t" << play.getGoalAnalysisTimeStamp() << "\t" << play.getGoalAnalysisPlayerPoints() << "\t" << play.getGoalAnalysisGamePoints() << "\t" << play.getAssistAnalysisNum() << "\t" << play.getAssistAnalysisWhich() << "\t" << play.getAssistAnalysisTimeStamp() << "\t" << play.getAssistAnalysisPlayerPoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != goalAnalysis);
	}
	out << endl;

	out << "Shot\tShotHow\tShotWhere\tShotFrame\tShotTimeStamp\tShotPlayerPoints\tShotGamePoints\t" << endl;
	tem = shotAnalysis;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getShotAnalysisNum() << "\t" << play.getShotAnalysisHow() << "\t" << play.getShotAnalysisWhere() << "\t" << play.getShotAnalysisFrame() << "\t" << play.getShotAnalysisTimeStamp() << "\t" << play.getShotAnalysisPlayerPoints() << "\t" << play.getShotAnalysisGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != shotAnalysis);
	}
	out << endl;

	out << "Steal\tStealHow\tStealWhich\tStealTimeStamp\tStealPlayerPoints\tStealGamePoints\t" << endl;
	tem = stealAnalysis;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getStealAnalysisNum() << "\t" << play.getStealAnalysisHow() << "\t" << play.getStealAnalysisWhich() << "\t" << play.getStealAnalysisTimeStamp() << "\t" << play.getStealAnalysisPlayerPoints() << "\t" << play.getStealAnalysisGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != stealAnalysis);
	}
	out << endl;

	out << "Tackle\tTackleHow\tTackleTimeStamp\tTacklePlayerPoints\tTackleGamePoints\t" << endl;
	tem = tackleAnalysis;
	if (tem == nullptr) {
		out << "\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTackleAnalysisNum() << "\t" << play.getTackleAnalysisHow() << "\t" << play.getTackleAnalysisTimeStamp() << "\t" << play.getTackleAnalysisPlayerPoints() << "\t" << play.getTackleAnalysisGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != tackleAnalysis);
	}
	out << endl;

	out << "Turnover\tTurnoverWhich\tTurnoverWhere\tTurnoverHow\tTurnoverTimeStamp\tTurnoverPlayerPoints\tTurnoverGamePoints\t" << endl;
	tem = turnoverAnalysis;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTurnoverAnalysisNum() << "\t" << play.getTurnoverAnalysisWhich() << "\t" << play.getTurnoverAnalysisWhere() << "\t" << play.getTurnoverAnalysisHow() << "\t" << play.getTurnoverAnalysisTimeStamp() << "\t" << play.getTurnoverAnalysisPlayerPoints() << "\t" << play.getTurnoverAnalysisGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != turnoverAnalysis);
	}
	out << endl;

	out << "Pressure\tPressureSuccess\tPressureWhere\tPressureTimeStamp\tPressurePlayerPoints\tPressureGamePoints\t" << endl;
	tem = pressure;
	if (tem == nullptr) {
		out << "\t\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getPressureNum() << "\t" << play.getPressureSuccess() << "\t" << play.getPressureWhere() << "\t" << play.getPressureTimeStamp() << "\t" << play.getPressurePlayerPoints() << "\t" << play.getPressureGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != pressure);
	}
	out << endl;

	out << "AllowedShot\tAllowedShotHow\tAllowedShotWhere\tAllowedShotTimeStamp\tAllowedShotGamePoints\t" << endl;
	tem = allowedShot;
	if (tem == nullptr) {
		out << "\t\t\t\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getAllowedShotNum() << "\t" << play.getAllowedShotHow() << "\t" << play.getAllowedShotWhere() << "\t" << play.getAllowedShotTimeStamp() << "\t" << play.getAllowedShotGamePoints() << endl;
			tem = tem->nextNodePtr;
		} while (tem != allowedShot);
	}
	out << endl;

	out << "x\ty\t" << endl;

	tem = longBall;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem ->dataVal;
			out << play.getLongBallTimeStamp() << "\t" << play.getLongBallGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != longBall);
	}

	tem = keyPass;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getKeyPassTimeStamp() << "\t" << play.getKeyPassGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != keyPass);
	}

	tem = takeOn;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTakeOnTimeStamp() << "\t" << play.getTakeOnGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != takeOn);
	}

	tem = goalAnalysis;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getGoalAnalysisTimeStamp() << "\t" << play.getGoalAnalysisGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != goalAnalysis);
	}

	tem = shotAnalysis;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getShotAnalysisTimeStamp() << "\t" << play.getShotAnalysisGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != shotAnalysis);
	}

	tem = stealAnalysis;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getStealAnalysisTimeStamp() << "\t" << play.getStealAnalysisGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != stealAnalysis);
	}

	tem = tackleAnalysis;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTackleAnalysisTimeStamp() << "\t" << play.getTackleAnalysisGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != tackleAnalysis);
	}

	tem = turnoverAnalysis;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getTurnoverAnalysisTimeStamp() << "\t" << play.getTurnoverAnalysisGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != turnoverAnalysis);
	}

	tem = pressure;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getPressureTimeStamp() << "\t" << play.getPressureGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != pressure);
	}

	tem = allowedShot;
	if (tem == nullptr) {
		out << "\t\t" << endl;
	}
	else {
		do {
			play = tem->dataVal;
			out << play.getAllowedShotTimeStamp() << "\t" << play.getAllowedShotGamePoints() << "\t" << endl;
			tem = tem->nextNodePtr;
		} while (tem != allowedShot);
	}

	out << endl;


	out.close();
}