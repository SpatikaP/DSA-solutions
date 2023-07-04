class MedianFinder {
public:
    priority_queue<int> maxh; //1sthalf
    priority_queue<int, vector<int>, greater<int>> minh; //2nd half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int ls=maxh.size();
        int rs=minh.size();
        if(ls==0) /// both left side and right side are empty
        {
            maxh.push(num); // add the first element to the left side
        }
        else if(ls==rs) /// both left side and right side has equal number of elements
        {
            if(num<minh.top()) // check if num is less than last element of left side 
            {
                maxh.push(num); // push is to the left side
            }
            else 
            {
                int temp=minh.top(); // remove the last element of the left side 
                minh.pop();
                minh.push(num);      // push to the right side 
                maxh.push(temp);     // push the num to the left side
            }
        }
        else /// ls!=rs & ls!=0 
        {
            if(rs==0) //ls=1 & rs=0
            {
                if(num>maxh.top()) // if num is greater than last element of left side
                {
                    minh.push(num);
                }
                else // if num is less than last element of left side
                {
                    int temp=maxh.top(); // remove left side last element
                    maxh.pop();
                    minh.push(temp);     // add to the right side
                    maxh.push(num);      //add num to left side
                }
            }
            else if(num>maxh.top())  // ls>rs & num is greater than last element of left side 
            {
                minh.push(num); //add to the right side
            }
            else
            {
                if(num<maxh.top()) // ls>rs & num is less than last element of left side
                {
                     int temp=maxh.top(); // remove left side last element
                     maxh.pop();
                     minh.push(temp);     // add to the right side
                     maxh.push(num);      //add num to left side
                }
                else{
                    minh.push(num); //push to the right side
                }
            }
        }
    }
    
    double findMedian() {
        int ls=maxh.size();
        int rs=minh.size();
        if(ls>rs) 
            return double(maxh.top());
        else{
            double ltop=maxh.top();
            double rtop=minh.top();
            double ans = (ltop+rtop)/2;
            return ans;
        }
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */