#include<iostream>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}
int main()
{
    string a ,b;
    cout<<"enter your string 1: ";
    cin>>a;
    cout<<"enter your string 2: ";
    cin>>b;
    int table[a.length()+1][b.length()+1];
    for(int i=0;i<=a.length();i++)
    {
        for (int j=0;j<=b.length();j++)
        {
            if (i==0 || j==0)
            {
                table[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                table[i][j]=1+table[i-1][j-1];
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    for(int i=0;i<=a.length();i++)
    {
        for (int j=0;j<=b.length();j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    string ans;
    int m=a.length();
	int n=b.length();
	while(table[m][n]!=0)
	{
		if (table[m][n]==table[m][n-1])
		{
			n=n-1;
			continue;
		}
		else
		{
			ans=ans+b[n-1];
			m=m-1;
			n=n-1;
			continue;
		}
		
	} 
	reverseStr(ans);
	cout<<"the longest substring is :- "<<ans;  
}