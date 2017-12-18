#include <iostream>
#include <vector>
using namespace std;

vector <string> v;
struct node
{
    node * child[10];
    int cnt;
};

node* getNode()
{
    int i;
    node* n = new node();
    for(i=0;i<10;i++)
        n->child[i]=NULL;
    n->cnt=0;
    return n;
}

void insertTrie(node* root,string s,int i)
{
    root->cnt++;
    if(i==s.size())
        return;
    int  x  = s[i]-'0';
    if(root->child[x]==NULL)
        root->child[x]=getNode();
    insertTrie(root->child[x],s,i+1);
}

int searchTrie(node* root,string s,int i)
{
    if(i==s.size())
        return root->cnt;
    int x = s[i]- '0';
    return searchTrie(root->child[x],s,i+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        v.clear();
        node * root = getNode();
        int n,i;
        cin>>n;
        for(i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
            insertTrie(root,s,0);
        }
        bool flag =true;
        for(string s:v)
        {
            int cnt = searchTrie(root,s,0);
           // cout<<s<<" : "<<cnt<<"\n";
            if(cnt>1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
