struct Line {
    pll p1, p2;
    Line() {};
    Line(pll p1, pll p2) : p1(p1), p2(p2) {}
};
int ccw(pll u, pll v, pll w) {
    int t1 = (v.first - u.first) * (w.second - u.second);
    int t2 = (v.second - u.second) * (w.first - u.first);
    if(t1 - t2 > 0) return 1;
    else if(t1 - t2 < 0) return -1;
    return 0;
}
bool cross(Line u, Line v) {
    pll a = u.p1; pll b = u.p2;
    pll c = v.p1; pll d = v.p2;
    int asect = ccw(a, b, c) * ccw(a, b, d);
    int bsect = ccw(c, d, a) * ccw(c, d, b);
    if(!asect && !bsect) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return asect <= 0 && bsect <= 0;
}