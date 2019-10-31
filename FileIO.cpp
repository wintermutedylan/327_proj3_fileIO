/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	ifstream file;
	file.open(filename.c_str());
	if (!file.is_open()){
		contents.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}

	string line;
	string token;
	stringstream ss;

	while (getline(file, line)){
		ss.str(line);
		getline(ss, contents, '\n');
		token += contents;
		ss.clear();

	}
	contents = token;

	return SUCCESS;

	//TODO fill in
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream file;
	file.open(filename.c_str());
	if (!file.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	string data;
	for (int i = 0; i < myEntryVector.size(); ++i){
		data = myEntryVector[i];
		file << data << endl;
	}
	if (file.is_open()){
		file.close();
	}
	return SUCCESS;

	//TODO fill in
}


