#include <bits/stdc++.h>

using namespace std;


void onlinejudge(){
     #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
     #endif
}

class TaxiDetails{
    public:
        int id;
        int revenue;
        string availableAfter;
        int position;
        
        TaxiDetails(int id){
            this->id = id;
            revenue = 0;
            availableAfter = "00:00";
            position = 1;
        }

        ~TaxiDetails(){
            cout<<"Taxi-"<<id<<" Removed in dynamic space\n";
        }
};


class Taxi{
    public:
        vector<TaxiDetails*> taxis;

        vector<int> distance , travelTime;

        int pointSize, initCost, initKM, remCost, limitDist;
        
        Taxi(int taxiCount, vector<int>&distance, vector<int>&travelTime, int initKM, int initCost, int remCost, int limitDist){
            
            pointSize = distance.size() + 1;
            taxis.resize(taxiCount + 1);
            this->distance.resize(pointSize + 1);
            this->travelTime.resize(pointSize + 1);
            this->initCost = initCost;
            this->initKM = initKM;
            this->remCost = remCost;
            this->limitDist = limitDist;
            
            
            for(int i=2;i<=pointSize;i++){
                this->distance[i] = this->distance[i-1] + distance[i-2];
                this->travelTime[i] = this->travelTime[i-1] + travelTime[i-2]; 
            }
            
            for(int i=1;i<=taxiCount;i++){
                taxis[i] = new TaxiDetails(i);
            }
        }
        
        ~Taxi(){
            for(TaxiDetails* i:taxis){
                if(i!=nullptr) delete(i);
            }
            cout<<"Taxi system abort";
        }
        
        int findRangeKM(int x,int y){
            if(x>y) swap(x,y);
            return distance[y] - distance[x];
        }
        
        int findRangeMin(int x,int y){
            if(x>y) swap(x,y);
            return travelTime[y] - travelTime[x];
        }
        
        
        
        int findBestTaxi(string pickupTime, int pos){
            int curRevenue = INT_MAX,curDistance = INT_MAX,taxiID = INT_MAX;
            
            for(int i=1; i<taxis.size(); i++){

                if(taxis[i]->availableAfter < pickupTime){ 

                    int taxiToPickupPointDist = findRangeKM(pos,taxis[i]->position);

                    if(taxiToPickupPointDist < curDistance) {
                        taxiID = taxis[i]->id;
                        curRevenue = taxis[i]->revenue;
                        curDistance = taxiToPickupPointDist;
                    }

                    if(taxiToPickupPointDist == curDistance){
                        if(taxis[i]->revenue < curRevenue) {
                            taxiID = taxis[i]->id;
                            curRevenue = taxis[i]->revenue;
                        }
                        if(taxis[i]->revenue == curRevenue){
                            taxiID = min(taxiID , taxis[i]->id);
                        }
                    }
                }
            }
            
            return ((taxiID == INT_MAX || curDistance > limitDist) ? -1 : taxiID);
        }
        
        
        string findDropTime(int hr,int min){
            string dropTime = "00:00";
            hr = (hr % 24);
            min = (min % 60);
            
            
            dropTime[1] = ('0' + (hr % 10));
            dropTime[0] = ('0' + (hr / 10 % 10));
            dropTime[4] = ('0' + (min % 10));
            dropTime[3] = ('0' + (min / 10 % 10));
            
            return dropTime;
        }
        
        int calculateCost(int pickupPoint,int dropPoint){
            int travelDist = findRangeKM(pickupPoint, dropPoint);
            if(travelDist <= initKM){
                return initCost;
            }
            travelDist -= initKM;
            
            return initCost + travelDist * remCost;
        }
        
        
        void bookTaxi(string customerName, int pickupPoint, int dropPoint, string pickupTime){

            int taxiID = findBestTaxi(pickupTime,pickupPoint);
            
            cout<<customerName<<" ";
            if(taxiID == -1){
                cout<<"REJECTED";
                return;
            }
            
            
            int taxiPos = taxis[taxiID]->position;
            int totalDist = findRangeKM(pickupPoint,taxiPos) + findRangeKM(pickupPoint,dropPoint);
            int totalTime = findRangeMin(pickupPoint,taxiPos) + findRangeMin(pickupPoint, dropPoint);
            
            int curHr = (pickupTime[0] - '0') * 10 + (pickupTime[1] - '0');
            int curMin = (pickupTime[3] - '0') * 10 + (pickupTime[4] - '0');
            
            curHr += (curMin + totalTime) / 60;
            curMin = (curMin + totalTime) % 60;
            
            string dropTime = findDropTime(curHr,curMin);
            int totalCost = calculateCost(pickupPoint,dropPoint);
            
            taxis[taxiID]->revenue += totalCost;
            taxis[taxiID]->position = dropPoint;
            taxis[taxiID]->availableAfter = dropTime;
            
            cout<<"Taxi-"<<taxiID<<" "<<totalCost<<" "<<dropTime;
        }
        
};



int main() {
    
    
    onlinejudge();

    int taxiCount, pickupCount, initPrice, initKM, remPrice,limitDist;
    cin>>taxiCount>>pickupCount;
    
    vector<int> km(pickupCount-1), min(pickupCount - 1);
    
    for(int &i:km) cin>>i;
    for(int &i:min) cin>>i;
    
    
    cin>> initKM >> initPrice >> remPrice >> limitDist;
    
    Taxi *taxi = new Taxi(taxiCount, km, min, initKM, initPrice, remPrice, limitDist);
    int query;

    
    cin >> query;
    
    while(query--){

        string customerName,pickupTime;
        int pickupPoint,dropPoint;
        cin>> customerName >> pickupPoint >> dropPoint >> pickupTime;


        taxi->bookTaxi(customerName,pickupPoint,dropPoint,pickupTime);
        cout<<endl;
    }

    delete(taxi);
    
    
    
}



// Manisha Taxi-1 450 08:55
// Arun REJECTED
// Bhuvana Taxi-1 250 10:15
// Saroj Taxi-2 450 11:55
// Anu Taxi-1 400 11:10
// Raj Taxi-1 600 01:15

// Liam Taxi-1 280 06:43
// Noah Taxi-2 100 06:28
// William REJECTED
// James Taxi-2 500 07:32
// Oliver Taxi-1 160 08:00
// Benk Taxi-3 280 08:38
// Ella REJECTED
// Lucas REJECTED
// Mason Taxi-2 800 09:09
// Logan Taxi-1 680 09:53
// Alex REJECTED
// Ethan Taxi-4 740 12:46
// Jacob REJECTED
// Mick Taxi-2 280 15:01
// Daniel Taxi-5 820 15:41
// Henry Taxi-6 160 15:19
// Jack Taxi-4 480 16:00
// Jeba REJECTED
// Aiden Taxi-1 680 16:29
// Mathew Taxi-5 480 16:48