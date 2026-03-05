// 10)MobBattle.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>
using namespace std;


//Make a struct that represents a Mob, it should have an attack skill, a damage rating, a name and health.Write a function that determines the outcome of a battle by passing two Mobs by reference.
//In the battle function make each Mob perform an attack on the other by using their attack skills to determine the outcome somehow.How is up to you, but some form of simulated dice roll using randomness is suggested(think tabletop RPGs).
//Based on the attack outcome, apply any damage according to the damage value and adjust the health of the target Mob.
//Output a relevant string to the console using the Mob’s names e.g.“The Orc hit the Unicorn for 24 damage!”
//Commit this to version control.
//
//Add an int main().Initialize two separate Mob variables.Give them different stats and names.
//Make a loop to continuously call the battle function on the mobs until one or both have their health reduced below zero.
//Track the current ‘round’ and display it on the console before displaying the result of that round.
//Once the battle is over, (A or B run out of health), determine the outcome of the battle(either A won, B won, or both are dead and it’s a draw) and display the result to the console, and exit the loop and program.
//Test and commit this to version control.





//structs
struct fighters
{
	//the basics to the structs witht he basic infomation
	string name = "";
	int damage = 0;
	int health = 0;


	// the void function to call apon a random animal to fight 
			// by getting a random number 
	void fighterSelect(int rand)
	{		// then finging the matching number in the switch case 
		switch (rand)
		{
		case 1:
			// high health mediocer damage
			name = "Bear";
			damage = 8;
			health = 80;
			break;
		case 2:
			// high damage low health
			name = "Hawk";
			damage = 16;
			health = 30;
			break;


		case 3:
			// middle ground
			name = "Badger";
			damage = 10;
			health = 50;
			break;


		case 4:
			//high damage mediocer health
			name = "Crab";
			damage = 12;
			health = 40;
			break;

		case 5:
			//tanky but low damage
			name = "Giant Clam";
			damage = 6;
			health = 100;
			break;

		}

	};
};
// the victory script grabbing the structs of the 2 fighters 
void victoryScript(fighters& fighter01, fighters& fighter02) 
{
	//if they are both dead 
	if ((fighter01.health <1) && (fighter02.health < 1))
	{
		//says their names and that it was a draw
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter01.name << " and " << fighter02.name << "\n";
		std::cout << " have seem to have knocked each other out resulting in a draw" << "\n";

	}
	//if only fighter 02 is dead
	else if (fighter02.health < 1)
	{ //clames fighter 01 as the victor
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter01.name << " has come out as with the win" << "\n";
	}
	// if fighter 01 is dead
	else if(fighter01.health < 1)
	{ //clames fighter 02 as the victor
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter02.name << " has come out as with the win" << "\n";
	}


	//return;
}	

//the battle script holding all of the fighting between the 2 fighters using their structs 
void battleScript(fighters& fighter01, fighters& fighter02)
{
	// multiplyer for the bonus damage apon hitting a crit
	float bonusDamage = 1.5;
	// the multiplyer if they only scratch the opponent 
	float halfDamage = 0.5;
	
	// a loop for running the turn counter that doesnt end due to unpredictability of the tuns 
	for (int  i = 1; ; i++)
	{	// the internal code keeping the code running aslong as they are 
		while ((fighter01.health > 0) && (fighter02.health > 0))
		{

			// reading out the current turn 
			std::cout << "----------------------------------------" << "\n";
			std::cout << "turn " << i << "\n";

			// a rand to gain a random chance for the atacks
			int hitRate(rand() % 20 + 1);
			// hits a crit if it is 16 or more 
			if (hitRate > 15)
			{
				fighter01.health -= (fighter02.damage * bonusDamage);
				std::cout << fighter02.name << "  crit!! " << fighter01.name << " for " << (fighter02.damage * bonusDamage) << " and is now on " << fighter01.health << "hp" << "\n";

			}
			//hits regularly if it lands above 10 
			else if (hitRate > 10)
			{
				fighter01.health -= fighter02.damage;
				std::cout << fighter02.name << "  hit " << fighter01.name << " for " << fighter02.damage  << " and is now on " << fighter01.health << "hp" << "\n";
			}
			//hits regularly if it lands above 5
			else if (hitRate > 5)
			{
				fighter01.health -= fighter02.damage * halfDamage;
				cout << fighter02.name << "  scratched   " << fighter01.name << " for " << fighter02.damage * halfDamage << " and is now on " << fighter01.health << "hp" << "\n";

			}
			// if it is 5 and below the attack missed 
			else
			{
				std::cout << fighter02.name << " missed " << fighter01.name << "\n";

			}

			
			// a rand to gain a random chance for the atacks
			int hitRate2(rand() % 20 + 1);
			// hits a crit if it is 16 or more 
			if (hitRate2 > 15)
			{
				fighter02.health -= fighter01.damage *bonusDamage;
				cout << fighter01.name << "  crit!!  " << fighter02.name << " for " << fighter01.damage *bonusDamage << " and is now on " << fighter02.health << "hp" << "\n";

			}
			//hits regularly if it lands above 10 
			else if (hitRate2 > 10)
			{
				fighter02.health -= fighter01.damage;
				cout << fighter01.name << "  hit  " << fighter02.name << " for " << fighter01.damage << " and is now on " << fighter02.health << "hp" << "\n";

			}
			//hits regularly if it lands above 5
			else if (hitRate2 > 5)
			{
				fighter02.health -= fighter01.damage *halfDamage;
				cout << fighter01.name << "  scratched   " << fighter02.name << " for " << fighter01.damage *halfDamage << " and is now on " << fighter02.health << "hp" << "\n";

			}
			// if it is 5 and below the attack missed
			else
			{
				cout << fighter01.name << " missed " << fighter02.name << "\n";

			}
			// after all the damage is done it checks to see if any fighter went below 0
			if ((fighter01.health < 1) || (fighter02.health < 1))
			{	//if it does run the victory script
				victoryScript(fighter01, fighter02);
				
			}
			//if non have died up the turn counter then restart the while loop
			i++;
		}
		
	} 


	//return; 
};














int main()
{	//to make the rand random
	srand((unsigned)time(NULL));
	//creates the fighter01
	fighters fighter01;
	//then assigns the fighter
	fighter01.fighterSelect(rand() % 5 + 1);
	//same with this one
	fighters fighter02;
	fighter02.fighterSelect(rand() % 5 + 1);
	
	//if they are both the same names then add an A and B to the end of the name
	if (fighter01.name == fighter02.name)
	{
		fighter01.name += " A";
		fighter02.name += " B";

	}
	//reads out the two fighters 
	std::cout << fighter01.name << " is fighting " << fighter02.name << "\n";

	//starts the battle script using the 2 selected fighters 
	battleScript(fighter01, fighter02);

}
