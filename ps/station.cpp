#include <iostream>
#include <cmath>
using namespace std;

double arr[4][3], result_distance = 300000.0;

void input(){
    for(int i=0; i<4; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    return;
}

double get_distance(double* dot1, double* dot2){
    double distance = 0.0;

    for(int i=0; i<3; i++){
        distance += pow(abs(dot1[i]-dot2[i]), 2);
    }

    return sqrt(distance);
}

void recursive(int depth, double startAB, double endAB, double startCD, double endCD){
    if(depth == 10){
        return;
    }

    double distanceAB = endAB-startAB, distanceCD = endCD-startCD;
    double tAB, tCD;
    double coorAB[3], coorCD[3];
    double min_distance = 300000.0, now_distance, min_tAB, min_tCD;
    for(int stepAB=0; stepAB<=100; ++stepAB){
        tAB = startAB + (distanceAB * (double)stepAB) / 100.0;

        for(int i=0; i<3; i++){
            coorAB[i] = (1.0 - tAB) * arr[0][i] + tAB * arr[1][i];
        }

        for(int stepCD=0; stepCD<=100; ++stepCD){
            tCD = startCD + (distanceCD * (double)stepCD) / 100.0;

            for(int j=0; j<3; j++){
                coorCD[j] = (1.0 - tCD) * arr[2][j] + tCD * arr[3][j];
            }

            now_distance = get_distance(coorAB, coorCD);
            if(now_distance < min_distance){
                min_distance = now_distance;
                min_tAB = tAB;
                min_tCD = tCD;
            }
            if(now_distance < result_distance){
                result_distance = now_distance;
            }
        }
    }

    double new_startAB = max(0.0, min_tAB*0.98);
    double new_endAB = min(1.0, min_tAB*1.02);
    double new_startCD = max(0.0, min_tCD*0.98);
    double new_endCD = min(1.0, min_tCD*1.02);

    recursive(depth+1, new_startAB, new_endAB, new_startCD, new_endCD);

    return;
}

void solve(){
    input();

    recursive(0, 0.0, 1.0, 0.0, 1.0);
    cout << ceil(result_distance) << endl;

    return;
}

int main(void){
    solve();

    return 0;
}