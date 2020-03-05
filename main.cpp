#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

struct Point //구조체를 활용하여 x,y좌표 선언
{
    int x;
    int y;
};

class two_dot
{
public:
    int n;
    int range1,range2;
    Point point1,point2;
    Point *p;
    double Min_length;
    double Max_length;

    two_dot(Point *p,int n);  //생성자
    int randomRange(int n1, int n2);  //최솟값 최댓값 범위 지정해주는 함수
    void MinMethod();  //최소값 구하는 메소드
    void MaxMethod();  //최대값 구하는 메소드

};

two_dot::two_dot(Point *p,int n)
{
    this->n = n;
    this->p = p;
}

int two_dot ::randomRange(int n1, int n2)
{
    this->range1 = n1;
    this->range2 = n2;
    while(n1>n2)  // 큰 수 작은 수가 잘못 정렬되어있을 때, swap을 한다.
    {
        int swap;
        swap = n1;
        n1 = n2;
        n2 = swap;
        break;
    }
    return (rand() % (n2-n1+1)) + n1;
}

void two_dot :: MinMethod()
{
    //최소값 결정하는 함수
    double distance;
    Min_length = this->Max_length;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!(i==j))
            {
             distance = sqrt(pow((p+i)->x - (p+j)->x,2)+pow((p+i)->y - (p+j)->y,2));
             if(distance < Min_length)
             {
                 Min_length = distance;
                 point1.x = (p+i)->x;
                 point1.y = (p+i)->y;
                 point2.x = (p+j)->x;
                 point2.y = (p+j)->y;
             }
             }
        }

    }
}

void two_dot :: MaxMethod()
{
    //최대값 결정하는 함수
    double distance;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            distance = sqrt(pow((p+i)->x - (p+j)->x,2)+pow((p+i)->y - (p+j)->y,2));
            if(distance > Max_length)
            {
                Max_length = distance;
                point1.x = (p+i)->x;
                point1.y = (p+i)->y;
                point2.x = (p+j)->x;
                point2.y = (p+j)->y;
            }
        }
    }
}

int main()
{
    cout << "Enter how many points you want to make : ";
    int n;
    cin >> n;
    if(n<=1)  //최소 2개의 점을 선택하게 하기
    {
        cout << "Wrong Input!" << endl;
        return 0;
    }

    Point *p;  //메모리 동적 할당으로 점의 개수를 정해준다.
    p = new Point[n];


    srand((unsigned int)time(nullptr));  //난수 생성

    two_dot td(p,n);  //객체 선언

    cout << "Enter the range of numbers : "; //수의 범위 입력
    cin >> td.range1 >> td.range2;
    for(int i=0;i<n;i++) //랜덤함수를 써서 구조체 x,y좌표 초기화시키기
    {
        p[i].x = td.randomRange(td.range1,td.range2);
        p[i].y = td.randomRange(td.range1,td.range2);
        cout << i+1 << ":" << "(" << p[i].x << "," << p[i].y << ")" << endl;
    }

    td.MaxMethod();   //최대값 찾기

    cout << endl;

    cout << "the max length is " << td.Max_length << endl;
    cout << "Point1 : (" << td.point1.x <<","<<td.point1.y<< ")" << endl;
    cout << "Point2 : (" << td.point2.x <<","<<td.point2.y<< ")" << endl;

    td.MinMethod();    //최솟값 찾기

    cout << endl;

    cout << "the min length is " << td.Min_length << endl;
    cout << "Point1 : (" << td.point1.x <<","<<td.point1.y<< ")" << endl;
    cout << "Point2 : (" << td.point2.x <<","<<td.point2.y<< ")" << endl;

    delete [] p;   //구조체 메모리 반환

    return 0;
}
