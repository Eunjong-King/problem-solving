#include "timebomb.h"
#include <vector>
using namespace std;

int main(void)
{
    int size, fight_count, fight_left=-1, first, result;

    box_ready();
    size = box_size();

    vector<int> v(size+1, -1);
    while(true){
        fight_count = 0;
        for(int i=1; i<=size; i++){
            if(v[i] == -1){
                if(fight_left == -1){
                    fight_left = i;
                }
                else{
                    ++fight_count;
                    result = box_comp(fight_left, i);

                    if(result == 1){
                        v[i] = fight_left;
                        first = fight_left;
                    }
                    else if(result == -1){
                        v[fight_left] = i;
                        first = i;
                    }

                    fight_left = -1;
                }
            }
        }

        if(fight_count == 0){
            break;
        }
    }

    fight_left = -1;
    for(int i=1; i<=size; i++){
        if(v[i] == first){
            if(fight_left == -1){
                fight_left = i;
            }
            else{
                result = box_comp(fight_left, i);

                if(result == -1){
                    fight_left = i;
                }
            }
        }
    }

    box_report(fight_left);

    return 0;
}
