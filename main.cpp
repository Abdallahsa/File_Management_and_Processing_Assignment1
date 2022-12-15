#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <filesystem>
using namespace std;
//Abdallah Saleh
struct PIndex {
	int offset;
	char ID[13];
};
struct PIndexD {
	int offset;
	char ID[30];
};

struct SecIndex
{
	char depID[30];
	int pointer;
};
struct SecIndexD
{
	char name[50];
	int pointer;
};
struct node {
	char id[30];
	short next;
};

void swap(PIndex* a, PIndex* b)
{
	PIndex t = *a;
	*a = *b;
	*b = t;
}

void swap(PIndexD* a, PIndexD* b)
{
	//overload swap for department
	PIndexD t = *a;
	*a = *b;
	*b = t;
}
void swapS(SecIndex* a, SecIndex* b)
{
	//swap in employee second index
	SecIndex t = *a;
	*a = *b;
	*b = t;
}
void swapS_D(SecIndexD* a, SecIndexD* b)
{
	//swap in Department second index
	SecIndexD t = *a;
	*a = *b;
	*b = t;
}

int partition(PIndex arr[], int low, int high)
{
	int pivot = atoi(arr[high].ID);    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].ID) <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partition(PIndexD arr[], int low, int high)
{
	//overload partition for department
	int pivot = atoi(arr[high].ID);    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].ID) <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partitionS(SecIndex arr[], int low, int high)
{
	//partition in Employee second Index
	int pivot = atoi(arr[high].depID);
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (atoi(arr[j].depID) <= pivot)
		{
			i++;    // increment index of smaller element
			swapS(&arr[i], &arr[j]);
		}
	}
	swapS(&arr[i + 1], &arr[high]);
	return (i + 1);
}
int partitionS_D(SecIndexD arr[], int low, int high)
{
	//partition in Department second Index
	char pivot[50];
	strcpy_s(pivot, arr[high].name);
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot

		if (strcmp(arr[j].name, pivot) <= 0)
		{
			i++;    // increment index of smaller element
			swapS_D(&arr[i], &arr[j]);
		}
	}
	swapS_D(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(PIndex arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void quickSort(PIndexD arr[], int low, int high)
{
	//overload quick sort for Department
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void quickSortS(SecIndex arr[], int low, int high)
{
	//qick sort in employee second index
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partitionS(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortS(arr, low, pi - 1);
		quickSortS(arr, pi + 1, high);
	}
}
void quickSortS_D(SecIndexD arr[], int low, int high)
{
	//qick sort in department second index
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partitionS_D(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortS_D(arr, low, pi - 1);
		quickSortS_D(arr, pi + 1, high);
	}
}

int indexBinarySearch(PIndex arr[], int p, int r, char* num) {
	// binary search in Primary index
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].ID) == atoi(num))
			return mid;
		if (atoi(arr[mid].ID) > atoi(num))
			return indexBinarySearch(arr, p, mid - 1, num);
		if (atoi(arr[mid].ID) < atoi(num))
			return indexBinarySearch(arr, mid + 1, r, num);
	}
	return -1;
}
int indexBinarySearch(PIndexD arr[], int p, int r, char* num) {
	//overload for department
	// binary search in Primary index
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].ID) == atoi(num))
			return mid;
		if (atoi(arr[mid].ID) > atoi(num))
			return indexBinarySearch(arr, p, mid - 1, num);
		if (atoi(arr[mid].ID) < atoi(num))
			return indexBinarySearch(arr, mid + 1, r, num);
	}
	return -1;
}
int indexBinarySearchS(SecIndex arr[], int p, int r, char* depID) {
	// binary search in secondry index in employee by dep_id
	if (p <= r) {
		int mid = (p + r) / 2;
		if (atoi(arr[mid].depID) == atoi(depID))
			return mid;
		if (atoi(arr[mid].depID) > atoi(depID))
			return indexBinarySearchS(arr, p, mid - 1, depID);
		if (atoi(arr[mid].depID) < atoi(depID))
			return indexBinarySearchS(arr, mid + 1, r, depID);
	}
	return -1;
}
int indexBinarySearchS_D(SecIndexD arr[], int p, int r, char* name) {
	//binary search in secondry index in department search by name
	if (p <= r) {
		int mid = (p + r) / 2;
		if (strcmp(arr[mid].name, name) == 0)
			return mid;
		if (strcmp(arr[mid].name, name) > 0)
			return indexBinarySearchS_D(arr, p, mid - 1, name);
		if (strcmp(arr[mid].name, name) < 0)
			return indexBinarySearchS_D(arr, mid + 1, r, name);
	}
	return -1;
}


