#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b)
{
   if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second.first > b.second.first);

}
 
int main()
{
    int t;
    cin>>t;
    vector<pair<int,pair<int,int>>> Server;
    for(int i = 0;i<t;i++)
    {
        int Content,Images,Forms;
        cin>>Content>>Images>>Forms;
        Server.push_back(make_pair(Content,make_pair(Images,Forms)));
    }
    sort(Server.begin(), Server.end(), sortbysec);
    
    for(int i = 0;i<t;i++)
    {
        cout<<Server[i].first<<","<<Server[i].second.first<<","<<Server[i].second.second<<endl;
    }
}