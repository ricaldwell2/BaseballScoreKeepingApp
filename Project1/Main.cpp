#include <iostream>
#include <vector>
#include <time.h>

//#pragma warning(disable : 4996)

// Prototypes of Funcitons used that are not the main() 
void MainMenu();
std::string GetCurrentDate();
std::vector<std::string> ScoreNewGame();
std::vector<std::string> ChooseTeam(bool isHomeTeam = false);
std::string GetTeamAbbreviation(std::string Team);
std::string SelectTeam(int TeamSelection);
std::string SelectBallpark(int BallparkChoice);
std::vector<int> InningData(int inningNumber, bool topInning, std::string HomeTeam, std::string AwayTeam);
std::vector<int> getBaseData(int hitType, int first, int second, int third, int runs);

int main()
{
	MainMenu();

	system("PAUSE");
	return 0;
}

void MainMenu()
{
	int choice = 0;

	while (choice <= 3 && choice >= 0)
	{
		// Options for Main Menu...TODO: Need to find other options to include in the Menu...new functionality??
		std::cout << "---------------------Baseball Scorekeeper------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Main Menu" << std::endl;
		std::cout << "1. Score a new Game" << std::endl;
		std::cout << "2. Score Game Played in the Past" << std::endl;
		std::cout << "3. View Previous Games Scored" << std::endl;
		std::cout << "4. See Overall Scoring Stats" << std::endl;
		std::cout << "5. Quit" << std::endl;
		// idea for new funcitonality 'Compare Score Card to official MLB Score Card'
		// query pitching rotation, players
		// input historic information based on data online??

		std::cout << "Input: ";
		std::cin >> choice;

		if (choice == 1)
		{
			ScoreNewGame();
		}
		else if (choice == 2)
		{
			std::cout << "Functionality Pending...Make Another Selection" << std::endl;
			MainMenu();
		}
		else if (choice == 3)
		{
			std::cout << "Functionality Pending...Make Another Selection" << std::endl;
			MainMenu();
		}
		else if (choice == 4)
		{
			std::cout << "Functionality Pending...Make Another Selection" << std::endl;
			MainMenu();
		}
		else if (choice == 5)
		{
			//system("PAUSE");
			return;
		}
		else
		{
			std::cout << "Please Select a Number Corresponding with a Menu Option" << std::endl;
			MainMenu();
		}
	}
}

std::string GetCurrentDate()
{
	// this will return the current date??
	//std::string date;

	char currDate[30];
	time_t t = time(NULL);
	//struct tm tm = *localtime(&t);
	//sprintf(currDate, "%d/%d/%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	std::cout << currDate;
	return currDate;

	//return date;
}

std::vector<std::string> ScoreNewGame()
{
	//std::string date = GetCurrentDate();
	std::string date = "06/19/2024";

	std::vector<std::string> gameData;

	// Choose Home Team Info
	std::vector <std::string> HomeTeamBallpark = ChooseTeam(true);


	std::string HomeTeam = HomeTeamBallpark[0];
	std::string Ballpark = HomeTeamBallpark[1];

	// Choose Away Team
	std::vector<std::string> AwayTeamBallpark = ChooseTeam(false);

	std::string AwayTeam = AwayTeamBallpark[0];

	std::cout << "The " << AwayTeam << " will be taking on the " << HomeTeam << " at " << Ballpark << " on " << date << std::endl;
	std::cout << std::endl;

	// These vectors hold data for both teams
	std::vector <int> HomeTeamData;
	std::vector <int> AwayTeamData;

	// Play Game through 9 innings
		// TODO: implement extra innings functionality
	//InningData(bool topInning, std::string HomeTeam, std::string AwayTeam);
	InningData(1, true, HomeTeam, AwayTeam);
	InningData(1, false, HomeTeam, AwayTeam);

	return gameData;
}

