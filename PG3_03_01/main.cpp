#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <list>
using namespace std;


int main() {

	vector<float> c = { 0.0f, 1.0f, 2.0f };

	printf("%f\n", c[1]); //1.0

	c[1] = -1.5f;


	printf("%f\n", c[1]); //-1.5

	vector<int> d; //has size of 0

	d.resize(10); //gives it a size of 10
	
	d.push_back(10); //adds 10 to the last number
	d.push_back(10); //adds 10 to the next last number
	d.pop_back(); //removes the second to last 10 and makes it 0

	int size = d.size();

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", d[i]);
	}

	vector<int> e = { 1,2,3 };

	vector<int>::iterator it;
	it = e.begin(); //it takes the first vector in "e", which is 1

	printf("%d\n", *it); //1

	it++; //move to the next number in the vector. THIS ISNT +1

	printf("%d\n\n", *it); //2

	vector<string> f = { "ローソン", "ファミマ", "セブン" };

	for (vector<string>::iterator it_f = f.begin(); it_f != f.end();it_f++) 
	{
		printf("%s\n", it_f->c_str()); //prints everything in the string 
	}

	vector<int> g = { 1,2,3 };

	g.erase(g.begin() + 1); //this deletes 2, which makes the remaining vector 1,3

	printf("%d\n", g[1]); //1


	g.pop_back(); //this erases the last number, so g[1] disappears

	printf("%d\n", g[0]); //1

	list<int> lst{ 1,4,5,7 };

	list<int>::iterator itr;

	itr = lst.begin();

	printf("%d\n", *itr);

	itr = lst.end(); //end is after the last thing in the list, so in this case after 7
	itr--; //go one slot before end(), which is 7
	printf("%d\n\n", *itr); //7

	for (auto itr = lst.begin(); itr != lst.end(); itr++) //1, 4, 5, 7
	{
		printf("%d\n", *itr); //prints everything in the list 
	}

	auto itr2 = lst.begin();
	printf("%d\n", *itr2);

	*itr2 = 9; //changes the first number into 9

	printf("%d\n", *itr2);

	itr2++; //goes to the second number in the list which is 4

	*itr2 = 10; //changes 4 into 10

	printf("%d\n", *itr2); //10, and the first itr2 is still 9
	
	itr2--;
	
	printf("%d\n\n", *itr2);


	list<int> list{ 1,3,5,7,10 };

	for (std::list<int>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		printf("%d\n", *itr);

		if (*itr == 3)
		{
			itr = list.insert(itr,0);
			printf("%d\n", *itr);
			itr++;
		}
	}
	

	return 0;

	
}