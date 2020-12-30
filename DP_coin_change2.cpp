#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <chrono>
#include <random>

using namespace std;
bool flag = true;
int counter = 0;
string test_title;
int number1; // one coin
int number2; // 5 coins
int number3; // 10 coins
int number4; // 25 coins
int number5; // holds all the number of coins that the user input
bool test = false;
// vector for coins
vector<int> coins;
void make_vec()
{
    coins.push_back(number1);
    coins.push_back(number2);
    coins.push_back(number3);
    coins.push_back(number4);
}
// one sub recursion function for spending 1 coin
void spend1coin()
{
    if (number1 > 0)
    {
        coins[0]++;
        number1--;
    }
}
// one sub recursion function for spending 5 coin

void spend5coin()
{
    if (number2 > 0)
    {
        coins[1]++;
        number2--;
    }
}
void spend10coin()
{

    if (number3 > 0)
    {
        coins[2]++;

        number3--;
    }
}
void spend25coin()
{
    if (number4 > 0)
    {
        coins[3]++;
        number4--;
    }
}
// recursively call spend coins to get a way to spend the number of coins offered in the question
// stops when the amount reach to 0;

void totalrescursion(int num)
{
    if (num == 0 || number1 == 0)
    {

        return;
    }
    if (num == 0 || number2 == 0)
    {
        return;
    }
    if (num == 0 || number3 == 0)
    {
        return;
    }
    if (num == 0 || number4 == 0)
    {
        return;
    }

    spend1coin();
    totalrescursion(num - 1);
    spend5coin();
    totalrescursion(num - 5);
    spend10coin();
    totalrescursion(num - 10);
    spend25coin();
    totalrescursion(num - 25);
}

void evaluate_command(string a)
{

    string number = string(a.c_str(), a.c_str() + a.find(" "));
    number1 = stoi(number);
    a = a.substr(a.find(" ") + 1, a.size());
    // second curtail
    number = string(a.c_str(), a.c_str() + a.find(" "));
    number2 = stoi(number);
    // third curtail
    a = a.substr(a.find(" ") + 1, a.size());
    number = string(a.c_str(), a.c_str() + a.find(" "));
    number3 = stoi(number);
    // third curtail
    a = a.substr(a.find(" ") + 1, a.size());
    number = string(a.c_str(), a.c_str() + a.size());
    number4 = stoi(number);
    int numb;
    cout << " " << number1 << " " << number2 << " " << number3 << " " << number4 << " "
         << "\n";
}

// when counter not equals to 1
void evaluate_command2(string a)
{

    number5 = stoi(a);
}

//make a vector
vector<vector<int>> totalvec(4, {0});
bool count1 = false;
int combine = 0;

