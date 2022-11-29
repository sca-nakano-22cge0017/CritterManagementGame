#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Critter 
{
public:
  Critter(int hunger = 0, int boredom = 0, int health = 50);
  void Talk();
  void Eat(int food = 4);
  void Play(int fun = 4);
  void Walk(int exercise = 20); 
  //追加機能：散歩
  //Additional features：stroll
  void Status();
  //追加機能：状態確認
  //Additional features：status check
  void Ranaways();
  //追加機能：家出
  //Additional features：ranaways
  void Sick();
  //追加機能：病気
  //Additional features：sick

private:
  int m_Hunger;
  int m_Boredom;
  int m_Health;
  //追加機能：健康状態
  //Additional features：Health status

  int GetMood() const;
  void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int health):
  m_Hunger(hunger),
  m_Boredom(boredom),
  m_Health(health)
{};


inline int Critter::GetMood() const
{
  return (m_Hunger + m_Boredom + m_Health);
}

void Critter::PassTime(int time)
{
  m_Hunger += time;
  m_Boredom += time;
  m_Health -= time;
}

void Critter::Talk()
{
  cout << "I'm a critter and I feel ";

  int mood = GetMood();
  if (mood > 15)
  {
    cout << "mad.\n";
  }
  else if (mood > 10)
  {
    cout << "frustrated.\n";
  }
  else if (mood > 5)
  {
    cout << "okay./n";
  }
  else
  {
    cout << "happy.\n";
  }

  cout << "I am ";
	
	if (m_Hunger > 10)
	{
		cout << "extremely";
	}
  	else if (m_Hunger > 5)
	{
		cout << "very";
	}
	else
	{
		cout << "not";
	}
	
	cout << " hungry.\n";
	
	cout << "I am ";
	
	if (m_Boredom > 10)
	{
		cout << "extremely";
	}
	else if (m_Boredom > 5)
	{
		cout << "very";
	}
	else
	{
		cout << "not";
	}
	
	cout << " bored.\n";
  
  PassTime();
}

void Critter::Eat(int food)
{
  cout << "Brruppp.\n";
  m_Hunger -= food;
  if (m_Hunger < 0)
  {
    m_Hunger = 0;
  }

  PassTime();
}

void Critter::Play(int fun)
{
  cout << "Wheee!\n";

  m_Boredom -= fun;
  if (m_Boredom < 0)
  {
    m_Boredom = 0;
  }

  PassTime();
}

void Critter::Walk(int exercise) //追加機能 / Additional features
{
  //５種類の台詞からランダムに表示、健康度が上昇
  //Randomly display from 5 different lines & Increased health
  
  srand(static_cast<unsigned int>(time(0)));
  int randomNumber = rand();

  int serif = (randomNumber % 5) + 1;
  cout << "It's an outing!\n";
  switch(serif)
  {
    case 1:
      cout << "I found a beautiful flower. I give it to you!\n";
      break;
    case 2:
      cout << "Look! There is a rainbow! We are lucky.\n";
      break;
    case 3:
      cout << "That's a dog. So cute!!\n";
      break;
    case 4:
      cout << "I smell a nice smell. This is ... curry?\n";
      break;
    case 5:
      cout << "Wow!! It started to rain!! It's cold...!\n";
      break;
    default:
      cout << "It's fun to gou out!\n";
  }

  m_Health += exercise;
  if (m_Health > 100)
  {
    m_Health = 100;
  }

  PassTime();
}

void Critter::Status() //追加機能 / Additional features
{
  //Critterの状態(空腹度、退屈度、健康度)を表示する
  //Critter's status(Hunger level, Boredom level, Health level) display
  cout << "Critter's Status\n";
  cout << "Hunger Level : " << m_Hunger << "\n";
  cout << "Boredom Level : " << m_Boredom << "\n";
  cout << "Health Level : " << m_Health << "\n\n";

  PassTime();
}

void Critter::Ranaways() //追加機能 / Additional features
{
  //退屈度が一定以上だと家出する
  if (m_Boredom > 10)
  {
    cout << "\n---Critter ran　away　from home...\n";
    cout << "Apparently he was boring...\n\n";

    cout << "---A few hours later---\n\n";
    cout << "He came back!! Woohoo!!\n";
    
    m_Boredom -= 2;

    PassTime();
  }
}

void Critter::Sick() //追加機能 / Additional features
{
  //Healthが低いと体調不良、風邪になる
  if ((m_Health <= 30) && (m_Health > 20))
  {
    cout << "\nCritter seems unwell.\n";

    PassTime();
  }
  if (m_Health <= 20)
  {
    cout << "Critter seems to have caught a cold.\n";

    PassTime();
  }
}

int main()
{
  Critter crit;

  int choice;
  do
  {
    crit.Ranaways();
    crit.Sick();
    
    cout << "\nCritter Caretaker\n\n";
    cout << "0 - Quit\n";
    cout << "1 - Listen to your critter\n";
    cout << "2 - Feed your critter\n";
    cout << "3 - Play with your critter\n";
    cout << "4 - Go for a walk\n";
    cout << "5 - Check Critter's status\n\n";

    cout << "Choice: ";
    cin >> choice;

  switch(choice)
    {
      case 0:
        cout << "Good-bye.\n";
        break;
      case 1:
        crit.Talk();
        break;
      case 2:
        crit.Eat();
        break;
      case 3:
        crit.Play();
        break;
      case 4:
        crit.Walk();
        break;
      case 5:
        crit.Status();
        break;
      default:
        cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
    }
  } while (choice != 0);

  return 0;
}
