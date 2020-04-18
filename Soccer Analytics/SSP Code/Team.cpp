#include "Team.h"
#include <string>

double Team::getPlayerNum() const {
	return playerNum;
}
string Team::getPlayerName() const {
	return playerName;
}
void Team::initializePlayer(double num, string nam) {
	playerNum = num;
	playerName = nam;
}


double Team::getPassNum() const {
	return playerNum;
}
int Team::getPassDistance() const {
	return passDistance;
}
int Team::getPassSuccess() const {
	return passSuccess;
}
double Team::getPassTimeStamp() const {
	return passTimeStamp;
}
void Team::initializePass(double num, int dist, int succ, double time) {
	playerNum = num;
	passDistance = dist;
	passSuccess = succ;
	passTimeStamp = time;
}

double Team::getShotNum() const {
	return playerNum;
}
int Team::getShotHow() const {
	return shotHow;
}
int Team::getShotWhere() const {
	return shotWhere;
}
int Team::getShotWhich() const {
	return shotWhich;
}
int Team::getOnGoal() const {
	return onGoal;
}
double Team::getShotTimeStamp() const {
	return shotTimeStamp;
}
void Team::initializeShot(double num, int how, int where , int which, int ong, double time) {
	playerNum = num;
	shotHow = how;
	shotWhere = where;
	shotWhich = which;
	onGoal = ong;
	shotTimeStamp = time;
}

double Team::getGoalNum() const {
	return playerNum;
}
int Team::getGoalHow() const {
	return goalHow;
}
int Team::getGoalWhere() const {
	return goalWhere;
}
int Team::getGoalWhich() const {
	return goalWhich;
}
double Team::getGoalTimeStamp() const {
	return goalTimeStamp;
}
double Team::getAssistNum() const {
	return assistNum;
}
int Team::getAssistWhich() const {
	return assistWhich;
}
double Team::getAssistTimeStamp() const {
	return assistTimeStamp;
}
void Team::initializeGoal(double num, int how, int where, int which, double time, double anum, int awhich, double atime) {
	
	playerNum = num;
	goalHow = how;
	goalWhere = where;
	goalWhich = which;
	goalTimeStamp = time;
	assistNum = anum;
	assistWhich = awhich;
	assistTimeStamp = atime;
}


double Team::getTackleNum() const {
	return playerNum;
}
int Team::getTackleHow() const {
	return tackleHow;
}
double Team::getTackleTimeStamp() const {
	return tackleTimeStamp;
}
void Team::initializeTackle(double num, int how, double time) {
	playerNum = num;
	tackleHow = how;
	tackleTimeStamp = time;
}

double Team::getStealNum() const {
	return playerNum;
}
int Team::getStealHow() const {
	return stealHow;
}
int Team::getStealWhich() const {
	return stealWhich;
}
double Team::getStealTimeStamp() const {
	return stealTimeStamp;
}
void Team::initializeSteal(double num, int how, int which, double time) {
	playerNum = num;
	stealHow = how;
	stealWhich = which;
	stealTimeStamp = time;
}


double Team::getFoulNum() const {
	return playerNum;
}
int Team::getFoulWhere() const {
	return foulWhere;
}
int Team::getFoulCard() const {
	return foulCard;
}
double Team::getFoulTimeStamp() const {
	return foulTimeStamp;
}
void Team::initializeFoul(double num, int where, int card, double time) {
	playerNum = num;
	foulWhere = where;
	foulCard = card;
	foulTimeStamp = time;
}


double Team::getOffSidesNum() const {
	return playerNum;
}
double Team::getOffSidesTimeStamp() const {
	return offSidesTimeStamp;
}
void Team::initializeOffSides(double num, double time) {
	playerNum = num;
	offSidesTimeStamp = time;
}


double Team::getGKSaveNum() const {
	return playerNum;
}
int Team::getGKSaveHow() const {
	return gkSaveHow;
}
int Team::getGKSaveWhich() const {
	return gkSaveWhich;
}
double Team::getGKSaveTimeStamp() const {
	return gkSaveTimeStamp;
}
void Team::initializeGKSave(double num, int how, int which, double time) {
	playerNum = num;
	gkSaveHow = how;
	gkSaveWhich = which;
	gkSaveTimeStamp = time;
}


double Team::getAwayGoalNum() const {
	return playerNum;
}
double Team::getAwayGoalTimeStamp() const {
	return awayGoalTimeStamp;
}
void Team::initializeAwayGoal(double num, double time) {
	playerNum = num;
	awayGoalTimeStamp = time;
}


