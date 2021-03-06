#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
  OrgChart organization;
  organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW")      // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

  cout << "organization:" << "\n" ;
  cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */

  cout << "level_order:" << "\n" ;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << (*it) << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI


  cout << "\n \n reverse_order:" << "\n" ;
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
    cout << (*it) << " " ;
  } // prints: VP_SW VP_BI CTO CFO COO CEO


  cout << "\n \n preorder:" << "\n" ;
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
    cout << (*it) << " " ;
  }  // prints: CEO CTO VP_SW CFO COO VP_BI


  cout << "\n \n like level order - for each loop:" << "\n" ;
  for (auto element : organization){ // this works like level order
    cout << element << " " ;
  } // prints: CEO CTO CFO COO VP_SW VP_BI


  cout << "\n \n  iterator with arrow operator:" << "\n" ;
  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
    cout << it->size() << " " ;
  } // prints: 3 3 3 3 5 5
  cout << "\n" ;


  cout << "\n   now the Chief Human Resources Officer(CHRO) is in charge:" << "\n" ;
  organization.add_root("CHRO"); 
  cout << organization << endl;

  cout << "\n  new level_order:" << "\n" ;
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
    cout << (*it) << " " ;
  } // prints: CHRO CTO CFO COO VP_SW VP_BI


  cout << "\n \n the CHRO now have the CMO (Chief Marketing Officer) as subordinate - for each loop:" << "\n" ;
  organization.add_sub("CHRO", "CMO");
  for (auto element : organization){
    cout << element << " " ;
  } // prints: CHRO CTO CFO COO CMO VP_SW VP_BI

  organization.add_sub("Mosh", "CMO");

  cout << "\n \n" ;
}
