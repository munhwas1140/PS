#ifndef _MY_POINT_H_
#define _MY_POINT_H_
class MyPoint {
public:
    MyPoint ();
    MyPoint (int coordX, int coordY);
    MyPoint (const MyPoint& p);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    bool operator== (const MyPoint& p) const;
    bool operator!= (const MyPoint& p) const;
    int dist2sqr(const MyPoint& p) const;
    int dist1(const MyPoint& p) const;
private:
    int x, y;
};
#endif // _MY_POINT_H_ 