double Team::getPracticePoints() const {
	return practicePoints;
}
int Team::getPracticeType() const {
	return practiceType;
}
void Team::initializePractice(double num, int type, double pnts) {
	playerNum = num;
	practiceType = type;
	practicePoints = pnts;
}

int Team::getLongBallNum() const {
	return playerNum;
}
int Team::getLongBallSuccess() const {
	return longBallSuccess;
}
int Team::getLongBallWhere() const {
	return longBallWhere;
}
double Team::getLongBallTimeStamp() const {
	return longBallTimeStamp;
}
int Team::getLongBallPlayerPoints() const {
	return longBallPlayerPoints;
}
int Team::getLongBallGamePoints() const {
	return longBallGamePoints;
}
void Team::initializeLongBall(int num, int succ, int whe, double ts, int player, int game) {
	playerNum = num;
	longBallSuccess = succ;
	longBallWhere = whe;
	longBallTimeStamp = ts;
	longBallPlayerPoints = player;
	longBallGamePoints = game;
}


int Team::getKeyPassNum() const {
	return playerNum;
}
int Team::getKeyPassWhere() const {
	return keyPassWhere;
}
double Team::getKeyPassTimeStamp() const {
	return keyPassTimeStamp;
}
int Team::getKeyPassPlayerPoints() const {
	return keyPassPlayerPoints;
}
int Team::getKeyPassGamePoints() const {
	return keyPassGamePoints;
}
void Team::initializeKeyPass(int num, int where, double ts, int player, int game) {
	playerNum = num;
	keyPassWhere = where;
	keyPassTimeStamp = ts;
	keyPassPlayerPoints = player;
	keyPassGamePoints = game;
}


int Team::getTakeOnNum() const {
	return playerNum;
}
int Team::getTakeOnSuccess() const {
	return takeOnSuccess;
}
int Team::getTakeOnWhere() const {
	return takeOnWhere;
}
double Team::getTakeOnTimeStamp() const {
	return takeOnTimeStamp;
}
int Team::getTakeOnPlayerPoints() const {
	return takeOnPlayerPoints;
}
int Team::getTakeOnGamePoints() const {
	return takeOnGamePoints;
}
void Team::initializeTakeOn(int num, int succ, int where, double ts, int player, int game) {
	playerNum = num;
	takeOnSuccess = succ;
	takeOnWhere = where;
	takeOnTimeStamp = ts;
	takeOnPlayerPoints = player;
	takeOnGamePoints = game;
}


int Team::getGoalAnalysisNum() const {
	return playerNum;
}
int Team::getGoalAnalysisHow() const {
	return goalAnalysisHow;
}
int Team::getGoalAnalysisWhere() const {
	return goalAnalysisWhere;
}
int Team::getGoalAnalysisWhich() const {
	return goalAnalysisWhich;
}
double Team::getGoalAnalysisTimeStamp() const {
	return goalAnalysisTimeStamp;
}
int Team::getGoalAnalysisPlayerPoints() const {
	return goalAnalysisPlayerPoints;
}
int Team::getGoalAnalysisGamePoints() const {
	return goalAnalysisGamePoints;
}
int Team::getAssistAnalysisNum() const {
	return assistNum;
}
int Team::getAssistAnalysisWhich() const {
	return assistAnalysisWhich;
}
double Team::getAssistAnalysisTimeStamp() const {
	return assistAnalysisTimeStamp;
}
int Team::getAssistAnalysisPlayerPoints() const {
	return assistAnalysisPlayerPoints;
}
void Team::initializeGoalAnalysis(int pnum, int ghow, int gwhere, int gwhich, double gts, int gplayer, int ggame, int anum, int awhich, double ats, int aplayer) {
	
	playerNum = pnum;
	goalAnalysisHow = ghow;
	goalAnalysisWhere = gwhere;
	goalAnalysisWhich = gwhich;
	goalAnalysisTimeStamp = gts;
	goalAnalysisPlayerPoints = gplayer;
	goalAnalysisGamePoints = ggame;
	assistNum = anum;
	assistAnalysisWhich = awhich;
	assistAnalysisTimeStamp = ats;
	assistAnalysisPlayerPoints = aplayer;
}


int Team::getShotAnalysisNum() const {
	return playerNum;
}
int Team::getShotAnalysisHow() const {
	return shotAnalysisHow;
}
int Team::getShotAnalysisWhere() const {
	return shotAnalysisWhere;
}
int Team::getShotAnalysisFrame()const {
	return shotAnalysisFrame;
}
double Team::getShotAnalysisTimeStamp() const {
	return shotAnalysisTimeStamp;
}
int Team::getShotAnalysisPlayerPoints() const {
	return shotAnalysisPlayerPoints;
}
int Team::getShotAnalysisGamePoints() const {
	return shotAnalysisGamePoints;
}
void Team::initializeShotAnalysis(int num, int how, int where, int frame, double ts, int player, int game) {
	playerNum = num;
	shotAnalysisHow = how;
	shotAnalysisWhere = where;
	shotAnalysisFrame = frame;
	shotAnalysisTimeStamp = ts;
	shotAnalysisPlayerPoints = player;
	shotAnalysisGamePoints = game;
}


