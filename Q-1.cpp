 #include <iostream>
using namespace std;

bool off(const string &s,int n,int k,int l){
    int ops=0;
    for(int i=0;i<n;){
        if(s[i]=='1'){
            ops++;
            if(ops>k)return false;
            i+=l;
        }else i++;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    int low=1,high=n,ans=n;

    while(low<=high){
        int mid=(low+high)/2;
        if(off(s,n,k,mid)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }

    cout<<ans;
    return 0;
}