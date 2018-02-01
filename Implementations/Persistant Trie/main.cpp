#include <iostream>

using namespace std;

struct stringTrie
{
    int val;
    stringTrie * child[26];
    stringTrie()
    {
        this->val=-1; // not exists
        for(int i=0;i<26;i++)
            this->child[i] = NULL;
    }
    stringTrie* dup(stringTrie* x) // x must be a valid NODE, If it is not present initially , we must create it
    {
        stringTrie * ret= new stringTrie();
        ret->val= x->val;
        for(int i=0;i<26;i++)
            ret->child[i]=x->child[i];
        return ret;
    }
    stringTrie* add(string s,int key,int in=0)
    {
        stringTrie* node =dup(this) ; // create a new node as duplicate of corresponding previous trie node
        if(in==(int)s.size())
        {
            node->val=  key;
            return node;
        }
        int c= s[in]-'a';
        if(this->child[c]==NULL) // If original trie doesn't have this node , then create and maintain the variant
            this->child[c]=new stringTrie();
        node->child[c]=this->child[c]->add(s,key,in+1);
        return node;
    }
    stringTrie* del(string s,int in=0)
    {
        return add(s,-1,in); // Same as adding the -1 in string
    }
    int query(string s,int in=0)
    {
        if(in==(int)s.size())
            return this->val;
        int c = s[in]-'a';
        if(this->child[c]==NULL)
            return -1;
        return this->child[c]->query(s,in+1);
    }
    void print()
    {
        int i;
        for(i=0;i<26;i++)
        {
            if(this->child[i]==NULL)
                continue;
            cout<<char('a'+i);
            this->child[i]->print();
            cout<<"\n";
        }
    }
};

struct sumTrie
{
    int cnt;
    sumTrie* child[2];
    sumTrie()
    {
        this->cnt=0;
        this->child[0]=this->child[1]=NULL;
    }
    sumTrie* dup(sumTrie* node)
    {
        sumTrie* ret = new sumTrie();
        ret->cnt = node->cnt;
        ret->child[0]=node->child[0];
        ret->child[1]=node->child[1];
        return ret;
    }
    sumTrie* add(int n,int l=29,int val=1)
    {
        sumTrie* node = dup(this); // create a copy
        node->cnt+=val; // add the value in new node
        if(l==-1)
            return node;
        int c = (((n>>l)&1 )>0);
        if(this->child[c]==NULL)
            this->child[c]=new sumTrie();
        node->child[c]= this->child[c]->add(n,l-1,val);
        return node;
    }
    sumTrie* del(int n,int l=29)
    {
        return add(n,l,-1); // subtracting 1 also removes it
    }
    int query(int n,int l=29)
    {
        if(l==-1)
            return 0;
        int c= (((n>>l)&1 )>0);;
        if(c==1)
        {
            int ans=0;
            if(this->child[0])
                ans= this->child[0]->cnt;
            if(this->child[1])
                return ans+this->child[1]->query(n,l-1);
            else
                return ans;
        }
        if(this->child[0])
            return this->child[0]->query(n,l-1);
        else
            return 0;
    }
};

sumTrie* perSum[100002];
stringTrie* perString[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    perSum[0]= new sumTrie();
    perString[0]= new stringTrie();
    for(int i=1;i<=q;i++)
    {
        string a,b;
        int d;
        cin>>a;
        if(a[0]=='u')
        {
            cin>>d;
            perSum[i]=perSum[i-d-1];
            perString[i]=perString[i-d-1];
        }
        else
        {
            cin>>b;
            if(a[0]=='s')
            {
                cin>>d;
                int p = perString[i-1]->query(b);
                if(p==-1) // new entry
                {
                    perString[i]= perString[i-1]->add(b,d);
                    perSum[i]=perSum[i-1]->add(d);
                }
                else
                {
                    // first remove entries
                   // perString[i]=perString[i-1]->del(b);   // Can be removed , as we can replace the same trie node
                    perSum[i]=perSum[i-1]->del(p);
                    perString[i]= perString[i-1]->add(b,d); // adding to current version
                    perSum[i]=perSum[i]->add(d); // adding to current version
                }
            }
            else if(a[0]=='r')
            {
                int p = perString[i-1]->query(b);
                if(p!=-1)
                {
                    perString[i]=perString[i-1]->del(b);
                    perSum[i]=perSum[i-1]->del(p);
                }
                else // not exists
                {
                    perSum[i]=perSum[i-1];
                    perString[i]=perString[i-1];
                }
            }
            else // query
            {
                perSum[i]=perSum[i-1];
                perString[i]=perString[i-1];
                int p = perString[i]->query(b);
             //   cout<<"Qp:"<<p<<"\n";
                int ans=-1;
                if(p!=-1)
                    ans = perSum[i]->query(p);
                cout<<ans<<"\n";
                cout<<flush;
            }
        }
    }
    return 0;
}
