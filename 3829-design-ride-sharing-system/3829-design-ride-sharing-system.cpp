class RideSharingSystem {
public:
    queue<int> rider;  
    queue<int> driver;
    RideSharingSystem() {
    queue<int> empty1;
    queue<int> empty2;
    swap(rider, empty1); 
    swap(driver, empty2); 
    return;
    }
    
    void addRider(int riderId) {
    rider.push(riderId) ; 
    return;
    }
    
    void addDriver(int driverId) {
    driver.push(driverId) ; 
    return  ;
    }
    
    vector<int> matchDriverWithRider() {
    if(!rider.empty() && !driver.empty()){
        int a=rider.front();
        int b=driver.front();
        rider.pop();
        driver.pop();
        return {b,a} ;
    }
    return  {-1,-1} ; 
    }
    
    void cancelRider(int riderId) {
        int n=rider.size();
        if(n==0)return;
        for(int i=0;i<n;i++){
            int a=rider.front();
            rider.pop();
            if(a==riderId)continue;
            rider.push(a);
        }
        return;

    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */