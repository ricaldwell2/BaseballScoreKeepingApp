#include <iostream>
#include <vector>
#include <ctime>

// Prototypes of Funcitons used that are not the main() 
void ScoreNewGame();
void MainMenu();
std::vector<std::string> ChooseTeam(bool isHomeTeam = false);
std::string SelectTeam(int TeamSelection);
std::string SelectBallpark(int BallparkChoice);

int main()
{
	std::cout << "---------------------Baseball Scorekeeper------------------------" << std::endl;

	MainMenu();

	//system("PAUSE");
	//return 0;
}

void MainMenu()
{
	int choice = 0;

	// Options for Main Menu...TODO: Need to find other options to include in the Menu...new functionality??
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
	do 
	{
		while (choice <= 3 && choice >= 0)
		{
			if (choice == 1)
			{
				ScoreNewGame();
				break;
			}
			else if (choice == 2)
			{
				std::cout << "Functionality Pending...Make Another Selection" << std::endl;
				MainMenu();
				break;
			}
			else if (choice == 3)
			{
				std::cout << "Functionality Pending...Make Another Selection" << std::endl;
				MainMenu();
				break;
			}
			else
			{
				std::cout << "Please Select a Number Corresponding with a Menu Option" << std::endl;
				MainMenu();
			}
		}
	} while (choice != 4);
	
}

void ScoreNewGame()
{
	std::time_t date = std::time(0); // TODO: Get current Date (maybe put functionality for user to enter date?)

	// Choose Home Team Info
	std::vector <std::string> HomeTeamData = ChooseTeam(true);

	std::string HomeTeam = HomeTeamData[0];
	std::string Ballpark = HomeTeamData[1];

	// Choose Away Team
	std::vector<std::string> AwayTeamData = ChooseTeam(false);

	std::string AwayTeam = AwayTeamData[0];

	std::cout << "The " << AwayTeam << " will be taking on the " << HomeTeam << " at " << Ballpark << " on " << date << std::endl;



	// Play Game through 9 innings
		// TODO: implement extra innings functionality
}

// TODO: Come up with a way to check isHomeTeam once rather than twice in that function
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