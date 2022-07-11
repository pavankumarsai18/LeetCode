class Solution {
public:
    int intersection(int a1, int a2, int b1, int b2)
    {
        if(a2 < b1 || b2 < a1) return 0;                     // no intersection
        if(a1 <= b1 && b1 <= a2 && a2 <= b2) return (a2-b1); // parital intersection
        if(b1 <= a1 && a1 <= b2 && b2 <= a2) return (b2-a1); // partial intersection
        if(a1 <= b1 && b1 <= b2 && b2 <= a2) return (b2-b1); // one is inside other
        return (a2-a1);                                      // one is inside another
    }
    
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        return (ax2-ax1)*(ay2-ay1) + (bx2 - bx1)*(by2-by1) - intersection(ax1,ax2,bx1,bx2)*intersection(ay1,ay2,by1,by2);
    }
};