int Team::getStealAnalysisNum() const {
	return playerNum;
}
int Team::getStealAnalysisHow() const {
	return stealAnalysisHow;
}
int Team::getStealAnalysisWhich() const {
	return stealAnalysisWhich;
}
double Team::getStealAnalysisTimeStamp() const {
	return stealAnalysisTimeStamp;
}
int Team::getStealAnalysisPlayerPoints() const {
	return stealAnalysisPlayerPoints;
}
int Team::getStealAnalysisGamePoints() const {
	return stealAnalysisGamePoints;
}
void Team::initializeStealAnalysis(int num, int how, int which, double ts, int player, int game) {
	playerNum = num;
	stealAnalysisHow = how;
	stealAnalysisWhich = which;
	stealAnalysisTimeStamp = ts;
	stealAnalysisPlayerPoints = player;
	stealAnalysisGamePoints = game;
}


int Team::getTackleAnalysisNum() const {
	return playerNum;
}
int Team::getTackleAnalysisHow() const {
	return tackleAnalysisHow;
}
double Team::getTackleAnalysisTimeStamp() const {
	return tackleAnalysisTimeStamp;
}
int Team::getTackleAnalysisPlayerPoints() const {
	return tackleAnalysisPlayerPoints;
}
int Team::getTackleAnalysisGamePoints() const {
	return tackleAnalysisGamePoints;
}
void Team::initializeTackleAnalysis(int num, int how, double ts, int player, int game) {
	playerNum = num;
	tackleAnalysisHow = how;
	tackleAnalysisTimeStamp = ts;
	tackleAnalysisPlayerPoints = player;
	tackleAnalysisGamePoints = game;
}


int Team::getTurnoverAnalysisNum() const {
	return playerNum;
}
int Team::getTurnoverAnalysisWhich() const {
	return turnoverAnalysisWhich;
}
int Team::getTurnoverAnalysisWhere() const {
	return turnoverAnalysisWhere;
}
int Team::getTurnoverAnalysisHow() const {
	return turnoverAnalysisHow;
}
double Team::getTurnoverAnalysisTimeStamp() const {
	return turnoverAnalysisTimeStamp;
}
int Team::getTurnoverAnalysisPlayerPoints() const {
	return turnoverAnalysisPlayerPoints;
}
int Team::getTurnoverAnalysisGamePoints() const {
	return turnoverAnalysisGamePoints;
}
void Team::initializeTurnoverAnalysis(int num, int which, int where, int how, double ts, int player, int game) {
	playerNum = num;
	turnoverAnalysisWhich = which;
	turnoverAnalysisWhere = where;
	turnoverAnalysisHow = how;
	turnoverAnalysisTimeStamp = ts;
	turnoverAnalysisPlayerPoints = player;
	turnoverAnalysisGamePoints = game;
}


int Team::getPressureNum() const {
	return playerNum;
}
int Team::getPressureSuccess() const {
	return pressureSuccess;
}
int Team::getPressureWhere() const {
	return pressureWhere;
}
double Team::getPressureTimeStamp() const {
	return pressureTimeStamp;
}
int Team::getPressurePlayerPoints() const {
	return pressurePlayerPoints;
}
int Team::getPressureGamePoints() const {
	return pressureGamePoints;
}
void Team::initializePressure(int num, int succ, int where, double ts, int player, int game) {
	playerNum = num;
	pressureSuccess = succ;
	pressureWhere = where;
	pressureTimeStamp = ts;
	pressurePlayerPoints = player;
	pressureGamePoints = game;
}


int Team::getAllowedShotNum() const {
	return playerNum;
}
int Team::getAllowedShotHow() const {
	return allowedShotHow;
}
int Team::getAllowedShotWhere() const {
	return allowedShotWhere;
}
double Team::getAllowedShotTimeStamp() const {
	return allowedShotTimeStamp;
}
int Team::getAllowedShotGamePoints() const {
	return allowedShotGamePoints;
}
void Team::initializeAllowedShot(int num, int how, int where, double ts, int game) {
	playerNum = num;
	allowedShotHow = how;
	allowedShotWhere = where;
	allowedShotTimeStamp = ts;
	allowedShotGamePoints = game;
}
