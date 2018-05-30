#include<stack>
#include <fstream>
//#include"Stack.h"
//#include "Stack.cpp"
//#include <vector>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	size_t nz;
	while (true)
	{
		cout << "Выберите задание (от 5 до 9, 0 - для выхода):"; cin >> nz;
		if (nz == 0)
		{
			break;
		}
		else if (nz == 5)
		{
			stack<stack<int>> s;
			stack<int> in_s;
			int a[9] = { 8,1,2,3,4,5,2,4,9 };
			s.push(in_s);
			s.top().push(a[0]);
			for (int i = 1; i < 9; i++)
			{
				if (s.top().top() < a[i])
					s.top().push(a[i]);
				else
				{
					stack<int> in_st;
					s.push(in_st);
					s.top().push(a[i]);
				}
			}
			while (!s.empty())
			{
				while (!s.top().empty())
				{
					cout << s.top().top() << "\t";
					s.top().pop();
				}
				cout << endl;s.pop();
			}	
		}
		else if (nz == 6)
		{
			stack<int> s, s1;
			ifstream in_file("6.txt");
			int tmp;
			while (!in_file.eof())
			{
				in_file >> tmp;
				s.push(tmp);
			}
			cout << s.size() << endl;
			cout << s.top() << endl;
			ifstream in("6-1.txt");
			while (!in.eof())
			{
				in >> tmp;
				s1.push(tmp);
			}
			cout << s1.size() << endl;
			cout << s1.top() << endl;
		}
		else if (nz == 8)
		{
			char s[] = "this is{ example } [(task) for my[group]] students";
			stack<char> s1; //for '(' 
			stack<char> s2;//for '['
			stack<char> s3;//for '{'

			for (int i = 0; i < strlen(s); i++)
			{
				if (s[i] == '(')
					s1.push('(');
				else if (s[i] == '[')
					s2.push('[');
				else if (s[i] == '{')
					s3.push('{');
				else if (s[i] == ')')
					if(!s1.empty())
					s1.pop();
				else if (s[i] == ']')
					if (!s2.empty())
						s2.pop();
				else if (s[i] == '}')
					if (!s3.empty())
						s3.pop();
				else if (s[i] == ')'&&s1.empty())
				{
					cout << "Uncorrect\t";
					break;
				}					
				else if (s[i] == ']'&&s2.empty())
				{
					cout << "Uncorrect\t";
					break;
				}
				else if (s[i] == '}'&&s3.empty())
				{
					cout << "Uncorrect\t";
					break;
				}
			}

			if (s1.empty()&&s2.empty()&&s3.empty())
				cout << "Correct\t";
			else 
				cout << "Uncorrect\t";
		}
		/*else if (nz == 6)
		{
			Stack<int> s, s1;
			ifstream in_file("6.txt");
			int tmp;
			while (!in_file.eof())
			{
				in_file >> tmp;				
				s.push(tmp);
			}
			cout << s.size() << endl;
			cout << s.top() << endl;

		}*/
		else
		{
			cout << "Такого задания не существует!";
		}
	}
	return 0;
}