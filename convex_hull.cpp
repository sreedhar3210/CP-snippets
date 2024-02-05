typedef pair<double,double> pdd;
pdd p0;     //point with minimum y-cordinate. or point of reference
 
double Area(pdd p1, pdd p2, pdd p3){
    /* area > 0 points are counterclockwise
    area < 0 points are clockwise
    area = 0 points are collinear*/
    double ans = 0.5*((p1.first*(p2.second-p3.second)) + (p2.first*(p3.second-p1.second)) +
    (p3.first*(p1.second-p2.second)));
    return ans;
}
 
bool cmp(pdd p1, pdd p2){
    double area = Area(p0,p1,p2);
    if(area == 0){
        double d1 = ((p1.first-p0.first)*(p1.first-p0.first)) + ((p1.second-p0.second)*(p1.second-p0.second));
        double d2 = ((p2.first-p0.first)*(p2.first-p0.first)) + ((p2.second-p0.second)*(p2.second-p0.second));
        return (d1 <= d2);
    }
    return (area > 0);
}
 
class convex_hull{
    //minimum number of points should be >= 2  or  n >= 2
    public:
        int n;
        vector<pii>points,ch_points;
 
        convex_hull(int n){
            this->n=n;
            points.resize(n);
        }
 
        void rearrange(){
            int i;
            //getting the minimum y  co-ordinate to index 0.
            for(i=1;i<n;i++){
                if(points[i].second < points[0].second)     swap(points[i],points[0]);
                else if(points[i].second == points[0].second &&
                        points[i].first < points[0].first)  swap(points[i],points[0]);
            }
            p0=points[0];           //setting point of reference
            sort(points.begin()+1,points.end(),cmp);
        }
 
        void find_convex_hull(bool include_collinear){
            // pass the argument as true if you wanted to include collinear points else pass false.
            int i;
            double area;
            rearrange();
            if(include_collinear){
                //reversing the ending points if they are collinear to make the code consistent.
                i=n-1;
                while(i>=0 && Area(points[0],points[i],points[n-1])==0)      i--;
                reverse(points.begin()+i+1,points.end());
            }
            ch_points.push_back(points[0]);
            ch_points.push_back(points[1]);
            for(i=2;i<n;i++){
                area=Area(ch_points[ch_points.size()-2],ch_points.back(),points[i]);
                while(((area<0) || (!include_collinear && area==0)) && ch_points.size() >= 2){
                    ch_points.pop_back();
                    area=Area(ch_points[ch_points.size()-2],ch_points.back(),points[i]);
                }
                ch_points.push_back(points[i]);
            }
        }

        double area_of_convex_hull(){
            double ans=0;
            for(int i=1;i+1<ch_points.size();i++){
                ans+=Area(ch_points[0],ch_points[i],ch_points[i+1]);
            }
            return ans;
        }
 
};
