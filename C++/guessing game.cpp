#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int secretNumber = (1 + (rand() % 50));
	int guess;
	int close;
	int guesstemp = 1;
	cout << "guess the secret number from 1 to 50: " << endl;
	cin >> guess;

	if (guess == secretNumber)
	{
		cout << "you win" << endl;
	}
	else if (guess != secretNumber)
	{
		cout << "try again" << endl;
	}
	int closetemp = sqrt(pow((secretNumber - guess), 2));
	
	do
	{
		cin >> guess;
		guesstemp = sqrt(pow((secretNumber - guess), 2));
		
		if (guess == secretNumber)
		{
			cout << "you win"<< endl;
		}
		else if (guess != secretNumber)
		{

			if (guesstemp < closetemp)
			{
				cout << "warmer, try again " << endl;
				

			}
			else if (guesstemp > closetemp)
			{
				cout << "colder, try again " << endl;
				
			}
			else if (guesstemp == closetemp)
			{
				cout << "try again" << endl;
			}
			close = guess;
			
			closetemp = sqrt(pow((secretNumber - close), 2));
		}
	} while(guess != secretNumber);
	
	


}