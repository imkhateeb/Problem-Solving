#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string ans = "";

        for(int i = 0; i < n; i++){
            int cnt = 0;

            while(i < n && cnt < 5){
                ans.push_back((char)(cnt + 'a'));
                i++;
                cnt++;
            }
            i--;
        }

        cout << ans << endl;
    }


    return 0;
}