#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct Point{
    float x, y;
    float dist(const Point &p){
        return sqrt((p.x-this->x)*(p.x-this->x) + (p.y-this->y)*(p.y-this->y));
    }
};

istream& operator>> (istream& i, Point& p)
{
    i>>p.x >> p.y;
    return i;
}

ostream& operator<< (ostream& o, const Point& p)
{
    o << "(" << p.x << "," << p.y << ")";
    return o;
}

bool cmp(Point& a, Point& b)
{
    return a.x < b.x;
}

pair<pair<Point,Point>,float> smallest_distance_bf(vector<Point>& points, int l, int r)
{
    float d = points[l].dist(points[l+1]);
    Point p1=points[l], p2=points[l+1];
    for(int i=0; i<r-1; i++)
    {
        for(int j=i+1; j<r; j++)
        {
            float d1 = points[i].dist(points[j]);
            if (d1 < d)
            {
                d = d1;
                p1=points[i], p2=points[j];
            }
        }
    }
    return {{p1,p2},d};
}

auto min(pair<pair<Point,Point>,float> x1, pair<pair<Point,Point>,float> x2)
{
    return (x1.second <= x2.second)?x1:x2;
}

pair<pair<Point,Point>,float> smallest_distance_dq(vector<Point>& points, int l, int r)
{
    int mid=(r+l)/2;
    if ((r-l)<=3){
        auto x = smallest_distance_bf(points, l, r);
        return x;
    }

    auto dl = smallest_distance_dq(points, l, mid);
    auto dr = smallest_distance_dq(points, mid+1, r);
    auto d = min(dl,dr);
    int small = mid-1;
    while(small >= l && points[mid].dist(points[small]) < d.second) {
        if (points[mid].dist(points[small]) < d.second){small--;}
    }
    small++;
    int big=mid+1;
    while(big < r && points[mid].dist(points[big]) < d.second) {
        if (points[mid].dist(points[big]) < d.second){big++;}
    }
    big--;

    auto strip_d = smallest_distance_bf(points, small, big);

    if (strip_d.second < d.second){
        d=strip_d;
    }
    return d;
}


int main()
{
    srand(time(0));
    vector<Point> points;
    int n = 10000;

    for (int i = 0; i < n; i++)
    {
        Point t;
        t.x = static_cast<float>(rand()) / RAND_MAX * 100.0;
        t.y = static_cast<float>(rand()) / RAND_MAX * 100.0;
        points.push_back(t);
    }
    sort(points.begin(), points.end(), cmp);
    auto x = smallest_distance_dq(points, 0, points.size() - 1);
    cout << "[" << x.first.first << ", " << x.first.second << "]" << " -> " << x.second;
    return 0;
}