class employee {


public:
	const static int PIndexESize = 100;
	SecIndex SIndex[PIndexESize];
	node linkedList[PIndexESize];
	PIndex index[PIndexESize];
	int PIndexCounter = 0;
	int SIndexCounter = 0;
	int linkPtr = 0;
	string dataFilePath = "employees.txt";
	string pIndexFilePath = "empIndex.txt";
	string sIndexFilePath = "emp_sIndex.txt";
	string sIndexLinkFilePath = "empLinkedList.txt";
	char employeeID[13];
	char deptID[30];
	char employeeName[50];
	char employeePosition[50];
	int indexOfArrayOfEmployeeID = 0;
	int arr[100];
	void savePIndex() {
		ofstream PIfile(pIndexFilePath, ios::trunc);
		for (int i = 0; i < PIndexCounter; i++)
		{
			PIndex temp = index[i];
			PIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		PIfile.close();
	}
	void saveSIndex() {
		ofstream SIfile(sIndexFilePath, ios::trunc);
		for (int i = 0; i < SIndexCounter; i++)
		{
			SecIndex temp = SIndex[i];
			SIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		SIfile.close();
	}
	void saveSLIndex() {

		ofstream Lfile(sIndexLinkFilePath, ios::trunc);
		for (int i = 0; i < linkPtr; i++)
		{
			node temp = linkedList[i];
			Lfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		Lfile.close();
	}
	void writeEmployee(employee &temp) {
			//enter data of employee by user

			ofstream outfile;
			outfile.open(dataFilePath, ios::app | ios::out | ios::binary);
			//******************************
			const int maxSize = 147;
			char buffer[maxSize];
			char id[13];
			char depID[30];
			strcpy_s(depID, temp.deptID);
			strcpy_s(id, temp.employeeID);
			//set deliameters
			temp = setDelemitars(temp);
			strcpy_s(buffer, temp.employeeID);
			strcat_s(buffer, temp.deptID);
			strcat_s(buffer, temp.employeeName);
			strcat_s(buffer, temp.employeePosition);
			//*****************************
			int len = strlen(buffer);
			outfile.seekp(0, ios::end);
			int address = outfile.tellp();

			//write new employee in employee file
			outfile.write((char*)&len, sizeof(len));
			outfile.write(buffer, len);

			writePIndex(id, address);//add new index to primary index
			writeSecIndex(depID, id);
			outfile.close();
			savePIndex();
			saveSIndex();
			saveSLIndex();

		}

	employee setDelemitars(employee &temp) {
		strcat_s(temp.employeeID, "|");
		strcat_s(temp.deptID, "|");
		strcat_s(temp.employeeName, "|");
		strcat_s(temp.employeePosition, "|");
		return temp;
	}
	void writeSecIndex(char *depID, char*id) {
		int found;
		if (SIndexCounter >= 1)
			found = indexBinarySearchS(SIndex, 0, SIndexCounter - 1, depID);
		else found = -1;
		if (found == -1) {
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);
			linkedList[linkPtr].next = -1;

			//new index in secIndex
			strcpy_s(SIndex[SIndexCounter].depID, depID);
			SIndex[SIndexCounter].pointer = linkPtr;
			quickSortS(SIndex, 0, SIndexCounter);//sort SIndex
			linkPtr++;
			SIndexCounter++;
		}
		else {
			//edit pointer of element are found in secIndex
			linkedList[linkPtr].next = SIndex[found].pointer;
			SIndex[found].pointer = linkPtr;
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);

			linkPtr++;
		}
		savePIndex();
		saveSIndex();
		saveSLIndex();


	}
	void writePIndex(char* id, int address) {
		strcpy_s(index[PIndexCounter].ID, id);
		index[PIndexCounter].offset = address;
		quickSort(index, 0, PIndexCounter);//sort primary index in ID
		PIndexCounter++;
		savePIndex();
		saveSIndex();
		saveSLIndex();
	}
	void readEmployeeByID(char* id) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Employee not exisit\n";
			return;
		}
		int len;
		employee e;
		outfile.seekg(index[address].offset, ios::beg);
		outfile.read((char*)&len, sizeof(len));
		char *buffer = new char[len];
		outfile.read(buffer, len);

