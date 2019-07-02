#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <vector>
#include <iostream.h>

#include <stdio.h>

void z_preprocess(vector<int> & Z, const string & str)
{
		const size_t len = str.size();

        Z.clear();
		Z.resize(len);
        if (0 == len)
				return;

		Z[0] = len;

		for (size_t curr = 1, left = 0, right = 1; curr < len; ++curr)
		{
				if (curr >= right)
				{
						size_t off = 0;
						while ( curr + off < len && str[curr + off] == str[off] )
								++off;
						Z[curr] = off;
						right = curr + Z[curr];
						left = curr;
				}
				else
				{
						const size_t equiv = curr - left;
						if (Z[equiv] < right - curr)
								Z[curr] = Z[equiv];
						else
						{
								size_t off = 0;
								while ( right + off < len && str[right - curr + off] == str[right + off] )
										++off;
								Z[curr] = right - curr + off;
								right += off;
								left = curr;
						}
				}
		}
}



int _tmain(int argc, _TCHAR* argv[]) 
{   system("chcp 1251");
	system("cls");
	string str;
	vector <int>  Z;
	cout<<"¬ведите слово"<<endl;
	cin>>str;
	system("pause");
	return 0;
}
