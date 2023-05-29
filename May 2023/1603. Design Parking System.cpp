// 1603. Design Parking System
// Problem Link - https://leetcode.com/problems/design-parking-system/

class ParkingSystem {
public:
    int bigCount=0;
    int mediumCount=0;
    int smallCount=0;
    
    ParkingSystem(int big, int medium, int small){
        bigCount=big;
        mediumCount=medium;
        smallCount=small;
    }
    
    bool addCar(int carType){
        if(carType==1 && bigCount!=0){
            bigCount--;
            return true;
        }else if(carType==2 && mediumCount!=0){
            mediumCount--;
            return true;
        }else if(carType==3 && smallCount!=0){
            smallCount--;
            return true;
        }
        return false;
    }
};
