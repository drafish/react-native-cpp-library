#include "HelloCxxModule.h"

#include "cxxreact/Instance.h"

HelloCxxModule::HelloCxxModule() {}

std::string HelloCxxModule::getName() {
  return "HelloCxxModule";
}

auto HelloCxxModule::getConstants() -> std::map<std::string, folly::dynamic> {
  return {
      {"one", 1}, {"two", 2}, {"animal", "fox"},
  };
}

auto HelloCxxModule::getMethods() -> std::vector<Method> {
  return {
      Method("foo", [](folly::dynamic args, Callback cb) { 
        example::Test test;
        int j = test.runTest();
        cb({j}); 
      }),
      Method("bar",
             [this]() {
               if (auto reactInstance = getInstance().lock()) {
                 reactInstance->callJSFunction(
                     "RCTDeviceEventEmitter", "emit",
                     folly::dynamic::array(
                         "appStateDidChange",
                         folly::dynamic::object("app_state", "active")));
               }
             }),
  };
}

extern "C" HelloCxxModule* createHelloCxxModule() {
  return new HelloCxxModule();
}
