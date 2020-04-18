#ifndef TEAM_H
#define TEAM_H
#include <string>
#include "Queue.h"

using namespace std;

class Team {
	private:
		double playerNum;
		string playerName;

		int passDistance;
		int passSuccess;
		double passTimeStamp;

		int shotHow;
		int shotWhere;
		int shotWhich;
		int onGoal;
		double shotTimeStamp;

		int goalHow;
		int goalWhere;
		int goalWhich;
		double goalTimeStamp;
		double assistNum;
		int assistWhich;
		double assistTimeStamp;

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

		int practiceType;
		double practicePoints;

		int longBallSuccess;
		int longBallWhere;
		double longBallTimeStamp;
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
		int assistAnalysisWhich;
		double assistAnalysisTimeStamp;
		int assistAnalysisPlayerPoints;

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
		

	public:
		double getPlayerNum() const;
		string getPlayerName() const;
		void initializePlayer(double, string);

		void initializePass(double, int, int, double);
		double getPassNum() const;
		int getPassDistance() const;
		int getPassSuccess() const;
		double getPassTimeStamp() const;

		void initializeShot(double, int, int, int, int, double);
		double getShotNum() const;
		int getShotHow() const;
		int getShotWhere() const;
		int getShotWhich() const;
		int getOnGoal() const;
		double getShotTimeStamp() const;

		void initializeGoal(double, int, int, int, double, double, int, double);
		double getGoalNum() const;
		int getGoalHow() const;
		int getGoalWhere() const;
		int getGoalWhich() const;
		double getGoalTimeStamp() const;
		double getAssistNum() const;
		int getAssistWhich() const;
		double getAssistTimeStamp() const;

		void initializeTackle(double, int, double);
		double getTackleNum() const;
		int getTackleHow() const;
		double getTackleTimeStamp() const;

		void initializeSteal(double, int, int, double);
		double getStealNum() const;
		int getStealHow() const;
		int getStealWhich() const;
		double getStealTimeStamp() const;

		void initializeFoul(double, int, int, double);
		double getFoulNum() const;
		int getFoulWhere() const;
		int getFoulCard() const;
		double getFoulTimeStamp() const;

		void initializeOffSides(double, double);
		double getOffSidesNum() const;
		double getOffSidesTimeStamp() const;

		void initializeGKSave(double, int, int, double);
		double getGKSaveNum() const;
		int getGKSaveHow() const;
		int getGKSaveWhich() const;
		double getGKSaveTimeStamp() const;

		void initializeAwayGoal(double, double);
		double getAwayGoalNum() const;
		double getAwayGoalTimeStamp() const;

		void initializePractice(double, int, double);
		double getPracticePoints() const;
		int getPracticeType() const;

		void initializeLongBall(int, int, int, double, int, int);
		int getLongBallNum() const;
		int getLongBallSuccess() const;
		int getLongBallWhere() const;
		double getLongBallTimeStamp() const;
		int getLongBallPlayerPoints() const;
		int getLongBallGamePoints() const;

		void initializeKeyPass(int, int, double, int, int);
		int getKeyPassNum() const;
		int getKeyPassWhere() const;
		double getKeyPassTimeStamp() const;
		int getKeyPassPlayerPoints() const;
		int getKeyPassGamePoints() const;

		void initializeTakeOn(int, int, int, double, int, int);
		int getTakeOnNum() const;
		int getTakeOnSuccess() const;
		int getTakeOnWhere() const;
		double getTakeOnTimeStamp() const;
		int getTakeOnPlayerPoints() const;
		int getTakeOnGamePoints() const;

		void initializeGoalAnalysis(int, int, int, int, double, int, int, int, int, double, int);
		int getGoalAnalysisNum() const;
		int getGoalAnalysisHow() const;
		int getGoalAnalysisWhere() const;
		int getGoalAnalysisWhich() const;
		double getGoalAnalysisTimeStamp() const;
		int getGoalAnalysisPlayerPoints() const;
		int getGoalAnalysisGamePoints() const;
		int getAssistAnalysisNum() const;
		int getAssistAnalysisWhich() const;
		double getAssistAnalysisTimeStamp() const;
		int getAssistAnalysisPlayerPoints() const;

		void initializeShotAnalysis(int, int, int, int, double, int, int);
		int getShotAnalysisNum() const;
		int getShotAnalysisHow() const;
		int getShotAnalysisWhere() const;
		int getShotAnalysisFrame()const;
		double getShotAnalysisTimeStamp() const;
		int getShotAnalysisPlayerPoints() const;
		int getShotAnalysisGamePoints() const;

		void initializeStealAnalysis(int, int, int, double, int, int);
		int getStealAnalysisNum() const;
		int getStealAnalysisHow() const;
		int getStealAnalysisWhich() const;
		double getStealAnalysisTimeStamp() const;
		int getStealAnalysisPlayerPoints() const;
		int getStealAnalysisGamePoints() const;

		void initializeTackleAnalysis(int, int, double, int, int);
		int getTackleAnalysisNum() const;
		int getTackleAnalysisHow() const;
		double getTackleAnalysisTimeStamp() const;
		int getTackleAnalysisPlayerPoints() const;
		int getTackleAnalysisGamePoints() const;

		void initializeTurnoverAnalysis(int, int, int, int, double, int, int);
		int getTurnoverAnalysisNum() const;
		int getTurnoverAnalysisWhich() const;
		int getTurnoverAnalysisWhere() const;
		int getTurnoverAnalysisHow() const;
		double getTurnoverAnalysisTimeStamp() const;
		int getTurnoverAnalysisPlayerPoints() const;
		int getTurnoverAnalysisGamePoints() const;

		void initializePressure(int, int, int, double, int, int);
		int getPressureNum() const;
		int getPressureSuccess() const;
		int getPressureWhere() const;
		double getPressureTimeStamp() const;
		int getPressurePlayerPoints() const;
		int getPressureGamePoints() const;

		void initializeAllowedShot(int, int, int, double, int);
		int getAllowedShotNum() const;
		int getAllowedShotHow() const;
		int getAllowedShotWhere() const;
		double getAllowedShotTimeStamp() const;
		int getAllowedShotGamePoints() const;

};

#endif