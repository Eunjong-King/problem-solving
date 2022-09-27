#include <iostream>
#include <vector>
using namespace std;
typedef pair<double, double> pd;

double outer_product(pd base, pd dot1, pd dot2){
    double tmp1 = base.first * dot1.second + dot1.first * dot2.second + dot2.first * base.second;
    double tmp2 = dot1.first * base.second + dot2.first * dot1.second + base.first * dot2.second;

    return (tmp1 - tmp2) / 2;
}

int main(){
    int N;
    cin >> N;

    vector<pd> coor(N);

    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        coor[i] = {x, y};
    }

    double result = 0;
    for(int i=1; i<N-1; i++){
        result += outer_product(coor[0], coor[i], coor[i+1]);
    }

    cout << fixed;
    cout.precision(1);
    cout << abs(result) << endl;

    return 0;
}