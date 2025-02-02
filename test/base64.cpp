#define BOOST_TEST_MODULE base64
#include <boost/test/included/unit_test.hpp>
#include "wasm_boost_test.hpp"

#include <xxhr/util.hpp>

std::map<std::string, std::string> test_data {
  { "", "" },
  { "TQ=="         , "M" },
  { "TWE="         , "Ma" },
  { "TWFu"         , "Man" },
  { "cGxlYXN1cmUu" , "pleasure." },
  { "bGVhc3VyZS4=" , "leasure." },
  { "ZWFzdXJlLg==" , "easure." },
  { "YXN1cmUu"     , "asure." },
  { "c3VyZS4="     , "sure." },
  { "c3VyZS4="     , "sure." },
  { "AQABAFEAAAD5AAAAAA==", { 0x01, 0x00, 0x01, 0x00, 0x51, 0x00, 0x00, 0x00, char(0xf9), 0x00, 0x00, 0x00, 0x00 } }
}; 


BOOST_AUTO_TEST_CASE(decode) {
  BOOST_REQUIRE(test_data.size() > 0);
  for (const auto& data : test_data) {
    BOOST_TEST_MESSAGE( data.first << " check if equals " << data.second);
    BOOST_REQUIRE_EQUAL(xxhr::util::decode64(data.first), data.second);
  }
} 

BOOST_AUTO_TEST_CASE(encode) {
  BOOST_REQUIRE(test_data.size() > 0);
  for (const auto& data : test_data) {
    BOOST_TEST_MESSAGE( data.first << " check if equals " << data.second);
    BOOST_REQUIRE_EQUAL(xxhr::util::encode64(data.second), data.first);
  }
} 
