#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
 
class Student
{
    private:
       std::string name;
       int points, index;
 
    public:
       Student(const std :: string& name = "", const int points = 0, const int index = 0) :
        name(name), points(points), index(index) {}
       
       std::string get_name() const {return name;}
       int get_points() const {return points;}
       int get_index() const {return index;}
 
       void set_name(const std::string& name) {this->name = name;}
       void set_points(const int points) {this->points = points;}
       void set_index(const int index) {this->index = index;}
 
       friend bool operator < (const Student&, const Student&);
 
       friend std::ostream& operator << (std::ostream&, const Student&);
 
};
 
bool operator < (const Student& s1, const Student& s2)  
{
    if(s1.points != s2.points)
    {
        return s1.points < s2.points;  
    }
    else
    {
        return s1.index < s2.index;
    }
}
 
std::ostream& operator << (std::ostream& out, const Student& s)
{
    out << s.name << ": points=" << s.points << ", index=" << s.index;
        return out;
}
 
void print_list(std::vector<Student>& lst)
{
    std::vector<Student>::iterator it;
 
    for(it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;
}
 
void scan_infile(std::vector<Student>& lst)
{
    std::string name;
    int points, index;
    std::ifstream infile;
    infile.open("students.txt");
    if (infile.is_open())
        while(!infile.eof())
        {
            infile >> name >> points >> index;
            lst.push_back(Student(name,points,index));
        }
}
 
int main()
{
    std::vector<Student> st;
 
    scan_infile(st);
 
    print_list(st);
 
    std::sort(st.begin(), st.end());
    print_list(st);
 
    return 0;
}
