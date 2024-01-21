class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea=0;
        int maxDiago=0;
        for(int i=0;i<dimensions.size();i++){
            int Diago=((dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]));
            int Area=(dimensions[i][0]*dimensions[i][1]);
            if(Diago>maxDiago){
                maxDiago=Diago;
                maxArea=Area;
            }
            else if(Diago==maxDiago){
                maxArea=max(Area,maxArea);
            }
        }
        return maxArea;
    }
};