		istringstream stream(buffer);
		stream.getline(e.employeeID, 13, '|');
		stream.getline(e.deptID, 30, '|');
		stream.getline(e.employeeName, 50, '|');
		stream.getline(e.employeePosition, 50, '|');
		printEmployee(e);
		outfile.close();
		delete buffer;
	}
	employee readEmployeeByIDForQ(char* id) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Employee not exisit\n";

		}
		else {
			int len;
			employee e;
			outfile.seekg(index[address].offset, ios::beg);
			outfile.read((char*)&len, sizeof(len));
			char *buffer = new char[len];
			outfile.read(buffer, len);

			istringstream stream(buffer);
			stream.getline(e.employeeID, 13, '|');
			stream.getline(e.deptID, 30, '|');
			stream.getline(e.employeeName, 50, '|');
			stream.getline(e.employeePosition, 50, '|');
			outfile.close();
			delete buffer;
			return e;
		}

	}
	void readEmployeeByDepID() {
		char depID[30];
		cout << "enter Department id :";
		cin >> depID;

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearchS(SIndex, 0, SIndexCounter, depID);
		if (address == -1)
		{
			cout << "\nthis Employee not exists\n";
			return;
		}

		int pointer = SIndex[address].pointer;
		int next = linkedList[pointer].next;
		cout << "*****************\n";
		readEmployeeByID(linkedList[pointer].id);
		while (next != -1) {
			cout << "*****************\n";
			readEmployeeByID(linkedList[next].id);
			next = linkedList[next].next;
		}
	}
	int* readEmployeeByDepIDForQ(char* depID) {
		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearchS(SIndex, 0, SIndexCounter, depID);
		if (address == -1)
		{
			cout << "\nthis Employee not exists\n";

		}
		else {
			int pointer = SIndex[address].pointer;
			int next = linkedList[pointer].next;
			arr[indexOfArrayOfEmployeeID] = atoi(linkedList[pointer].id);
			indexOfArrayOfEmployeeID++;
			while (next != -1) {
				arr[indexOfArrayOfEmployeeID] = atoi(linkedList[next].id);
				indexOfArrayOfEmployeeID++;
				next = linkedList[next].next;

			}
			return arr;
		}
	}
	void deleteEmployee() {
		char id[30];
		employee e;
		cout << "Enter Employee ID :";
		cin >> id;
		fstream f(dataFilePath, ios::binary | ios::out | ios::in);
		int address = indexBinarySearch(index,0,PIndexCounter,id);
		if (address == -1)
		{
			cout << "\n Employee not found\n";
			return;
		}
		//shift pIndex
		f.seekp(index[address].offset + 4, ios::beg);
		f << '*';

		for (int i = address; i<PIndexCounter-1; i++)
			index[i] = index[i + 1];
		PIndexCounter--;
		for (int i = 0; i < linkPtr ; i++) {
			if (linkedList[i].id == id) {
				if (linkedList[i].next != -1) {
					e = readEmployeeByIDForQ(linkedList[linkedList[i].next].id);
					int found = indexBinarySearchS(SIndex, 0, SIndexCounter, e.deptID);
					SIndex[found].pointer = linkedList[i].next;
					linkedList[i].next = -1;
					strcpy_s(linkedList[i].id, "-1");
				}
				else {
					e = readEmployeeByIDForQ(linkedList[i].id);
					int found = indexBinarySearchS(SIndex, 0, SIndexCounter, e.deptID);
					for (int i = found; i < SIndexCounter - 1; i++)
						SIndex[i] = SIndex[i + 1];
					SIndexCounter--;
				}
				break;
			}
		}
		f.close();
		savePIndex();
		saveSIndex();
		saveSLIndex();
	}
	void printEmployee(employee &e) {
		if (e.employeeID[0] == '*') {
			cout << "\nthis Employee not exisit\n";
			return;
		}
		cout << "Employee ID : " << e.employeeID << endl;
		cout << "Employee DepID : " << e.deptID << endl;
		cout << "Employee Name : " << e.employeeName << endl;
		cout << "Employee Pos : " << e.employeePosition << endl;
	}
	void loadPIndex() {

		ifstream PIfile(pIndexFilePath);
		/*
		PIfile.open(indexFilePath, ios::binary | ios::in);
		PIfile.seekg(0, ios::beg);
		*/
		PIndexCounter = 0;
		while (true)
		{

			PIndex temp;
			PIfile.read((char*)&temp, sizeof(temp));
			if (PIfile.eof())
				break;
			index[PIndexCounter] = temp;
			PIndexCounter++;
		}

		PIfile.close();
	}

	void loadSIndex() {

		ifstream SIfile(sIndexFilePath);
		SIndexCounter = 0;
		while (true)
		{

			SecIndex temp;
			SIfile.read((char*)&temp, sizeof(temp));
			if (SIfile.eof())
				break;
			SIndex[SIndexCounter] = temp;
			SIndexCounter++;
		}

		SIfile.close();
	}


	void loadSLIndex() {

		ifstream Lfile(sIndexLinkFilePath);
		linkPtr = 0;
		while (true)
		{

			node temp;
			Lfile.read((char*)&temp, sizeof(temp));
			if (Lfile.eof())
				break;
			linkedList[linkPtr] = temp;
			linkPtr++;
		}


		Lfile.close();
	}


};