std::vector<std::string> ChooseTeam(bool isHomeTeam)
{
	int TeamChoice = 0;
	std::string TeamSelection, Ballpark, TeamSide;
	std::vector<std::string> TeamData;

	if (isHomeTeam == true)
		TeamSide = "Home";
	else
		TeamSide = "Away";

	std::cout << "Choose Number corresponding with the " << TeamSide << " Team" << std::endl;

	// Home Team Selection
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "1. Arizona Diamondbacks  | 2. Atlanta Braves      | 3. Baltimore Orioles   | 4. Boston Red Sox        | 5. Chicago Cubs" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "6. Chicago White Sox     | 7. Cincinnati Reds     | 8. Cleveland Guardians | 9. Colorado Rockies      | 10. Detroit Tigers" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "11. Houston Astros       | 12. Kansas City Royals | 13. Los Angeles Angels | 14. Los Angeles Dodgers  | 15. Miami Marlins" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "16. Milwaukee Brewers    | 17. Minnesota Twins    | 18. New York Mets      | 19. New York Yankees     | 20. Oakland Athletics" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "21. Philadelphia Philles | 22. Pittsburgh Pirates | 23. San Diego Padres   | 24. San Francisco Giants | 25. Seattle Mariners" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "26. St. Louis Cardinals  | 27. Tampa Bay Rays     | 28. Texas Rangers      | 29. Toronto Blue Jays    | 30. Washington Nationals" << std::endl;
	std::cout << "---------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "0. Back to Menu" << std::endl;

	// User Input
	std::cout << "Input: ";
	std::cin >> TeamChoice;

	while (TeamChoice <= 30 && TeamChoice >= 0)
	{
		if (TeamChoice == 0)
		{
			std::cout << "Going back to main menu." << std::endl;
			MainMenu();
			break;
		}
		
		else
		{
			TeamSelection = SelectTeam(TeamChoice);
			Ballpark = SelectBallpark(TeamChoice);
			break;
		}
	}

	// Store the Home Team and Ballpark into a vector to return Selected Team's Data
	if (isHomeTeam == true)
	{
		TeamData.push_back(TeamSelection);
		TeamData.push_back(Ballpark);
	}
	else
		TeamData.push_back(TeamSelection);

	return TeamData;
}

std::string SelectTeam(int TeamSelection)
{
	std::string Team;
	
	switch (TeamSelection)
	{
	case 1:
		Team = "Arizona Diamondbacks";
		break;
	case 2:
		Team = "Atlanta Braves";
		break;
	case 3:
		Team = "Baltimore Orioles";
		break;
	case 4:
		Team = "Boston Red Sox";
		break;
	case 5:
		Team = "Chicago Cubs";
		break;
	case 6:
		Team = "Chicago White Sox";
		break;
	case 7:
		Team = "Cincinnati Reds";
		break;
	case 8:
		Team = "Cleveland Guardians";
		break;
	case 9:
		Team = "Colorado Rockies";
		break;
	case 10:
		Team = "Detroit Tigers";
		break;
	case 11:
		Team = "Houston Astros";
		break;
	case 12:
		Team = "Kansas City Royals";
		break;
	case 13:
		Team = "Los Angeles Angels";
		break;
	case 14:
		Team = "Los Angeles Dodgers";
		break;
	case 15:
		Team = "Miami Marlins";
		break;
	case 16:
		Team = "Milwaukee Brewers";
		break;
	case 17:
		Team = "Minnesota Twins";
		break;
	case 18:
		Team = "New York Mets";
		break;
	case 19:
		Team = "New York Yankees";
		break;
	case 20:
		Team = "Oakland Athletics";
		break;
	case 21:
		Team = "Philadelphia Phillies";
		break;
	case 22:
		Team = "Pittsburgh Pirates";
		break;
	case 23:
		Team = "San Diego Padres";
		break;
	case 24:
		Team = "San Francisco Giants";
		break;
	case 25:
		Team = "Seattle Mariners";
		break;
	case 26:
		Team = "St. Louis Cardinals";
		break;
	case 27:
		Team = "Tampa Bay Rays";
		break;
	case 28:
		Team = "Texas Rangers";
		break;
	case 29:
		Team = "Toronto Blue Jays";
		break;
	case 30:
		Team = "Washington Nationals";
		break;
	}

	return Team;
}

