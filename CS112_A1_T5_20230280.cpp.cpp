// Program: number scrabble is to get the first three numbers from the user and their sum is 15 and also before the secon user  so he wins

// Author: author: fatema elzhraa ahmed mohamed elfiky and ID:20230280


// Version: Number of 8 program version


// Date: 2/3/2024
#include <iostream>
#include<vector>
#include<string>
using namespace std;
// this part to see the str contain any numbers or not
bool isStringNumeric(const string& str) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}
//this one to see if not number re enter again till to be a number
string validation_string(string nums1add)
{
	
	while (!isStringNumeric(nums1add))
	{
		cout << "enter a valid num\n";
		cin >> nums1add;
		
	}
	return nums1add;
}
// this one validate to be only one digit and to be in the range of the list 
string validation(string nums1add,vector<string>list)
{
	while (nums1add.size() != 1)
	{
		cout << "enter a valid num\n";
		cin >> nums1add;
	}
	bool valid = false;
	while (true)
	{
		for (int i = 0; i <list.size(); i++)
		{
			if (list[i] == nums1add) {
				valid = true;
				break;
			}
		}
		if (valid)
		{
			break;
		}
		cout << "enter a valid num\n";
		cin >> nums1add;
		nums1add = validation_string(nums1add);
	}
	return nums1add;

}
int main()
{
	//game data
	vector<string>list = {"1","2","3","4","5","6","7","8","9"};
	cout << "there is a list of numbers from 1-9\n" ;
	// printing the valid list
	cout << "[";
	for (int i = 0; i < 9 ; i++)
	{
		if (i == 8) {
			cout << list[i];
		}
		else
		{
			cout << list[i] << ",";
		}
	}
	cout << "]"<<endl;
	string nums1 = "", nums2 = "";
	// the idea of the game
	while (true)
	{
		//player1 turn
		cout << "player1:enter a num: \n";
		string nums1add;
		cin >> nums1add;
		//validtion for string
		//validtion for the range of the list
		nums1add = validation_string(nums1add);
		nums1add = validation(nums1add,list);
		nums1 = nums1 + nums1add;
		for (size_t i = 0; i < list.size(); i++)//erasing from the list 
		{
			if (list[i] == nums1add)
			{
				list.erase(list.begin()+i);
				break;
			}
		}
		bool booli1 = false;//to say if the sum is 15 is found or not 
		//all possible summations for the integers if they give 15 or not
		if (!(nums1.size() == 1 || nums1.size() == 2))
		{
			for (int i = 0; i < nums1.size()-1; i++)
			{
				for (int j = 0; j < nums1.size(); j++)
				{
					if (nums1[i] != nums1[j])
					{
						for (int k = 0; k < nums1.size(); k++)
						{
							if (nums1[i] != nums1[k] && nums1[i] != nums1[j] && nums1[k] != nums1[j])
							{
								if (int(nums1[i]) - 48 + int(nums1[k]) - 48 + int(nums1[j]) - 48 == 15)
								{
									booli1 = true;
									cout << "player1 won\n";
									break;
								}
							}
						}
					}
					if (booli1)
					{
						break;
					}
				}
				if (booli1)
				{
					break;
				}
			}
		}
		if (booli1)
		{
			break;
		}
		if (list.empty() && booli1 == false)// to see if there is a draw or not
		{
			cout << "draw\n";
			break;
		}
		cout << "now you have\n";///printing the remained og list after choosing the integers
		cout << "[";
		for (int i = 0; i < list.size(); i++)
		{
			if (i == list.size()-1) {
				cout << list[i];
			}
			else
			{
				cout << list[i] << ",";
			}
		}
		cout << "]" << endl;
		//player2 turn
		cout << "player2:enter a num: \n";
		cin >> nums1add;
		//validtion for string
		//validtion for the range of the list
		nums1add = validation_string(nums1add);
		nums1add = validation(nums1add, list);
		nums2 = nums2 + nums1add;
		for (size_t i = 0; i < list.size(); i++)//erasing what is choosen from the list 
		{
			if (list[i] == nums1add)
			{
				list.erase(list.begin() + i);
				break;
			}
		}
		bool booli2 = false;//to say if the sum 15 is found or not 
		//all possible summations for the integers if they give 15 or not
		if (!(nums2.size() == 1 || nums2.size() == 2))
		{
			for (int i = 0; i < nums2.size() - 1; i++)
			{
				for (int j = 0; j < nums2.size(); j++)
				{
					if (nums2[i] != nums2[j])
					{
						for (int k = 0; k < nums2.size(); k++)
						{
							if (nums2[i] != nums2[k] && nums2[i] != nums2[j] && nums2[k] != nums2[j])
							{
								if (int(nums2[i]) - 48 + int(nums2[k]) - 48 + int(nums2[j]) - 48 == 15)
								{
									booli2 = true;
									cout << "player2 won\n";
									break;
								}
							}
						}
					}
					if (booli2)
					{
						break;
					}
				}
				if (booli2)
				{
					break;
				}
			}
		}
		if (booli2)
		{
			break;
		}
		if (list.empty() && booli2 == false&& booli1 == false)// to say if the players are in the draw case or not  
		{                                                       
			cout << "draw\n";
			break;
		}
		cout << "now you have\n";//printing what is remained from the list 
		cout << "[";
		for (int i = 0; i < list.size(); i++)
		{
			if (i == list.size() - 1) {
				cout << list[i];
			}
			else
			{
				cout << list[i] << ",";
			}
		}
		cout << "]" << endl;

	}
	
}

