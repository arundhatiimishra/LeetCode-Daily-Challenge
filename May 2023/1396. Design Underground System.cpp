// 1396. Design Underground System
// Problem Link - https://leetcode.com/problems/design-underground-system/

class UndergroundSystem{
public:
    map<int,pair<string,int>> mp;
    map<pair<string,string>,pair<int,int>> use;
    
    UndergroundSystem(){
       
    }
    
    void checkIn(int id,string stationName,int t){
        mp[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t){
        pair<string,string> stations;
        stations.first=mp[id].first;
        stations.second=stationName;
        use[stations].first+=(t-mp[id].second);
        use[stations].second++;
    }
    
    double getAverageTime(string startStation, string endStation){
        double sum=use[{startStation,endStation}].first;
        double num=use[{startStation,endStation}].second;
        return sum/num; 
    }
};