std::string SelectBallpark(int BallparkChoice)
{
	std::string Ballpark;

	switch(BallparkChoice)
	{
	case 1:
		Ballpark = "Chase Field";
		break;
	case 2:
		Ballpark = "Sun Trust Park";
		break;
	case 3:
		Ballpark = "Camden Yards";
		break;
	case 4:
		Ballpark = "Fenway Park";
		break;
	case 5:
		Ballpark = "Wrigley Field";
		break;
	case 6:
		Ballpark = "Guaranteed Rate Ballpark";
		break;
	case 7:
		Ballpark = "Great American Ballpark";
		break;
	case 8:
		Ballpark = "Progressive Field";
		break;
	case 9:
		Ballpark = "Coors Field";
		break;
	case 10:
		Ballpark = "Comerica Park";
		break;
	case 11:
		Ballpark = "Minute Maid Park";
		break;
	case 12:
		Ballpark = "Kaufman Stadium";
		break;
	case 13:
		Ballpark = "Angel Stadium";
		break;
	case 14:
		Ballpark = "Dodgers Stadium";
		break;
	case 15:
		Ballpark = "LoanDepot Park";
		break;
	case 16:
		Ballpark = "America Family Field";
		break;
	case 17:
		Ballpark = "Target Field";
		break;
	case 18:
		Ballpark = "Citi Field";
		break;
	case 19:
		Ballpark = "Yankee Stadium";
		break;
	case 20:
		Ballpark = "Oakland Coliseum";
		break;
	case 21:
		Ballpark = "Citizens Bank Park";
		break;
	case 22:
		Ballpark = "PNC Park";
		break;
	case 23:
		Ballpark = "Petco Park";
		break;
	case 24:
		Ballpark = "Oracle Park";
		break;
	case 25:
		Ballpark = "T-Mobile Park";
		break;
	case 26:
		Ballpark = "Busch Stadium";
		break;
	case 27:
		Ballpark = "Tropicana Field";
		break;
	case 28:
		Ballpark = "Globe Life Field";
		break;
	case 29:
		Ballpark = "Rogers Centre";
		break;
	case 30:
		Ballpark = "Nationals Park";
		break;
	}
	
	return Ballpark;
}

std::string GetTeamAbbreviation(std::string Team)
{
	std::string Abbreviation;

	if (Team == "Arizona Diamondbacks")
		Abbreviation = "AZ";
	else if (Team == "Atlanta Braves")
		Abbreviation = "ATL";
	else if (Team == "Baltimore Orioles")
		Abbreviation = "BAL";
	else if (Team == "Boston Red Sox")
		Abbreviation = "BOS";
	else if (Team == "Chicago Cubs")
		Abbreviation = "CHC";
	else if (Team == "Chicago White Sox")
		Abbreviation = "CWS";
	else if (Team == "Cincinnati Reds")
		Abbreviation = "CIN";
	else if (Team == "Cleveland Guardians")
		Abbreviation = "CLE";
	else if (Team == "Colorado Rockies")
		Abbreviation = "COL";
	else if (Team == "Detroit Tigers")
		Abbreviation = "DET";
	else if (Team == "Houston Astros")
		Abbreviation = "HOU";
	else if (Team == "Kansas City Royals")
		Abbreviation = "KC";
	else if (Team == "Los Angeles Angels")
		Abbreviation = "LAA";
	else if (Team == "Los Angeles Dodgers")
		Abbreviation = "LAD";
	else if (Team == "Miami Marlins")
		Abbreviation = "MIA";
	else if (Team == "Milwaukee Brewers")
		Abbreviation = "MIL";
	else if (Team == "Minnesota Twins")
		Abbreviation = "MIN";
	else if (Team == "New York Mets")
		Abbreviation = "NYM";
	else if (Team == "New York Yankees")
		Abbreviation = "NYY";
	else if (Team == "Oakland Athletics")
		Abbreviation = "OAK";
	else if (Team == "Philadelphia Phillies")
		Abbreviation = "PHI";
	else if (Team == "Pittsburgh Pirates")
		Abbreviation = "PIT";
	else if (Team == "San Diego Padres")
		Abbreviation = "SD";
	else if (Team == "San Francisco Giants")
		Abbreviation = "SF";
	else if (Team == "Seattle Mariners")
		Abbreviation = "SEA";
	else if (Team == "St. Louis Cardinals")
		Abbreviation = "STL";
	else if (Team == "Tampa Bay Rays")
		Abbreviation = "TB";
	else if (Team == "Texas Rangers")
		Abbreviation = "TEX";
	else if (Team == "Toronto Blue Jays")
		Abbreviation = "TOR";
	else if (Team == "Washington Nationals")
		Abbreviation = "WSH";

	return Abbreviation;
}

