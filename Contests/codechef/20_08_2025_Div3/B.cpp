#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt = 1;
        bool odd = (a[0] % 2 == 1);

        for(int i = 1; i < n; i++){
            if(odd && a[i]%2 == 0){
                cnt++;
                odd = false;
            }else if(!odd && a[i]%2 != 0){
                cnt++;
                odd = true;
            }
        }

        cout << cnt << endl;
    }


    return 0;
}