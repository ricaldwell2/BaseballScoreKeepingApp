#include <iostream>
#include <vector>
#include <time.h>

//#pragma warning(disable : 4996)

// Prototypes of Funcitons used that are not the main() 
void MainMenu();
std::string GetCurrentDate();
std::vector<std::string> ScoreNewGame();
std::vector<std::string> ChooseTeam(bool isHomeTeam = false);
std::string SelectTeam(int TeamSelection);
std::string SelectBallpark(int BallparkChoice);

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
		std::cout << "2. View Previous Games Scored" << std::endl;
		std::cout << "3. See Overall Scoring Stats" << std::endl;
		std::cout << "4. Quit" << std::endl;
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
	struct tm tm = *localtime(&t);
	sprintf(currDate, "%d/%d/%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
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
	std::vector <std::string> HomeTeamData = ChooseTeam(true);

	std::string HomeTeam = HomeTeamData[0];
	std::string Ballpark = HomeTeamData[1];

	// Choose Away Team
	std::vector<std::string> AwayTeamData = ChooseTeam(false);

	std::string AwayTeam = AwayTeamData[0];

	std::cout << "The " << AwayTeam << " will be taking on the " << HomeTeam << " at " << Ballpark << " on " << date << std::endl;
	std::cout << std::endl;



	// Play Game through 9 innings
		// TODO: implement extra innings functionality

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

std::vector<int> InningData(bool topInning, std::string HomeTeam, std::string AwayTeam)
{
	// Inning Variables
	int pitchCount = 0, balls = 0, strikes = 0, outs = 0, runs = 0;
	int choice = 0;
	std::string fieldingTeam;
	std::string hittingTeam;

	// Pitch Outcomes
	if (topInning == true)
	{
		fieldingTeam = HomeTeam;
		hittingTeam = AwayTeam;
	}
	else
	{
		fieldingTeam = AwayTeam;
		hittingTeam = HomeTeam;
	}

	// Message to show who is hitting and how is fielding
	std::cout << "The " << fieldingTeam << " is taking the field." << std::endl;
	std::cout << "The " << hittingTeam << " is going to bat." << std::endl;
	
	// While outs is less than 3
	while (outs != 3)
	{
		while (strikes < 3 || balls < 4)
		{
			std::cout << "Pitch thrown, what is the outcome?" << std::endl;
			std::cout << "1. Ball" << std::endl;
			std::cout << "2. Strike" << std::endl;
			std::cout << "3. Hit" << std::endl;
			std::cout << "4. Ball 4" << std::endl;
			std::cout << "5. Strike 3 Swinging" << std::endl;
			std::cout << "6. Strike 3 Looking" << std::endl;
			std::cin >> choice;

			if (choice == 1)
			{
				++balls;
				std::cout << "Balls " << balls << " : Strikes " << strikes << std::endl;
			}
			else if (choice == 2)
			{
				++strikes;
				std::cout << "Balls " << balls << " : Strikes" << strikes << std::endl;
			}
			else if (choice == 3)
			{
				// hit outcome...maybe a function?
			}
			else if (choice == 4)
			{
				if (balls < 3)
					std::cout << "Unable to make this choice, since there haven't been enough balls." << std::endl;
				else
				{
					++balls;
					std::cout << "Ball 4, runner takes base." << std::endl;
				}
			}
			else if (choice == 5)
			{
				if (strikes < 2)
					std::cout << "Unable to make this choice, since there haven't been enough strikes." << std::endl;
				else
				{
					++strikes;
					std::cout << "Strike 3, runner is out." << std::endl;
					++outs;
				}
			}
			else if (choice == 6)
			{
				if (strikes < 2)
					std::cout << "Unable to make this choice, since there haven't been enough strikes." << std::endl;
				else
				{
					++strikes;
					std::cout << "Strike 3, runner is out." << std::endl;
					++outs;
				}
			}
		}
	}

	
		

}