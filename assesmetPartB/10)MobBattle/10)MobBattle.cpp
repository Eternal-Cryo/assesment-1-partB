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
	
	string name = "";
	int damage = 0;
	int health = 0;

	void fighterSelect(int rand)
	{
		switch (rand)
		{
		case 1:
			name = "Bear";
			damage = 12;
			health = 80;
			break;
		case 2:
			name = "Hawk";
			damage = 16;
			health = 30;
			break;


		case 3:
			name = "Badger";
			damage = 10;
			health = 60;
			break;


		case 4:
			name = "Crab";
			damage = 8;
			health = 40;
			break;

		case 5:
			name = "Giant Clam";
			damage = 6;
			health = 100;
			break;

		}

	};
};
void victoryScript(fighters& fighter01, fighters& fighter02) 
{
	if ((fighter01.health <1) && (fighter02.health < 1))
	{
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter01.name << " and " << fighter02.name << "\n";
		std::cout << " have seem to have knocked each other out resulting in a draw" << "\n";

	}
	else if (fighter02.health < 1)
	{
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter01.name << " has come out as with the win" << "\n";
	}
	else if(fighter01.health < 1)
	{
		std::cout << "-------------------------------------------------" << "\n";
		std::cout << fighter02.name << " has come out as with the win" << "\n";
	}


	//return;
}	
void battleScript(fighters& fighter01, fighters& fighter02)
{
	float bonusDamage = 1.5;
	float halfDamage = 0.5;
	int i = 1;
	for ( i = 1;   i < 100; i++)
	{
		while ((fighter01.health > 0) && (fighter02.health > 0))
		{

			
			std::cout << "----------------------------------------" << "\n";
			std::cout << "turn " << i << "\n";

			int hitRate(rand() % 20 + 1);
			if (hitRate > 15)
			{
				fighter01.health -= (fighter02.damage * bonusDamage);
				std::cout << fighter02.name << "  crit!! " << fighter01.name << " for " << (fighter02.damage * bonusDamage) << " and is now on " << fighter01.health << "hp" << "\n";

			}
			else if (hitRate > 10)
			{
				fighter01.health -= fighter02.damage;
				std::cout << fighter02.name << "  hit " << fighter01.name << " for " << fighter02.damage  << " and is now on " << fighter01.health << "hp" << "\n";
			}
			else if (hitRate > 5)
			{
				fighter01.health -= fighter02.damage * halfDamage;
				cout << fighter02.name << "  scratched   " << fighter01.name << " for " << fighter02.damage * halfDamage << " and is now on " << fighter01.health << "hp" << "\n";

			}
			else
			{
				std::cout << fighter02.name << " missed " << fighter01.name << "\n";

			}

			if ((fighter01.health < 1) || (fighter02.health < 1))
			{
				victoryScript(fighter01, fighter02);
				break;
			}

			int hitRate2(rand() % 20 + 1);
			if (hitRate2 > 15)
			{
				fighter02.health -= fighter01.damage *bonusDamage;
				cout << fighter01.name << "  crit!!  " << fighter02.name << " for " << fighter01.damage *bonusDamage << " and is now on " << fighter02.health << "hp" << "\n";

			}
			else if (hitRate2 > 10)
			{
				fighter02.health -= fighter01.damage;
				cout << fighter01.name << "  hit  " << fighter02.name << " for " << fighter01.damage << " and is now on " << fighter02.health << "hp" << "\n";

			}
			else if (hitRate2 > 5)
			{
				fighter02.health -= fighter01.damage *halfDamage;
				cout << fighter01.name << "  scratched   " << fighter02.name << " for " << fighter01.damage *halfDamage << " and is now on " << fighter02.health << "hp" << "\n";

			}
				
			else
			{
				cout << fighter01.name << " missed " << fighter02.name << "\n";

			}
			if ((fighter01.health < 1) || (fighter02.health < 1))
			{
				victoryScript(fighter01, fighter02);
				break;
			}
			i++;
		}
		
	} 


	//return; 
};














int main()
{
	srand((unsigned)time(NULL));

	fighters fighter01;
	fighter01.fighterSelect(rand() % 5 + 1);

	fighters fighter02;
	fighter02.fighterSelect(rand() % 5 + 1);
	
	
	if (fighter01.name == fighter02.name)
	{
		fighter01.name += " A";
		fighter02.name += " B";

	}

	std::cout << fighter01.name << " is fighting " << fighter02.name << "\n";

	battleScript(fighter01, fighter02);

}
