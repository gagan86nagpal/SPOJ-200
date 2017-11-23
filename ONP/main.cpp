#include <iostream>

using namespace std;
char stk[402];
bool isOperator(char c)
{
    return c=='+' ||c=='-'|| c=='*' ||c=='/' ||c=='^';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int top=-1;
        string exp;
        string outp="";
        cin>>exp;
        for(int i=0;i<(int)exp.size();i++)
        {
            char c=exp[i];
            if(c=='(' || isOperator(c))
            {
                stk[++top]=c;
            }
            else if(c==')')
            {
                while(top>=0 && stk[top]!='(')
                {
                    char x = stk[top--];
                    outp+=x;
                }
                if(stk[top]=='(')
                    top--;
            }
            else
                outp+=c;
        }
        cout<<outp<<"\n";
    }
    return 0;
}
