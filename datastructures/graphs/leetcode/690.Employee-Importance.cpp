/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
  void dfs(int src,
           vector<Employee *> employees,
           std::unordered_map<int, int> &lookupIdtoEmployee,
           int &totalImportance)
  {
    int thisEmp = lookupIdtoEmployee[src];

    totalImportance += employees[thisEmp]->importance;

    for (const auto &eachSub : employees[thisEmp]->subordinates)
    {
      dfs(eachSub, employees, lookupIdtoEmployee, totalImportance);
    }
  }

public:
  int getImportance(vector<Employee *> employees, int id)
  {
    std::unordered_map<int, int> lookupIdtoEmployee;
    int totalImportance = 0;

    for (int i = 0; i < employees.size(); ++i)
    {
      lookupIdtoEmployee[employees[i]->id] = i;
    }

    // input id, stands as source of dfs, keep track of nodes, visited will be needed if there is a cycle
    dfs(id, employees, lookupIdtoEmployee, totalImportance);

    return totalImportance;
  }
};