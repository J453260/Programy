#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>
using namespace std;

class Point
{
    int dimension;
    int id;
    string name;
    vector<double> coordinates; //współrzędne
    //vector<vector<dimension>> history;

public:
    Point(int id, string name, int dim) : id(id), name(name), dimension(dim)
    {
        coordinates.resize(dim);
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int dim() const
    {
        return coordinates.size();
    }

    void set(size_t i, double v)
    {
        coordinates.at(i) = v;    // ustaw wartość współrzędnej
    }

    void read()
    {
        for(double& x : coordinates)
        {
            cin >> x;
        }
    }


    static double distance(const Point& a, const Point& b)
    {
        double sum = 0;
        for(size_t i = 0; i < a.coordinates.size(); ++i)
        {
            double diff = a.coordinates[i] - b.coordinates[i];
            sum += diff * diff;
        }
        return sqrt(sum);
    }
};

class PointDatabase
{
    vector<Point> data;
    int nextId = 1;
    int dimension;

public:

    void SetDimension()
    {
        cout<<"Wymiar: ";
        cin>>dimension;
    }

    void addPoint()
    {
        string name;
        cout<<"Nazwa: ";
        cin>>name;

        Point point(nextId++, name, dimension);
        cout<<"Podaj wspolrzedne:\n";
        point.read();
        data.push_back(point);
    }

    void Display() const
    {
        for(const auto& p : data)
        {
            cout<<"ID: "<<p.getId()<<" Nazwa: "<<p.getName()<<"  Wymiar:"<<p.dim()<<endl<<endl;
        }
    }

    Point* find(int id)
    {
        for(auto& p : data)
        {
            if(p.getId() == id) return &p;
        }
        return nullptr;
    }

    Point* findNearest(int id)
    {
        Point* target = find(id);
        if(!target || data.size() < 2) return nullptr;

        Point* nearest = nullptr;
        double minDist = numeric_limits<double>::max();

        for(auto& p : data)
        {
            if(p.getId() == id) continue;
            if(p.dim() != target->dim()) continue;

            double d = Point::distance(*target, p);
            if(d < minDist)
            {
                minDist = d;
                nearest = &p;
            }
        }
        return nearest;
    }
};

class MainPanel
{
    PointDatabase database;

public:
    void Panel()
    {
        cout<<"| --- Panel glowny --- |"<<endl;
        cout<<"|                      |"<<endl;
        cout<<"|   Wybierz operacje:  |"<<endl;
        cout<<"| 1.Dodaj punkt        |"<<endl;
        cout<<"| 2.Pokaz punkty       |"<<endl;
        cout<<"| 3.Oblicz najblizszy  |"<<endl;
        cout<<"| punkt do wskazanego  |"<<endl;
        cout<<"| 4.Zakoncz program    |"<<endl;
        cout<<"|                      |"<<endl;
        cout<<"| Podaj najpierw wymiar|"<<endl;
        cout<<"|dla wszystkich punktow|"<<endl;
        cout<<"|                      |"<<endl;
        cout<<"| -------------------- |"<<endl;
        cout<<endl;
        database.SetDimension();

        while(true)
        {
            cout<<"| -------------------- |"<<endl;
            cout<<"|                      |"<<endl;
            cout<<"|   Wybierz operacje:  |"<<endl;
            cout<<"| 1.Dodaj punkt        |"<<endl;
            cout<<"| 2.Pokaz punkty       |"<<endl;
            cout<<"| 3.Oblicz najblizszy  |"<<endl;
            cout<<"| punkt do wskazanego  |"<<endl;
            cout<<"| 4.Zakoncz program    |"<<endl;
            cout<<"|                      |"<<endl;
            cout<<"| -------------------- |"<<endl;
            cout<<endl;
            int wybor;
            cout<<"Wybor: ";
            cin>>wybor;

            switch(wybor)
            {
            case 1:
                database.addPoint();
                break;
            case 2:
                database.Display();
                break;
            case 3:
            {
                int id;
                cout<<"Podaj ID punktu: ";
                cin>>id;
                Point* nearest = database.findNearest(id);
                Point* target = database.find(id);
                if(nearest && target)
                    cout << "Najblizszy punkt: ID=" << nearest->getId()
                         << " " << nearest->getName()
                         << ", odleglosc=" << Point::distance(*target, *nearest) << endl;
                else
                    cout << "Nie znaleziono punktu lub baza zawiera tylko ten punkt\n";

                break;
            }

            case 4:
                return;

            default:
                cout << "Nieprawidlowy wybor"<<endl;
            }
        }
    };
};



int main()
{
    MainPanel start;
    start.Panel();
    return 0;
}
