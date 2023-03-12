#include<bits/stdc++.h>
using namespace std;

void solve(int a)
{
    int n;
    cin>>n;
    float total_hours=0.00, accent_qty=0.00, regular_qty=0.00;
    while (n--)
    {
        float Total_bedrooms, R , S , H;
        cin>>Total_bedrooms>>R>>S>>H;
        float total_rooms = (R*3.00) + (S*4.00) + (H*6.00);
        float act_rooms = total_rooms /3;
        float reglr_room = total_rooms - act_rooms;
        total_hours += act_rooms*2.50;
        total_hours += reglr_room*3.25;
        accent_qty+=act_rooms*1.50;
        regular_qty+=reglr_room*2.25;
    }
    cout<<"Case #"<<a<<": "<<fixed<<setprecision(2)<<total_hours<<", "<<accent_qty<<", "<<regular_qty<<endl;
}
int main()
{
    int t;
    cin>>t;
    int a =1;
    while(t--)
    {
        solve(a);
        a++;
    }
    
}