std::vector<int> InningData(int inningNumber, bool topInning, std::string HomeTeam, std::string AwayTeam)
{
	// Inning Variables
	int pitchCount = 0, balls = 0, strikes = 0, outs = 0, hits = 0, runsHomeTeam = 0, runsAwayTeam = 0, runs = 0;
	int choice = 0;
	int hitType = 0, hitChoice = 0, strikeChoice = 0;
	int runnerOnFirst = 0, runnerOnSecond = 0, runnerOnThird = 0;
	std::string fieldingTeam;
	std::string hittingTeam;
	std::vector<int> gameData;

	// Pitch Outcomes
	if (topInning == true)
	{
		fieldingTeam = HomeTeam;
		hittingTeam = AwayTeam;
		runs = runsAwayTeam;
	}
	else
	{
		fieldingTeam = AwayTeam;
		hittingTeam = HomeTeam;
		runs = runsHomeTeam;
	}

	// Inning Data for the user
	if (topInning)
		std::cout << "Top of Inning " << inningNumber << std::endl;
	else
		std::cout << "Bottom of Inning " << inningNumber << std::endl;

	// Message to show who is hitting and how is fielding
	std::cout << "The " << fieldingTeam << " are taking the field." << std::endl;
	std::cout << "The " << hittingTeam << " are going to bat." << std::endl;
	
	// While outs is less than 3
	while (outs != 3)
	{
		while (strikes < 3 || balls < 4)
		{
			std::cout << GetTeamAbbreviation(HomeTeam) << " " << runsHomeTeam << " - " << GetTeamAbbreviation(AwayTeam) << " " << runsAwayTeam << std::endl;
			std::cout << "Field View - " << "1B: " << runnerOnFirst << " 2B: " << runnerOnSecond << " 3B: " << runnerOnThird << std::endl;
			std::cout << "Outs: " << outs << std::endl;
			std::cout << "----------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Pitch thrown, what is the outcome?" << std::endl;
			std::cout << "1. Ball" << std::endl;
			std::cout << "2. Strike" << std::endl;
			std::cout << "3. Hit" << std::endl;
			std::cin >> choice;
			// TODO: Advance Base runner (could be due to a fielding error)
			// TODO: Balk
			// TODO: Intentional Walk

			if (choice == 1)
			{
				if (balls < 3)
				{
					++balls;
					std::cout << "Balls " << balls << " : Strikes " << strikes << std::endl;
				}
				else if (balls == 3)
				{
					++balls;
					std::cout << "Ball " << balls << ", runner takes base." << std::endl;
					
					// Attempt to move runners (if possible) TODO: Work on this logic....will be needed as base for rest of application
					if (runnerOnFirst && !runnerOnSecond && !runnerOnThird)
					{
						runnerOnFirst = 0;
						runnerOnSecond = 1;
					}
					else if(!runnerOnFirst && runnerOnSecond && !runnerOnThird)
					{
						runnerOnSecond = 0;
						runnerOnThird = 1;
					}
					if (runnerOnThird)
					{
						runnerOnThird = 0;
						if (topInning)
							++runsAwayTeam;
						else
							++runsHomeTeam;
					}
					runnerOnFirst = 1;
					
					// reset balls and strikes
					balls = 0;	
					strikes = 0;
					break;
				}
				
			}
			else if (choice == 2)
			{
				if (strikes < 2)
				{
					++strikes;
					std::cout << "Balls " << balls << " : Strikes " << strikes << std::endl;
				}
				else if (strikes == 2)
				{
					++strikes;

					std::cout << "Was the Strike..." << std::endl;
					std::cout << "1. Looking" << std::endl;
					std::cout << "2. Swinging" << std::endl;
					std::cout << "3. Foul Tip" << std::endl;
					std::cin >> strikeChoice;
					
					if (strikeChoice == 1)
					{
						std::cout << "Strike " << strikes << " Strikeout Looking" << std::endl;
						++outs;

						// reset balls and strikes
						balls = 0;
						strikes = 0;
						break;
					}
					else if (strikeChoice == 2)
					{
						std::cout << "Strike " << strikes << " Strikeout Swinging" << std::endl;
						++outs;

						// reset balls and strikes
						balls = 0;
						strikes = 0;
						break;
					}
					else if (strikeChoice == 3)
					{
						std::cout << "Strike " << strikes << " Strikeout Foul Tip" << std::endl;
						++outs;

						// reset balls and strikes
						balls = 0;
						strikes = 0;
						break;
					}
					else
					{
						std::cout << "Select a response from the list." << std::endl;
					}
				}
			}
			else if (choice == 3)
			{
				// hit outcome...maybe a function?
				++hits;

				std::cout << "What is the Hit Type?" << std::endl;
				std::cout << "1. Single" << std::endl;
				std::cout << "2. Double" << std::endl;
				std::cout << "3. Triple" << std::endl;
				std::cout << "4. Home Run" << std::endl;
				std::cin >> hitChoice;

				std::vector<int> baseData = getBaseData(hitChoice, runnerOnFirst, runnerOnSecond, runnerOnThird, runs);
				
				// Add runs from baseData to the 'runs' variable
				runs += baseData[0];
				runnerOnThird = baseData[1];
				runnerOnSecond = baseData[2];
				runnerOnFirst = baseData[3];

				if (topInning == true)
					runsHomeTeam += runs;
				else
					runsAwayTeam += runs;
			}
		}
	}

	// Push game data back into vector and return vector
	gameData.push_back(pitchCount);
	gameData.push_back(hits);
	gameData.push_back(runsHomeTeam);
	gameData.push_back(runsAwayTeam);
	
	return gameData;
}

