#pragma once
#include <raylib.h>

#include "gamestates.h"
#include "globals.h"


class skillcheckscreen: public gamestate
{
private:
	void DrawNormalSkillCheck(void); //DRAW SKILL CHECK FUNCTION
	void DrawHexRuinSkillCheck(void);
	void DrawDecisiveStrikeSkillCheck(void);

	void GenerateNormalSkillCheckZone(void); //GENERATION SKILL CHECK FUNCTION
	void GenerateHexRuinSkillCheckZone(void);
	void GenerateDecisiveStrikeSkillCheckZone(void);

	void NormalSkillCheck(void); // NORMAL SKILL CHECK
	void HexRuinSkillCheck(void); //HEX RUIN SKILL CHECK
	void DecisiveStrikeSkillCheck(void);

	void CheckForDoctorSkillCheck(void);
	void CheckForNormalSkillCheck(void);
	void CheckForRuinSkillCheck(void);
	void CheckForDSSkillCheck(void);
	void TempDSandDoctor(void);

	Vector2 middle = { screenWidth / 2, screenHeight / 2 };

	const float spawnLocation = 90.0f; //STARTING LOCATION OF SKILL CHECK NEEDLE
	const int spawnZone1 = -30; //SPAWN ZONES FOR SKILL CHECKS
	const int spawnZone2 = -270;

	const int doctorspawnZone1 = 200;
	const int doctorspawnZone2 = 450;

	const Rectangle startbutton = { middle.x, 340, 100, 50 };
	const Rectangle stopbutton = { middle.x - 100, 340, 100, 50 };
	const Rectangle achievbutton = { 10, 224, 200, 50 }; //A LOT OF VARIABLES
	const Rectangle Help = { 10 , 279, 200 ,50 };
	const Rectangle UnnervingPresenceButton = {10, 354, 50, 20};
	const Rectangle DoctorSkillCheckButton = { 10, 390, 50, 20 };
	bool startbuttonpressed = false;
	bool stopbuttonpressed = false;
	bool achievementspressed = false; //VARIABLES FOR WHEN BUTTONS ARE PRESSED
	bool skillcheckactive = false;
	bool helpbuttonpressed = false;

	bool UnnervingPresence = false;
	bool DoctorSkillCheck = false;

	const int radius = 100; //RADIUS OF CIRCLE

	int score = 0;
	int combo = 0; //SCORE VARIABLES
	int missed = 0;

	int gameMode = 0;
	bool guiDropdownboxEditmode = false;

	Vector2 greatSkillCheckZone = {0, 0};
	Vector2 goodSkillCheckZone = {0, 0}; //VARIABLES FOR SKILL CHECK ZONES
	float rotationAngle = spawnLocation;
	bool moveSkillCheck = true;
	bool buttonclicked = false;

	double timer;
	double spawnSkillcheckTimer; //TIMERS

public:
	void logic(void) final override;
	void render(void) final override;

	skillcheckscreen(void); //SKILL CHECK SCREEN
	~skillcheckscreen(void) final override;
};

extern Vector2 middle;
