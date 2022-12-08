#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int getMax(std::vector<int> list)
{
	int max{};
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > max)
			max = list[i];
	}
	return max;
}

int getTopThree(std::vector<int> list)
{
	int top1{getMax(list)};
	int top2{}, top3{};
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > top2 && list[i] < top1) //gets the second largest element, enters block only if smaller than largest
		{
			top2 = list[i];
		}
		if (list[i] > top3 && list[i] < top2) //gets the third largest element, enters block only if smaller than 2nd largest
		{
			top3 = list[i];
		}
	}
	return top1 + top2 + top3;

}

std::vector<int> calorieList()
{
	std::vector<int> calorieSums{ 0 };
	std::ifstream elfList;
	std::string line;
	int i{ 0 };
	elfList.open("input.txt");
	while (std::getline(elfList, line)) //reads lines from input text file
	{
		if (line == "")					//if line empty, add new element to vector (new elf)
		{
			calorieSums.push_back(0);
			++i;
			continue;
		}
		calorieSums[i] += std::stoi(line); //add up each elf's calories
	}
	return calorieSums;
}

int main()
{
	std::vector<int> list{ calorieList() };
	int maxCalories{ getMax(list) };
	std::cout << "The fattest elf has packed " << maxCalories << " calories.\n";
	std::cout << "The top three elves have packed " << getTopThree(list) << " calories total.\n";
	return 0;
}

