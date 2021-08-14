#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CodeBuilder {
 protected:
  string name;
  vector<pair<string, string>> members;

 public:
  CodeBuilder(const string& class_name) : name(class_name) {
    // todo
  }

  CodeBuilder& add_field(const string& name, const string& type) {
    members.push_back(make_pair(type, name));
    return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj) {
    os << "class " << obj.name << '\n';
    os << "{\n";
    
    // Structured binding declaration (since C++17)
    // for(const auto& [type, name] : obj.members) {
    //     os << "  " << type << " " << name << ";\n";
    // }
    
    for (const auto& p : obj.members) {
      os << "  " << p.first << " " << p.second << ";\n";
    }
    
    os << "};\n";
    return os;
  }
};

int main() {
  auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
  cout << cb;
}