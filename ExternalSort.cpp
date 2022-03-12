#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define int long long 

const int MAXOPENFILELIMIT = 512; // specific to C... can be changed using _setmaxstdio();
const int MUSTAVAILABLEFILECOUNT = 100;
const int MUSTAVAILABLEMEMORY = 200; // in MB

struct help {
	int curr_val, fileNO;
};
struct compare {
	bool operator()(const help& h1, const help& h2) const {
		return h1.curr_val > h2.curr_val;	
	}
};
// supposed to return memory in mb
int getAvailableMemory() {
	
	MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
    return status.ullTotalPhys * 1e-6;
		
}

int getFileSize(fstream& file) {
	
	std::streampos fsize = 0;
    fsize = file.tellg();
    file.seekg( 0LL, std::ios::end );
    fsize = file.tellg() - fsize;
    file.clear();
	file.seekg (0, ios::beg);
    return fsize * (1e-6); // to convert bytes to mb
    
}

// supposed to return maximumFile i can use with backup
int getAvailableFileCount() {
	return MAXOPENFILELIMIT - MUSTAVAILABLEFILECOUNT;
}

/*
 returns 
 
 1  : if whole file can be stored in memory
 0  : if external sort is needed
-1  : if sorting not possible

*/
int InitialChecks(int availableMemory, int fileSize, int maxFileAvailable) {
	
	// internalSort
	if(fileSize < availableMemory) {
		return 1;
	}
	
	int fileRequired = (fileSize + availableMemory - 1) / availableMemory;
	//no Sort is Possible under given specification
	if(fileRequired > maxFileAvailable) {
		return -1;
	}
	
	// externalSort
	return 0;
	
}



int breakIntoChunks(fstream& input, int sizeOfEachFile) {
	
	int fileName = 0;
	vector<int> arr;
	
	while(!input.eof()) {
		int temp; input >> temp;
		arr.push_back(temp);
		if(arr.size() == sizeOfEachFile) {
			
			sort(arr.begin(), arr.end());
			
			string FileName = "D:\\ExternalSortBigData\\" + to_string(fileName++) + ".txt"; 
			fstream tempFile;
			tempFile.open(FileName, ios::out);
			for(int i = 0; i < (int)arr.size() - 1; i++) {
				tempFile << arr[i] << ' ';
			}
			tempFile << arr.back();
			arr.clear();
			tempFile.close();
		}	
	}
	
	if(!arr.empty()) {
		
		sort(arr.begin(), arr.end());
		
		string FileName = "D:\\ExternalSortBigData\\" + to_string(fileName++) + ".txt"; 
		fstream tempFile;
		tempFile.open(FileName, ios::out);
		
		for(int i = 0; i < (int)arr.size() - 1; i++) {
			tempFile << arr[i] << ' ';
		}
		
		tempFile << arr.back();
		tempFile.close();
	}
	return fileName;
}


void mergeChunks(fstream& output, int filesCount) {
	
	vector<fstream> files(filesCount);
	priority_queue<help, vector<help>, compare> pq;
	for(int i = 0; i < filesCount; i++) {
		
		string fileName = "D:\\ExternalSortBigData\\" + to_string(i) + ".txt";
		
		files[i].open(fileName, ios::in);
		int temp;
		files[i] >> temp;
		
		pq.push({temp, i});
	}
	
	while(!pq.empty()) {
		help top = pq.top();
		pq.pop();
		output << top.curr_val << ' ';
		if(!files[top.fileNO].eof()) {
			int temp;
			files[top.fileNO] >> temp;
			top.curr_val = temp;
			pq.push(top);
		}
		else {
			files[top.fileNO].close();
		}
	}
	
}


int32_t main() {
	
	fstream input, output;
	input.open("D:\\ExternalSortBigData\\input.txt", ios::in); // reading from input.txt
	output.open("D:\\ExternalSortBigData\\output.txt", ios::out); // wrinting to output.txt
	
	//check if files are successfully opened
	if(!input.is_open() || !output.is_open()) {
		cout << "FILE NOT PRESENT\n";
		exit(0);
	}
	
	//calculating system specification and file size
	int availableMemory = getAvailableMemory();
	int maxFileAvailable = getAvailableFileCount();	
	int fileSize = getFileSize(input);
	
	// checking whether sorting is possible and if possible then internal or external
	int isSortingPossible = InitialChecks(availableMemory, fileSize, maxFileAvailable);

	isSortingPossible = 0;

	if(isSortingPossible == 1) {
		vector<int> arr;
		int temp;
		while(!input.eof()) {
			input >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		for(auto &x: arr) {
			output << x << ' ';
		}
	}
	else if(isSortingPossible == -1)  {
		cout << "UPGRADE YOUR COMPUTER\n";
		
	}
	else {
		int eachFileIntegerCapacity = (availableMemory * 1e6) / sizeof(long long);
		
		eachFileIntegerCapacity = 3;
		
		int countFileChunks = breakIntoChunks(input, eachFileIntegerCapacity);
		
		input.close();
		mergeChunks(output, countFileChunks);
		output.close();
	}
	
}