class department {



public:
	const static int PIndexESize = 100;
	SecIndexD SIndex[PIndexESize];
	node linkedList[PIndexESize];
	PIndexD index[PIndexESize];
	int PIndexCounter = 0;
	int SIndexCounter = 0;
	int linkPtr = 0;
	int next = 0;
	string dataFilePath = "departments.txt";
	string pIndexFilePath = "depIndex.txt";
	string sIndexFilePath = "dep_sIndex.txt";
	string sIndexLinkFilePath = "depLinkedList.txt";
	char departID[30];
	char departName[50];
	char departManger[50];
	int indexOfArrayOfDepartmentID = 0;
	int arr[100];
	void savePIndex() {
		ofstream PIfile(pIndexFilePath, ios::trunc);
		for (int i = 0; i < PIndexCounter; i++)
		{
			PIndexD temp = index[i];
			PIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		PIfile.close();
	}
	void saveSIndex() {
		ofstream SIfile(sIndexFilePath, ios::trunc);
		for (int i = 0; i < SIndexCounter; i++)
		{
			SecIndexD temp = SIndex[i];
			SIfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		SIfile.close();
	}
	void saveSLIndex() {
		ofstream Lfile(sIndexLinkFilePath, ios::trunc);
		for (int i = 0; i < linkPtr; i++)
		{
			node temp = linkedList[i];
			Lfile.write((char*)&temp, sizeof(temp)); //fixed len record, fixed len field
		}
		Lfile.close();
	}
	void writeDepartment(department &temp) {
		//enter data of employee by user
		ofstream outfile;
		outfile.open(dataFilePath, ios::app | ios::out | ios::binary);
		//******************************
		const int maxSize = 133;
		char buffer[maxSize];
		char id[30];
		char name[50];
		strcpy_s(id, temp.departID);
		strcpy_s(name, temp.departName);
		//set deliameters
		temp = setDelemitars(temp);
		strcpy_s(buffer, temp.departID);
		strcat_s(buffer, temp.departName);
		strcat_s(buffer, temp.departManger);
		//*****************************
		int len = strlen(buffer);
		outfile.seekp(0, ios::end);
		int address = outfile.tellp();

		//write new employee in employee file
		outfile.write((char*)&len, sizeof(len));
		outfile.write(buffer, len);

		writePIndex(id, address);//add new index to primary index
		writeSecIndex(name, id);
		outfile.close();
		savePIndex();
		saveSIndex();
		saveSLIndex();

	}
	department setDelemitars(department &temp) {
		strcat_s(temp.departID, "|");
		strcat_s(temp.departName, "|");
		strcat_s(temp.departManger, "|");
		return temp;
	}
	void writeSecIndex(char *name, char*id) {
		int found;
		if (SIndexCounter >= 1)
			found = indexBinarySearchS_D(SIndex, 0, SIndexCounter - 1, name);
		else found = -1;
		if (found == -1) {
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);
			linkedList[linkPtr].next = -1;

			//new index in secIndex
			strcpy_s(SIndex[SIndexCounter].name, name);
			SIndex[SIndexCounter].pointer = linkPtr;
			quickSortS_D(SIndex, 0, SIndexCounter);//sort SIndex
			linkPtr++;
			SIndexCounter++;
		}
		else {
			//edit pointer of element are found in secIndex
			linkedList[linkPtr].next = SIndex[found].pointer;
			SIndex[found].pointer = linkPtr;
			//new index in linked list
			strcpy_s(linkedList[linkPtr].id, id);

			linkPtr++;
		}
		savePIndex();
		saveSIndex();
		saveSLIndex();


	}
	void writePIndex(char* id, int address) {
		strcpy_s(index[PIndexCounter].ID, id);
		index[PIndexCounter].offset = address;
		quickSort(index, 0, PIndexCounter);//sort primary index in ID
		PIndexCounter++;
		savePIndex();
		saveSIndex();
		saveSLIndex();
	}
	void readDepartmentByID(char* id) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Department not exists\n";
			return;
		}
		int len;
		department d;
		outfile.seekg(index[address].offset, ios::beg);
		outfile.read((char*)&len, sizeof(len));
		char *buffer = new char[len];
		outfile.read(buffer, len);

