#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(int a)
{
    ll mango =0, apple=0 , orange=0 , lemon=0, coco=0;
    ll num ,days;
    cin>>num>>days;

    mango = 27500;
    ll temp = days/15;
    mango = mango * temp;

    apple = 12000;
    temp = days/10;
    apple = apple * temp;

    orange= 10000;
    temp = days/6;
    orange = orange * temp;

    lemon = 7500;
    temp = days/5;
    lemon = lemon* temp;

    coco= 8000;
    temp = days/15;
    coco = coco* temp;

    ll maxterm = 0.4*num;
    maxterm--;
    vector<ll> fruits;
    fruits.push_back(mango);
    fruits.push_back(orange);
    fruits.push_back(lemon);
    fruits.push_back(apple);
    fruits.push_back(coco);

    ll sum = 0;
    sort(fruits.begin(),fruits.end(),greater<int>());
    ll n = fruits.size();
    
    for(int i=0 ;i<n; i++ ) 
    {
        sum +=fruits[i];
    }
    ll tempnumber = num - n;
    for(int i=0 ; i<n; i++)
    {
        if(maxterm < tempnumber) 
        {
            sum+=fruits[i]*maxterm;
            tempnumber -= maxterm;
        }
        else{
            sum+=fruits[i]*tempnumber;
            break;
        }
    }
    cout << "Case #"<<a<<": "<<sum <<endl;
}
int main()
{
    int t;
    cin>>t;
    int a=1;
    while(t--){
        solve(a);
        a++;
    }
}
