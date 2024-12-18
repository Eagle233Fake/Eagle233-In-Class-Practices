
#include <iostream>
 
using namespace std;
 
int n,ans=4;//2,3,5,7
 
bool prime(int x){
 
    if(x<2) return false;
 
    if(x%2==0 && x!=2) return false;
 
    if(x==2) return true;
 
    for(int i=3;i*i<=x;i+=2){
 
        if(x%i==0){
 
            return false;
 
        }
 
    }
 
    return true;
 
}
 
bool check(int x){
 
    while(x){
 
        int f=x%10;
 
        if(f%2==0 && !(f==2 && x/10==0)) return false;
 
        x/=10;
 
    }
 
    return true;
 
}
 
int main(){
 
    cin>>n;
 
    for(int i=23;i<=n;i+=2){
 
        int k=i;
 
        if(check(k)){
 
            ans++;
 
            while(k){
 
                if(!prime(k)){
 
                    ans--;
 
                    break;
 
                }
 
                k/=10;
 
            }
 
        }
 
    }
 
    cout<<ans;
 
    return 0;
 
}