		istringstream stream(buffer);
		stream.getline(d.departID, 30, '|');
		stream.getline(d.departName, 50, '|');
		stream.getline(d.departManger, 50, '|');
		printDepartment(d);
		outfile.close();
		delete buffer;
	}
	department readDepartmentByIDForQ(char* id) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\nthis Department not exists\n";

		}
		else {
			int len;
			department d;
			outfile.seekg(index[address].offset, ios::beg);
			outfile.read((char*)&len, sizeof(len));
			char *buffer = new char[len];
			outfile.read(buffer, len);

			istringstream stream(buffer);
			stream.getline(d.departID, 30, '|');
			stream.getline(d.departName, 50, '|');
			stream.getline(d.departManger, 50, '|');
			return d;
			outfile.close();
			delete buffer;
		}
	}
	void readDepartmentByName() {
		char name[50];
		cout << "enter Department Name :";
		cin >> name;

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearchS_D(SIndex, 0, SIndexCounter, name);
		if (address == -1)
		{
			cout << "\nthis Department not exists\n";
			return;
		}

		int pointer = SIndex[address].pointer;
		int next = linkedList[pointer].next;
		cout << "*****************\n";
		readDepartmentByID(linkedList[pointer].id);
		while (next != -1) {
			cout << "*****************\n";
			readDepartmentByID(linkedList[next].id);
			next = linkedList[next].next;
		}
	}
	int* readDepartmentByNameForQ(char* name) {

		ifstream outfile;
		outfile.open(dataFilePath, ios::binary | ios::in);

		int address = indexBinarySearchS_D(SIndex, 0, SIndexCounter, name);
		if (address == -1)
		{
			cout << "\nthis Department not exists\n";

		}
		else {
			int pointer = SIndex[address].pointer;
			int next = linkedList[pointer].next;
			arr[indexOfArrayOfDepartmentID] = atoi(linkedList[pointer].id);
			indexOfArrayOfDepartmentID++;
			while (next != -1) {
				arr[indexOfArrayOfDepartmentID] = atoi(linkedList[next].id);
				indexOfArrayOfDepartmentID++;
				next = linkedList[next].next;
			}
			return arr;
		}
	}
	void deleteDepartment() {
		char id[30];
		department d;
		cout << "Enter Department ID :";
		cin >> id;
		fstream f(dataFilePath, ios::binary | ios::out | ios::in);
		int address = indexBinarySearch(index, 0, PIndexCounter, id);
		if (address == -1)
		{
			cout << "\n Department not found\n";
			return;
		}
		//shift pIndex
		f.seekp(index[address].offset + 4, ios::beg);
		f << '*';

		for (int i = address; i<PIndexCounter - 1; i++)
			index[i] = index[i + 1];
		PIndexCounter--;
		for (int i = 0; i < linkPtr; i++) {
			if (linkedList[i].id == id) {
				if (linkedList[i].next != -1) {
					d = readDepartmentByIDForQ(linkedList[linkedList[i].next].id);
					int found = indexBinarySearchS_D(SIndex, 0, SIndexCounter, d.departName);
					SIndex[found].pointer = linkedList[i].next;
					linkedList[i].next = -1;
					strcpy_s(linkedList[i].id, "-1");
				}
				else {
					d = readDepartmentByIDForQ(linkedList[i].id);
					int found = indexBinarySearchS_D(SIndex, 0, SIndexCounter, d.departName);
					for (int i = found; i < SIndexCounter - 1; i++)
						SIndex[i] = SIndex[i + 1];
					SIndexCounter--;
				}
				break;
			}
		}

		f.close();
		savePIndex();
		saveSIndex();
		saveSLIndex();
	}
	void printDepartment(department &d) {
		if (d.departID[0] == '*') {
			cout << "\nthis Department not exists\n";
			return;
		}
		cout << "Department ID : " << d.departID << endl;
		cout << "Department Name : " << d.departName << endl;
		cout << "Department Manger : " << d.departManger << endl;

	}

	void loadPIndex() {

		ifstream PIfile(pIndexFilePath);
		/*
		PIfile.open(indexFilePath, ios::binary | ios::in);
		PIfile.seekg(0, ios::beg);
		*/
		PIndexCounter = 0;
		while (true)
		{

			PIndexD temp;
			PIfile.read((char*)&temp, sizeof(temp));
			if (PIfile.eof())
				break;
			index[PIndexCounter] = temp;
			PIndexCounter++;
		}

		PIfile.close();
	}

	void loadSIndex() {

		ifstream SIfile(sIndexFilePath);
		SIndexCounter = 0;
		while (true)
		{

			SecIndexD temp;
			SIfile.read((char*)&temp, sizeof(temp));
			if (SIfile.eof())
				break;
			SIndex[SIndexCounter] = temp;
			SIndexCounter++;
		}
		SIfile.close();
	}

	void loadSLIndex() {

		ifstream Lfile(sIndexLinkFilePath);
		linkPtr = 0;
		while (true)
		{

			node temp;
			Lfile.read((char*)&temp, sizeof(temp));
			if (Lfile.eof())
				break;
			linkedList[linkPtr] = temp;
			linkPtr++;
		}
		Lfile.close();
	}

};

