class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaOfA = area(ax1, ax2, ay1, ay2);
        int areaOfB = area(bx1, bx2, by1, by2);

        int areaOfOverlap = calcOverlap(ax1, ax2, bx1, bx2) * calcOverlap(ay1, ay2, by1, by2);

        return areaOfA + areaOfB - areaOfOverlap;
    }
    
    int calcOverlap(int a1, int a2, int b1, int b2) {
        int overlap =  min(a2, b2) - max(a1, b1);
        return overlap > 0 ? overlap: 0;
    }
    
    int area(int x1, int x2, int y1, int y2) {
        return (y2 - y1) * (x2 - x1);
    }
};