void get_sum(int a)
{
    combine = a;
}
int get_factor(int a)
{

    int times = a / 5;
    int times2 = a / 10;
    int times3 = a / 25;
    if (number1 * 1 + number2 * 5 +number4 * 25>= a)
    {
        count1 = true;
        for (int i = 1; i < number2 + 1; i++)
        {
            for (int j = 1; j < number1 + 1; j++)
            {
                for(int k = 1;k<number4+1;k++){
                    if (5 * i + j + 25*k== a)
                    {
                        totalvec[0].push_back(j);
                        totalvec[1].push_back(i);
                        totalvec[2].push_back(0);
                        totalvec[3].push_back(k);
                    }
                }    
            }
        }
        
        int sum = totalvec[0][0] + totalvec[1][0]+ totalvec[3][0];
        for (int i = 0; i < totalvec[0].size(); i++)
        {
            if (totalvec[0][i] + totalvec[1][i] + totalvec[3][i]> sum)
            {
                sum = totalvec[0][i] + totalvec[1][i]+ totalvec[3][i];
                get_sum(sum);
                return i;
            }
        }
    }
    //newly added one
if (number2 * 5 + number4 * 25 >= a)
    {
        count1 = true;
        for (int i = 1; i < number2 + 1; i++)
        {
            for (int j = 1; j < number4 + 1; j++)
            {
                if (5 * i + 25* j == a)
                {
                    totalvec[0].push_back(0);
                    totalvec[1].push_back(i);
                    totalvec[2].push_back(0);
                    totalvec[3].push_back(j);
                }
            }
        }
        int sum = totalvec[1][0] + totalvec[3][0];

        for (int i = 0; i < totalvec[1].size(); i++)
        {
            if (totalvec[1][i] + totalvec[3][i] > sum)
            {
                sum = totalvec[1][i] + totalvec[3][i];
                get_sum(sum);
                return i;
            }
        }
    }

    if (number2 * 5 + number3 * 10 >= a)
    {
        count1 = true;
        for (int i = 1; i < number2 + 1; i++)
        {
            for (int j = 1; j < number3 + 1; j++)
            {
                if (5 * i + 10 * j == a)
                {
                    totalvec[0].push_back(0);
                    totalvec[1].push_back(i);
                    totalvec[2].push_back(j);
                    totalvec[3].push_back(0);
                }
            }
        }
        int sum = totalvec[1][0] + totalvec[2][0];

        for (int i = 0; i < totalvec[1].size(); i++)
        {
            if (totalvec[1][i] + totalvec[2][i] > sum)
            {
                sum = totalvec[1][i] + totalvec[2][i];
                get_sum(sum);
                return i;
            }
        }
    }
    if (number3 * 10 + number4 * 25 >= a)
    {
        count1 = true;
        for (int i = 1; i < number3 + 1; i++)
        {
            for (int j = 1; j < number4 + 1; j++)
            {
                if (10 * i + 25 * j == a)
                {
                    totalvec[0].push_back(0);
                    totalvec[1].push_back(0);
                    totalvec[2].push_back(i);
                    totalvec[3].push_back(j);
                }
            }
        }
        int sum = totalvec[2][0] + totalvec[3][0];

        for (int i = 0; i < totalvec[2].size(); i++)
        {
            if (totalvec[2][i] + totalvec[3][i] > sum)
            {
                sum = totalvec[2][i] + totalvec[3][i];
                get_sum(sum);
                return i;
            }
        }
    }
    if (number2 * 5 + number3 * 10 + number4 * 25 >= a)
    {
        count1 = true;
        for (int i = 1; i < number3 + 1; i++)
        {
            for (int j = 1; j < number4 + 1; j++)
            {
                for (int k = 1; k < number2 + 1; k++)
                {
                    if (5 * k + 10 * i + 25 * j == a)
                    {
                        totalvec[0].push_back(0);
                        totalvec[1].push_back(k);
                        totalvec[2].push_back(i);
                        totalvec[3].push_back(j);
                    }
                }
            }
        }

        int sum = totalvec[1][0] + totalvec[2][0] + totalvec[3][0];

        for (int i = 0; i < totalvec[2].size(); i++)
        {
            if (totalvec[1][i] + totalvec[2][i] + totalvec[3][i] > sum)
            {
                sum = totalvec[1][i] + totalvec[2][i] + totalvec[3][i];
                get_sum(sum);
                return i;
            }
        }
    }
    if (number1 * 1 + number4 * 25 >= a)
    {
        count1 = true;
        for (int i = 1; i < number1 + 1; i++)
        {
            for (int j = 1; j < number4 + 1; j++)
            {
                if (1 * i + 25 * j == a)
                {
                    totalvec[0].push_back(i);
                    totalvec[1].push_back(0);
                    totalvec[2].push_back(0);
                    totalvec[3].push_back(j);
                }
            }
        }
        int sum = totalvec[0][0] + totalvec[3][0];

        for (int i = 0; i < totalvec[0].size(); i++)
        {
            if (totalvec[0][i] + totalvec[3][i] > sum)
            {
                sum = totalvec[0][i] + totalvec[3][i];
                get_sum(sum);
                return i;
            }
        }
    }
      if (number1 * 1 + number2 * 5 >= a)
    {
        count1 = true;
        for (int i = 1; i < number2 + 1; i++)
        {
            for (int j = 1; j < number1 + 1; j++)
            {
                if (5 * i + j == a)
                {
                    totalvec[0].push_back(j);
                    totalvec[1].push_back(i);
                    totalvec[2].push_back(0);
                    totalvec[3].push_back(0);
                }
            }
        }
        int sum = totalvec[0][0] + totalvec[1][0];

        for (int i = 0; i < totalvec[0].size(); i++)
        {
            if (totalvec[0][i] + totalvec[1][i] > sum)
            {
                sum = totalvec[0][i] + totalvec[1][i];
                get_sum(sum);
                return i;
            }
        }
    }
    if (count1 == true && test == true)
    {
        combine = 0;
    }
    if (count1 == true && test == false)
    {
        cout << "This can not be converted\n";
    }

    return 0;
}
void substract(int a)
{
    number1 = number1 - totalvec[0][a];
    number2 = number2 - totalvec[1][a];
    number3 = number3 - totalvec[2][a];
    number4 = number4 - totalvec[3][a];
    cout << "-" << totalvec[0][a] << " " << totalvec[1][a] << " " << totalvec[2][a] << " " << totalvec[3][a] << "\n";
    cout << "----------\n";
    cout << " " << number1 << " " << number2 << " " << number3 << " " << number4 << " "
         << "\n";

    totalvec = {};
    totalvec[0] = {0};
    totalvec[1] = {0};
    totalvec[2] = {0};
    totalvec[3] = {0};
}
void initilize_vec()
{
    totalvec = {};
    totalvec[0] = {0};
    totalvec[1] = {0};
    totalvec[2] = {0};
    totalvec[3] = {0};
}

