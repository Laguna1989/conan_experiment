#include <iostream>

#define APPROVALS_CATCH2_V3

#include "catch2/catch_all.hpp"
#include "ApprovalTests.hpp"


TEST_CASE("catch2_starter sample")
{
    ApprovalTests::Approvals::verify(42);
}