void enterEmployeeData(employee &temp) {
	cout << "Enter Employee ID: ";
	cin.getline(temp.employeeID, 13);
	cout << "Enter Employee Department ID :";
	cin.getline(temp.deptID, 30);
	cout << "Enter Employee Name :";
	cin.getline(temp.employeeName, 50);
	cout << "Enter Employee Position :";
	cin.getline(temp.employeePosition, 50);
}
void enterDepartmentData(department &temp) {
	cout << "Enter Department ID :";
	cin.getline(temp.departID, 30);
	cout << "Enter Department Name :";
	cin.getline(temp.departName, 50);
	cout << "Enter Department Manger :";
	cin.getline(temp.departManger, 50);
}
void query(employee &e, department &d) {
	employee t;
	department t1;
	char text0[200];
	cout << "Query format with spaces [select -- from -- where -- = "; cout << "\"--"; cout << "\"] \n";
	cout << "Enter Query: ";
	cin.getline(text0, 200);
	string text, delim = " ", arr[8];
	string s;
	text.append(text0);
	int pos = 0, i = 0;
	while ((pos = text.find(delim)) != string::npos) {
		arr[i] = (text.substr(0, pos));
		text.erase(0, pos + delim.length());
		i++;
	}
	arr[i] = text;
	if (arr[0] == "select" && arr[2] == "from" && arr[4] == "where" && arr[6] == "=" &&arr[7].length()>=3&&arr[7][0]=='"'&&arr[7][arr[7].length() - 1]=='"') {
		arr[7].erase(0, 1);
		arr[7].erase(arr[7].length() - 1, arr[7].length());
		if (arr[3] == "Employee" || arr[3] == "employee") {
			if (arr[5] == "id") {
				char id[13];
				strcpy_s(id, arr[7].c_str());
				t = e.readEmployeeByIDForQ(id);
				if (arr[1] == "all") {
					cout << "********RESULT**********\n";
					e.printEmployee(t);
				}
				else if (arr[1] == "name") {
					cout << "********RESULT**********\n";
					cout << t.employeeName << endl;
				}
				else if (arr[1] == "depID") {
					cout << "********RESULT**********\n";
					cout << t.deptID << endl;
				}
				else if (arr[1] == "position") {
					cout << "********RESULT**********\n";
					cout << t.employeePosition << endl;
				}
			}
			else if (arr[5] == "depID") {
				char depID[30];
				strcpy_s(depID, arr[7].c_str());
				int *employeeArray;
				employeeArray = e.readEmployeeByDepIDForQ(depID);
				int size = e.indexOfArrayOfEmployeeID;
				if (arr[1] == "all") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(employeeArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						cout << "*********Employee " << j + 1 << "*********\n";
						e.readEmployeeByID(id);
					}
					e.indexOfArrayOfEmployeeID = 0;
				}
				else if (arr[1] == "id") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(employeeArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						t = e.readEmployeeByIDForQ(id);
						cout << j + 1 << " : " << t.employeeID << endl;
					}
					e.indexOfArrayOfEmployeeID = 0;
				}
				else if (arr[1] == "name") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(employeeArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						t = e.readEmployeeByIDForQ(id);
						cout << j + 1 << " : " << t.employeeName << endl;
					}
					e.indexOfArrayOfEmployeeID = 0;

				}
				else if (arr[1] == "position") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(employeeArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						t = e.readEmployeeByIDForQ(id);
						cout << j + 1 << " : " << t.employeePosition << endl;
					}
					e.indexOfArrayOfEmployeeID = 0;
				}
			}

		}
		else if (arr[3] == "Department" || arr[3] == "department") {
			if (arr[5] == "id") {
				char id[30];
				strcpy_s(id, arr[7].c_str());
				t1 = d.readDepartmentByIDForQ(id);
				if (arr[1] == "all") {
					cout << "********RESULT**********\n";
						d.printDepartment(t1);
				}
				else if (arr[1] == "name") {
					cout << "********RESULT**********\n";
					cout << t1.departName << endl;
				}
				else if (arr[1] == "manger") {
					cout << "********RESULT**********\n";
					cout << t1.departManger << endl;
				}
			}
			else if (arr[5] == "name") {
				char name[50];
				strcpy_s(name, arr[7].c_str());
				int *departmentArray;
				departmentArray = d.readDepartmentByNameForQ(name);
				int size = d.indexOfArrayOfDepartmentID;
				if (arr[1] == "all") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(departmentArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						cout << "************" << j + 1 << "***********" << endl;
						d.readDepartmentByID(id);
					}
					d.indexOfArrayOfDepartmentID = 0;
				}
				else if (arr[1] == "id") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(departmentArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						t1 = d.readDepartmentByIDForQ(id);
						cout << j + 1 << " : " << t1.departID << endl;
					}
					d.indexOfArrayOfDepartmentID = 0;
				}
				else if (arr[1] == "manger") {
					cout << "********RESULT**********\n";
					for (int j = 0; j < size; j++) {
						s = to_string(*(departmentArray + j));
						char* id = new char[s.length()];
						strcpy(id, s.c_str());
						t = e.readEmployeeByIDForQ(id);
						cout << j + 1 << ": " << t.employeeName << endl;
					}
					d.indexOfArrayOfDepartmentID = 0;

				}
			}
		}
	}
	else {
		cout << "Query Syntax not correct !\n";
	}

}
bool checkDepartmentIn(department &d) {
	int found = indexBinarySearch(d.index, 0, d.PIndexCounter, d.departID);
	if (found == -1)
		return false;
	return true;
}
bool checkEmployeeConstraints(employee &e, department &d) {
	int found = indexBinarySearch(e.index, 0, e.PIndexCounter, e.employeeID);//check if new employee id exisit in others employees
	int found1 = indexBinarySearch(d.index, 0, d.PIndexCounter, e.deptID);//check if new employee depID exisit in Departments
	//-1 equal not found
	cout << found << ";;" << found1 << endl;
	if (found != -1) {
		cout << "Error:Employee already exisit\n";
		return false;
	}
	else if (found1 == -1) {
		cout << "Error:Department Not Found\n";
		return false;
	}
	return true;
}
bool checkDepartmentConstraints(department &d) {
	int found = indexBinarySearch(d.index, 0, d.PIndexCounter, d.departID);//check if new department id exisit in others departments
	//-1 equal not found
	if (found != -1) {
		cout << "Error:Department already exisit\n";
		return false;
	}
	return true;
}
void openFiles(employee &e, department &d) {
	ifstream f1, f2, f3, f4, f5, f6;
	f1.open(e.pIndexFilePath);
	f2.open(e.sIndexFilePath);
	f3.open(e.sIndexLinkFilePath);
	f4.open(d.pIndexFilePath);
	f5.open(d.sIndexFilePath);
	f6.open(d.sIndexLinkFilePath);
	if (f1)
		e.loadPIndex();
	if (f2)
		e.loadSIndex();
	if (f3)
		e.loadSLIndex();
	if (f4)
		d.loadPIndex();
	if (f5)
		d.loadSIndex();
	if (f6)
		d.loadSLIndex();
}
void saveFiles(employee &e, department &d) {
	e.savePIndex();
	e.saveSIndex();
	e.saveSLIndex();
	d.savePIndex();
	d.saveSIndex();
	d.saveSLIndex();
}
int main() {
	employee e;
	department d;
	openFiles(e, d);
	int select1 = 0;
	bool bCheck;//check true or false
	while (select1 != 11) {
		cout << "1-Add New Employee\n2-Add New Department\n3-Delete Employee(ID)\n4-Delete Department(ID)\n5-Print Employee(ID)";
		cout << "\n6-Print Employee (Dep_ID)\n7-Print Department (ID)\n8-Print Department(Dep_Name)\n9-Write Query\n10-Exit\n";
		cin >> select1;
		switch (select1)
		{
		case 1:
			cin.ignore(100, '\n');
			bCheck = false;
			enterEmployeeData(e);
			bCheck= checkEmployeeConstraints(e, d);

			if(!bCheck){
				cout << "*********TRY AGAIN*********\n";
				cout << "Enter Employee ID\n";
				cin.getline(e.employeeID, 13);
				cout << "Enter Employee ID\n";
				cin.getline(e.deptID, 30);
				bCheck = checkEmployeeConstraints(e, d);
			}
			if (bCheck)
				e.writeEmployee(e);
			break;
		case 2:
			bCheck = false;
			cin.ignore(100, '\n');
			enterDepartmentData(d);
			bCheck = checkDepartmentConstraints(d);
			if (!bCheck) {
				cout << "*********TRY AGAIN*********\n";
				cout << "Enter Department ID\n";
				cin.getline(d.departID, 30);
				bCheck = checkDepartmentConstraints(d);
			}
			if (bCheck)
				d.writeDepartment(d);
			break;
		case 3:
			e.deleteEmployee();
			break;
		case 4:
			d.deleteDepartment();
			break;
		case 5:
			char id[13];
			cout << "Enter Employee ID: ";
			cin >> id;
			e.readEmployeeByID(id);
			break;
		case 6:
			e.readEmployeeByDepID();
			break;
		case 7:
			char id1[50];
			cout << "Enter Department ID: ";
			cin >> id1;
			d.readDepartmentByID(id1);
			break;
		case 8:
			d.readDepartmentByName();
			break;
		case 9:
			cin.ignore(100, '\n');
			query(e,d);
			break;
		case 10:
			saveFiles(e, d);
			select1 = 11;
			break;
		}
	}


	system("pause");
}