void divider(int a)
{
    cout << a << "\n";
    if (a % 1 == 0 && a != 0 && a / 1 <= number1)
    {
        int times = a / 1;

        totalvec[0].push_back(times);
        totalvec[1].push_back(0);
        totalvec[2].push_back(0);
        totalvec[3].push_back(0);
        substract(1);
    }
    else if (a % 5 == 0 && a != 0 && a / 5 <= number2)
    {
        int times = a / 5;
        test = true;
        get_factor(a);
        initilize_vec();
        if (times > combine)
        {
            totalvec[0].push_back(0);
            totalvec[1].push_back(times);
            totalvec[2].push_back(0);
            totalvec[3].push_back(0);
            substract(1);
        }
        else
        {
            substract(get_factor(a));
        }

        test = false;
    }
    else if (a % 10 == 0 && a != 0 && a / 10 <= number3)
    {
        int times = a / 10;
        test = true;
        get_factor(a);
        initilize_vec();
        if (times > combine)
        {

            totalvec[0].push_back(0);
            totalvec[1].push_back(0);
            totalvec[2].push_back(times);
            totalvec[3].push_back(0);
            substract(1);
        }
        else
        {
            substract(get_factor(a));
        }
    }
    else if (a % 25 == 0 && a != 0 && a / 25 <= number4)
    {
        int times = a / 25;
        test = true;
        get_factor(a);
        initilize_vec();
        if (times > combine)
        {
            totalvec[0].push_back(0);
            totalvec[1].push_back(0);
            totalvec[2].push_back(0);
            totalvec[3].push_back(times);
            substract(1);
        }
        else
        {
            substract(get_factor(a));
        }
    }

    else
    {
        substract(get_factor(a));
    }
}
// get userinput
void get_input()
{
    while (flag)
    {
        cout << "Please input the number of coins here: ";
        getline(cin, test_title);
        counter++;
        if (test_title == "")
        {
            cout << "Give a valid input next time\n";
            exit(3);
        }
        if (counter == 1)
            evaluate_command(test_title);

        if (counter > 1)
        {
            evaluate_command2(test_title);
            divider(number5);
        }
    }
}

int main()
{

    get_input();

   


    return 0;
}