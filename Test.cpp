#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("general organization functions"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Father"););
    CHECK_NOTHROW(organization.add_sub("Father", "Child"););
    CHECK_NOTHROW(organization.add_root("New-father"););
    OrgChart SecondOrganization;
    CHECK_NOTHROW(SecondOrganization.add_root("Dad"););
    CHECK_NOTHROW(SecondOrganization.add_sub("Dad", "Son"););

    // wrong root name throws
    CHECK_THROWS(SecondOrganization.add_sub("FakeDad", "Son"));

    auto it = organization.begin_level_order();
    auto itSecond = SecondOrganization.begin_level_order();

    CHECK((*itSecond != *it));
    CHECK((*itSecond == "Dad"));

    OrgChart EmptyOrganization;
    CHECK_THROWS(EmptyOrganization.checkIfEmpty());
    
  
}



TEST_CASE("level_order_iterator"){
    OrgChart organization;
    organization.add_root("Head")
      .add_sub("Head", "Shoulder")
      .add_sub("Head", "Shoulder2")
      .add_sub("Head", "Shoulder3")
      .add_sub("Shoulder", "Leg")
      .add_sub("Shoulder", "Leg2");

    auto it = organization.begin_level_order();
    auto end = organization.end_level_order();
    
    CHECK(it != end); 
    CHECK(*it == "Head");
    CHECK_NOTHROW(++it;);
    CHECK(it != end);
    CHECK((*it == "Shoulder" || *it == "Shoulder2" || *it == "Shoulder3"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Shoulder2" || *it == "Shoulder1" || *it == "Shoulder3"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Shoulder2" || *it == "Shoulder1" || *it == "Shoulder3"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Leg" || *it == "Leg2"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Leg" || *it == "Leg2"));
    ++it;
    CHECK_FALSE(it != end);
}


TEST_CASE("general iterator (level-order like)"){
    OrgChart organization;
    organization.add_root("Father")
      .add_sub("Father", "Son")
      .add_sub("Father", "Son2")
      .add_sub("Son", "GrandKid")
      .add_sub("Son", "GrandKid2");

    auto it = organization.begin();
    auto end = organization.end();

    CHECK(it != end);
    CHECK(*it == "Father");
    CHECK_NOTHROW(++it;);
    CHECK(it != end);
    CHECK((*it == "Son" ));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Son2"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "GrandKid" ));
    ++it;
    CHECK(it != end);
    CHECK((*it == "GrandKid2"));
    ++it;
    CHECK_FALSE(it != end);
}

TEST_CASE("reverse_order_iterator"){
    OrgChart organization;
    organization.add_root("Dad")
      .add_sub("Dad", "Kid")
      .add_sub("Dad", "Kid2")
      .add_sub("Kid", "Friend");

    auto it = organization.begin_reverse_order();
    auto end = organization.end_reverse_order();
    
    CHECK(it != end);
    CHECK(it != end);
    CHECK((*it == "Friend" ));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Kid" || *it == "Kid2"));
    ++it;
    CHECK(it != end);
    CHECK((*it == "Kid" || *it == "Kid2"));
    ++it;
    CHECK(*it == "Dad");
    ++it;
    CHECK_FALSE(it != end);

}

TEST_CASE("preorder_iterator"){

    OrgChart Chart;
    Chart.add_root("Father")
      .add_sub("Father", "Kid")
      .add_sub("Father", "Kid2")
      .add_sub("Kid", "GrandKid");

    auto it = Chart.begin_preorder();
    auto end = Chart.end_preorder();
    CHECK(it != end);
    CHECK(*it == "Father");

    CHECK_NOTHROW(++it;);
    CHECK(it != end);
    CHECK((*it == "Kid" || *it == "Kid2"));
    if (*it != "Kid") {
        ++it;
        CHECK(it != end);
        CHECK(*it == "Child1");
        ++it;
        CHECK(it != end);
        CHECK((*it == "GrandKid"));
        ++it;

    }
    else {
        ++it;
        CHECK(it != end);
        CHECK((*it == "GrandKid"));
        ++it;
        CHECK(it != end);
        CHECK(*it == "Kid2");
        ++it;
    }
}
