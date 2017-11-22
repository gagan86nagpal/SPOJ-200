#include <bits/stdc++.h>
using namespace std;
vector<int>  add_vectors(vector <int> v1,vector <int> &v2){
    vector<int> ret(max(v1.size(),v2.size()),0);
    int sum,carry=0;
    int i=v1.size()-1,j=v2.size()-1,pos=ret.size()-1;
    while(i>=0 && j>=0){
        sum= (v1[i]+v2[j]+carry )%10;
        carry=(v1[i] +v2[j]+carry)/10;
        ret[pos--]=sum;
        i--,j--;
    }
    while(i>=0){
        sum = (v1[i]+carry)%10;
        carry= (v1[i]+carry)/10;
        ret[pos--]=sum;
        i--;
    }
    while(j>=0){
        sum =(v2[j]+carry)%10;
        carry = (v2[j]+carry)/10;
        ret[pos--]=sum;
        j--;
    }
    if(carry>0)
        ret.insert(ret.begin(),carry);
    return ret;
}
vector <int> multiply(vector<int> v1,vector <int> v2){
    vector <int> ret;
    int i,j;
    for(j=v2.size()-1;j>=0;j--){
        vector <int> aux;
        aux.clear();
        int carry=0;
        int mul;
        for(i=v1.size()-1;i>=0;i--){
            mul =(v2[j]*v1[i] +carry)%10;
            carry = (v2[j]*v1[i] +carry)/10;
            aux.push_back(mul);
        }
        if(carry>0)
            aux.push_back(carry);
        reverse(aux.begin(),aux.end());
        for(int k=j+1;k<v2.size();k++)
            aux.push_back(0);
        if(ret.empty())
            ret=vector<int>(aux.size(),0);
        ret=add_vectors(ret,aux);
    }
    return ret;
}
vector <int> numToVector(int x){
    vector <int> ret;
    while(x>0){
        ret.push_back(x%10);
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void print(vector<int> x){
    for(int y:x)
        cout<<y;
    cout<<"\n";
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector <int> ans;
        ans.push_back(1);
        for(int i=2;i<=n;i++){
            vector <int> aux = numToVector(i);
            ans=multiply(ans,aux);
        }
        print(ans);
    }
    return 0;
}
