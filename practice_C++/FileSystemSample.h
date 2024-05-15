#pragma once
#include<filesystem>


using namespace std;

void replaceAll(string& path, const string delimiter, const string rep)
{
	string temp = path;
	size_t pos = 0;
	while ((pos = temp.find(delimiter, pos)) != string::npos)
	{
		temp.replace(pos, delimiter.length(), rep);
		pos += rep.length();
	}

	path = temp;

	return ;
}

void CreateDir() 
{
	filesystem::path root = "C:\\Users\\ryoo0\\OneDrive\\Course\\udemy\\C++\\practice_C++\\practice_C++";
	filesystem::path path1 = "Lecture";
	filesystem::path path2 = "Examples";

	path1 = root / path1 / path2;
	
	filesystem::create_directories(path1);

	filesystem::remove_all(path1.parent_path());

	return;
}