std::vector<int> getBaseData(int hitType, int first, int second, int third, int runs)
{
	//////////////////////////////////////////////
	//
	//	Guide to Hit Types
	//
	//	0 = Walk
	//	1 = Single
	//	2 = Double
	//	3 = Triple
	//	4 = Home Run
	// 
	//	NOTE: Generally advancing runner will be
	///////////////////////////////////////////////

	std::vector<int> baseData;

	int newRuns = 0;

	// In the event of a walk or a single
	if (hitType == 0 || hitType == 1)
	{

		if ((first == 1) && (second == 0) && (third == 0))
		{
			first = 1;
			second = 1;
			third = 0;
		}
		else if ((first == 1) && (second == 1) && (third == 0))
		{
			first = 1;
			second = 1;
			third = 1;
		}
		else if ((first == 1) && (second == 1) && (third == 1))
		{
			first = 1;
			second = 1;
			third = 1;
			newRuns = ++runs;
		}
		else if ((first == 1) && (second == 0) && (third == 1))
		{
			first = 1;
			second = 1;
			third = 0;
			newRuns = ++runs;
		}
		else if ((first == 0) && (second == 1) && (third == 1))
		{
			first = 1;
			second = 0;
			third = 1;
			newRuns = ++runs;
		}
		else if ((first == 0) && (second == 0) && (third == 1))
		{
			first = 1;
			second = 0;
			third = 0;
			newRuns = ++runs;
		}
		else if ((first == 0) && (second == 1) && (third == 0))
		{
			first = 1;
			second = 0;
			third = 1;
		}
		else if ((first == 0) && (second == 0) && (third == 0))
		{
			first = 1;
			second = 0;
			third = 0;
		}
		else
		{
			std::cout << "Found a base mix you haven't written yet!!!" << std::endl;
		}
	}
	else if (hitType == 2)	// Double
	{
		if ((first == 0) && (second == 0) && (third == 0))
		{
			first = 0;
			second = 1;
			third = 0;
		}
		else if ((first == 1) && (second == 1) && (third == 1))
		{
			first = 0;
			second = 1;
			third = 1;
			newRuns = runs + 2;
		}
		else if ((first == 1) && (second == 0) && (third == 0))
		{
			first = 0;
			second = 1;
			third = 1;
		}
		else if ((first == 1) && (second == 1) && (third == 0))
		{	
			first = 0;
			second = 1;
			third = 1;
			newRuns = ++runs;
		}
		else if ((first == 0) && (second == 1) && (third == 1))
		{
			first = 0;
			second = 1;
			third = 0;
			newRuns = runs + 2;
		}
		else if ((first == 0) && (second == 0) && (third == 1))
		{
			first = 0;
			second = 1;
			third = 0;
			newRuns = ++runs;
		}
		else
		{
			std::cout << "Found a base mix you haven't written yet!!!" << std::endl;
		}
	}
	else if (hitType == 3)	// Triple
	{
		if ((first == 0) && (second == 0) && (third == 0))
		{
			first = 0;
			second = 0;
			third = 1;
		}
		else if ((first == 1) && (second == 1) && (third == 1))
		{
			first = 0;
			second = 0;
			third = 1;
			newRuns = runs + 3;
		}
		else if ((first == 0) && (second == 1) && (third == 1) ||
				 (first == 1) && (second == 0) && (third == 1))
		{
			first = 0;
			second = 0;
			third = 1;
			newRuns = runs + 2;
		}
		else if ((first == 1) && (second == 0) && (third == 1))
		{
			first = 0;
			second = 0;
			third = 1;
			newRuns = runs + 2;
		}
		else
		{
			std::cout << "Found a base mix you haven't written yet!!!" << std::endl;
		}
	}
	else if (hitType == 4)	// Home Run
	{
		if ((first == 0) && (second == 0) && (third == 0))
		{
			first = 0;
			second = 0;
			third = 0;
			newRuns = ++runs;
		}
		else if ((first == 1) && (second == 1) && (third == 1))	// Grand Slam
		{
			first = 0;
			second = 0;
			third = 0;
			newRuns = runs + 4;
		}
		else if (((first == 1) && (second == 0) && (third == 0)) ||
			((first == 0) && (second == 1) && (third == 0)) ||
			((first == 0) && (second == 0) && (third == 0)))	// One Runner On
		{
			first = 0;
			second = 0;
			third = 0;
			newRuns = runs + 2;
		}
		else if (((first == 1) && (second == 1) && (third == 0)) ||
				((first == 1) && (second == 0) && (third == 1)) ||
				((first == 0) && (second == 1) && (third == 1)))	// 2 Runners On
		{
			first = 0;
			second = 0;
			third = 0;
			newRuns = runs + 3;
		}
		else
		{
			std::cout << "Found a base mix you haven't written yet!!!" << std::endl;
		}
	}
	else
	{
		std::cout << "A proper hit type was not given." << std::endl;
	}

	baseData.push_back(newRuns);
	baseData.push_back(third);
	baseData.push_back(second);
	baseData.push_back(first);

	return baseData;
}